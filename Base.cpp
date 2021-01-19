#include "DXUT.h"
#include "Bullet.h"
#include "Effect.h"
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
				GetDamage(1);
				BulletManager::GetInstance()->bullets[i]->GetDamage(1);
			}
		}
	}
}

void Base::Update()
{
	CheckCollision();
	Move();
	objecttexture->position = position;
	
	if (HP <= 0)
	{
		if (type == ENEMY)
		{
			Director::GetInstance()->Score += 100;
		}
		isactive = false;
		position = { 9999,9999 };
		objecttexture->isactive = false;
		objecttexture->position = { 9999,9999 };
	}
}
