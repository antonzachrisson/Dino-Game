// input.hpp

#pragma once

#include <input/mouse.hpp>
#include <input/keyboard.hpp>

namespace papaya {
   struct KeyPressedEvent;
   struct KeyReleasedEvent;
   struct MouseMoveEvent;
   struct MouseButtonEvent;
   struct MouseWheelEvent;

   class Input {
   public:
      Input();

      void update();

      void on_event(const KeyPressedEvent &event);
      void on_event(const KeyReleasedEvent &event);
      void on_event(const MouseMoveEvent &event);
      void on_event(const MouseButtonEvent &event);
      void on_event(const MouseWheelEvent &event);

      const Mouse &mouse() const;
      const Keyboard &keyboard() const;

   private:
      Mouse mouse_;
      Keyboard keyboard_;
   };
} // !papaya
