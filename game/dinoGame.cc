#include "dinoGame.hpp"

using namespace papaya;

dinoGame::dinoGame(papaya::Runtime& runtime) : runtime_(runtime)
{
	Init();
	interactionKey = Key::Space;
	elapsedJump = 0.0f;
	elapsedSpawn = 0.0f;
	elapsed = 0.0f;
	elapsedScore = 0.0f;
	dino_ = new dino();
	bg_ = new bg();
	state = menu;
	
	for (int i = 0; i < 10; i++)
	{
		bigs[i] = new bigobstacle();
	}

	for (int i = 0; i < 10; i++)
	{
		smalls[i] = new smallobstacle();
	}

	jumping = false;
	randSpawn = 0.5f;
	distance = 0.0f;
	numBig = 0;
	numSmall = 0;
	score_ = 0;

	verticesNum[4][0] = { Vector2(1009.0f,  0.0f), Vector2(0.0f, 0.0f), Color(1.0f, 1.0f, 1.0f, 1.0f) };
	verticesNum[4][1] = { Vector2(1024.0f,  0.0f), Vector2(1.0f, 0.0f), Color(1.0f, 1.0f, 1.0f, 1.0f) };
	verticesNum[4][2] = { Vector2(1024.0f, 20.0f), Vector2(1.0f, 1.0f), Color(1.0f, 1.0f, 1.0f, 1.0f) };
	verticesNum[4][3] = { Vector2(1009.0f, 20.0f), Vector2(0.0f, 1.0f), Color(1.0f, 1.0f, 1.0f, 1.0f) };

	for (int i = 3; i >= 0; i--)
	{
		for (int j = 3; j >= 0; j--)
		{
			verticesNum[i][j] = verticesNum[4][j];
			verticesNum[i][j].position_.x_ -= (15.0f * (4 - i));
		}
	}

	verticesHigh[4][0] = { Vector2(1009.0f,  20.0f), Vector2(0.0f, 0.0f), Color(1.0f, 1.0f, 1.0f, 1.0f) };
	verticesHigh[4][1] = { Vector2(1024.0f,  20.0f), Vector2(1.0f, 0.0f), Color(1.0f, 1.0f, 1.0f, 1.0f) };
	verticesHigh[4][2] = { Vector2(1024.0f, 40.0f), Vector2(1.0f, 1.0f), Color(1.0f, 1.0f, 1.0f, 1.0f) };
	verticesHigh[4][3] = { Vector2(1009.0f, 40.0f), Vector2(0.0f, 1.0f), Color(1.0f, 1.0f, 1.0f, 1.0f) };

	for (int i = 3; i >= 0; i--)
	{
		for (int j = 3; j >= 0; j--)
		{
			verticesHigh[i][j] = verticesHigh[4][j];
			verticesHigh[i][j].position_.x_ -= (15.0f * (4 - i));
		}
	}

	for (int i = 0; i < 5; i++)
	{
		score[i] = 0;
	}
};

dinoGame::~dinoGame()
{
	delete dino_;
	delete bg_;
	for (int i = 0; i < 10; i++)
	{
		delete bigs[i];
	}
	for (int i = 0; i < 10; i++)
	{
		delete smalls[i];
	}
};

bool dinoGame::Update(float deltatime)
{
	elapsed = deltatime;
	jump();
	bg_->moveBg(elapsed);
	bg_->moveGround(elapsed);
	spawn();
	moveObs();
	checkCollision();
	Score();
	return true;
}

void dinoGame::Render()
{
	Graphics::clear({ 0, 0, 0, 0 });
	Graphics::set_viewport({ 0, 0, 1024, 576 });
	Graphics::set_projection(Matrix4::orthographic(1024.0f, 576.0f));

	const Vertex verticesMenu[] =
	{
	   { Vector2(0.0f,  0.0f), Vector2(0.0f, 0.0f), Color(1.0f, 1.0f, 1.0f, 1.0f) },
	   { Vector2(1024.0f,  0.0f), Vector2(1.0f, 0.0f), Color(1.0f, 1.0f, 1.0f, 1.0f) },
	   { Vector2(1024.0f, 576.0f), Vector2(1.0f, 1.0f), Color(1.0f, 1.0f, 1.0f, 1.0f) },
	   { Vector2(0.0f, 576.0f), Vector2(0.0f, 1.0f), Color(1.0f, 1.0f, 1.0f, 1.0f) },
	};

	for (int i = 4; i >= 0; i--)
	{
		if (score[i] == 0) numTextures[i] = runtime_.textures().find("assets/0.png");
		if (score[i] == 1) numTextures[i] = runtime_.textures().find("assets/1.png");
		if (score[i] == 2) numTextures[i] = runtime_.textures().find("assets/2.png");
		if (score[i] == 3) numTextures[i] = runtime_.textures().find("assets/3.png");
		if (score[i] == 4) numTextures[i] = runtime_.textures().find("assets/4.png");
		if (score[i] == 5) numTextures[i] = runtime_.textures().find("assets/5.png");
		if (score[i] == 6) numTextures[i] = runtime_.textures().find("assets/6.png");
		if (score[i] == 7) numTextures[i] = runtime_.textures().find("assets/7.png");
		if (score[i] == 8) numTextures[i] = runtime_.textures().find("assets/8.png");
		if (score[i] == 9) numTextures[i] = runtime_.textures().find("assets/9.png");
	}

	switch (getState()) {
	default:
	case menu:
		Graphics::render(menuTexture, 4, verticesMenu);
		break;
	case dead:
		Graphics::render(deadTexture, 4, verticesMenu);
		for (int i = 0; i < 5; i++)
		{
			Graphics::render(numTextures[i], 4, verticesNum[i]);
		}
		for (int i = 0; i < 5; i++)
		{
			Graphics::render(highTextures[i], 4, verticesHigh[i]);
		}
		break;
	case play:
		Graphics::render(bgTexture, 4, bg_->verticesBg);
		Graphics::render(groundTexture, 4, bg_->verticesGround);
		Graphics::render(dinoTexture, 4, dino_->verticesDino);
		for (int i = 0; i < 5; i++)
		{
			Graphics::render(numTextures[i], 4, verticesNum[i]);
		}

		for (int i = 0; i < 10; i++)
		{
			Graphics::render(bigTexture, 4, bigs[i]->verticesBig);
		}

		for (int i = 0; i < 10; i++)
		{
			Graphics::render(smallTexture, 4, smalls[i]->verticesSmall);
		}
		for (int i = 0; i < 5; i++)
		{
			Graphics::render(highTextures[i], 4, verticesHigh[i]);
		}
		break;
	}
}

void dinoGame::jump()
{
	if (runtime_.input().keyboard().released(interactionKey)) {
		jumping = true;
	}
	else if (jumping) {
		elapsedJump += elapsed;
		if (elapsedJump <= 0.5f)
		{
			for (int i = 0; i < 4; i++)
			{
				dino_->verticesDino[i].position_.y_ -= elapsed * 200.0f;
			}
		}
		if (elapsedJump > 0.5f)
	    {
			for (int i = 0; i < 4; i++)
			{
				dino_->verticesDino[i].position_.y_ += elapsed * 200.0f;
			}
		}
		if (elapsedJump >= 1.0f)
		{
			jumping = false;
			dino_->verticesDino[0] = { Vector2(30.0f,  400.0f), Vector2(0.0f, 0.0f), Color(1.0f, 1.0f, 1.0f, 1.0f) };
			dino_->verticesDino[1] = { Vector2(81.0f,  400.0f), Vector2(1.0f, 0.0f), Color(1.0f, 1.0f, 1.0f, 1.0f) };
			dino_->verticesDino[2] = { Vector2(81.0f, 454.0f), Vector2(1.0f, 1.0f), Color(1.0f, 1.0f, 1.0f, 1.0f) };
			dino_->verticesDino[3] = { Vector2(30.0f, 454.0f), Vector2(0.0f, 1.0f), Color(1.0f, 1.0f, 1.0f, 1.0f) };
		}
	}
	else
	{
		elapsedJump = 0.0f;
	}
}

void dinoGame::spawn()
{
	elapsedSpawn += elapsed;
	if (elapsedSpawn >= randSpawn)
	{
		elapsedSpawn = 0.0f;
		randSpawn = rand.range(1.0f, 2.5f);
		float obsType = rand.range(0.0f, 2.0f);
		if (obsType < 1.0f)
		{
			if (numBig >= 10)
			{
				numBig = 0;
			}
			if (bigs[numBig]->active)
			{
				for (int i = 0; i < 4; i++)
				{
					bigs[numBig]->verticesBig[i] = bigs[numBig]->startBig[i];
				}
			}
			bigs[numBig]->active = true;
			numBig++;
		}
		else
		{
			if (numSmall >= 10)
			{
				numSmall = 0;
			}
			if (smalls[numSmall]->active)
			{
				for (int i = 0; i < 4; i++)
				{
					smalls[numSmall]->verticesSmall[i] = smalls[numSmall]->startSmall[i];
				}
			}
			smalls[numSmall]->active = true;
			numSmall++;
		}
	}
}

void dinoGame::moveObs()
{
	for (int i = 0; i < 10; i++)
	{
		if (bigs[i]->active)
		{
			for (int j = 0; j < 4; j++)
			{
				bigs[i]->verticesBig[j].position_.x_ -= elapsed * 150.0f;
			}
		}
		if (smalls[i]->active)
		{
			for (int j = 0; j < 4; j++)
			{
				smalls[i]->verticesSmall[j].position_.x_ -= elapsed * 150.0f;
			}
		}
	}
}

void dinoGame::checkCollision()
{
	for (int i = 0; i < 10; i++)
	{
		if (dino_->verticesDino[2].position_.x_ > bigs[i]->verticesBig[3].position_.x_ + 10.0f && dino_->verticesDino[3].position_.x_ < bigs[i]->verticesBig[2].position_.x_ - 10.0f && dino_->verticesDino[2].position_.y_ > bigs[i]->verticesBig[0].position_.y_ + 25.0f)
		{
			setState(dead);
		}
		if (dino_->verticesDino[2].position_.x_ > smalls[i]->verticesSmall[3].position_.x_ + 20.0f && dino_->verticesDino[3].position_.x_ < smalls[i]->verticesSmall[2].position_.x_ - 20.0f && dino_->verticesDino[2].position_.y_ > smalls[i]->verticesSmall[0].position_.y_ + 25.0f)
		{
			setState(dead);
		}
	}
}

void dinoGame::Score()
{
	elapsedScore += elapsed;
	if (elapsedScore >= 0.1f)
	{
		elapsedScore = 0.0f;
		score_++;
		score[4] = score_ % 10;
		score[3] = score_ / 10 % 10;
		score[2] = score_ / 100 % 10;
		score[1] = score_ / 1000 % 10;
		score[0] = score_ / 10000 % 10;
	}
}

void dinoGame::setState(dinoGame::State_ state_)
{
	state = state_;
}

bool dinoGame::Init()
{
	runtime_.filesystem().enumerate_folder("assets/",
		[&](const char* filename) {
			runtime_.textures().load(filename);
		});
	dinoTexture = runtime_.textures().find("assets/dino.png");
	bgTexture = runtime_.textures().find("assets/bg.png");
	groundTexture = runtime_.textures().find("assets/ground.png");
	bigTexture = runtime_.textures().find("assets/big.png");
	smallTexture = runtime_.textures().find("assets/small.png");
	menuTexture = runtime_.textures().find("assets/menu.png");
    deadTexture = runtime_.textures().find("assets/dead.png");

	for (int i = 0; i < 5; i++)
	{
		numTextures[i] = runtime_.textures().find("assets/0.png");
	}

	for (int i = 0; i < 5; i++)
	{
		highTextures[i] = runtime_.textures().find("assets/0.png");
	}

	return true;
}

dinoGame::State_ dinoGame::getState()
{
	return state;
}



