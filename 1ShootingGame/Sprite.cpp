#include "DXUT.h"
#include "Sprite.h"

Sprite::Sprite()
{
}

Sprite::~Sprite()
{
	Renderer::GetInstance()->RemoveRenderTarget(this);
}

void Sprite::SetTexture(wstring path)
{
	texture = TextureManager::GetInstance()->LoadTexture(path);
	SetRect(&imageRect, 0, 0, texture->info.Width, texture->info.Height);
	Renderer::GetInstance()->AddRenderTarget(this);
}

RECT Sprite::GetRect()
{
	RECT r;
	r.right = position.x + (texture->info.Width / 2 * scale.x);
	r.left = position.x - (texture->info.Width / 2 * scale.x);
	r.top = position.y - (texture->info.Height / 2 * scale.y);
	r.bottom = position.y + (texture->info.Height / 2 * scale.y);
	return r;
}

float Sprite::GetDistance(Vec2 obj)
{
	Vec2 temp = position - obj;
	return sqrt(temp.x * temp.x + temp.y * temp.y);
}

float Sprite::Look(Vec2 obj)
{
	Vec2 temp = position - obj;
	return atan2(temp.y, temp.x);
}

bool Sprite::Animation(wstring path, float t, int f) // time, max frame
{
	deltatime += DELTATIME; // 0.0�������� �ð��� ��� �ö󰡿�
	if (deltatime > t) // �Ű������� ���� t���� deltatime�� Ŀ����, ���� ���������� �Ѿ��
	{
		++frame; // ������ �÷��ְ�
		if (frame > f) // ���� �������� �ִ� �����Ӻ��� Ŀ������
		{
			frame = 0; // ������ �ʱ�ȭ
			return true; // ����
		}
		auto p = path + L" (" + to_wstring(frame) + L").png"; // �� �κ��� �߿��ϴ�
		// �ڱ� ���� ���ҽ� �� �ִϸ��̼ǵ��� ��Ÿ����,
		// player (1), player (2) �̷��ų�
		// player1, player2 �̷��� �Ǿ�������
		// ���� ���ڿ��� ��������� �� ���´�.
		SetTexture(p); // �ؽ��� ����
		deltatime = 0; // ��ŸŸ�� �ʱ�ȭ
	}
	return false;
}

void Sprite::Draw()
{
	if (isactive == false)
		return;
	if (texture == nullptr)
		return;
	isui ? Director::GetInstance()->sprite->Begin(D3DXSPRITE_ALPHABLEND) :
		Director::GetInstance()->sprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_OBJECTSPACE);
	Director::GetInstance()->sprite->SetTransform(&GetMatrix());
	Vec3 center = { texture->info.Width * pivot.x, texture->info.Height * pivot.y, 0 };
	Director::GetInstance()->sprite->Draw(texture->texture, &imageRect, &center, nullptr, color);
	Director::GetInstance()->sprite->End();
}
