// game_run.cc

#include <papaya.hpp>

#include <stdexcept>

#include "dinoGame.hpp"
#include "dino.hpp"
#include "bg.hpp"

int game_run()
{
    using namespace papaya;

    try {
        Platform platform;
        Window window("papaya", 1024, 576);
        Dispatcher dispatcher;
        Input input;
        FileSystem filesystem("lippuu", "papaya");
        Renderer renderer;

        TextureStorage textures(filesystem);

        Runtime runtime(dispatcher,
            input,
            filesystem,
            textures,
            renderer);

        dinoGame* game = new dinoGame(runtime);

        if (!Graphics::init()) {
            throw std::runtime_error("Could not initialize Graphics!");
        }

        dispatcher.register_listener<KeyPressedEvent>(input);
        dispatcher.register_listener<KeyReleasedEvent>(input);

        Debug::log("Platform and window ok!");
        
       
        const Texture* highTextures_[5];
        for (int i = 0; i < 5; i++)
        {
            highTextures_[i] = game->runtime_.textures().find("assets/0.png");
        }

        int highScore[5];
        int highScore_ = 0;
        for (int i = 0; i < 5; i++)
        {
            highScore[i] = 0;
        }

        bool running = true;
        while (running) {
            auto dt = game->runtime_.deltatime();
            game->runtime_.input().update();
            if (!game->runtime_.dispatcher().update()) {
                running = false;
            }

            float mouse_x = static_cast<float>(input.mouse().x());
            float mouse_y = static_cast<float>(input.mouse().y());
            Vector2 mp = Vector2(mouse_x, mouse_y) / Vector2(1024.0f, 576.0f);

            game->Render();

            switch (game->getState()) {
                default:
                case game->menu:
                    if (game->runtime_.input().keyboard().released(game->interactionKey)) {
                        game->setState(game->play);
                    }
                    break;
                case game->dead:
                    if (game->score_ > highScore_)
                    {
                        highScore_ = game->score_;
                        for (int i = 0; i < 5; i++)
                        {
                            highScore[i] = game->score[i];
                            highTextures_[i] = game->numTextures[i];
                            game->highTextures[i] = highTextures_[i];
                        }
                    }

                    if (game->runtime_.input().keyboard().released(game->interactionKey)) {
                        delete game;
                        game = new dinoGame(runtime);
                        for (int i = 0; i < 5; i++)
                        {
                            game->highTextures[i] = highTextures_[i];
                        }
                        game->setState(game->play);
                    }
                    break;
                case game->play:
                    game->Update(dt.as_seconds());
                    break;
            }
            
            window.present();
        }

        Graphics::shut();
    }
    catch (std::exception& e) {
        (void)e;
    }

    return 0;
}
