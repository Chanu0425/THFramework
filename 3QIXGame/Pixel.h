#pragma once
#include "Sprite.h"
class Pixel :
    public Sprite
{
private:
protected:
public:
    PIXELSTATE state;
    Pixel(void);
    virtual ~Pixel(void);
    void Update(void) override;
};

