#include "CatOwnedStates.h"  // �����
#include "fsm/State.h"
#include "Cat.h"   // �����
#include "Locations.h"
#include "messaging/Telegram.h"
#include "MessageDispatcher.h"
#include "MessageTypes.h"
#include "Time/CrudeTimer.h"
#include "EntityNames.h"

#include <iostream>
using std::cout;


#ifdef TEXTOUTPUT
#include <fstream>
extern std::ofstream os;
#define cout os
#endif


//------------------------------------------------------------------------methods for SleepAllDay
WorkAtsaloon* WorkAtsaloon::Instance()
{
	static WorkAtsaloon instance;

	return &instance;
}


void WorkAtsaloon::Enter(Cat* pCat)
{
	if (pCat->Location() != saloon)
	{
		cout << "\n" << GetNameOfEntity(pCat->ID()) << ": " << "Working at the saloon. I thinking of Elsa";

		pCat->ChangeLocation(saloon);
	}
}


void WorkAtsaloon::Execute(Cat* pCat)
{
	pCat->BackSaloon();
	//cout << "\n" << GetNameOfEntity(pCat->ID()) << ": " << "I miss Elsa" << ", m_iThirst: "<< pCat->m_iMiss;

	if (pCat->Missing())
	{
		pCat->GetFSM()->ChangeState(VisitHomeMeetElsa::Instance());
	}
	else
		pCat->GetFSM()->RevertToPreviousState();
	
}


void WorkAtsaloon::Exit(Cat* pCat)
{
	cout << "\n" << GetNameOfEntity(pCat->ID()) << ": "
		<< "Hoo, I worked a lot ";
}


bool WorkAtsaloon::OnMessage(Cat* pCat, const Telegram& msg)
{
	//send msg to global message handler
	return false;
}

//------------------------------------------------------------------------methods for VisitHomeGetWater

VisitHomeMeetElsa* VisitHomeMeetElsa::Instance()
{
	static VisitHomeMeetElsa instance;
	
	return &instance;
}

void VisitHomeMeetElsa::Enter(Cat* pCat)
{
	// ������ ��� �̵�
	if (pCat->Location() != shack)
	{
		cout << "\n" << GetNameOfEntity(pCat->ID()) << ": " << "I miss you so much. I love you";

		pCat->ChangeLocation(shack);
	}

	// ����̰� ���翡�� �λ��Ѵ�. (�޼��� ����)
	// �ش� �޼��� �ڵ��� MinersWifeOwnedStates.cpp ������ 59��°�� ����
	Dispatch->DispatchMessage(SEND_MSG_IMMEDIATELY, //time delay
		pCat->ID(),        //ID of sender      : ����̰� 
		ent_Elsa,            //ID of recipient : ���翡�� �λ�
		Msg_LoveElsa,   //the message           : �λ�(�޼���) ����
		NO_ADDITIONAL_INFO);
}


void VisitHomeMeetElsa::Execute(Cat* pCat)
{
	// ���� �ؼ�
	pCat->MeetElsa();
	pCat->GetFSM()->RevertToPreviousState();
}


void VisitHomeMeetElsa::Exit(Cat* pCat)
{
	cout << "\n" << GetNameOfEntity(pCat->ID()) << ": " << "See you later";
}


bool VisitHomeMeetElsa::OnMessage(Cat* pCat, const Telegram& msg)
{
	//send msg to global message handler
	return false;
}

///////////////////////////////////////////////////////////////////////////////////////////////

ReadyBusiness* ReadyBusiness::Instance()
{
	static ReadyBusiness instance;

	return &instance;
}

void ReadyBusiness::Enter(Cat* pCat)
{
	//cout << "\n" << GetNameOfEntity(pCat->ID()) << ": " << "I miss Elsa" << ", m_iThirst: " << pCat->m_iMiss;
	if (pCat->Location() != saloon)
	{
		cout << "\n" << GetNameOfEntity(pCat->ID()) << ": " << "orders are over";

		pCat->ChangeLocation(saloon);
	}


}


void ReadyBusiness::Execute(Cat* pCat)
{
	cout << "\n" << GetNameOfEntity(pCat->ID()) << ": Busy busy, processing orders";
	if (pCat->OrderBackUp()) {
		pCat->GetFSM()->ChangeState(WorkAtsaloon::Instance());
	}
	if (pCat->Missing()) {
		pCat->GetFSM()->ChangeState(VisitHomeMeetElsa::Instance());
	}
}

void ReadyBusiness::Exit(Cat* pCat)
{
	cout << "\n" << GetNameOfEntity(pCat->ID()) << ": I solved it, all!"; 
}

bool ReadyBusiness::OnMessage(Cat* pCat, const Telegram& msg)
{
	return false;
}