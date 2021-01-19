#include "DXUT.h"
#include "menuScene.h"
#include "testScene.h"

void testScene::Init()
{
	p = new Player();
	
	BulletManager::GetInstance()->CreateBullet();
	EnemyManager::GetInstance()->CreateEnemy();
	EffectManager::GetInstance()->CreateEffect();

	Camera::GetInstance()->CameraInit();
	Sound::GetInstance()->LoadSound(L"Res/Forest Birds 01.wav", L"BGM");
	//Sound::GetInstance()->PlaySFX(L"BGM", true);
	for (int i = 0; i < 2; ++i)
	{
		back[i] = new Sprite();
		// y + -
		back[i]->SetTexture(L"background.png");
		back[i]->layer = -30;
		Renderer::GetInstance()->Sort();
	}
	back[0]->position = { ScreenW / 2, ScreenH / 2 };
	back[1]->position = { ScreenW / 2, -(ScreenH / 2) };

	for (int i = 0; i < 5; ++i)
	{
		ui[i] = new Sprite;
		ui[i]->scale = { 2,2 };
		ui[i]->layer = 10;
		ui[i]->SetTexture(L"player1.png");
		// 55 45
		// x값이 높아져야죠?
		// 55 + (i * 10)
		ui[i]->position =
		{
			55 + ((float)i * 60),
			45
		};
	}

	b = new Boss();
	b->position = { ScreenW / 2 , -100 };

	scorefont = new Font();
	scorefont->Createfont(2, 2, L"BroadwayEngraved BT");
	scorefont->position = { ScreenW - 400, 0 };
}

void testScene::Update()
{
	for (int i = 0; i < 5; ++i)
		ui[i]->isactive = false;
	for (int i = 0; i < p->HP; ++i)
		ui[i]->isactive = true;

	dt += DELTATIME;
	bossspawntime += DELTATIME;

	if (bossspawntime > 3)
	{
		if (b->position.y < 100)
		{
			b->position.y += 30 * DELTATIME;
		}
		else
		{
			b->startpattern = true;
		}
	}

	if (dt > 3.f)
	{
		EnemyManager::GetInstance()->SpawnEnemy({ ScreenW / 2, 0 }, E2, p);
		dt = 0;
	}

	Camera::GetInstance()->CameraUpdate();
	for (int i = 0; i < 2; ++i)
	{
		back[i]->position.y += 200.f * DELTATIME;
		if (back[i]->position.y > (ScreenH + ScreenH / 2))
		{
			back[i]->position.y = -(ScreenH / 2);
		}
	}

	string num = to_string(Director::GetInstance()->Score);
	string result = "Score : " + num;
	scorefont->SetFont((char*)result.c_str());

	if (DXUTWasKeyPressed('P'))
	{
		Director::GetInstance()->ChangeScene(new menuScene);
		return; // 씬 꼭 바꿔줄때 리턴해야함
	}

	if (p->HP <= 0)
	{
		//if (연출 끝)
		// 여기에다 연출 넣고싶으면 넣어도 됨!
		Director::GetInstance()->isgameend = true;
		Director::GetInstance()->ChangeScene(new rankScene);
		return;
	}
}

void testScene::Exit()
{
	cout << "탈출" << endl;
	for (int i = 0; i < 5; ++i)
		delete ui[i];
	for (int i = 0; i < 2; ++i)
		delete back[i];
	delete p;
	BulletManager::GetInstance()->DeleteBullet();
	EnemyManager::GetInstance()->DeleteEnemy();
	EffectManager::GetInstance()->DeleteEffect();
	delete b;
	delete scorefont;
	//Sound::GetInstance()->StopSFX(L"BGM");
}
