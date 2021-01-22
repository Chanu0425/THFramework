#include "DXUT.h"
#include "Bullet.h"

Bullet::Bullet()
{
	objectsprite->SetTexture(L"bullet.png");
	position = { 9999,9999 };
	scale = { 0.3f,0.3f };
	hp = 1;
	maxhp = 1;
	movespeed = 800;
}

Bullet::~Bullet()
{
}

void Bullet::IDLE()
{
}

void Bullet::HIT()
{
	if (hp <= 0)
		state = BaseState::DIE;
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
		b->objectsprite->isactive = false;
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
			bullets[i]->objectsprite->isactive = true;
			bullets[i]->hp = bullets[i]->maxhp;
			bullets[i]->state = BaseState::IDLE;
			bullets[i]->alivetime = 3.f;
			bullets[i]->dir = dir;
			bullets[i]->objectsprite->rotation = atan2(dir.y, dir.x);
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
