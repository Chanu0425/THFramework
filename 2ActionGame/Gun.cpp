#include "DXUT.h"
#include "Gun.h"

Gun::Gun()
{
	SetTexture(L"pistol.png");
	scale.x = -1;
}

Gun::~Gun()
{
}

void Gun::Update()
{
	
	Vec2 point = Director::GetInstance()->GetMousePos();
	rotation = Look(point);

	if (DXUTIsMouseButtonDown(VK_LEFT) && Director::GetInstance()->OnMouseDown())
	{
		Vec2 dir = position - point;
		D3DXVec2Normalize(&dir, &dir);
		BulletManager::GetInstance()->SpawnBullet(position, dir);
	}

	if (position.x < point.x)
	{
		scale.y = -1;
	}
	else
		scale.y = 1;
}
