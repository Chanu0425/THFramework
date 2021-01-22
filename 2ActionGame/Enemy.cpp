#include "DXUT.h"
#include "Enemy.h"

Enemy::Enemy()
{
	enemytype = EnemyType::Enemy1;
	position = { 9999,9999 };
	objectsprite->SetTexture(L"m3idle.png");
	objectsprite->scale = { originscale, originscale };
	movespeed = 30;
	font = new Font();
	font->Createfont(2, 2, L"Arial");
	font->SetFont((char*)to_string(hp).c_str());
	font->color = Color(0, 0, 0, 1);
}

Enemy::~Enemy()
{
}

void Enemy::IDLE()
{
	switch (enemytype)
	{
	case EnemyType::Enemy1:
		if (objectsprite->texture->tag != L"m3idle.png")
			objectsprite->SetTexture(L"m3idle.png");
		break;
	case EnemyType::Enemy2:
		if (objectsprite->texture->tag != L"m2idle.png")
			objectsprite->SetTexture(L"m2idle.png");
		break;
	case EnemyType::Enemy3:
		if (objectsprite->texture->tag != L"m1idle.png")
			objectsprite->SetTexture(L"m1idle.png");
		break;
	}
	
}

void Enemy::HIT()
{
	switch (enemytype)
	{
	case EnemyType::Enemy1:
		if (objectsprite->texture->tag != L"m3hit.png")
			objectsprite->SetTexture(L"m3hit.png"); 
		break;
	case EnemyType::Enemy2:
		if (objectsprite->texture->tag != L"m2hit.png")
			objectsprite->SetTexture(L"m2hit.png"); 
		break;
	case EnemyType::Enemy3:
		if (objectsprite->texture->tag != L"m1hit.png")
			objectsprite->SetTexture(L"m1hit.png");
		break;
	}
	
}

void Enemy::DIE()
{
	int ran = rand() % 3;
	if (ran == 0)
	{
		int ran2 = rand() % 2; // 아이템 개수
		ItemManager::GetInstance()->SpawnItem(position, (ItemType)ran2);
	}
	font->isactive = false;
}

void Enemy::Move()
{
	Vec2 dir = PlayerManager::GetInstance()->p->position - position;
	D3DXVec2Normalize(&dir, &dir);
	position += dir * DELTATIME * movespeed * GLOBAL::timescale;
}

void Enemy::Update()
{
	font->SetFont((char*)to_string(hp).c_str());
	font->position.x = position.x;
	font->position.y = position.y - 30;
	Base::Update();
	if (PlayerManager::GetInstance()->p->position.x > position.x)
	{
		objectsprite->scale.x = originscale;
	}
	else
		objectsprite->scale.x = -originscale;
}

void EnemyManager::CreateEnemy()
{
	for (int i = 0; i < 10; ++i)
	{
		Enemy* enemy = new Enemy();
		enemy->isactive = false;
		enemy->objectsprite->isactive = false;
		enemys.emplace_back(enemy);
	}
}

void EnemyManager::SpawnEnemy(Vec2 pos, EnemyType type, int wave)
{
	for (int i = 0; i < enemys.size(); ++i)
	{
		if (enemys[i]->isactive == false)
		{
			enemys[i]->position = pos;
			enemys[i]->enemytype = type;
			enemys[i]->state = BaseState::IDLE;
			switch (enemys[i]->enemytype)
			{
			case EnemyType::Enemy1:
				enemys[i]->objectsprite->scale = { 1.5f,1.5f };
				enemys[i]->movespeed = 30;
				enemys[i]->objectsprite->SetTexture(L"m3idle.png");
				enemys[i]->originscale = 1.5f;
				enemys[i]->hp = 5 + wave;
				enemys[i]->maxhp = 5 + wave;
				break;
			case EnemyType::Enemy2:
				enemys[i]->objectsprite->scale = { 2.5f,2.5f };
				enemys[i]->movespeed = 30;
				enemys[i]->objectsprite->SetTexture(L"m2idle.png");
				enemys[i]->originscale = 2.5f;
				enemys[i]->hp = 15 + wave;
				enemys[i]->maxhp = 15 + wave;
				break;
			case EnemyType::Enemy3:
				enemys[i]->objectsprite->scale = { 1.5f,1.5f };
				enemys[i]->movespeed = 60;
				enemys[i]->objectsprite->SetTexture(L"m1idle.png");
				enemys[i]->originscale = 1.5f;
				enemys[i]->hp = 5 + wave;
				enemys[i]->maxhp = 5 + wave;
				break;
			}

			enemys[i]->isactive = true;
			enemys[i]->objectsprite->isactive = true;
			enemys[i]->font->isactive = true;
			return;
		}
	}
}

void EnemyManager::DeleteEnemy()
{
	for (int i = 0; i < enemys.size(); ++i)
		delete enemys[i];
	enemys.clear();
}
