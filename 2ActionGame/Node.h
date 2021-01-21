#pragma once
class Node // ��ü (��ü) �� ������ ���� ������
{
public:
	Node() {};
	virtual ~Node() {};

	// �����ؾ� �ϴ� �Ǽ�
	// scale�� ������ 1 0�̸� �Ⱥ��δ�
	// color �� �����ؾ��Ѵ�. alpha�� 0�̸� �Ⱥ��δ�.
	// Renderer���� �� �Ѱ�����ϰ�
	// ���� ���� �ӿ��� �Լ��� �� ȣ��Ǵ��� �����ϰ�
	// Matrix (���) ������ ����� �ߴ��� Ȯ���غ���.

	Vec2 position = { 0,0 };
	Vec2 scale = { 1,1 };
	Vec2 pivot = { 0.5f,0.5f };
	int layer = 0; // Ŭ���� �տ� �´�!
	float rotation = 0;
	bool isactive = true; // ����ֳ�? �׾���?
	bool isui = false; // �� ��ü�� UI�ΰ�? �ƴϸ� ������Ʈ�ΰ�?
	Color color = Color(1, 1, 1, 1);
	RECT imageRect;

	virtual void Update() {};
	virtual void Draw() {};

	D3DXMATRIX GetMatrix();
};

