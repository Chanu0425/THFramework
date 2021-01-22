#pragma once
#include "Scene.h"
class menuScene :
    public Scene
{
public:
    void Init() override;
    void Update() override;
    void Exit() override;
};

