#pragma once
class Scene // �ϳ��� ���. ��: �޴�, ����, ���ھ�, ����
{
public:
	virtual void Init() PURE; // ���� (�ʱ�ȭ)
	virtual void Update() PURE; // ������Ʈ & ����
	virtual void Exit() PURE; // ������
};

