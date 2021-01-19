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
	// path���� ������, ������ �˻�â�� �۲� ġ�� ������ ��Ʈ���� �̸��� ������ �ȴ�.
	// �� : "Arial"
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
					cout << "����!" << endl;
					Director::GetInstance()->ChangeScene(new testScene);
					return;
					break;
				case 1: // rank
					cout << "��ũ!" << endl;
					Director::GetInstance()->ChangeScene(new rankScene);
					return;
					break;
				case 2: // exit
					cout << "����!" << endl;
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
