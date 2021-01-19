#include "DXUT.h"
#include "Enemy.h"

Enemy::Enemy()
{
	HP = 3;
	movespeed = 10;
	scale = { 1,1 };
	position = { 9999,9999 };
	attackspeed = 1.1f;
	layer = 2; // ���̾� �����ϰ�
	SetTexture(L"collisionbox.png"); // �ؽ��� ����
	// ���࿡ �ؽ��� �����ϰ� ���Ŀ� ���̾� ������ ���� �ִ�?
	// �ϸ� �׳� Renderer �� Sort ȣ�⸸ �ϸ� �ȴ�!
	color.a = 0;
	objecttexture->layer = 3;
	Renderer::GetInstance()->Sort();
	objecttexture->scale = { 3,3 };

	type = ENEMY;
}

void Enemy::Enemy1Move()
{
	position.y += movespeed * DELTATIME;
}

void Enemy::Enemy1Attack()
{
	if (deltatime > attackspeed)
	{
		BulletManager::GetInstance()->ShootBullet(position, ENEMY);
		deltatime = 0;
	}
	else
		deltatime += DELTATIME;

	objecttexture->Animation(L"m1", 0.2f, 5);
}

void Enemy::Enemy2Move()
{
	direction = *playerpos - position;
	D3DXVec2Normalize(&direction, &direction);
	position += movespeed * DELTATIME * direction;
	objecttexture->Animation(L"m2", 0.2f, 5);
}

void Enemy::Enemy2Attack()
{
	//
	
}

void Enemy::Move()
{
	switch (etype)
	{
	case E1:
		Enemy1Move();
		break;
	case E2:
		Enemy2Move();
		break;
	}
}

void Enemy::Update()
{
	switch (etype)
	{
	case E1:
		Enemy1Attack();
		break;
	case E2:
		Enemy2Attack();
		break;
	}

	Base::Update();
}
