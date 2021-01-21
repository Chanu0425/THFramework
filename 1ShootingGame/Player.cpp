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
	// 여기 둘 다, 'O' 같은 char 형이 들어갈수도 있지만, (아스키코드 형태)
	// VK_ 형태도 넣을 수 있다!
	if (DXUTWasKeyPressed(VK_SPACE))
	{
		// 사운드
		BulletManager::GetInstance()->ShootBullet(position, PLAYER);
	}
}

void Player::Move()
{
	if (DXUTIsKeyDown('W')) // 이동
		position.y -= movespeed * DELTATIME;
	if (DXUTIsKeyDown('A')) // 이동
		position.x -= movespeed * DELTATIME;
	if (DXUTIsKeyDown('S')) // 이동
		position.y += movespeed * DELTATIME;
	if (DXUTIsKeyDown('D')) // 이동
		position.x += movespeed * DELTATIME;
}

void Player::Clip()
{
	if (position.x > ScreenW - texture->info.Width / 2 * scale.x) // 내 중심점 - 이미지의 크기 / 2 * 스케일
		position.x = ScreenW - texture->info.Width / 2 * scale.x;
	if (position.x < texture->info.Width / 2 * scale.x) // 내 중심점 + 이미지의 크기 / 2 * 스케일
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
