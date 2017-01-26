#pragma once

#ifndef INC_DOH3D_RESOURCEMAN_H
#define INC_DOH3D_RESOURCEMAN_H


#include "Texture.h"
#include "RBitmapFont.h"


namespace Doh3d
{

	class ResourceMan
	{
	public:

		static bool init();
		static bool dispose();

		static bool loadResources();
		static bool unloadResources();


		static void setTextureDir(const std::string& pTextureDir) { d_textureDir = pTextureDir; }
		static void setFontDir(const std::string& pFontDir) { d_fontDir = pFontDir; }
		static const std::string& getTextureDir() { return d_textureDir; }
		static const std::string& getFontDir() { return d_fontDir; }


		static Texture getTexture(int pTi);
		static bool getTi(const std::string& pTextureName, int& pTi);
		static bool createFontTexture(const std::string& pText, const std::string& pFont, LPDIRECT3DTEXTURE9& pTexture,
										   int& pTexWidth, int& pTexHeight, std::vector<int>& pCharOffsets);

	private:

		static std::string d_textureDir;
		static std::string d_fontDir;

		static std::vector<Texture> d_textures;
		static std::vector<RBitmapFont> d_fonts;


		static bool parseTextureDir(const std::string& pDir);
		static bool parseFontDir(const std::string& pDir);

	};

} // ns Doh3d


#endif // INC_DOH3D_RESOURCEMAN_H
