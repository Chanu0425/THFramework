#pragma once
#include "Sprite.h"
class Base : // 모든 물체 (게임에 나오는 객체들) 들이 가지고 있는 스텟 또는 함수
    public Sprite
{
public:
    Base();
    virtual ~Base();

    bool isPlayer = false;

    Sprite* objecttexture;
    ObjectType type;
    int HP = 5;
    float movespeed = 15;
    float attackspeed = 0.5f;
    float deltatime = 0;
    float invincibletime = -1.f;

    int damage = 1;

    void GetDamage(int damage);

    virtual void Activefalse() {};

    virtual void Move() {};
    
    void CheckCollision();
    void Update() override;
};

