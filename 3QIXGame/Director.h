#include "Scene.h"
#include "Camera.h"
#include "Singleton.h"
#pragma once
class Director : // �� ������. ���� �̵� ������ ����մϴ�.
	public Singleton<Director>
{
private:
	map<SceneTag, Scene*> sceneMap;
	Scene* currentScene; // ���� ���̷�Ʈx���� ���ư��� ��
public:
	POINT p;
	float timescale = 1;
	int Score = 0;
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

	Vec2 GetMousePos()
	{
		GetCursorPos(&p);
		ScreenToClient(DXUTGetHWND(), &p);
		return { float(p.x), float(p.y) };
	};

	void Init();
	void AddScene(SceneTag _sceneTag, Scene* _scene);
	void ChangeScene(SceneTag _sceneTag);
	void UpdateScene();
};
