#include <stdio.h>
#include "second.h"

const int HEADER_SIZE = 5;
const int FIXED_SIZE  = 3;

Package::Package(char *buf, int size):
    buffer  (Buffer(buf,size)), 
    header  (Buffer(buf,                          HEADER_SIZE)),
    fixed   (Buffer(buf+HEADER_SIZE,              FIXED_SIZE)),
    body    (Buffer(buf+HEADER_SIZE+FIXED_SIZE,   size-HEADER_SIZE-FIXED_SIZE))
{
    printf("Package(buf, size=%d)\n",size);
}

Package::Package(Package &package, int offset):
    Package(package.buffer.buf+offset, package.buffer.size-offset) {}
