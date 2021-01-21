#include "DXUT.h"
#include "Font.h"

Font::Font()
{
	memset(buffer, '\0', 256);
}

Font::~Font()
{
	Renderer::GetInstance()->RemoveRenderTarget(this);
	font->Release();
}

void Font::SetFont(char* fontstr)
{
	sprintf(buffer, fontstr);
}

void Font::Draw()
{
	if (isactive == false)
		return;
	if (font == nullptr)
		return;
	RECT r;
	SetRect(&r, (long)position.x, (long)position.y, 0, 0);
	font->DrawTextA(nullptr, buffer, -1, &r, DT_NOCLIP, color);
}

void Font::Createfont(float scale, float weight, LPCWSTR path)
{
	D3DXCreateFont(DEVICE, 20 * scale, 0, weight, 1, false, 1, 0, 0, 0 | FF_DONTCARE, path, &font);
	Renderer::GetInstance()->AddRenderTarget(this);
}
