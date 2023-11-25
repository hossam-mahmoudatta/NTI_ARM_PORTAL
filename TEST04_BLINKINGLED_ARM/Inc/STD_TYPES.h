 /******************************************************************************
 *
 * Module File: Common Standard - Platform Types Abstraction
 *
 * File Name: STD_TYPES.h
 *
 * Description: Datatypes for ARM
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/

#ifndef STD_TYPES_H
#define STD_TYPES_H

/*******************************************************************************
 *                              						Types  Declarations	                         					  *
 *******************************************************************************/

#ifndef FALSE
	#define FALSE      (0u)
#endif

#ifndef TRUE
	#define TRUE        (1u)
#endif

#define LOGIC_HIGH					1 //(1u)
#define LOGIC_LOW					0 //(0u)

#define NULL_PTR						((void*)0x00)
#define NULL								0

#define SET									1
#define CLR									0

#define ENABLE									1
#define DISABLE									0


typedef unsigned char					u8;          /*           0 .. 255              */
typedef signed char           			s8;          /*        -128 .. +127             */
typedef unsigned short				u16;         /*           0 .. 65535            */
typedef signed short          			s16;         /*      -32768 .. +32767           */
typedef unsigned long         			u32;         /*           0 .. 4294967295       */
typedef signed long           			s32;         /* -2147483648 .. +2147483647      */
typedef unsigned long long			u64;         /*       0 .. 18446744073709551615  */
typedef signed long long				s64;         /* -9223372036854775808 .. 9223372036854775807 */
typedef float								f32;
typedef double								f64;
typedef long double  					f80;
typedef const unsigned char			cu8;


#endif

/*******************************************************************************
 *                              								End of Module					               					  *
 *******************************************************************************/
