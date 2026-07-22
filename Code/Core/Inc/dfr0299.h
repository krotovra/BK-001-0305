/*
 * dfr0299.h
 *
 *  Created on: 14 ����. 2018 �.
 *      Author: ��������
 */

#ifndef DFR0299_H_
#define DFR0299_H_

#include "UART.h"

void mp3_specify_tracking(unsigned int track); //0-2999, ����� �������� ������
void mp3_next();
void mp3_prev();
//0x06 set volume 0-30
void mp3_set_volume(unsigned int volume);

//0x07 set EQ0/1/2/3/4/5    Normal/Pop/Rock/Jazz/Classic/Bass
void mp3_set_EQ(unsigned int eq);
void mp3_playrepeat(unsigned int track);  //��������� ���� �� �����

//0x09 set device 1/2/3/4/5 U/SD/AUX/SLEEP/FLASH
void mp3_set_device(unsigned int device);

//
void mp3_sleep();//
void mp3_reset();
void mp3_play();
void mp3_pause();
//
void mp3_stop ();

void mp3_incvolume();

void mp3_decvolume();



#endif /* DFR0299_H_ */
