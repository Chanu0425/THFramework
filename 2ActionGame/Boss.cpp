#include "DXUT.h"
#include "Boss.h"

Boss::Boss()
{
	objectsprite->SetTexture(L"bossidle (1).png");
	position = { 0, 0 };
	scale = { 2,3 };
	objectsprite->scale = { 3.5f, 3.5f };
	movespeed = 30;
	hp = 30;
	maxhp = 30;
	enemytype = EnemyType::EnemyBoss;
}

Boss::~Boss()
{

}

void Boss::IDLE()
{
	objectsprite->Animation(L"bossidle", 0.1f, 2);
}

void Boss::HIT()
{
	objectsprite->SetTexture(L"bosshit.png");
}

void Boss::DIE()
{

}

void Boss::Move()
{
	Vec2 dir = PlayerManager::GetInstance()->p->position - position;
	D3DXVec2Normalize(&dir, &dir);
	position += dir * DELTATIME * movespeed * GLOBAL::timescale;
}

void Boss::Update()
{
	RECT r;
	if (IntersectRect(&r, &PlayerManager::GetInstance()->p->GetRect(), &GetRect()))
	{
		if (PlayerManager::GetInstance()->p->invincibletime <= 0)
		{
			PlayerManager::GetInstance()->p->GetDamage(damage);
			PlayerManager::GetInstance()->p->invincibletime = 1.f;

		}
	}
	Base::Update();
	if (PlayerManager::GetInstance()->p->position.x > position.x)
	{
		objectsprite->scale.x = 3.5f;
	}
	else
		objectsprite->scale.x = -3.5f;
}
