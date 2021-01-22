#include "DXUT.h"
#include "Gun.h"

Gun::Gun()
{
	SetTexture(L"pistol.png");
	scale.x = -1;
	type = GunType::Pistol;
}

Gun::~Gun()
{
}

void Gun::SetGunType(GunType type)
{
	if (this->type == type)
		return;
	
	deltatime = 0;
	this->type = type;
	switch (type)
	{
	case GunType::Pistol:
		SetTexture(L"pistol.png");
		recoiltime = 0.6f;
		break;
	case GunType::Rifle:
		SetTexture(L"rifle.png");
		recoiltime = 0.1f;
		break;
	}
}

void Gun::Update()
{
	deltatime += DELTATIME;
	Vec2 point = Director::GetInstance()->GetMousePos();
	rotation = Look(point);

	if (DXUTIsMouseButtonDown(VK_LEFT))
	{
		if (deltatime > recoiltime)
		{

			if (type == GunType::Rifle) // 라이플이다
			{
				if(bulletleft > 0)
				{
					--bulletleft;
					Vec2 dir = position - point;
					D3DXVec2Normalize(&dir, &dir);
					BulletManager::GetInstance()->SpawnBullet(position, dir);
				}
			}
			else // 아니다
			{
				Vec2 dir = position - point;
				D3DXVec2Normalize(&dir, &dir);
				BulletManager::GetInstance()->SpawnBullet(position, dir);
			}
			deltatime = 0;
		}
	}

	if (position.x < point.x)
	{
		scale.y = -1;
	}
	else
		scale.y = 1;
}
