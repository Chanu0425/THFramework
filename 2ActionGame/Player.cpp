#include "DXUT.h"
#include "Effect.h"
#include "Player.h"

Player::Player()
{
	position = { ScreenW / 2, ScreenH / 2 };
	objectsprite->layer = 5;
	objectsprite->SetTexture(L"playeridle.png");
	objectsprite->scale = { 1.5f,1.5f };
	isPlayer = true;
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
	Camera::GetInstance()->shaketime = 0.05f;
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

	dashcooltime -= DELTATIME;
	dashcurrenttime -= DELTATIME;

	timeslowcooltime -= DELTATIME;
	timeslowcurrenttime -= DELTATIME;

	if (dashcurrenttime > 0)
	{
		movespeed = 600;
		EffectManager::GetInstance()->SpawnEffect(position, EffectType::Player);
	}
	else
		movespeed = 300;

	if (DXUTWasKeyPressed('Q') && dashcooltime <= 0)
	{
		dashcooltime = 1.f;
		dashcurrenttime = 0.2f;
	}

	if (timeslowcurrenttime > 0)
	{
		GLOBAL::timescale = 0.2f;
	}
	else
		GLOBAL::timescale = 1;

	if (DXUTWasKeyPressed('E') && timeslowcooltime <= 0)
	{
		timeslowcooltime = 1.f;
		timeslowcurrenttime = 0.5f;
	}
	
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
