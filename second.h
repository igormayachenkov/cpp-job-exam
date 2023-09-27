class Buffer{
public:
    char *buf;
    int size;
    Buffer(char *buf, int size):buf(buf), size(size){
        if(size<0) throw "Buffer. Wrong size value.";
    }
};

class Package{
protected:
    Buffer buffer;
public:
    Buffer header;
    Buffer fixed;
    Buffer body;
    Package(char *buf, int size);
};