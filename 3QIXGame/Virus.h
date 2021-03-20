#pragma once
#include "Sprite.h"
#include "Singleton.h"

class Virus :
    public Sprite
{
private:
    void SpeedMove();
    void BigMove();
    void FlashMove();
    void ToxinoMove();
public:
    float delta = 0.f;
    float movespeed = 0.05f;
    int speed = 1;
    int indexX = 0;
    int indexY = 0;
    VIRUSTAG tag;
    Virus();
    virtual ~Virus();

    void Update() override;
};

class VirusManager :
    public Singleton<VirusManager>
{
private:
    int difficulty = 1;
    std::vector<Virus*> virusVector;
public:
    void SetDifficulty(int _val);
    void CreateVirus();
    void SpawnVirus(Vec2 _position, int _startX, int _startY, VIRUSTAG _tag);
    std::vector<std::pair<int, int>> GetVirusPositions();
    void DeleteVirus();
};