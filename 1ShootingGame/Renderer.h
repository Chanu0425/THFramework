#pragma once
#include "Node.h"
#include "Singleton.h"
class Renderer : // 리스트에 있는 객체들을 그려주기 위한 클래스.
    public Singleton<Renderer>
{
private:
    list<Node*> rendertargets;
    static bool Comp(Node* a, Node* b);
public:
    void AddRenderTarget(Node* node); // 렌더시킬 노드의 리스트에 매개변수 node를 emplace_back
    void RemoveRenderTarget(Node* node); // 렌더시킬 노드의 리스트에 매개변수 node를 제거
    void Sort(); // 정렬
    void Render(); // 렌더
    void Clear() { rendertargets.clear(); };
};

