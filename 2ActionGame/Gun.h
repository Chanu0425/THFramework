#pragma once
#include "Director.h"
#include "Bullet.h"
#include "Sprite.h"
class Gun :
    public Sprite
{
public:
    GunType type;

    Gun();
    virtual ~Gun();

    void Update() override;
};

