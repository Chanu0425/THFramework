#include "DXUT.h"
#include "Base.h"

Base::Base()
{
	state = BaseState::IDLE;
}

Base::~Base()
{
}

void Base::GetDamage(int damage)
{
	hp -= damage;
	hitfacetime = 0.5f;
	state = BaseState::HIT;
}

void Base::Update()
{
	switch (state)
	{
	case BaseState::IDLE:
		IDLE();
		break;
	case BaseState::HIT:
		hitfacetime -= DELTATIME;
		HIT();
		if (hitfacetime <= 0)
			state = BaseState::IDLE;
		break;
	case BaseState::DIE:
		DIE();
		break;
	}


	Move();
	if (hp <= 0)
	{
		state = BaseState::DIE;
	}
}
