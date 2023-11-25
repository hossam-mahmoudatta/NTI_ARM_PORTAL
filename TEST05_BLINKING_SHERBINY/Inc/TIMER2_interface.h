
#ifndef TIMER2_INTERFACE_H_
#define TIMER2_INTERFACE_H_


#define Channle1		0
#define Channle2		1

#define TIMER2_RISING_EDGE 0
#define TIMER2_FALLING_EDGE 1
void TIMER2_VoidInitInputCapture(u8 Copy_ChannleNumber);
u8 Timer2_u8InputCaptureSetCallBack(void (*Copy_pvCallBackFunc)(void));
void Timer2_VoidSetPreload(u8 Copy_u8Preload);

void Timer2_VoidEnableIntOnEachChannle(u8 Copy_ChannleNumber);
void Timer2_VoidDisableIntOnEachChannle(u8 Copy_ChannleNumber);

void Timer2_VoidChangePolarityOnEachChannle(u8 Copy_ChannleNumber,u8 Copy_Edge);
u32  Timer2_VoidGetCapturedValue(u8 Copy_ChannleNumber);
#endif /* TIMER2_INTERFACE_H_ */





