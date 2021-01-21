#include "DXUT.h"
#include "Enemy1.h"

Enemy1::Enemy1()
{
	eType = E1;
	HP = 3;
	movespeed = 10;
	scale = { 3,3 };
	position = { ScreenW / 2,ScreenH / 2 };
	attackspeed = 0.1f;
	layer = 2; // ���̾� �����ϰ�
	SetTexture(L"m1 (1).png"); // �ؽ��� ����
	// ���࿡ �ؽ��� �����ϰ� ���Ŀ� ���̾� ������ ���� �ִ�?
	// �ϸ� �׳� Renderer �� Sort ȣ�⸸ �ϸ� �ȴ�!
	type = ENEMY;
}

void Enemy1::Move()
{
	position.y += movespeed * DELTATIME;
}

void Enemy1::Update()
{
	if (deltatime > attackspeed)
	{
		BulletManager::GetInstance()->ShootBullet(position, ENEMY);
		deltatime = 0;
	}
	else
		deltatime += DELTATIME;
	
	Animation(L"m1", 0.2f, 5);
	Base::Update();
}
