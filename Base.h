#pragma once
#include "Sprite.h"
class Base : // ��� ��ü (���ӿ� ������ ��ü��) ���� ������ �ִ� ���� �Ǵ� �Լ�
    public Sprite
{
public:
    Base();
    virtual ~Base();

    Sprite* objecttexture;
    ObjectType type;
    int HP = 5;
    float movespeed = 15;
    float attackspeed = 0.5f;
    float deltatime = 0;
    
    void GetDamage(int damage);

    virtual void Move() {};
    
    void CheckCollision();
    void Update() override;
};

