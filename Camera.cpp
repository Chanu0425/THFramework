#include "DXUT.h"
#include "Camera.h"

void Camera::CameraInit()
{
	D3DXMatrixIdentity(&WM); // ���� ��� �ʱ�ȭ (���� ��ķ� �ٲ���)
}

void Camera::CameraUpdate()
{
	D3DXMATRIX translation;
	D3DXMatrixTranslation(&translation, -cameraPos.x, -cameraPos.y, 0);
	D3DXMATRIX rotation;
	D3DXMatrixRotationZ(&rotation, cameraRot);
	
	//if (camRot != 0) camRot /= 1.1;
	
	VM = translation * rotation;

	D3DXMatrixOrthoLH(&PM, ScreenW * cameraSize, -ScreenH * cameraSize, 0, 1);

	DEVICE->SetTransform(D3DTS_WORLD, &WM);
	DEVICE->SetTransform(D3DTS_VIEW, &VM);
	DEVICE->SetTransform(D3DTS_PROJECTION, &PM);
}
