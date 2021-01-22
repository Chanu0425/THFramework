#pragma once
#include "Director.h"
#include "Bullet.h"
#include "Sprite.h"
class Gun :
    public Sprite
{
public:
    GunType type;

    int bulletleft = 0;

    float recoiltime = 0.6f; // 쏘고 난 뒤 다음 쏘는 그 간격
    float deltatime = 0;



    Gun();
    virtual ~Gun();

    void SetGunType(GunType type);

    void Update() override;
};

