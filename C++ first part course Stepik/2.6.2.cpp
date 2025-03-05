#include <iostream>
using namespace std;
char * resize_fun(char * str, unsigned size_str, unsigned new_size)
{
    char * new_str = new char [new_size];
    std::copy(str, str + size_str, new_str);
    delete [] str;
    str = 0;
    return new_str;
}

char *getline()
{
    unsigned nmemb = 5;
    char * str = new char [nmemb];
    char c = '\0';
    unsigned size_str = 0;
    while (cin.get(c) && c != '\n'){
        str[size_str] = c;
        if (++size_str == nmemb){
             str = resize_fun(str, nmemb, nmemb * 2);
             nmemb *= 2;
        }
    }
    str[size_str] = '\0';
    return str;
}