#include "DXUT.h"
#include "Effect.h"

Effect::Effect()
{
	
}

Effect::~Effect()
{
}

void Effect::Update()
{
	if (eType == EffectType::Player)
		alivetime -= DELTATIME;
	if (alivetime <= 0)
		isactive = false;
}

void EffectManager::CreateEffect()
{
	for (int i = 0; i < 20; ++i)
	{
		Effect* e = new Effect();
		e->isactive = false;
		effects.emplace_back(e);
		EffectFont* ef = new EffectFont();
		ef->isactive = false;
		ef->font->isactive = false;
		efonts.emplace_back(ef);
	}
}

void EffectManager::SpawnEffect(Vec2 pos, EffectType type)
{
	for (int i = 0; i < effects.size(); ++i)
	{
		if (effects[i]->isactive == false)
		{
			effects[i]->isactive = true;
			effects[i]->position = pos;
			effects[i]->eType = type;
			effects[i]->alivetime = 0.3f;
			effects[i]->scale = { 1.5f,1.5f };
			switch (effects[i]->eType)
			{
			case EffectType::Player: // ÀÜ»ó
				effects[i]->SetTexture(L"playeridle.png");
				effects[i]->scale = { 1.5f,1.5f };
				effects[i]->color.a = 0.4f;
				break;
			case EffectType::Bomb:
				break;
			}
			return;
		}
	}
}

void EffectManager::SpawnEffectFont(Vec2 pos, int damage)
{
	for (int i = 0; i < efonts.size(); ++i)
	{
		if (efonts[i]->isactive == false)
		{
			efonts[i]->font->isactive = true;
			efonts[i]->isactive = true;
			efonts[i]->position = pos;
			efonts[i]->font->SetFont((char*)to_string(damage).c_str());
			return;
		}
	}
}

void EffectManager::DeleteEffect()
{
	for (int i = 0; i < effects.size(); ++i)
		delete effects[i];
	effects.clear();

	for (int i = 0; i < efonts.size(); ++i)
		delete efonts[i];
	efonts.clear();
}

EffectFont::EffectFont()
{
	font = new Font();
	font->Createfont(2, 2, L"Arial");
	font->SetFont("test");
	font->color = Color(0, 0, 0, 1);
	Renderer::GetInstance()->AddRenderTarget(this);
}

EffectFont::~EffectFont()
{
	delete font;
	Renderer::GetInstance()->RemoveRenderTarget(this);
}

void EffectFont::Update()
{
	font->position = position;
	font->color.a -= DELTATIME;
	if (font->color.a <= 0)
	{
		font->color.a = 1;
		font->isactive = false;
		isactive = false;
	}
}
