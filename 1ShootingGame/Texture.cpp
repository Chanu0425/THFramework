#include "DXUT.h"
#include "Texture.h"

Texture* TextureManager::LoadTexture(wstring path)
{
	for (auto it : texturelist)
		if (it->tag == path)
			return it;
	
	Texture* tex = new Texture();
	auto route = L"Res/" + path; // 예 : test.png 만 적어도 받아온다
	tex->tag = path;


	//D3DXCreateTextureFromFileEx(
	//	LPDIRECT3DDEVICE9         pDevice,
	//	LPCWSTR                   pSrcFile,
	//	UINT                      Width,
	//	UINT                      Height,
	//	UINT                      MipLevels,
	//	DWORD                     Usage,
	//	D3DFORMAT                 Format,
	//	D3DPOOL                   Pool,
	//	DWORD                     Filter,
	//	DWORD                     MipFilter,
	//	D3DCOLOR                  ColorKey,
	//	D3DXIMAGE_INFO * pSrcInfo, // OUT
	//	PALETTEENTRY * pPalette,
	//	LPDIRECT3DTEXTURE9 * ppTexture); // OUT
	if (FAILED(D3DXCreateTextureFromFileEx(
		DXUTGetD3D9Device(),
		route.c_str(), // 경로 파악 잘해야한다!
		-2,-2,1,0,
		D3DFORMAT::D3DFMT_A8B8G8R8,
		D3DPOOL::D3DPOOL_MANAGED,
		D3DX_FILTER_NONE,
		D3DX_FILTER_NONE, 0,
		&tex->info, nullptr, &tex->texture)))
	{// 텍스쳐를 불러오는데 실패했을때
		wcout << "FAILED : " << route << endl;
		delete tex;
	}
	else
	{// 텍스쳐를 불러오는데 성공했을때
		wcout << "COMPLETE : " << route << endl;
		texturelist.emplace_back(tex);
		return tex;
	}
}
