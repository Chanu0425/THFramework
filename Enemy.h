#pragma once
#include "Bullet.h"
#include "Base.h"
class Enemy :
    public Base
{
public:
    EnemyType etype; // ���¸� �������ִ� enum
    Enemy();

    // pragma region�� �ʼ��� �ƴϴ�! ������ ���� ���ϰ� �ϱ� ���ؼ� ����Ѵ�.
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