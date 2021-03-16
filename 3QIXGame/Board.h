#pragma once
#include "Pixel.h"
#include "Sprite.h"
class Board :
    public Sprite
{
private:
    bool checkedPixels[50][50];
    bool showplayerpos = true; // debug
    PIXELDIRECTION direction;
    list<Pixel*> paths;
    list<Pixel*> clear1;
    list<Pixel*> clear2;
    void CheckBoard(int _posX, int _posY, int _index);
    void SpawnObsticle(int _posX, int _posY);

    int score = 0;

protected:
public:
    int pathStartposX = 0;
    int pathStartposY = 0;

    int nextposX = 0;
    int nextposY = 0;

    int backposX = 0; // 바로 직전
    int backposY = 0; // 바로 직전

    int playerX = 49;
    int playerY = 49;
    bool isCutting = false;

    Board(void);
    virtual ~Board(void);
    Pixel* pixels[50][50];
    void Update(void) override;
};

