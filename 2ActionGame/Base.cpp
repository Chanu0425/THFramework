#include "DXUT.h"
#include "Bullet.h"
#include "Base.h"

Base::Base()
{
	state = BaseState::IDLE;
	enemytype = EnemyType::EnemyNone;
	layer = 3;
	color.a = 0;
	SetTexture(L"collisionbox.png");
	objectsprite = new Sprite();
}

Base::~Base()
{
	delete objectsprite;
}

void Base::GetDamage(int damage)
{
	hp -= damage;
	hitfacetime = 0.5f;
	state = BaseState::HIT;
}

void Base::Update()
{
	invincibletime -= DELTATIME;

	if (enemytype != EnemyType::EnemyNone)
	{
		if (invincibletime <= 0)
		{
			for (int i = 0; i < BulletManager::GetInstance()->bullets.size(); ++i)
			{
				if (BulletManager::GetInstance()->bullets[i]->isactive == true)
				{
					RECT r;
					if (IntersectRect(&r, &BulletManager::GetInstance()->bullets[i]->GetRect(), &GetRect()))
					{
						GetDamage(BulletManager::GetInstance()->bullets[i]->damage);
						BulletManager::GetInstance()->bullets[i]->GetDamage(damage);
						invincibletime = 0.1f;
					}
				}
			}
		}
	}


	switch (state)
	{
	case BaseState::IDLE:
		IDLE();
		break;
	case BaseState::HIT:
		hitfacetime -= DELTATIME;
		HIT();
		if (hitfacetime <= 0)
			state = BaseState::IDLE;
		break;
	case BaseState::DIE:
		DIE();
		position = { 9999,9999 };
		isactive = false;
		objectsprite->isactive = false;
		break;
	}

	Move();
	objectsprite->position = position;

	if (hp <= 0)
	{
		state = BaseState::DIE;
	}
}
