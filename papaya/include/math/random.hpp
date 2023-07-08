// random.hpp

#ifndef PAPAYA_RANDOM_HPP_INCLUDED
#define PAPAYA_RANDOM_HPP_INCLUDED

namespace papaya {
   class Random final {
   public:
      static float normalized();
      static float range(const float min, const float max);
   };
} // !papaya

#endif // !PAPAYA_RANDOM_HPP_INCLUDED
