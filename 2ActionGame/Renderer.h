#pragma once
#include "Node.h"
#include "Singleton.h"
class Renderer : // ����Ʈ�� �ִ� ��ü���� �׷��ֱ� ���� Ŭ����.
    public Singleton<Renderer>
{
private:
    list<Node*> rendertargets;
    static bool Comp(Node* a, Node* b);
public:
    void AddRenderTarget(Node* node); // ������ų ����� ����Ʈ�� �Ű����� node�� emplace_back
    void RemoveRenderTarget(Node* node); // ������ų ����� ����Ʈ�� �Ű����� node�� ����
    void Sort(); // ����
    void Render(); // ����
    void Clear() { rendertargets.clear(); };
};

