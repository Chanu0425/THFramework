#pragma once
class Scene // 하나의 장면. 예: 메뉴, 게임, 스코어, 상점
{
public:
	virtual void Init() PURE; // 시작 (초기화)
	virtual void Update() PURE; // 업데이트 & 렌더
	virtual void Exit() PURE; // 나가기
};

