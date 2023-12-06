/**********************************************************/
/* Author    :  Hosny & Tariq                             */
/* Date      :  14 Nov 2023                               */
/* Version   :  V01                                       */
/**********************************************************/
#ifndef HAL_MOTOR_MOTOR_CONFIG_H_
#define HAL_MOTOR_MOTOR_CONFIG_H_




/**************** MOTOR RIGHT FORWARD**********/
          /***********PORTS**********/
#define MOTOR_RF_IN1_PORT                       GPIOB
#define MOTOR_RF_IN2_PORT                       GPIOB

#define MOTOR_RF_ENA_PORT                       GPIOB

          /***********PINS**********/

#define MOTOR_RF_IN1_PIN                       PIN14
#define MOTOR_RF_IN2_PIN                       PIN15

#define MOTOR_RF_ENA_PIN                       PIN8





/**************** MOTOR LEFT FORWARD**********/
          /***********PORTS**********/
#define MOTOR_LF_IN1_PORT                       GPIOB
#define MOTOR_LF_IN2_PORT                       GPIOB

#define MOTOR_LF_ENA_PORT                       GPIOB

          /***********PINS**********/

#define MOTOR_LF_IN1_PIN                       PIN12
#define MOTOR_LF_IN2_PIN                       PIN13

#define MOTOR_LF_ENA_PIN                       PIN9






/**************** MOTOR RIGHT BACK**********/
          /***********PORTS**********/
#define MOTOR_RB_IN1_PORT                       GPIOB
#define MOTOR_RB_IN2_PORT                       GPIOB

#define MOTOR_RB_ENA_PORT                       GPIOB

          /***********PINS**********/

#define MOTOR_RB_IN1_PIN                       PIN3
#define MOTOR_RB_IN2_PIN                       PIN4

#define MOTOR_RB_ENA_PIN                       PIN6


/**************** MOTOR LEFT BACK**********/
          /***********PORTS**********/
#define MOTOR_LB_IN1_PORT                       GPIOB
#define MOTOR_LB_IN2_PORT                       GPIOB

#define MOTOR_LB_ENA_PORT                       GPIOB

          /***********PINS**********/

#define MOTOR_LB_IN1_PIN                       PIN5
#define MOTOR_LB_IN2_PIN                       PIN10

#define MOTOR_LB_ENA_PIN                       PIN7
#endif /* HAL_MOTOR_MOTOR_CONFIG_H_ */
