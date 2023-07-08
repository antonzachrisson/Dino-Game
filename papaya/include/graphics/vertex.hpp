// vertex.hpp

#pragma once

#include <math/color.hpp>
#include <math/vector2.hpp>

namespace papaya {
   class Vertex {
   public:
      Vector2 position_;
      Vector2 texcoord_;
      Color   color_;
   };
} // !papaya
