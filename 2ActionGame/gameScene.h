#pragma once
#include "Sprite.h"
#include "Player.h"
#include "Bullet.h"
#include "Item.h"
#include "Scene.h"
class gameScene :
    public Scene
{
public:
    void Init() override;
    void Update() override;
    void Exit() override;
};

