#include "DXUT.h"
#include "Pixel.h"

Pixel::Pixel(void)
{
	SetTexture(L"Pixel.png");
	scale = { 0.05f,0.05f };
}

Pixel::~Pixel(void)
{
}

void Pixel::Update(void)
{
	
}