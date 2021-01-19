#pragma once
#include "Enemy.h"
#include "Player.h"
#include "Singleton.h"
class EnemyManager :
    public Singleton<EnemyManager>
{
public:
    vector<Enemy*> enemys;
    //1. 각 에너미마다 벡터를 만들어서 사용.
    //2. 에너미를 하나의 벡터에 넣어서, 타입 체크 후 그놈을 불러다 오기
    void CreateEnemy();
    void SpawnEnemy(Vec2 pos, EnemyType type, Player* p = nullptr);
    void DeleteEnemy();
};

