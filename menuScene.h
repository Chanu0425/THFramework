#pragma once
#include "Sprite.h"
#include "Font.h"
#include "rankScene.h"
#include "Scene.h"
class menuScene :
    public Scene
{
public:
    Font* font;
    Sprite* buttons[3];
    void Init() override;
    void Update() override;
    void Exit() override;
};

