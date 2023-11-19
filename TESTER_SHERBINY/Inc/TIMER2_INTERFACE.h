
#ifndef TIMER2_INTERFACE_H_
#define TIMER2_INTERFACE_H_


#define Channle1		0



void TIMER2_VoidInitInputCapture(u8 Copy_ChannleNumber);
u8 Timer2_u8InputCaptureSetCallBack(void (*Copy_pvCallBackFunc)(void));
void Timer2_VoidSetPreload(u8 Copy_u8Preload);

#endif /* TIMER2_INTERFACE_H_ */





