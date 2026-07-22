/*
 * Keyboard.h
 *
 *  Created on: 20 ���. 2020 �.
 *      Author: VasinS
 */

#ifndef KEYBOARD_H_
#define KEYBOARD_H_

#include "TypeDefine.h"

#define KeyboardSize 9

#define Key_Learning                      0
#define Key_Control                       1
#define Key_VolumeDec                     2
#define Key_VolumeInc                     3

#define Key_Stages_Semen  			      4
#define Key_Instruments_For_Semen         5
#define Key_Rectocervical_way             6
#define Key_Manocervical_way              7
#define Key_Vizocervical_way			  8
/*
#define Key_Perimeter                     9
#define Key_Salpingitis                   10
#define Key_Ovariitis                     11
#define Key_persistent_yellow_body        12
#define Key_Luteal_cysts                  13
#define Key_Ovarian_hypofunction          14
#define Key_Follicular_cysts              15
*/

void  KeyboardInit();
void  KeyboardProcess();
UINT8 KeyboardGetLockState();

#endif /* KEYBOARD_H_ */
