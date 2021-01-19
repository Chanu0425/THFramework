#include "DXUT.h"
#include "Font.h"
#include "rankScene.h"

void rankScene::Init()
{
	name[0] = ' ';
	name[1] = ' ';
	name[2] = ' ';
	name[3] = '\0';

	for (int i = 0; i < 5; ++i)
	{
		fonts[i] = new Font();
		fonts[i]->Createfont(2, 1, L"BroadwayEngraved BT");
		fonts[i]->SetFont("test");
		fonts[i]->position = { 800, 100 + ((float)i * 100) };
	}

	nameFont = new Font();
	nameFont->Createfont(2, 1, L"BroadwayEngraved BT");
	nameFont->SetFont("testname");
	nameFont->position = { 50, 100 };

	scoreFont = new Font();
	scoreFont->Createfont(2, 1, L"BroadwayEngraved BT");
	scoreFont->SetFont("testscore");
	scoreFont->position = { 50, 200 };

	returnFont = new Font();
	returnFont->Createfont(2, 1, L"BroadwayEngraved BT");
	returnFont->SetFont("testreturn");
	returnFont->position = { 1000, 600 };

	if (Director::GetInstance()->isgameend == false)
		isentered = true;
}

void rankScene::Update()
{
	POINT p;
	GetCursorPos(&p);
	ScreenToClient(DXUTGetHWND(), &p);

	// 문자 입력
	if (isentered == false && Director::GetInstance()->isgameend == true)
	{
		for (int i = 0; i < 26; i++)
		{
			if (DXUTWasKeyPressed('A' + i))
			{
				for (int j = 0; j < sizeof(name); j++) // sizeof name == name의 크기. [4]니까 4byte. 즉 4번 돈다는 얘기!
				{
					if (name[j] == ' ')
					{
						name[j] = 'A' + i;
						break;
					}
				}
			}
		}

		char a[100] = { 0, };
		sprintf(a, "PLEASE ENTER YOUR INITIAL : %s", name);
		nameFont->SetFont(a);
		sprintf(a, " SCORE : %d", Director::GetInstance()->Score);
		scoreFont->SetFont(a);

		if (DXUTWasKeyPressed(VK_RETURN))
		{
			if (name[0] != ' ' && name[1] != ' ' && name[2] != ' ')
			{
				Rank r;
				r.name[0] = name[0];
				r.name[1] = name[1];
				r.name[2] = name[2];
				r.name[3] = '\0';
				r.score = Director::GetInstance()->Score;
				Director::GetInstance()->ranking.emplace_back(r);
				sort(Director::GetInstance()->ranking.begin(),
					Director::GetInstance()->ranking.end(),
					Director::GetInstance()->Comp);
				name[0] = ' ';
				name[1] = ' ';
				name[2] = ' ';
				name[3] = '\0';
				isentered = true;
				Director::GetInstance()->isgameend = false;
				nameFont->SetFont("");
				scoreFont->SetFont("");
			}
		}
	}

	

	if (DXUTWasKeyPressed(VK_BACK)) // 백스페이스 누르면 문자들 다 초기화!
	{
		name[0] = ' ';
		name[1] = ' ';
		name[2] = ' ';
		name[3] = '\0';
	}

	for (int i = 0; i < Director::GetInstance()->ranking.size(); i++)
	{
		if (i < 5) // 최대 출력 폰트 크기만큼
		{
			char buff[100] = { 0, };
			sprintf(buff, "%d : %s %d", i + 1, 
				Director::GetInstance()->ranking[i].name, 
				Director::GetInstance()->ranking[i].score);
			fonts[i]->SetFont(buff);
		}
	}

	// 만약에 메뉴씬에서 들어왔으면, 그냥 나가게 할 수 있되
	// 게임씬에서 들어왔으면, 스코어를 적고 나가게
	if (DXUTWasKeyPressed('P') && isentered == true)
	{
		Director::GetInstance()->ChangeScene(new menuScene);
	}
}

void rankScene::Exit()
{
	for (int i = 0; i < 5; ++i)
		delete fonts[i];
	delete scoreFont;
	delete returnFont;
	delete nameFont;
}
