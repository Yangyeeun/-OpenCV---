#ifndef CAT_OWNED_STATES_H
#define CAT_OWNED_STATES_H
//------------------------------------------------------------------------
//
//  Name:   CatOwnedStates.h
//
//  ����̴� ��� ���� ��ϴ�.�׷��� ���� ������ ���� �� ���� ���ʴϴ�.
//  ���� ����, ���翡�� �λ縦 �մϴ�. 
//  ���� ���� ������ �ؼҵǾ��ٸ�, �ٽ� ���翡 ���� ���� ��ϴ�.
//
//------------------------------------------------------------------------
#include "fsm/State.h"


class Cat;
struct Telegram;


class WorkAtsaloon : public State<Cat>   
{
private:

	WorkAtsaloon() {}

	//copy ctor and assignment should be private
	WorkAtsaloon(const WorkAtsaloon&);
	WorkAtsaloon& operator=(const WorkAtsaloon&);

public:

	//this is a singleton
	static WorkAtsaloon* Instance();

	virtual void Enter(Cat* miner);

	virtual void Execute(Cat* miner);

	virtual void Exit(Cat* miner);

	virtual bool OnMessage(Cat* agent, const Telegram& msg);

};

//------------------------------------------------------------------------

class VisitHomeMeetElsa: public State<Cat>
{
private:

	VisitHomeMeetElsa() {}

	//copy ctor and assignment should be private
	VisitHomeMeetElsa(const VisitHomeMeetElsa&);
	VisitHomeMeetElsa& operator=(const VisitHomeMeetElsa&);

public:

	//this is a singleton
	static VisitHomeMeetElsa* Instance();

	virtual void Enter(Cat* miner);

	virtual void Execute(Cat* miner);

	virtual void Exit(Cat* miner);

	virtual bool OnMessage(Cat* agent, const Telegram& msg);
};

class ReadyBusiness : public State<Cat>
{
private:

	ReadyBusiness() {}

	//copy ctor and assignment should be private
	ReadyBusiness(const ReadyBusiness&);
	ReadyBusiness& operator=(const ReadyBusiness&);

public:

	//this is a singleton
	static ReadyBusiness* Instance();

	virtual void Enter(Cat* miner);

	virtual void Execute(Cat* miner);

	virtual void Exit(Cat* miner);

	virtual bool OnMessage(Cat* agent, const Telegram& msg);
};



#endif