

#ifndef TIMER3_INTERFACE_H_
#define TIMER3_INTERFACE_H_

#define Channle1		0
#define Channle2		1

#define TIMER3_RISING_EDGE 0
#define TIMER3_FALLING_EDGE 1

void TIMER3_VoidInitInputCapture(u8 Copy_ChannleNumber);
u8 Timer3_u8InputCaptureSetCallBack(void (*Copy_pvCallBackFunc)(void));
void Timer3_VoidSetPreload(u8 Copy_u8Preload);

void Timer3_VoidEnableIntOnEachChannle(u8 Copy_ChannleNumber);
void Timer3_VoidDisableIntOnEachChannle(u8 Copy_ChannleNumber);

void Timer3_VoidChangePolarityOnEachChannle(u8 Copy_ChannleNumber,u8 Copy_Edge);
u32  Timer3_VoidGetCapturedValue(u8 Copy_ChannleNumber);


#endif /* TIMER3_INTERFACE_H_ */
