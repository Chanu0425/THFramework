#pragma once
#include "Sprite.h"
class Base :
    public Sprite
{
public:
    Base();
    virtual ~Base();

    BaseState state;

    wstring hitfacepath;

    int hp = 5;
    int maxhp = 5;

    bool isinvincible = false;
    float invincibletime = 0.f;

    float movespeed = 300;

    float hitfacetime = 0.2f;

    virtual void IDLE() PURE;
    virtual void HIT() PURE;
    virtual void DIE() PURE;

    virtual void GetDamage(int damage); // 일반 가상함수

    virtual void Move() PURE; // 순수 가상함수 (무조건 구현해야함)
    
    void Update() override;
};

