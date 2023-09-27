#include <stdio.h>
#include "second.h"

const int HEADER_SIZE = 5;
const int FIXED_SIZE  = 3;

Package::Package(char *buf, int size):
    buffer  ({buf,size}), 
    header  ({buf,                          HEADER_SIZE}),
    fixed   ({buf+HEADER_SIZE,              FIXED_SIZE}),
    body    ({buf+HEADER_SIZE+FIXED_SIZE,   size-HEADER_SIZE-FIXED_SIZE})
{
    printf("Package(buf, size=%d)\n",size);
}

