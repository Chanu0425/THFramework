#include "DXUT.h"
#include "Director.h"
#include "testScene.h"
#include "menuScene.h"

void menuScene::Init()
{
	for (int i = 0; i < 3; ++i)
	{
		buttons[i] = new Sprite();
		buttons[i]->position = { 1100, 340 + ((float)i * 150) };
		buttons[i]->isui = true;
		buttons[i]->scale = { 4,4 };
	}
	buttons[0]->SetTexture(L"start.png");
	buttons[1]->SetTexture(L"rank.png");
	buttons[2]->SetTexture(L"exit.png");
	font = new Font();
	// path에다 넣을건, 윈도우 검색창에 글꼴 치면 나오는 폰트들의 이름을 넣으면 된다.
	// 예 : "Arial"
	font->Createfont(6, 2, L"BroadwayEngraved BT");
	font->SetFont("SHOOTINGGAME");
	font->position = { 180,150 };
}

void menuScene::Update()
{
	POINT p;
	GetCursorPos(&p);
	ScreenToClient(DXUTGetHWND(), &p);

	if (Director::GetInstance()->OnMouseUp())
	{
		for (int i = 0; i < 3; ++i)
		{
			if (PtInRect(&buttons[i]->GetRect(), p))
			{
				switch (i)
				{
				case 0: // start
					cout << "시작!" << endl;
					Director::GetInstance()->ChangeScene(new testScene);
					return;
					break;
				case 1: // rank
					cout << "랭크!" << endl;
					Director::GetInstance()->ChangeScene(new rankScene);
					return;
					break;
				case 2: // exit
					cout << "나가!" << endl;
					exit(1);
					break;
				}
			}

		}
	}
}

void menuScene::Exit()
{
	for (int i = 0; i < 3; ++i)
		delete buttons[i];
	delete font;
}
