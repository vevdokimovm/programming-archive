// Процедура переворачивает строку непосредственно в буфере
// Ограничение. Не использовать библиотечные функции.
// Пример.
// "Hello" -> "olleH"

void ReverseString(char * szBuffer)
{
	size_t i = 0;
	size_t len = 0;
	while (szBuffer[i] != '\0')
	{
		++len, ++i;
	}

	char * ans = new char[len + 1];

	// "Hello\0"
	// len = 5
	i = 0;
	while (len >= 0)
	{
		ans[i] = szBuffer[len - 1];
		++i, --len;
	}

	ans[i] = '\0';
	// int bar = 6;
	// int foo = bar++;
	for (size_t k = 0; k < len; ++k){
		szBuffer[k] = ans[k];
	}
	delete[] ans;

}

int main()
{
	char s[6] = "Hello";
	char * s1 = s;
	char & s2 = *s1;
	char * & s3 = s1;
	ReverseString(s1);
	std::cout << s << std::endl;
	return 0;
}