#pragma once
#include "Player.h"
#include "Sprite.h"
#include "Font.h"

class Effect :
    public Sprite
{
public:
    EffectType eType;
    float alivetime = 0.3f;

    Effect();
    virtual ~Effect();

    void Update() override;
};

class EffectFont :
    public Node
{
public:
    Font* font;

    EffectFont();
    virtual ~EffectFont();

    void Update() override;
};

class EffectManager :
    public Singleton<EffectManager>
{
public:
    vector<Effect*> effects;
    vector<EffectFont*> efonts;
    void CreateEffect();
    void SpawnEffect(Vec2 pos, EffectType type);
    void SpawnEffectFont(Vec2 pos, int damage);
    void DeleteEffect();
};