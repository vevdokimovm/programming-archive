#include <cstddef>

struct Expression;
struct Number;
struct BinaryOperation;

struct SharedPtr
{
    explicit SharedPtr(Expression *ptr = 0)
        : _ptr(ptr), _counter(0) { if (_ptr) _counter = new size_t(1); }
    ~SharedPtr(){
        if (_ptr && --*_counter == 0)
            delete _ptr, delete _counter;
    }
    SharedPtr(const SharedPtr & sharedptr)
        : _ptr(sharedptr._ptr), _counter(sharedptr._counter) { if (_ptr) ++*_counter; }
    void swapper(SharedPtr & sharedptr){
        std::swap(_ptr, sharedptr._ptr);
        std::swap(_counter, sharedptr._counter);
    }
    SharedPtr& operator=(const SharedPtr & sharedptr){
        SharedPtr(sharedptr).swapper(*this);
        return *this;
    }


    Expression* get() const { return _ptr; }
    void reset(Expression *ptr = 0){
        SharedPtr(ptr).swapper(*this);
    }
    Expression& operator*() const { return *_ptr; }
    Expression* operator->() const { return _ptr; }
    Expression* _ptr;
    size_t* _counter;
};