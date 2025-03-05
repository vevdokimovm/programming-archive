#include <cstring> // strlen, strcpy
struct String {
	String(const char *str = "");
	String(size_t n, char c);
	~String();
    void append(String & other){
	    char * new_ptr = new char [size + other.size + 1];
	    strcpy(new_ptr, str);
	    strcpy(new_ptr + size, other.str);
        delete [] str;
        str = new_ptr;
        size += other.size;
	}
	size_t size;
	char *str;
};