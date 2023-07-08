// texture_storage.hpp

#pragma once

#include <string>
#include <unordered_map>
#include <graphics/texture.hpp>

namespace papaya {
	class FileSystem;

	class TextureStorage {
	public:
		TextureStorage(FileSystem &filesystem);
		~TextureStorage();

		bool is_loaded(const char *filename) const;
		void load(const char *filename);
		void unload(const char *filename);
		const Texture *find(const char *filename) const;

	private:
		FileSystem &filesystem_;
		std::unordered_map<std::string, Texture> storage_;
	};
} // !papaya
