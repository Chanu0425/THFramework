#include "DXUT.h"
#include "Bullet.h"

Bullet::Bullet()
{
	HP = 1;
	scale = { 1,1 };
	movespeed = 300;
	type = PLAYER;
}

void Bullet::Move()
{
	if (dirtrue == false)
	{
		switch (type)
		{
		case PLAYER:
			position.y -= movespeed * DELTATIME;
			break;
		case ENEMY:
			position.y += movespeed * DELTATIME;
			break;
		}
	}
	else
	{
		position += dir * movespeed * DELTATIME;
	}
}

void Bullet::Clip()
{
	if (position.x > ScreenW)
		isactive = false;
	if (position.x < 0)
		isactive = false;
	if (position.y > ScreenH)
		isactive = false;
	if (position.y < 0)
		isactive = false;
}

void Bullet::Update()
{
	Clip();
	Base::Update();
}

void BulletManager::CreateBullet()
{
	for (int i = 0; i < 50; ++i)
	{
		Bullet* b = new Bullet();
		b->isactive = false;
		bullets.emplace_back(b);
	}
}

void BulletManager::ShootBullet(Vec2 pos, ObjectType type, Vec2 dir)
{
	// 오브젝트 풀링
	for (int i = 0; i < 50; ++i)
	{
		if (bullets[i]->isactive == false)
		{
			bullets[i]->position = pos;
			bullets[i]->type = type;
			bullets[i]->isactive = true;
			bullets[i]->HP = 1;
			Vec2 temp = { 0,0 };
			if (dir == temp) // 서로 float라서, 근사치 값이 들어가기에 추후에 뭔가 이상해진다면
				// 반올림 해주는 함수 사용해야함.
				bullets[i]->dirtrue = false;
			else
			{
				bullets[i]->dir = dir;
				bullets[i]->dirtrue = true;
			}
			switch (type)
			{
			case PLAYER:
				bullets[i]->SetTexture(L"bullet.png");
				bullets[i]->scale = { 2,2 };
				break;
			case ENEMY:
				bullets[i]->SetTexture(L"redbullet.png");
				bullets[i]->scale = { 1,1 };
				break;
			}
			return;
		}
	}
}

void BulletManager::DeleteBullet()
{
	for (int i = 0; i < 50; ++i)
		delete bullets[i];
	bullets.clear();
}
