#include "Cat.h"

bool Cat::HandleMessage(const Telegram& msg)
{
	return m_pStateMachine->HandleMessage(msg);
}


void Cat::Update()
{
	SetTextColor(0x000f);  // ÇÏ¾á»ö ±Û¾¾
	//SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);

	m_iMiss += 1;
	m_iOrder += 1;
	m_pStateMachine->Update();
}

bool Cat::Missing()const
{
	if (m_iMiss >= Miss_Elsa) { return true; }

	return false;

}

bool Cat::OrderBackUp()const
{
	if (m_iOrder >= Max_Order) { return true; }

	return false;

}
