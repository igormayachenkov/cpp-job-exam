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

void printData(short val){
	unsigned short mask=0b1000000000000000;
	for(int k=0; k<16; k++){
		putchar((val & mask)?'1':'0');
		mask=mask>>1;
	}		
}

int main(void){
	char buf[]="Hello world!";
	int start=13, len=13;
	short data;

	printBuf(buf, strlen(buf));

	// Get data test
	data = getdata(buf,start,len);
	printf ("getdata(buf, start=%d, len=%d) => %d   ", start, len, data);
	printData(data);
    putchar('\n');

	// Put data test
	putdata(buf,start,len,data);
//	putdata(buf,start,len,0xffff);
	
	printBuf(buf, strlen(buf));

    return 0;
}




