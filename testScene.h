#pragma once
#include "Sprite.h"
#include "Camera.h"
#include "Sound.h"
#include "Player.h"
#include "Bullet.h"
#include "EnemyManager.h"
#include "Effect.h"
#include "Boss.h"
#include "Font.h"
#include "rankScene.h"
#include "Scene.h"
class testScene :
    public Scene
{
public:
    float bossspawntime = 0;
    float dt = 0;
    Font* scorefont = nullptr;
    Player* p = nullptr;
    Boss* b = nullptr;
    Sprite* back[2];
    Sprite* ui[5];
    void Init() override;
    void Update() override;
    void Exit() override;
};

