#include "DXUT.h"
#include "Node.h"

D3DXMATRIX Node::GetMatrix()
{
	D3DXMATRIX m;
	//D3DXMATRIX* WINAPI D3DXMatrixTransformation2D
	//(D3DXMATRIX * pOut, CONST D3DXVECTOR2 * pScalingCenter,
	//	FLOAT ScalingRotation, CONST D3DXVECTOR2 * pScaling,
	//	CONST D3DXVECTOR2 * pRotationCenter, FLOAT Rotation,
	//	CONST D3DXVECTOR2 * pTranslation);
	// 중요한건, Scaling, Rotation, Translation
	D3DXMatrixTransformation2D(&m, nullptr, 0, &scale, nullptr, rotation,
		&position);
	return m;
}
