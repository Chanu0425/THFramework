#pragma once
#include "Sprite.h"
class Pixel :
    public Sprite
{
private:
protected:
public:
    int indexX = 0;
    int indexY = 0;
    PIXELDIRECTION direction;
    PIXELSTATE state;
    Pixel(void);
    virtual ~Pixel(void);
    void Update(void) override;
};

