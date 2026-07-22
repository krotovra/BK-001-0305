
#include "dfr0299.h"

char send_buf[10]={0x7E,0xFF,0x06,0,0,0,0,0,0,0xEF}; //отправить строку

//calc checksum (1~6 byte)
unsigned int mp3_get_checksum ()
{  
  unsigned int sum = 0;
  
  for (int i=1; i<7; i++)
  {
    sum = sum + (((unsigned int)(send_buf[i]))&0x00FF);
  }
  
  return -sum;
}

//fill checksum to send_buf (7~8 byte)
void mp3_fill_checksum()
{
  unsigned int checksum = mp3_get_checksum();
  
  send_buf[7] = (unsigned char)(checksum>>8);
  send_buf[8] = (unsigned char)checksum;
}

void mp3_send_cmd2 (unsigned char cmd, unsigned int arg) {
  send_buf[3] = cmd;
//  fill_uint16_bigend ((&send_buf+5), arg);
  send_buf[5] = (unsigned char)(arg>>8);
  send_buf[6] = (unsigned char)arg;

  mp3_fill_checksum ();

  UART_WriteString(send_buf, 10);
  UART_StartTransmit();
}

//
void mp3_send_cmd (unsigned char cmd) {
  send_buf[3] = cmd;
//  fill_uint16_bigend ((&send_buf+5), 0);
  send_buf[5] = 0;
  send_buf[6] = 0;

  mp3_fill_checksum ();

  UART_WriteString(send_buf, 10);
  UART_StartTransmit();
}


//
void mp3_specify_tracking (unsigned int track) { //0-2999, сразу начинает играть
  mp3_send_cmd2 (0x03, track);
}

//
void mp3_next () {
  mp3_send_cmd (0x01);
}

//
void mp3_prev () {
  mp3_send_cmd (0x02);
}

//0x06 set volume 0-30
void mp3_set_volume (unsigned int volume) {
  mp3_send_cmd2 (0x06, volume);
}

//0x07 set EQ0/1/2/3/4/5    Normal/Pop/Rock/Jazz/Classic/Bass
void mp3_set_EQ (unsigned int eq) {
  mp3_send_cmd2 (0x07, eq);
}

void mp3_playrepeat(unsigned int track) { //странная команда, скорее всего повторяет трек по кругу
  mp3_send_cmd2 (0x08, track);
}

//0x09 set device 1/2/3/4/5 U/SD/AUX/SLEEP/FLASH
void mp3_set_device (unsigned int device) {
  mp3_send_cmd2 (0x09, device);
}

//
void mp3_sleep () {
  mp3_send_cmd (0x0a);
}

//
void mp3_reset () {
  mp3_send_cmd (0x0c);
}

//
void mp3_play () {
  mp3_send_cmd (0x0d);
}

//
void mp3_pause () {
  mp3_send_cmd (0x0e);
}

//
void mp3_stop () {
  mp3_send_cmd (0x16);
}

void mp3_incvolume () {
mp3_send_cmd (0x04);
}

void mp3_decvolume () {
mp3_send_cmd (0x05);
}
