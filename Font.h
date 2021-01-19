#pragma once
#include "Renderer.h"
#include "Node.h"
class Font :
    public Node
{
public:
    Font();
    virtual ~Font();

    LPD3DXFONT font = nullptr; // 진짜 글씨를 띄워 줄 놈
    char buffer[256]; // 글자를 담을 버퍼

    void SetFont(char* fontstr);
    void Draw() override;
    void Createfont(float scale, float weight, LPCWSTR path);
};

