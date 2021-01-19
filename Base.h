#pragma once
#include "Sprite.h"
class Base : // ��� ��ü (���ӿ� ������ ��ü��) ���� ������ �ִ� ���� �Ǵ� �Լ�
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

