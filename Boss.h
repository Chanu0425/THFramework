#pragma once
#include "EnemyManager.h"
#include "Enemy.h"
class Boss :
	public Enemy
{
public:
	// ���ϵ�
	// 1. �ѽ��
	// 2. ���� ��ȯ
	Boss();
	virtual ~Boss();
	float movementtime = 0;
	bool startpattern = false;
	bool spawnmonster = false;
	int state = 0; // 0 == �� 1 == ����

	void ShootBullet();
	void SpawnMonster();

	void Move() override;
	void Update() override;
};