#pragma once

#ifndef INC_DOH3D_ALPHAMAP_H
#define INC_DOH3D_ALPHAMAP_H


namespace Doh3d
{

  // TODO: change to AlphaTexture that is inherited from the Texture class
	class AlphaMap
	{
	public:

		bool init(bool pAlphaCheck, LPDIRECT3DTEXTURE9 pTexture);

		bool check(int pX, int pY) const;

	private:

		int d_width;
		int d_height;

		bool d_solid;
		std::vector<bool> d_mask;

	};

} // ns Doh3d


#endif // INC_DOH3D_ALPHAMAP_H
