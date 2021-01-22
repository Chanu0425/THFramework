#pragma once
#include "Gun.h"
#include "Base.h"
#include "Singleton.h"
class Player :
    public Base
{
public:
    Gun* gun = nullptr;

    Player();
    virtual ~Player();

    void IDLE() override;
    void HIT() override;
    void DIE() override;

    void Move() override;
    void Update() override;
};

class PlayerManager :
    public Singleton<PlayerManager>
{
public:
    Player* p;
    void CreatePlayer();
    void SpawnPlayer(Vec2 pos);
    void DeletePlayer();
};