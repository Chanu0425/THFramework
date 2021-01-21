#pragma once
#include "Base.h"
#include "Singleton.h"
class Bullet :
    public Base
{
public:
    Vec2 dir = { 0,0 };
    float alivetime = 1.f;

    Bullet();
    virtual ~Bullet();

    void IDLE() override;
    void HIT() override;
    void DIE() override;

    void Move() override;
    void Update() override;
};

class BulletManager :
    public Singleton<BulletManager>
{
public:
    vector<Bullet*> bullets;
    void CreateBullet();
    void SpawnBullet(Vec2 pos, Vec2 dir);
    void DeleteBullet();
};