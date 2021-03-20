#pragma once
#include "VIM.h"
#include "Sprite.h"
#include "Items.h"

class Items :
    public Sprite
{
private:
    void Heal(VIM* vim);
    void Barrier(VIM* vim);
    void Immune(VIM* vim);
    void Speed(VIM* vim);
public:
    ITEMTAG tag;
    int ItemIndexX = 0;
    int ItemIndexY = 0;
    Items();
    virtual ~Items();

    void GetItem(VIM* vim);
    void Update() override;
};

class ItemManager :
    public Singleton<ItemManager>
{
private:
    vector<Items*> items;
public:
    void CreateItem();
    void SpawnItem(Vec2 _position, int _X, int _Y,ITEMTAG _tag);
    void CheckItem(int _X, int _Y, VIM* vim);
    void DeleteItem();
};