#include <cstddef>

template <typename T>
class Array
{
public:
	explicit Array(size_t size = 0, const T& value = T());
	Array(const Array& other);
	~Array();
	Array& operator=(Array other);
	void swap(Array &other);
	size_t size() const;
	T& operator[](size_t idx);
	const T& operator[](size_t idx) const;

private:
	size_t size_;
	T *data_;
};

// put your code here
template<typename Type,
         typename Cmp>
Type minimum(const Array<Type> object, Cmp fun){
    Type temp = object[0];
    for (size_t i = 0; i < object.size(); ++i)
        fun(temp, object[i]) ? temp : temp = object[i];
    return temp;
}