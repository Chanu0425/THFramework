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

    virtual void GetDamage(int damage); // �Ϲ� �����Լ�

    virtual void Move() PURE; // ���� �����Լ� (������ �����ؾ���)
    
    void Update() override;
};

