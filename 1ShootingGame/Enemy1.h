#pragma once
#include "Bullet.h"
#include "Base.h"
class Enemy1 :
    public Base
{
public:
    EnemyType eType;
    Enemy1();
    
    void Move() override;
    void Update() override;
};

