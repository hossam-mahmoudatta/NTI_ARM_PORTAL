

#ifndef TIMER3_INTERFACE_H_
#define TIMER3_INTERFACE_H_

#define Channle1		0



void TIMER3_VoidInitInputCapture(u8 Copy_ChannleNumber);
u8 Timer3_u8InputCaptureSetCallBack(void (*Copy_pvCallBackFunc)(void));
void Timer3_VoidSetPreload(u8 Copy_u8Preload);




#endif /* TIMER3_INTERFACE_H_ */
