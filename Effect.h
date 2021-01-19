#pragma once
#include "Singleton.h"
#include "Sprite.h"
class Effect :
    public Sprite
{
public:
    Effect();
    
    void Update() override;
};

class EffectManager :
    public Singleton<EffectManager>
{
public:
    vector<Effect*> effects;
    void CreateEffect();
    void SpawnEffect(Vec2 pos);
    void DeleteEffect();
};