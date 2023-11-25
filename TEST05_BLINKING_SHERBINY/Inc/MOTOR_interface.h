/**********************************************************/
/* Author    :  Hosny & Tariq                             */
/* Date      :  14 Nov 2023                               */
/* Version   :  V01                                       */
/**********************************************************/

#ifndef HAL_MOTOR_MOTOR_INTERFACE_H_
#define HAL_MOTOR_MOTOR_INTERFACE_H_


void MOTORS_Void_MotorInit();



/******************************MOTOR RIGHT FORWARD*********************/
void MOTOR_RF_Void_MotorSetSpeed(u32 Copy_U8_Speed);
void MOTOR_RF_GO_FORWARD ();
void MOTOR_RF_GO_BACKWARD ();
void MOTOR_RF_STOP();

/******************************MOTOR LEFT FORWARD*********************/
void MOTOR_LF_Void_MotorSetSpeed(u32 Copy_U8_Speed);
void MOTOR_LF_GO_FORWARD ();
void MOTOR_LF_GO_BACKWARD ();
void MOTOR_LF_STOP();



/******************************MOTOR RIGHT BACK*********************/
void MOTOR_RB_Void_MotorSetSpeed(u32 Copy_U8_Speed);
void MOTOR_RB_GO_FORWARD ();
void MOTOR_RB_GO_BACKWARD ();
void MOTOR_RB_STOP();

/******************************MOTOR LEFT BACK*********************/
void MOTOR_LB_Void_MotorSetSpeed(u32 Copy_U8_Speed);
void MOTOR_LB_GO_FORWARD ();
void MOTOR_LB_GO_BACKWARD ();
void MOTOR_LB_STOP();







#endif /* HAL_MOTOR_MOTOR_INTERFACE_H_ */
