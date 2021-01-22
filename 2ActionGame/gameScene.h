#pragma once
#include "Sprite.h"
#include "Player.h"
#include "Bullet.h"
#include "Item.h"
#include "Enemy.h"
#include "Scene.h"
class gameScene :
    public Scene
{
public:
    int wave = 1;
    float delta = 0;

    void WaveOn(int wavenum);

    void Init() override;
    void Update() override;
    void Exit() override;
};

