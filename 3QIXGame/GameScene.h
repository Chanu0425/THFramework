#pragma once
#include "Scene.h"
class GameScene :
    public Scene
{
public:
    void Init() override;
    void Update() override;
    void Exit() override;
};

