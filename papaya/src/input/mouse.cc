// mouse.cc

#include "input/mouse.hpp"

namespace papaya {
   Mouse::Mouse()
      : x_(0)
      , y_(0)
      , wheel_(0)
      , buttons_{}
   {
   }
   // fira mono

   void Mouse::update()
   {
      wheel_ = 0;
      for (auto &button : buttons_) {
         button.pressed_ = false;
         button.released_ = false;
      }
   }

   int Mouse::x() const
   {
      return x_;
   }

   int Mouse::y() const
   {
      return y_;
   }

   int Mouse::wheel() const
   {
      return wheel_;
   }

   bool Mouse::down(const Button button) const
   {
      return buttons_[int(button)].down_;
   }

   bool Mouse::pressed(const Button button) const
   {
      return buttons_[int(button)].pressed_;
   }

   bool Mouse::released(const Button button) const
   {
      return buttons_[int(button)].released_;
   }

   bool Mouse::any_down() const
   {
      for (int index = 0; index < int(Button::Count); index++) {
         if (down(Button(index))) {
            return true;
         }
      }

      return false;
   }

   bool Mouse::any_pressed() const
   {
      for (int index = 0; index < int(Button::Count); index++) {
         if (pressed(Button(index))) {
            return true;
         }
      }

      return false;
   }

   bool Mouse::any_released() const
   {
      for (int index = 0; index < int(Button::Count); index++) {
         if (released(Button(index))) {
            return true;
         }
      }

      return false;
   }

   bool Mouse::first_down(Button &button) const
   {
      for (int index = 0; index < int(Button::Count); index++) {
         if (down(Button(index))) {
            button = Button(index);
            return true;
         }
      }

      return false;
   }

   bool Mouse::first_pressed(Button &button) const
   {
      for (int index = 0; index < int(Button::Count); index++) {
         if (pressed(Button(index))) {
            button = Button(index);
            return true;
         }
      }

      return false;
   }

   bool Mouse::first_released(Button &button) const
   {
      for (int index = 0; index < int(Button::Count); index++) {
         if (released(Button(index))) {
            button = Button(index);
            return true;
         }
      }

      return false;
   }

   void Mouse::on_mouse_move(const int x, const int y)
   {
      x_ = x;
      y_ = y;
   }

   void Mouse::on_mouse_button(const Button button, const bool pressed)
   {
      buttons_[int(button)].down_ = pressed;
      if (pressed) {
         buttons_[int(button)].pressed_ = true;
         buttons_[int(button)].released_ = false;
      }
      else {
         buttons_[int(button)].pressed_ = false;
         buttons_[int(button)].released_ = true;
      }
   }

   void Mouse::on_mouse_wheel(const int delta)
   {
      wheel_ = delta;
   }
} // !papaya
