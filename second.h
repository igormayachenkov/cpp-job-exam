struct Buffer{
    char *buf;
    int size;
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