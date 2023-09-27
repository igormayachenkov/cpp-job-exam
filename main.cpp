//#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "first.h"


void printBuf(char *buf, int len){
	for(int i=0; i<len; i++){
	    unsigned char ch = buf[i];
		for(unsigned char k=0,mask=0b10000000; k<8; k++,mask=mask>>1){
			putchar((ch & mask)?'1':'0');
		}		
		putchar(((i+1)%8)?' ':'\n'); // 8 numbers in a row
	}
    putchar('\n');
}

void printShort(short val){
	unsigned short mask=0b1000000000000000;
	for(int k=0; k<16; k++){
		putchar((val & mask)?'1':'0');
		mask=mask>>1;
	}		
}

int main(void){
	char buf[]="Hello world!";

	printBuf(buf, strlen(buf));

	int start=13, len=13;
	short data;
	data = getdata(buf,start,len);
	printf ("getdata(buf, start=%d, len=%d) => %d   ", start, len, data);
//	data=data&0xffff;
	//data = 0xffff>>0x000a;
	//data = 0b0010101100001111;
	printShort(data);
    putchar('\n');

    return 0;
}




