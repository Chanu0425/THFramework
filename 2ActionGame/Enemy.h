#pragma once
#include "Player.h"
#include "Item.h"
#include "Base.h"
class Enemy :
    public Base
{
public:
    float originscale = 1.5f;

    Enemy();
    virtual ~Enemy();

    void IDLE() override;
    void HIT() override;
    void DIE() override;

    void Move() override;
    void Update() override;
};

class EnemyManager :
    public Singleton<EnemyManager>
{
public:
    vector<Enemy*> enemys;
    void CreateEnemy();
    void SpawnEnemy(Vec2 pos, EnemyType type, int wave);
    void DeleteEnemy();
};

