#pragma once
#include "Bullet.h"
#include "Base.h"
class Enemy :
    public Base
{
public:
    EnemyType etype; // 상태를 결정해주는 enum
    Enemy();

    // pragma region은 필수가 아니다! 하지만 보기 편하게 하기 위해서 사용한다.
#pragma region ENEMY1
    void Enemy1Move();
    void Enemy1Attack();
#pragma endregion

#pragma region ENEMY2
    Vec2* playerpos;
    Vec2 direction;
    void Enemy2Move();
    void Enemy2Attack();
#pragma endregion

    void Move() override;
    void Update() override;
};