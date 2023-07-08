// input.cc

#include "input/input.hpp"
#include "platform/events.hpp"

namespace papaya {
   Input::Input()
   {
   }

   void Input::update()
   {
      mouse_.update();
      keyboard_.update();
   }

   void Input::on_event(const KeyPressedEvent &event)
   {
      keyboard_.on_key_pressed(event.keycode, event.repeat);
   }

   void Input::on_event(const KeyReleasedEvent &event)
   {
      keyboard_.on_key_released(event.keycode);
   }

   void Input::on_event(const MouseMoveEvent &event)
   {
      mouse_.on_mouse_move(event.x, event.y);
   }

   void Input::on_event(const MouseButtonEvent &event)
   {
      mouse_.on_mouse_button(event.button, event.pressed);
   }

   void Input::on_event(const MouseWheelEvent &event)
   {
      mouse_.on_mouse_wheel(event.delta);
   }

   const Mouse &Input::mouse() const
   {
      return mouse_;
   }

   const Keyboard &Input::keyboard() const
   {
      return keyboard_;
   }
} // !papaya
