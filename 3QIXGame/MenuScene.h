#pragma once
#include "Sprite.h"
#include "Scene.h"
class MenuScene :
    public Scene
{
public:
    Sprite* start = nullptr;
    void Init() override; 
    void Update() override;
    void Exit() override;
};

