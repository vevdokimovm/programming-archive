void strcat(char *to, const char *from)
{
    unsigned str1_size = 0;
    for (; *to != '\0'; ++to)
        str1_size++;
    unsigned str2_size = 0;
    for (; *from != '\0'; ++from)
        str2_size++;
    from -= str2_size;
    for (; str2_size > 0; str2_size--)
    {
        *to = *from;
        from++;
        to++;
    }
    *to = '\0';
}