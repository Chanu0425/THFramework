#pragma once
#include "Singleton.h"

class Texture // ���� & ������ �Ӽ��� ���� Ŭ����
{
public:
	D3DXIMAGE_INFO info; // �ҷ��� ������ �Ӽ� (�ʺ� ���� ���...)
	LPDIRECT3DTEXTURE9 texture; // �ؽ���
	wstring tag; // ����ȭ �������� ���� �±�
};

class TextureManager : // �ؽ��ĸ� ���� �� �Ǵ� ���� ������ ����Ʈ �ӿ��� ��������� Ŭ����.
	public Singleton<TextureManager>
{
private:
	list<Texture*> texturelist;
public:
	Texture* LoadTexture(wstring path);
	void ReleaseAllTexture();
};