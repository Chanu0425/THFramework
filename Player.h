#pragma once
#include "Bullet.h"
#include "Base.h"
class Player :
    public Base
{
public:
    bool isinvincible = false;
    Player();
    virtual ~Player();

    void ShootBullet();

    void Move() override; // 움직임
    void Clip(); // 화면 밖에 못나가게
    void Update() override;
};

