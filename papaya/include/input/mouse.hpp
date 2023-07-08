// mouse.hpp

#pragma once 

#include <input/button.hpp> 

namespace papaya {
   class Mouse {
   public:
      Mouse();

      void update();

      int x() const;
      int y() const;
      int wheel() const;

      bool down(const Button button) const;
      bool pressed(const Button button) const;
      bool released(const Button button) const;

      bool any_down() const;
      bool any_pressed() const;
      bool any_released() const;

      bool first_down(Button &button) const;
      bool first_pressed(Button &button) const;
      bool first_released(Button &button) const;

      void on_mouse_move(const int x, const int y);
      void on_mouse_button(const Button button, const bool pressed);
      void on_mouse_wheel(const int delta);

   private:
      int x_;
      int y_;
      int wheel_;
      struct {
         bool down_;
         bool pressed_;
         bool released_;
      } buttons_[int(Button::Count)];
   };
} // !papaya
