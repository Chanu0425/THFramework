#pragma once
#include "EnemyManager.h"
#include "Enemy.h"
class Boss :
	public Enemy
{
public:
	// ∆–≈œµÈ
	// 1. √—ΩÓ±‚
	// 2. ∏ÛΩ∫≈Õ º“»Ø
	Sprite* hpbar = nullptr;

	Boss();
	virtual ~Boss();
	float movementtime = 0;
	bool startpattern = false;
	bool spawnmonster = false;
	int state = 0; // 0 == √— 1 == ∏ÛΩ∫≈Õ

	void ShootBullet();
	void SpawnMonster();

	void Activefalse() override;

	void Move() override;
	void Update() override;
};