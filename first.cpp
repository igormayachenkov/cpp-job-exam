#include <stdio.h>

// BUFFER UTILS
// index - from left to right
inline bool bufGetBit(char *buf, int index){
	int iByte = index/8; // byte index
	int iBit  = index%8; // bit index in the byte
	bool bit  = buf[iByte]&(0b10000000>>iBit);
	printf ("bufGetBit   %d %d %d   \n", iByte, iBit, bit);
	return bit;
}

inline void bufSetBit(char *buf, int index, bool bit){
	int iByte = index/8; // byte index
	int iBit  = index%8; // bit index in the byte
	printf ("bufSetBit   %d %d %d   \n", iByte, iBit, bit);
	if(bit) 
		buf[iByte] |=  (0b10000000>>iBit); // set bit
	else
		buf[iByte] &= ~(0b10000000>>iBit); // clear bit

}

// DATA UTILS
// index - from right to left
bool dataVerifyLen(int len){
	if(len<0 || len>sizeof(short)*8) {
		printf("Wrong len value: %d\n",len); 
		return false;
	}
	return true;
}
inline bool dataGetBit(unsigned short data, int index){
	bool bit  = data & 1<<index;
	printf ("dataGetBit   %d %d   ", index, bit);
	return bit;
}

// THE FUNCTIONS
short getdata(char *buf, int start, int len){
	if(!dataVerifyLen(len)) return 0;
	short data = 0;

	for(int i=0; i<len; i++){
		int index = start + len - i - 1; // bit index in the buffer

		if( bufGetBit(buf,index) ){
			// Set data bit
			if(index==start)// sign bit
				data = -data;
			else // data bit
				data |= 1<<i; // set data bit
		}else{
			// Clear data bit
			// ... do nothing here, initial bit is 0
		}
	}

	return data;
}

void  putdata(char *buf, int start, int len, short value){
	if(!dataVerifyLen(len)) return;

	short data = value<0 ? -value : value; // get positive data value

	for(int i=0; i<len; i++){
		bool bit = dataGetBit(data,i);
		bufSetBit(
			buf,
			start + len - i - 1,
			i==start ? value<0 : bit // sign or data bit
		);
	}
}