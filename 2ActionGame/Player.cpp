#include "DXUT.h"
#include "Player.h"

Player::Player()
{
	position = { ScreenW / 2, ScreenH / 2 };
	SetTexture(L"playeridle.png");
	scale = { 1.5f,1.5f };
	gun = new Gun();
}

Player::~Player()
{
}

void Player::IDLE()
{
	if (texture->tag != L"playeridle.png")
		SetTexture(L"playeridle.png");
}

void Player::HIT()
{
	if (texture->tag != L"playerhit.png")
		SetTexture(L"playerhit.png");
}

void Player::DIE()
{
}

void Player::Move()
{
	if (DXUTIsKeyDown('W'))
		position.y -= movespeed * DELTATIME;
	if (DXUTIsKeyDown('S'))
		position.y += movespeed * DELTATIME;
	if (DXUTIsKeyDown('A'))
		position.x -= movespeed * DELTATIME;
	if (DXUTIsKeyDown('D'))
		position.x += movespeed * DELTATIME;
}

void Player::Update()
{
	cout << "hp : " << hp << endl;
	cout << bulletleft << endl;

	Base::Update();

	Vec2 point = Director::GetInstance()->GetMousePos();

	if (position.x > point.x)
		scale.x = -1.5f;
	else
		scale.x = 1.5f;

	gun->position = position;
	if (scale.x == 1.5f)
		gun->position.x = position.x + 40;
	else
		gun->position.x = position.x - 40;
}

void PlayerManager::CreatePlayer()
{
	p = new Player();
	p->isactive = false;
}

void PlayerManager::SpawnPlayer(Vec2 pos)
{
	p->position = pos;
	p->isactive = true;
}

void PlayerManager::DeletePlayer()
{
	delete p;
}
