#include "Scene.h"
#include "Singleton.h"
#pragma once
class Director : // �� ������. ���� �̵� ������ ����մϴ�.
	public Singleton<Director>
{
private:
	Scene* currentScene; // ���� ���̷�Ʈx���� ���ư��� ��
public:
	int Score = 110;
	int mouse = 0;
	bool OnMouseDown()
	{
		if (mouse == 1)
		{
			return true;
		}
		return false;
	};
	bool OnMouse()
	{
		if (mouse == 2)
		{
			return true;
		}
		return false;
	};
	bool OnMouseUp()
	{
		if (mouse == 3)
		{
			return true;
		}
		return false;
	};
	LPD3DXSPRITE sprite;

	// �޴����� ��ũ�� ������ �׷��ϱ� �ʿ䰡 ����.
	// ���ӿ��� ��ũ�� ������ ���ھ �׾����ϱ�, �Է��ؾ��Ѵ�.
	bool isgameend = false; // �÷��̾ �״� ���, ������ �ϴٰ� ���Գ�?

	vector<Rank> ranking;
	static bool Comp(Rank a, Rank b) { return a.score > b.score; }; // ��ŷ�� �������ִ� �Լ�

	void Init();
	void ChangeScene(Scene* _scene);
	void UpdateScene();
};
