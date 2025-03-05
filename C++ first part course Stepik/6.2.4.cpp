struct ICloneable;

template <typename T>
struct ValueHolder;


class Any
{
public:
    Any()
        : object(0) {}

    template <typename T>
    Any(T value)
        : object(new ValueHolder<T>(value)) {}

    ~Any () { delete object; }

    Any(const Any& any)
        : object(any.object ? any.object->clone() : any.object) {}

    void swapper(Any & any){
        std::swap(object, any.object);
    }
    Any& operator=(Any const& any){
        Any(any).swapper(*this);
        return *this;
    }
    template<typename T>
    Any& operator=(T const& any){
        delete object;
        object = new ValueHolder<T>(any);
        return *this;
    }

    template <class T>
    T* cast(){
        ValueHolder<T>* ptr = dynamic_cast<ValueHolder<T>*>(object);
        return (ptr ? &ptr->data_ : NULL);
    }

private:
    ICloneable* object;
};