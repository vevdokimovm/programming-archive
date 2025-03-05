#include <iostream>
#include <set>
#include <vector>

int main() 
{
	int n = 0;
	std::cin >> n;
	std::set<int> books;
	int book = 0;
	for (int i = 0; i < n; ++i)
	{
		std::cin >> book;
		books.insert(book);
	}

	std::vector<int> US_books;
	for (auto book : books)
	{
		US_books.push_back(book);
	}


	bool flag = false;
	for (int i = 0; i < US_books.size(); ++i)
	{
		if (i == 0)
		{
			std::cout << US_books[0] << ' ';
		}
		else if (i == n - 1)
		{
			std::cout << US_books[US_books.size() - 1] << ' ' << std::endl;
		}
		else 
		{
			if (US_books[i] == US_books[i - 1] + 1 &&
				US_books[i] == US_books[i + 1] - 1)
			{
				if (flag == false) {
					std::cout << "..." << ' ';
					flag = true;
				}

			}
			else {
				std::cout << US_books[i] << ' ';
				flag = false;
			}
		}
	}
	std::cout << std::endl;

	// for (auto book : books)
	// {
	// 	std::cout << book << ' ';
	// }
	// std::cout << std::endl;
	// for (auto book : US_books)
	// {
	// 	std::cout << book << ' ';
	// }
	return 0;
}



