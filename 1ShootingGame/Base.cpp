#include "DXUT.h"
#include "Bullet.h"
#include "Effect.h"
#include "EnemyManager.h"
#include "Base.h"

Base::Base()
{
	objecttexture = new Sprite();
	objecttexture->scale = { 3,3 };
	objecttexture->layer = 30;
}

Base::~Base()
{
	delete objecttexture;
}

void Base::GetDamage(int damage)
{
	HP -= damage;
}

void Base::CheckCollision()
{
	for (int i = 0; i < BulletManager::GetInstance()->bullets.size(); ++i)
	{
		// ���࿡ ���� �÷��̾��, �� �Ѿ��̶��� �浹�Ǿ������?
		// �� �ݴ��, ���� ���̸�, �÷��̾� �Ѿ��̶��� �浹�Ǿ���Ѵ�.
		if (BulletManager::GetInstance()->bullets[i]->isactive == true) // ����� ���������
		{
			if (type == PLAYER && BulletManager::GetInstance()->bullets[i]->type == PLAYER)
				continue;
			if (type == ENEMY && BulletManager::GetInstance()->bullets[i]->type == ENEMY)
				continue;

			RECT r;
			if (IntersectRect(&r, &GetRect(), &BulletManager::GetInstance()->bullets[i]->GetRect()))
			{
				// ����

				// ���࿡ �浹�� �Ǿ���?
				EffectManager::GetInstance()->SpawnEffect(BulletManager::GetInstance()->bullets[i]->position); // bullet[i]��°�� ���������� �ص� ��!
				
				
				if (isPlayer)
				{
					if (invincibletime < 0)
					{
						GetDamage(BulletManager::GetInstance()->bullets[i]->damage);
						invincibletime = 1.f;
					}
				}
				else
					GetDamage(BulletManager::GetInstance()->bullets[i]->damage);
				BulletManager::GetInstance()->bullets[i]->GetDamage(damage);
			}
		}
	}

	for (int i = 0; i < EnemyManager::GetInstance()->enemys.size(); ++i)
	{
		if (EnemyManager::GetInstance()->enemys[i]->isactive == true) // ����� ���������
		{
			if (type == ENEMY && EnemyManager::GetInstance()->enemys[i]->type == ENEMY)
				continue;
			RECT r;
			if (IntersectRect(&r, &GetRect(), &EnemyManager::GetInstance()->enemys[i]->GetRect()))
			{
				// ����

				// ���࿡ �浹�� �Ǿ���?
				EffectManager::GetInstance()->SpawnEffect(
					EnemyManager::GetInstance()->enemys[i]->position); // bullet[i]��°�� ���������� �ص� ��!
				if (isPlayer)
				{
					if (invincibletime < 0)
					{
						GetDamage(EnemyManager::GetInstance()->enemys[i]->damage);
						invincibletime = 1.f;
					}
				}
				else
					GetDamage(EnemyManager::GetInstance()->enemys[i]->damage);
				EnemyManager::GetInstance()->enemys[i]->GetDamage(damage);
			}
		}
	}
}

void Base::Update()
{
	CheckCollision();
	Move();
	objecttexture->position = position;
	
	if (isPlayer == true)
	{
		invincibletime -= DELTATIME;
	}


	if (HP <= 0)
	{
		if (type == ENEMY)
		{
			Director::GetInstance()->Score += 100;
		}
		Activefalse();
		isactive = false;
		position = { 9999,9999 };
		objecttexture->isactive = false;
		objecttexture->position = { 9999,9999 };
	}
}
