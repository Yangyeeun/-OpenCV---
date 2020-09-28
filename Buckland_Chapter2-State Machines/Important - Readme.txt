20200929
B877022 양예은

----------

WestWorldWithMessaging.sln파일을 실행시키면 됩니다.
VS2019에서 작성했습니다.

-----------

전체스토리는 아내를 위해 열심히 일만 하고 집에서는 잠과 음식만 먹는 Bob과
 밥의 친구이자 술집주인인 John,
바빠서 자신에게 소홀한 Bob을 두고 John과 사랑하여 Bob이 은행에 모은 돈으로 John에게 새 가게를 차려주려는 Elsa의 이야기 입니다.

------------
주인공 John을 추가하였습니다. 
John은 Cat.h/Cat.cpp/CatOwnedStates.h/CatOwnedStates.cppp에서 확인 가능합니다.

John은 Bob의 친구이며 술집주인입니다. 
John의 state는 ReadyBusiness,VisitHomeMeetElsa,WorkAtsaloon 세가지이며 기본 state는 ReadyBusiness입니다.
John은 saloon에서 장사를하고 준비를하며 VisitHomeMeetElsa일때는 shack로 이동합니다.

매초마다 Elsa에 대한 그리움m_iMiss이 증가하고 Miss_Elsa 수치를 넘어서면 VisitHomeMeetElsa상태로 넘어갑니다.
VisitHomeMeetElsa에서 John은 Msg_LoveElsa를 보내고 Elsa는 이 메시지를 받으면 "I love you,too"라는 반응을 합니다.
VisitHomeMeetElsa에서 Elsa를 만나면 Miss_Elsa 수치는 0이 되어 이전 상태로 되돌아 갑니다.

또한 매초 m_iOrder주문 수가 증가하고 Max_Order를 넘어서면 John은WorkAtsaloon 상태로 가서 장사를 합니다.
이 상태에서 m_iOrder=0이 됩니다.  만약 Missing상태이면 VisitHomeMeetElsa으로 변하고 아니면 이전 상태로 돌아갑니다.


Elsa는 VisitMessage를 MsgToJohn상태로 바꾸어 랜덤하게 말을 말을 합니다.
위에서 말한 것처럼  John이 Msg_LoveElsa를 보내고 Elsa는 이 메시지를 받으면 반응을 합니다.

Bob은 이야기의 흐름에 맞게 ComfortLevel를 높이고 집에서 Elsa에게 반응도 안하고 일하러 가는 말로 변경하였습니다.





