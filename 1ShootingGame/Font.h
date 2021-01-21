#pragma once
#include "Renderer.h"
#include "Node.h"
class Font :
    public Node
{
public:
    Font();
    virtual ~Font();

    LPD3DXFONT font = nullptr; // ��¥ �۾��� ��� �� ��
    char buffer[256]; // ���ڸ� ���� ����

    void SetFont(char* fontstr);
    void Draw() override;
    void Createfont(float scale, float weight, LPCWSTR path);
};

