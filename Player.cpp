#include "DXUT.h"
#include "Player.h"
Player::Player()
{
	scale = { 0.7f, 0.7f };
	HP = 5;
	movespeed = 200;
	position = { ScreenW / 2, ScreenH / 2 + 150 };
	
	objecttexture->SetTexture(L"player1.png");
	layer = 31;
	color.a = 0;
	SetTexture(L"collisionbox.png");
	isPlayer = true;
	type = PLAYER;
}

Player::~Player()
{
}

void Player::ShootBullet()
{
	//DXUTWasKeyPressed
	//DXUTIsKeyDown
	// ���� �� ��, 'O' ���� char ���� ������ ������, (�ƽ�Ű�ڵ� ����)
	// VK_ ���µ� ���� �� �ִ�!
	if (DXUTWasKeyPressed(VK_SPACE))
	{
		// ����
		BulletManager::GetInstance()->ShootBullet(position, PLAYER);
	}
}

void Player::Move()
{
	if (DXUTIsKeyDown('W')) // �̵�
		position.y -= movespeed * DELTATIME;
	if (DXUTIsKeyDown('A')) // �̵�
		position.x -= movespeed * DELTATIME;
	if (DXUTIsKeyDown('S')) // �̵�
		position.y += movespeed * DELTATIME;
	if (DXUTIsKeyDown('D')) // �̵�
		position.x += movespeed * DELTATIME;
}

void Player::Clip()
{
	if (position.x > ScreenW - texture->info.Width / 2 * scale.x) // �� �߽��� - �̹����� ũ�� / 2 * ������
		position.x = ScreenW - texture->info.Width / 2 * scale.x;
	if (position.x < texture->info.Width / 2 * scale.x) // �� �߽��� + �̹����� ũ�� / 2 * ������
		position.x = texture->info.Width / 2 * scale.x;
	if (position.y > ScreenH - texture->info.Height * scale.y)
		position.y = ScreenH - texture->info.Height * scale.y;
	if (position.y < texture->info.Height / 2 * scale.y)
		position.y = texture->info.Height / 2 * scale.y;
}

void Player::Update()
{
	if (DXUTWasKeyPressed(VK_F2))
		isinvincible = !isinvincible;

	if (isinvincible)
		HP = 5;

	ShootBullet();
	Base::Update();
	Clip();
}
