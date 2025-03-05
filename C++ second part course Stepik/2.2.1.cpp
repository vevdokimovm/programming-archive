template<class T>
struct Array
{
    // все объявленные ниже методы уже реализованы
    explicit Array(size_t size = 0);
    Array(Array const& a);
    Array & operator=(Array const& a);
    ~Array();

    size_t size() const;
    T &         operator[](size_t i);
    T const&    operator[](size_t i) const;

    // реализуйте перемещающий конструктор
    Array (Array && array)
        : data_(array.data_),
          size_(array.size_){
              array.data_ = nullptr;
              array.size_ = 0;
          }
    // реализуйте перемещающий оператор присваивания
    Array& operator=(Array && array){
        if (this != &array){
            this->~Array();
            data_ = array.data_;
            size_ = array.size_;
            array.data_ = nullptr;
            array.size_ = 0;
        }
        return *this;
    }
    
private:    
    size_t  size_;
    T *     data_;    
};