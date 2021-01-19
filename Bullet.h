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
    void CreateBullet(); // 씬 시작할때 호출
    void ShootBullet(Vec2 pos, ObjectType type, Vec2 dir = { 0,0 }); // Create가 되고, Delete가 되지 않은 상태에서 호출
    void DeleteBullet(); // 씬 끝날때 호출
};

