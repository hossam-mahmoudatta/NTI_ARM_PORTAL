#ifndef TIMER3_PRIVATE_H_
#define TIMER3_PRIVATE_H_



#define TIMER3_BASE_ADDRESS                        0x40000400

#define TIMER3_CR1                           *((volatile u32*)(TIMER3_BASE_ADDRESS +0x00))
#define TIMER3_DIER                          *((volatile u32*)(TIMER3_BASE_ADDRESS +0x0C))
#define TIMER3_SR                            *((volatile u32*)(TIMER3_BASE_ADDRESS +0x10))
#define TIMER3_CCER                          *((volatile u32*)(TIMER3_BASE_ADDRESS +0x20))
#define TIMER3_SMCR                          *((volatile u32*)(TIMER3_BASE_ADDRESS +0x08))

#define TIMER3_CCMR1                         *((volatile u32*)(TIMER3_BASE_ADDRESS +0x18))
#define TIMER3_CCMR2                         *((volatile u32*)(TIMER3_BASE_ADDRESS +0x1C))
#define TIMER3_CCER                          *((volatile u32*)(TIMER3_BASE_ADDRESS +0x20))
#define TIMER3_PSC 							*((volatile u32*)(TIMER3_BASE_ADDRESS +0x28))
#define TIMER3_CNT 							*((volatile u32*)(TIMER3_BASE_ADDRESS +0x24))
#define TIMER3_CCR1                          *((volatile u32*)(TIMER3_BASE_ADDRESS +0x34))
#define TIMER3_CCR2                          *((volatile u32*)(TIMER3_BASE_ADDRESS +0x38))
#define TIMER3_CCR3                          *((volatile u32*)(TIMER3_BASE_ADDRESS +0x3C))
#define TIMER3_ARR                           *((volatile u32*)(TIMER3_BASE_ADDRESS +0x2C))




#endif /* TIMER3_PRIVATE_H_ */
