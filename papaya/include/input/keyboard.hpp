// keyboard.hpp

#pragma once

#include <input/key.hpp>

namespace papaya {
   class Keyboard {
   public:
      Keyboard();

      void update();

      bool down(const Key keycode) const;
      bool pressed(const Key keycode) const;
      bool released(const Key keycode) const;

      bool any_down() const;
      bool any_pressed() const;
      bool any_released() const;

      bool first_down(Key &keycode) const;
      bool first_pressed(Key &keycode) const;
      bool first_released(Key &keycode) const;

      void on_key_pressed(const Key keycode, const bool repeat);
      void on_key_released(const Key keycode);

   private:
      struct {
         bool down_;
         bool pressed_;
         bool released_;
      } keys_[int(Key::Count)];
   };
} // !papaya
