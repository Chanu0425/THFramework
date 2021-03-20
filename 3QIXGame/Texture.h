#pragma once
#include "Singleton.h"

class Texture // 사진 & 사진의 속성을 담은 클래스
{
public:
	D3DXIMAGE_INFO info; // 불러온 사진의 속성 (너비 높이 등등...)
	LPDIRECT3DTEXTURE9 texture; // 텍스쳐
	wstring tag; // 최적화 목적으로 넣은 태그
};

class TextureManager : // 텍스쳐를 파일 속 또는 현재 저장한 리스트 속에서 끄집어내오는 클래스.
	public Singleton<TextureManager>
{
private:
	list<Texture*> texturelist;
public:
	Texture* LoadTexture(wstring path);
	void ReleaseAllTexture();
};