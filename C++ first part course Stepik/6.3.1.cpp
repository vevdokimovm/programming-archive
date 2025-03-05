// Определите шаблон SameType с двумя типовыми
// параметрами. В шаблоне должна быть определена
// одна статическая константа типа bool с именем
// value
template<typename T,
         typename V>
class SameType{
    public:
    static const bool value = false;
};

template<typename T>
class SameType<T, T>{
    public:static const bool value = true;
};