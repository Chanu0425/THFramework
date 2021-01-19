#pragma once
#include "Director.h"
#include "menuScene.h"
#include "Scene.h"
class rankScene :
    public Scene
{
public:
    bool isentered = false;
    Font* fonts[5]; // ·©Å©µé
    Font* nameFont;
    Font* scoreFont;
    Font* returnFont;
    char name[4];

    void Init() override;
    void Update() override;
    void Exit() override;
};

