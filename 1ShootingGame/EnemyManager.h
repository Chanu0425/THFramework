#pragma once
#include "Enemy.h"
#include "Player.h"
#include "Singleton.h"
class EnemyManager :
    public Singleton<EnemyManager>
{
public:
    vector<Enemy*> enemys;
    //1. �� ���ʹ̸��� ���͸� ���� ���.
    //2. ���ʹ̸� �ϳ��� ���Ϳ� �־, Ÿ�� üũ �� �׳��� �ҷ��� ����
    void CreateEnemy();
    void SpawnEnemy(Vec2 pos, EnemyType type, Player* p = nullptr);
    void DeleteEnemy();
};

