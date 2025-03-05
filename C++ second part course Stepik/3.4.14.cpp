#include <iostream>
#include <vector>
#include <list>

template<class T>
class VectorList
{
private:
	using VectT = std::vector<T>;
	using ListT = std::list<VectT>;

public:
	using value_type = T;

	VectorList() 				   = default;
	VectorList(VectorList const &) = default;
	VectorList(VectorList &&) 	   = default;

	VectorList & operator=(VectorList &&)      = default;
	VectorList & operator=(VectorList const &) = default;

	~VectorList() = default;

	// Конструктор для метода append
	VectorList(T * p, T * q) {}

	// Метод, который будет использоваться для заполнения VectorList
	// гарантирует, что в списке не будет пустых массивов
	template<class It>
	void append(It p, It q)
	{
		if (p != q) data_.push_back(VectT(p, q));
	}

	bool empty() const { return size() == 0; }

	size_t size() const
	{
		size_t size = 0;
		for (auto it = data_.begin(); it != data_.end(); ++it)
		{
			VectT vec = *it;
			size_t n = vec.size();
			for (size_t i = 0; i < n; ++i) ++size;
		}
		return size;
	}

	// ... const_iterator ...
	// const_iterator begin() const { return ...; }
	// const_iterator end() const { return ...; }

	// ... const_reverse_iterator ...

	// const_reverse_iterator rbegin() const { return ...; }
	// const_reverse_iterator rend() const { return ...; }

private:
	ListT data_;
	class const_iterator : public std::iterator<std::bidirectional_iterator_tag,
										 		T const,
										 		ptrdiff_t,
												T const *,
												T const &>
	{
	private: 
		using const_reverse_iterator = std::reverse_iterator<const_iterator>;

	public:
		const_iterator()   					   			   = default;
		const_iterator(const_iterator const &) 			   = default;
		const_iterator(const_iterator &&)      			   = default;
		const_iterator & operator=(const_iterator &&) 	   = default;
		const_iterator & operator=(const_iterator const &) = default;
		~const_iterator() 								   = default;


		const_iterator operator++(int);
		const_iterator & operator++();
		const_iterator operator--(int);
		const_iterator & operator--();
		bool operator!=(const_iterator const &) const;
		bool operator==(const_iterator const &) const;
		const_iterator & operator*() const;
		const_iterator * operator->() const;
	private:
		typename ListT::const_iterator itListT;
		typename VectT::const_iterator itVectT;
		ListT const * _data;
	};
};

int main(int argc, char * argv[])
{
	return 0;
}
