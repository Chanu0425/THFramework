#pragma once
#include "Singleton.h"
class Camera :
    public Singleton<Camera>
{
public:
    float shaketime = 0;
    Vec2 followpos = { ScreenW / 2, ScreenH / 2 };

    D3DXMATRIX WM;
    D3DXMATRIX VM;
    D3DXMATRIX PM;

    float cameraSize = 1; // 확대 비율
    float cameraRot = 0;
    Vec2 cameraPos = { ScreenW / 2, ScreenH / 2 };

    void CameraInit();
    void CameraUpdate();
};

