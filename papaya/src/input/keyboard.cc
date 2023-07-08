// keyboard.cc

#include "input/keyboard.hpp"

namespace papaya {
   Keyboard::Keyboard() 
      : keys_{}
   {
   }

   void Keyboard::update()
   {
      for (auto &key : keys_) {
         key.pressed_ = false;
         key.released_ = false;
      }
   }

   bool Keyboard::down(const Key keycode) const
   {
      return keys_[int(keycode)].down_;
   }

   bool Keyboard::pressed(const Key keycode) const 
   {
      return keys_[int(keycode)].pressed_;
   }

   bool Keyboard::released(const Key keycode) const
   {
      return keys_[int(keycode)].released_;
   }

   bool Keyboard::any_down() const
   {
      for (int index = 0; index < int(Key::Count); index++) {
         if (down(Key(index))) {
            return true;
         }
      }

      return false;
   }

   bool Keyboard::any_pressed() const
   {
      for (int index = 0; index < int(Key::Count); index++) {
         if (pressed(Key(index))) {
            return true;
         }
      }

      return false;
   }

   bool Keyboard::any_released() const 
   {
      for (int index = 0; index < int(Key::Count); index++) {
         if (released(Key(index))) {
            return true;
         }
      }

      return false;
   }

   bool Keyboard::first_down(Key &keycode) const
   {
      for (int index = 0; index < int(Key::Count); index++) {
         if (down(Key(index))) {
            keycode = Key(index);
            return true;
         }
      }

      return false;
   }
   
   bool Keyboard::first_pressed(Key &keycode) const
   {
      for (int index = 0; index < int(Key::Count); index++) {
         if (pressed(Key(index))) {
            keycode = Key(index);
            return true;
         }
      }

      return false;
   }

   bool Keyboard::first_released(Key &keycode) const
   {
      for (int index = 0; index < int(Key::Count); index++) {
         if (released(Key(index))) {
            keycode = Key(index);
            return true;
         }
      }

      return false;
   }

   void Keyboard::on_key_pressed(const Key keycode, const bool repeat)
   {
      if (repeat) {
         return;
      }

      keys_[int(keycode)].down_ = true;
      keys_[int(keycode)].pressed_ = true;
      keys_[int(keycode)].released_ = false;
   }

   void Keyboard::on_key_released(const Key keycode)
   {
      keys_[int(keycode)].down_ = false;
      keys_[int(keycode)].pressed_ = false;
      keys_[int(keycode)].released_ = true;
   }
} // !papaya
