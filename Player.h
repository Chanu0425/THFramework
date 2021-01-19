#pragma once
#include "Bullet.h"
#include "Base.h"
class Player :
    public Base
{
public:
    Player();
    virtual ~Player();

    void ShootBullet();

    void Move() override; // ������
    void Clip(); // ȭ�� �ۿ� ��������
    void Update() override;
};

