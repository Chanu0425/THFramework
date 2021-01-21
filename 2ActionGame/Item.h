#pragma once
#include "Singleton.h"
#include "Player.h" 
#include "Sprite.h"
class Item :
    public Sprite
{
public:
    ItemType type;
    float alivetime = 5.f;

    Item();
    virtual ~Item();

    void Update() override;
};

class ItemManager :
    public Singleton<ItemManager>
{
public:
    vector<Item*> items;
    void CreateItem();
    void SpawnItem(Vec2 pos, ItemType type);
    void DeleteItem();
};