#include <stdio.h>

bool bufGetBit(char *buf, int index){
	int iByte = index/8; // byte index
	int iBit  = index%8; // bit index in the byte
	bool bit  = buf[iByte]&(0b10000000>>iBit);
	printf ("bufGetBit   %d %d %d   \n", iByte, iBit, bit);
	return bit;
}

void bufSetBit(char *buf, int index){

}
void bufClearBit(char *buf, int index){

}

short getdata(char *buf, int start, int len){
	if(len<0 || len>sizeof(short)*8) {printf("Wrong len value: %d\n",len); return 0;}
	short data = 0;

	//unsigned short mask = 1;
	for(int i=0; i<len; i++){
		int index = start + len - i - 1;

		if( bufGetBit(buf,index) ){
			// Set data bit
			if(index==start)// sign bit
				data = -data;
			else // data bit
				data = data | 1<<i;
		}else{
			// Clear data bit
			// ... do nothing here
		}
	}

	return data;
}