#pragma once
#include "Gun.h"
#include "Base.h"
#include "Camera.h"
#include "Singleton.h"
class Player :
    public Base
{
public:
    Gun* gun = nullptr;

    float dashcooltime = 0;
    float dashcurrenttime = 0;

    float timeslowcooltime = 0;
    float timeslowcurrenttime = 0;

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