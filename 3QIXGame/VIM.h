#pragma once
#include "Sprite.h"
class VIM :
    public Sprite
{
private:
public:
    float movementspeed = 0.07f;
    int HP = 5;
    float immunetime = 0;
    bool isimmune = false;

    VIM();
    virtual ~VIM();
    void Update() override;
};

