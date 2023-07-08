// dispatcher.cc

#include "platform/dispatcher.hpp"
#include "platform/events.hpp"

#include "input/key.hpp"
#include "input/button.hpp"

#include <SDL.h>

namespace papaya {
   inline constexpr Button sdl_to_button(const Uint8 button)
   {
      switch (button)
      {
         case SDL_BUTTON_LEFT:   return Button::Left;
         case SDL_BUTTON_RIGHT:  return Button::Right;
         case SDL_BUTTON_MIDDLE: return Button::Middle;
      }

      return Button::Invalid;
   }

   inline constexpr Key scancode_to_keycode(const SDL_Scancode code)
   {
      switch (code) {
         case SDL_SCANCODE_BACKSPACE: return Key::Back;
         case SDL_SCANCODE_TAB: return Key::Tab;
         case SDL_SCANCODE_CLEAR: return Key::Clear;
         case SDL_SCANCODE_RETURN: return Key::Enter;
         case SDL_SCANCODE_PAUSE: return Key::Pause;
         case SDL_SCANCODE_CAPSLOCK: return Key::CapsLock;
         case SDL_SCANCODE_ESCAPE: return Key::Escape;
         case SDL_SCANCODE_SPACE: return Key::Space;
         case SDL_SCANCODE_PAGEUP: return Key::PageUp;
         case SDL_SCANCODE_PAGEDOWN: return Key::PageDown;
         case SDL_SCANCODE_END: return Key::End;
         case SDL_SCANCODE_HOME: return Key::Home;
         case SDL_SCANCODE_LEFT: return Key::Left;
         case SDL_SCANCODE_UP: return Key::Up;
         case SDL_SCANCODE_RIGHT: return Key::Right;
         case SDL_SCANCODE_DOWN: return Key::Down;
         case SDL_SCANCODE_PRINTSCREEN: return Key::PrintScreen;
         case SDL_SCANCODE_INSERT: return Key::Insert;
         case SDL_SCANCODE_DELETE: return Key::Del;
         case SDL_SCANCODE_0: return Key::Num0;
         case SDL_SCANCODE_1: return Key::Num1;
         case SDL_SCANCODE_2: return Key::Num2;
         case SDL_SCANCODE_3: return Key::Num3;
         case SDL_SCANCODE_4: return Key::Num4;
         case SDL_SCANCODE_5: return Key::Num5;
         case SDL_SCANCODE_6: return Key::Num6;
         case SDL_SCANCODE_7: return Key::Num7;
         case SDL_SCANCODE_8: return Key::Num8;
         case SDL_SCANCODE_9: return Key::Num9;
         case SDL_SCANCODE_A: return Key::A;
         case SDL_SCANCODE_B: return Key::B;
         case SDL_SCANCODE_C: return Key::C;
         case SDL_SCANCODE_D: return Key::D;
         case SDL_SCANCODE_E: return Key::E;
         case SDL_SCANCODE_F: return Key::F;
         case SDL_SCANCODE_G: return Key::G;
         case SDL_SCANCODE_H: return Key::H;
         case SDL_SCANCODE_I: return Key::I;
         case SDL_SCANCODE_J: return Key::J;
         case SDL_SCANCODE_K: return Key::K;
         case SDL_SCANCODE_L: return Key::L;
         case SDL_SCANCODE_M: return Key::M;
         case SDL_SCANCODE_N: return Key::N;
         case SDL_SCANCODE_O: return Key::O;
         case SDL_SCANCODE_P: return Key::P;
         case SDL_SCANCODE_Q: return Key::Q;
         case SDL_SCANCODE_R: return Key::R;
         case SDL_SCANCODE_S: return Key::S;
         case SDL_SCANCODE_T: return Key::T;
         case SDL_SCANCODE_U: return Key::U;
         case SDL_SCANCODE_V: return Key::V;
         case SDL_SCANCODE_W: return Key::W;
         case SDL_SCANCODE_X: return Key::X;
         case SDL_SCANCODE_Y: return Key::Y;
         case SDL_SCANCODE_Z: return Key::Z;
         case SDL_SCANCODE_KP_0: return Key::Keypad_0;
         case SDL_SCANCODE_KP_1: return Key::Keypad_1;
         case SDL_SCANCODE_KP_2: return Key::Keypad_2;
         case SDL_SCANCODE_KP_3: return Key::Keypad_3;
         case SDL_SCANCODE_KP_4: return Key::Keypad_4;
         case SDL_SCANCODE_KP_5: return Key::Keypad_5;
         case SDL_SCANCODE_KP_6: return Key::Keypad_6;
         case SDL_SCANCODE_KP_7: return Key::Keypad_7;
         case SDL_SCANCODE_KP_8: return Key::Keypad_8;
         case SDL_SCANCODE_KP_9: return Key::Keypad_9;
         case SDL_SCANCODE_KP_MULTIPLY: return Key::Keypad_Multiply;
         case SDL_SCANCODE_KP_PLUS: return Key::Keypad_Add;
         case SDL_SCANCODE_KP_PERIOD: return Key::Keypad_Separator;
         case SDL_SCANCODE_KP_MINUS: return Key::Keypad_Subtract;
         case SDL_SCANCODE_KP_DECIMAL: return Key::Keypad_Decimal;
         case SDL_SCANCODE_KP_DIVIDE: return Key::Keypad_Divide;
         case SDL_SCANCODE_F1: return Key::F1;
         case SDL_SCANCODE_F2: return Key::F2;
         case SDL_SCANCODE_F3: return Key::F3;
         case SDL_SCANCODE_F4: return Key::F4;
         case SDL_SCANCODE_F5: return Key::F5;
         case SDL_SCANCODE_F6: return Key::F6;
         case SDL_SCANCODE_F7: return Key::F7;
         case SDL_SCANCODE_F8: return Key::F8;
         case SDL_SCANCODE_F9: return Key::F9;
         case SDL_SCANCODE_F10: return Key::F10;
         case SDL_SCANCODE_F11: return Key::F11;
         case SDL_SCANCODE_F12: return Key::F12;
         case SDL_SCANCODE_NUMLOCKCLEAR: return Key::NumLock;
         case SDL_SCANCODE_SCROLLLOCK: return Key::ScrollLock;
         case SDL_SCANCODE_LSHIFT: return Key::LeftShift;
         case SDL_SCANCODE_RSHIFT: return Key::RightShift;
         case SDL_SCANCODE_LCTRL: return Key::LeftControl;
         case SDL_SCANCODE_RCTRL: return Key::RightControl;
         case SDL_SCANCODE_LALT: return Key::LeftAlt;
         case SDL_SCANCODE_RALT: return Key::RightAlt;
         case SDL_SCANCODE_LGUI: return Key::LeftWin;
         case SDL_SCANCODE_GRAVE: return Key::Grave;
         case SDL_SCANCODE_COMMA: return Key::Comma;
         case SDL_SCANCODE_MINUS: return Key::Minus;
         case SDL_SCANCODE_EQUALS: return Key::Equals;
         case SDL_SCANCODE_LEFTBRACKET: return Key::LeftBracket;
         case SDL_SCANCODE_RIGHTBRACKET: return Key::RightBracket;
         case SDL_SCANCODE_BACKSLASH: return Key::Backslash;
         case SDL_SCANCODE_SEMICOLON: return Key::SemiColon;
         case SDL_SCANCODE_APOSTROPHE: return Key::Apostrophe;
         case SDL_SCANCODE_PERIOD: return Key::Period;
         case SDL_SCANCODE_SLASH: return Key::Slash;
         case SDL_SCANCODE_NONUSBACKSLASH: return Key::Pipe;
         case SDL_SCANCODE_MENU: return Key::Menu;
      }

      return Key::None;
   }

   Dispatcher::Dispatcher()
   {
   }

   bool Dispatcher::update()
   {
      SDL_Event event{};
      while (SDL_PollEvent(&event)) {
         if (event.type == SDL_MOUSEMOTION) {
            submit(MouseMoveEvent{ event.motion.x, event.motion.y });
         }
         else if (event.type == SDL_MOUSEBUTTONDOWN) {
            Button button = sdl_to_button(event.button.button);
            if (button != Button::Invalid) {
               submit(MouseButtonEvent{ button, true });
            }
         }
         else if (event.type == SDL_MOUSEBUTTONUP) {
            Button button = sdl_to_button(event.button.button);
            if (button != Button::Invalid) {
               submit(MouseButtonEvent{ button, false });
            }
         }
         else if (event.type == SDL_MOUSEWHEEL) {
            submit(MouseWheelEvent{ event.wheel.y });
         }
         else if (event.type == SDL_KEYDOWN) {
            Key keycode = scancode_to_keycode(event.key.keysym.scancode);
            if (keycode != Key::None) {
               bool repeat = event.key.repeat != 0 ? true : false;
               submit(KeyPressedEvent{ keycode, repeat });
            }
         }
         else if (event.type == SDL_KEYUP) {
            Key keycode = scancode_to_keycode(event.key.keysym.scancode);
            if (keycode != Key::None) {
               submit(KeyReleasedEvent{ keycode });
            }
         }
         else if (event.type == SDL_QUIT) {
            submit( WindowClosingEvent{} );
            return false;
         }
      }

      return true;
   }
} // !papaya
 