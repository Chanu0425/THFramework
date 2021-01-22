#include "DXUT.h"
#include "Player.h"

Player::Player()
{
	position = { ScreenW / 2, ScreenH / 2 };
	objectsprite->SetTexture(L"playeridle.png");
	objectsprite->scale = { 1.5f,1.5f };
	gun = new Gun();
}

Player::~Player()
{
}

void Player::IDLE()
{
	if (objectsprite->texture->tag != L"playeridle.png")
		objectsprite->SetTexture(L"playeridle.png");
}

void Player::HIT()
{
	if (objectsprite->texture->tag != L"playerhit.png")
		objectsprite->SetTexture(L"playerhit.png");
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
	Base::Update();

	if (DXUTWasKeyPressed('1'))
		gun->SetGunType(GunType::Pistol);
	if (DXUTWasKeyPressed('2'))
		gun->SetGunType(GunType::Rifle);

	Vec2 point = Director::GetInstance()->GetMousePos();

	if (position.x > point.x)
		objectsprite->scale.x = -1.5f;
	else
		objectsprite->scale.x = 1.5f;

	gun->position = position;
	if (objectsprite->scale.x == 1.5f)
		gun->position.x = position.x + 40;
	else
		gun->position.x = position.x - 40;
}

void PlayerManager::CreatePlayer()
{
	p = new Player();
	p->isactive = false;
	p->objectsprite->isactive = false;
}

void PlayerManager::SpawnPlayer(Vec2 pos)
{
	p->position = pos;
	p->isactive = true;
	p->objectsprite->isactive = true;
}

void PlayerManager::DeletePlayer()
{
	delete p;
}
