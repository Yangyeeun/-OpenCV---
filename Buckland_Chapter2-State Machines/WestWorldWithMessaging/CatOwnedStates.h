#ifndef CAT_OWNED_STATES_H
#define CAT_OWNED_STATES_H
//------------------------------------------------------------------------
//
//  Name:   CatOwnedStates.h
//
//  고양이는 계속 잠을 잡니다.그러다 목이 마르면 집에 들어가 물을 마십니다.
//  집에 들어갈때, 엘사에게 인사를 합니다. 
//  물을 마셔 갈증이 해소되었다면, 다시 마당에 나가 잠을 잡니다.
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