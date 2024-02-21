#include<memory>
template<class T,class Alloc=std::allocator<T>>
class vector2_9
{
public:
    typedef T value_type;
    typedef T* iterator;
    typedef T& reference;
    typedef size_t size_type;
protected:
    size_type size;
    iterator start;
    iterator finish;
    iterator end_of_storage;
public:
    ...
};
