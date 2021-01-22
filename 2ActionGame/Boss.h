#pragma once
#include "Base.h"
class Boss :
    public Base
{
public:
    Boss();
    virtual ~Boss();

    void IDLE() override;
    void HIT() override;
    void DIE() override;

    void Move() override;
    void Update() override;
};

