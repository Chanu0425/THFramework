#include "DXUT.h"
#include "Effect.h"

Effect::Effect()
{
	layer = 10;
	scale = { 4,4 };
	SetTexture(L"effect (1).png");
}

void Effect::Update()
{
	if (Animation(L"effect", 0.1f, 7))
	{
		isactive = false;
		position = { 9999,9999 };
	}
}

void EffectManager::CreateEffect()
{
	for (int i = 0; i < 50; ++i)
	{
		Effect* effect = new Effect();
		effect->isactive = false;
		effects.emplace_back(effect);
	}
}

void EffectManager::SpawnEffect(Vec2 pos)
{
	// 1. 위치
	// 2. 레이어 UI > layer > OBJ
	// 3. Effect 텍스쳐 & 키 & 타임 X
	for (int i = 0; i < effects.size(); ++i)
	{
		if (effects[i]->isactive == false)
		{
			effects[i]->isactive = true;
			effects[i]->position = pos;
			return;
		}
	}
}

void EffectManager::DeleteEffect()
{
	for (int i = 0; i < effects.size(); ++i)
		delete effects[i];
	effects.clear();
}