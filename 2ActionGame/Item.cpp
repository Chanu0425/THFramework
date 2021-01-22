#include "DXUT.h"
#include "Item.h"

Item::Item()
{
	SetTexture(L"hpitem.png");
}

Item::~Item()
{
}

void Item::Update()
{
	RECT r;
	if (IntersectRect(&r, &PlayerManager::GetInstance()->p->GetRect(), &GetRect()))
	{
		switch (type)
		{
		case ItemType::HealthItem:
			PlayerManager::GetInstance()->p->hp++;
				break;
		case ItemType::BulletItem:
			PlayerManager::GetInstance()->p->gun->bulletleft += 30;
			break;
		}
		isactive = false;
	}

	color.a = (alivetime / 5);

	if (alivetime <= 0)
		isactive = false;
}

void ItemManager::CreateItem()
{
	for (int i = 0; i < 20; ++i)
	{
		Item* it = new Item();
		it->isactive = false;
		items.emplace_back(it);
	}
}

void ItemManager::SpawnItem(Vec2 pos, ItemType type)
{
	for (int i = 0; i < items.size(); ++i)
	{
		if (items[i]->isactive == false)
		{
			items[i]->isactive = true;
			items[i]->position = pos;
			items[i]->type = type;
			items[i]->color.a = 1;
			items[i]->alivetime = 5.f;

			switch (type)
			{
			case ItemType::HealthItem:
				items[i]->SetTexture(L"hpitem.png");
				break;
			case ItemType::BulletItem:
				items[i]->SetTexture(L"bulletitem.png");
				break;
			}

			return;
		}
	}
}

void ItemManager::DeleteItem()
{
	for (int i = 0; i < items.size(); ++i)
		delete items[i];
	items.clear();
}
