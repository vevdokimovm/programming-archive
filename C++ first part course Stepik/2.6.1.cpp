char *resize(const char *str, unsigned size, unsigned new_size)
{
	char * b = new char [new_size];
	for (size_t i = 0; i < new_size; ++i)
    {
        b[i] = str[i];
    }
    delete [] str;
    str = 0;
    return b;
}