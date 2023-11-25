/**********************************************************/
/* Author    :  Hosny & Tariq                             */
/* Date      :  14 Nov 2023                               */
/* Version   :  V01                                       */
/**********************************************************/
#ifndef MCAL_TIMER_TIMER_PRIVATE_H_
#define MCAL_TIMER_TIMER_PRIVATE_H_

//#define TIMER_BASE_ADDRESS                        0x40000000
//
//#define TIMER_CR1                           *((volatile u32*)(TIMER_BASE_ADDRESS +0x00))
//#define TIMER_CCMR1                         *((volatile u32*)(TIMER_BASE_ADDRESS +0x18))
//#define TIMER_CCMR2                         *((volatile u32*)(TIMER_BASE_ADDRESS +0x1C))
//#define TIMER_CCER                          *((volatile u32*)(TIMER_BASE_ADDRESS +0x20))
//#define TIMER_PSC 							*((volatile u32*)(TIMER_BASE_ADDRESS +0x28))
//#define TIMER_CCR1                          *((volatile u32*)(TIMER_BASE_ADDRESS +0x34))
//#define TIMER_CCR2                          *((volatile u32*)(TIMER_BASE_ADDRESS +0x38))
//#define TIMER_CCR3                          *((volatile u32*)(TIMER_BASE_ADDRESS +0x3C))
//#define TIMER_ARR                           *((volatile u32*)(TIMER_BASE_ADDRESS +0x2C))
//
//


#define TIMER4_BASE_ADDRESS                          0x40000800

#define TIMER4_CR1                          *((volatile u32*)(TIMER4_BASE_ADDRESS + 0x00))
#define TIMER4_CR2                          *((volatile u32*)(TIMER4_BASE_ADDRESS + 0x04))
#define TIMER4_SMCR                         *((volatile u32*)(TIMER4_BASE_ADDRESS + 0x08))
#define TIMER4_DIER                         *((volatile u32*)(TIMER4_BASE_ADDRESS + 0x0C))
#define TIMER4_SR                           *((volatile u32*)(TIMER4_BASE_ADDRESS + 0x10))
#define TIMER4_EGR                          *((volatile u32*)(TIMER4_BASE_ADDRESS + 0x14))
#define TIMER4_CCMR1                        *((volatile u32*)(TIMER4_BASE_ADDRESS + 0x18))
#define TIMER4_CCMR2                        *((volatile u32*)(TIMER4_BASE_ADDRESS + 0x1C))
#define TIMER4_CCER                         *((volatile u32*)(TIMER4_BASE_ADDRESS + 0x20))
#define TIMER4_CNT                          *((volatile u32*)(TIMER4_BASE_ADDRESS + 0x24))
#define TIMER4_PSC                          *((volatile u32*)(TIMER4_BASE_ADDRESS + 0x28))
#define TIMER4_CCR1                          *((volatile u32*)(TIMER4_BASE_ADDRESS +0x34))
#define TIMER4_CCR2                          *((volatile u32*)(TIMER4_BASE_ADDRESS +0x38))
#define TIMER4_CCR3                          *((volatile u32*)(TIMER4_BASE_ADDRESS +0x3C))
#define TIMER4_CCR4                          *((volatile u32*)(TIMER4_BASE_ADDRESS +0x40))
#define TIMER4_ARR                          *((volatile u32*)(TIMER4_BASE_ADDRESS + 0x2C))


#endif /* MCAL_TIMER_TIMER_PRIVATE_H_ */
