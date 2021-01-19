#pragma once
#include "Singleton.h"
#include "Base.h"
class Bullet :
    public Base
{
public:
    bool dirtrue = false;
    Vec2 dir;
    Bullet();
    void Move() override;
    void Clip();
    void Update() override;
};

class BulletManager :
    public Singleton<BulletManager>
{
public:
    vector<Bullet*> bullets;
    void CreateBullet(); // �� �����Ҷ� ȣ��
    void ShootBullet(Vec2 pos, ObjectType type, Vec2 dir = { 0,0 }); // Create�� �ǰ�, Delete�� ���� ���� ���¿��� ȣ��
    void DeleteBullet(); // �� ������ ȣ��
};

