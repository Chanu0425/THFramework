#pragma once
#include "Board.h"
#include "Scene.h"
class GameScene :
    public Scene
{
public:
    Board* b = nullptr;
    void Init() override;
    void Update() override;
    void Exit() override;
};

