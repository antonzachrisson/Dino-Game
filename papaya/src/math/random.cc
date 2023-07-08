// random.cc

#include "math/random.hpp"

#include <random>

namespace papaya {
   namespace {
      std::random_device rd;
      std::mt19937 mt(rd());
      std::uniform_real_distribution<float> dist(0.0, 1.0);

      inline float random()
      {
         return dist(mt);
      }
   } // !anon

   // static 
   float Random::normalized()
   {
      return random();
   }

   float Random::range(const float min, const float max)
   {
      return min + (max - min) * random();
   }
} // !papaya
