template<typename T
        , class V>
bool compare(T const& a, T const& b, V (T::*mptr)() const)
{
    return (a.*mptr)() < (b.*mptr)();
}