#include "DXUT.h"
#include "Bullet.h"

Bullet::Bullet()
{
	SetTexture(L"bullet.png");
	position = { 9999,9999 };
	hp = 1;
	maxhp = 1;
}

Bullet::~Bullet()
{
}

void Bullet::IDLE()
{
}

void Bullet::HIT()
{
}

void Bullet::DIE()
{
}

void Bullet::Move()
{
	position += -dir * movespeed * DELTATIME;
}

void Bullet::Update()
{
	Base::Update();
	alivetime -= DELTATIME;
	if (alivetime <= 0)
		state = BaseState::DIE;
}

void BulletManager::CreateBullet()
{
	for (int i = 0; i < 30; ++i)
	{
		Bullet* b = new Bullet();
		b->isactive = false;
		bullets.emplace_back(b);
	}
}

void BulletManager::SpawnBullet(Vec2 pos, Vec2 dir)
{
	for (int i = 0; i < bullets.size(); ++i)
	{
		if (bullets[i]->isactive == false)
		{
			bullets[i]->position = pos;
			bullets[i]->isactive = true;
			bullets[i]->hp = bullets[i]->maxhp;
			bullets[i]->state = BaseState::IDLE;
			bullets[i]->dir = dir;
			bullets[i]->rotation = atan2(dir.y, dir.x);
			return;
		}
	}
}

void BulletManager::DeleteBullet()
{
	for (int i = 0; i < bullets.size(); ++i)
		delete bullets[i];
	bullets.clear();
}
