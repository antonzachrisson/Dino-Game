// texture.hpp

#pragma once

namespace papaya {
   class Texture {
   public:
      enum class Format {
         Rgb8,
         Rgba8,
      };

      enum class Filter {
         Nearest,
         Linear,
      };

      enum class Address {
         Clamp,
         Repeat,
         Mirror,
      };

   public:
      Texture();

      unsigned int handle() const;
      bool is_valid() const;
      int width() const;
      int height() const;

      bool create(const Format format,
                  const int width,
                  const int height,
                  const void *data,
                  const Filter filter = Filter::Nearest,
                  const Address address = Address::Clamp);
      void destroy();

   private:
      unsigned int id_;
      int width_;
      int height_;
   };
} // !papaya
