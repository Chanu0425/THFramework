#pragma once
#include "Texture.h"
#include "Director.h"
#include "Renderer.h"
#include "Node.h"
class Sprite : // �ؽ��ĸ� ������ ������ �׷��ִ� Ŭ����.
    // ������ ��������Ʈ�� ��������, ���������� ������ �Ѱ��ش�.
    public Node
{
private:
    float deltatime = 0.0f;
    int frame = 0;
public:
    Sprite();
    virtual ~Sprite();

    Texture* texture; // ��������Ʈ�� �ؽ���

    void SetTexture(wstring path);

    RECT GetRect();

    float GetDistance(Vec2 obj);
    float Look(Vec2 obj);

    bool Animation(wstring path, float t, int f);

    void Draw() override;
};

