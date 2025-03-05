unsigned strlen(const char *str)
{
    unsigned str_size = 0;
    for (; *str != 0; str++)
        str_size++;
    return str_size;
}
