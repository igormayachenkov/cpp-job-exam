#include <stdio.h>
#include <string.h>
#include "first.h"
#include "second.h"


void printBuf(char *buf, int len){
	for(int i=0; i<len; i++){
	    unsigned char ch = buf[i];
		for(unsigned char k=0,mask=0b10000000; k<8; k++,mask=mask>>1){
			putchar((ch & mask)?'1':'0');
		}		
		putchar(((i+1)%8)?' ':'\n'); // 8 numbers in a row
	}
    putchar('\n');
	putchar('\n');
}
void printBuf(Buffer &buffer){printBuf(buffer.buf, buffer.size);}


void printData(short val){
	unsigned short mask=0b1000000000000000;
	for(int k=0; k<16; k++){
		putchar((val & mask)?'1':'0');
		mask=mask>>1;
	}	
}

int main(void){
	char buf[]="Hello world!";
	int size = sizeof(buf);
	int start=13, len=13;
	short data;

	//--------------------------------------
	// TASK 1 TEST
	printf("-------------- task 1 -------------------\n");
	try{

		// Initial buffer
		printf("initial buffer:\n");
		printBuf(buf, size);

		// Get data test
		data = getdata(buf,start,len);
		printf ("getdata(buf, start=%d, len=%d)   =>  %d   ", start, len, data);
		printData(data); 	putchar('\n');


		// Put data test
		putdata(buf,start,len,data);
		printf ("putdata(buf, start=%d, len=%d, data= %d   ", start, len, data);
		printData(data); 	printf(" )\n\n");


		// Final buffer
		printf("final buffer:\n");
		printBuf(buf, size); 
	}catch(const char* error){
		printf("\nERROR: %s\n",error);
	}


	//--------------------------------------
	// TASK 2 TEST
	printf("\n-------------- task 2 -------------------\n");
	try{
		Package package(buf, size);
		printf("base buffer:\n");
		printBuf(buf, size);
		printf("package.header:\n");
		printBuf(package.header);
		printf("package.fixed:\n");
		printBuf(package.fixed);
		printf("package.body:\n");
		printBuf(package.body);

		Package package2(package,1);
		printf("package2.header:\n");
		printBuf(package2.header);

	}catch(const char* error){
		printf("\nERROR: %s\n",error);
	}

    return 0;
}




