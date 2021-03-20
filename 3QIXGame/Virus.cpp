#include "DXUT.h"
#include "Virus.h"

void Virus::SpeedMove()
{
	if (delta <= 0)
	{
		indexX += speed;
		if (indexX > 49)
		{
			// movespeed 감소 후 다시 증가
			indexX = 49;
			speed = -1;
		}
		else if (indexX < 0)
		{
			// movespeed 감소 후 다시 증가
			indexX = 0;
			speed = 1;
		}
		delta = movespeed;
	}
	else
		delta -= DXUTGetElapsedTime();
}

void Virus::BigMove()
{
}

void Virus::FlashMove()
{
}

void Virus::ToxinoMove()
{
}

Virus::Virus()
{
	layer = -1;
	SetTexture(L"Item.png");
	scale = { 0.05f,0.05f };
}

Virus::~Virus()
{

}

void Virus::Update()
{
	switch (tag)
	{
	case SPEEDVIRUS:
		SpeedMove();
		break;
	case BIGVIRUS:
		BigMove();
		break;
	case FLASHVIRUS:
		FlashMove();
		break;
	case TOXINO:
		ToxinoMove();
		break;
	default:
		break;
	}
}

void VirusManager::SetDifficulty(int _val)
{
	difficulty = _val;
}

void VirusManager::CreateVirus()
{
	for (int i = 0; i < 20; ++i)
	{
		Virus* v = new Virus();
		v->isactive = false;
		virusVector.emplace_back(v);
	}
}

void VirusManager::SpawnVirus(Vec2 _position, int _startX, int _startY, VIRUSTAG _tag)
{
	for (int i = 0; i < virusVector.size(); ++i)
	{
		if (virusVector[i]->isactive == false)
		{
			virusVector[i]->isactive = true;
			virusVector[i]->tag = _tag;
			virusVector[i]->indexX = _startX;
			virusVector[i]->indexY = _startY;
			virusVector[i]->position = _position;
			switch (_tag)
			{
			case SPEEDVIRUS:
				break;
			case BIGVIRUS:
				break;
			case FLASHVIRUS:
				break;
			case TOXINO:
				break;
			default:
				break;
			}
		}
	}
	
}

std::vector<std::pair<int, int>> VirusManager::GetVirusPositions()
{
	std::vector<std::pair<int, int>> virusPositions;
	for (int i = 0; i < virusVector.size(); ++i)
	{
		if (virusVector[i]->isactive == true)
		{
			virusPositions.emplace_back(virusVector[i]->indexX, virusVector[i]->indexY);
		}
	}
	return virusPositions;
}

void VirusManager::DeleteVirus()
{
	for (int i = 0; i < virusVector.size(); ++i)
	{
		delete virusVector[i];
	}
	virusVector.clear();
}
