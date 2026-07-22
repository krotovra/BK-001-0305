/*
 * CircularBuffer.h
 *
 *  Created on: 1 но€б. 2018 г.
 *      Author: VasinS
 */

#ifndef CIRCULARBUFFER_H_
#define CIRCULARBUFFER_H_


#define CircularBuffer struct struct_CircularBuffer

struct struct_CircularBuffer
{
	volatile int   size;
	volatile int   add_pos;
	volatile int   next_add_pos;
	volatile int   get_pos;
	volatile char  add_res;
	volatile char  get_res;

	volatile char* c_bytes;
};


void CBuff_Init(CircularBuffer* cb, char* memory, int size);

void CBuff_AddChar(CircularBuffer* cb, char c);

char CBuff_GetChar(CircularBuffer* cb);

char CBuff_ReadChar(CircularBuffer* cb);

char CBuff_IsEmpty(CircularBuffer* cb);


#endif /* CIRCULARBUFFER_H_ */
