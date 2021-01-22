#include "Scene.h"
#include "Camera.h"
#include "Singleton.h"
#pragma once
class Director : // 총 관리자. 씬의 이동 변경을 담당합니다.
	public Singleton<Director>
{
private:
	Scene* currentScene; // 현재 다이렉트x에서 돌아가는 씬
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

	// 메뉴에서 랭크로 들어갈때는 그러니까 필요가 없다.
	// 게임에서 랭크로 들어갈때는 스코어를 쌓았으니까, 입력해야한다.
	bool isgameend = false; // 플레이어가 죽던 살던, 게임을 하다가 들어왔냐?

	vector<Rank> ranking;
	static bool Comp(Rank a, Rank b) { return a.score > b.score; }; // 랭킹을 정렬해주는 함수

	void Init();
	void ChangeScene(Scene* _scene);
	void UpdateScene();
};
