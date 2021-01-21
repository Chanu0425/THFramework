#include "DXUT.h"
#include "Renderer.h"

bool Renderer::Comp(Node* a, Node* b)
{
	return (a->layer < b->layer);
}

void Renderer::AddRenderTarget(Node* node)
{
	if (find(rendertargets.begin(), rendertargets.end(), node) != rendertargets.end())
		return;
	rendertargets.emplace_back(node);
	Sort();
}

void Renderer::RemoveRenderTarget(Node* node)
{
	rendertargets.remove(node);
}

void Renderer::Sort()
{
	rendertargets.sort(Comp);
}

void Renderer::Render()
{
	for (auto it : rendertargets)
	{
		if (it->isactive)
		{
			it->Update();
			it->Draw();
		}
	}
}
