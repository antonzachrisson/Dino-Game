// dispatcher.hpp

#pragma once

#include <vector>
#include <functional>

namespace papaya {
   class Dispatcher {
   public:
      Dispatcher();

      bool update();

      template <typename EventType>
      void submit(const EventType &event)
      {
         auto &list = listeners<EventType>();
         for (auto &listener : list) {
            listener(event);
         }
      }

      template <typename EventType, typename ListenerType>
      void register_listener(ListenerType &listener)
      {
         auto &list = listeners<EventType>();
         list.emplace_back( [&listener](const EventType &event) { listener.on_event(event); } );
      }

   private:
      template <typename EventType>
      static auto &listeners()
      {
         static std::vector<std::function<void(const EventType &)>> list;
         return list;
      }
   };
} // !papaya
