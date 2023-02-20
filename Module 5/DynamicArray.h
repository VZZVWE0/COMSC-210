//Prorgammer: Anna Felipe
//Programmer ID: 1506055

#ifndef DynamicArray_h
#define DynamicArray_h
template <typename T>
class DynamicArray
{
    T* value; 
    int cap;
    T dummy;

public:
    DynamicArray(int = 2); 
    DynamicArray(const DynamicArray<T>&);
    ~DynamicArray() { delete[] value; } 
    DynamicArray<T>& operator=(const DynamicArray<T>&); 
    int capacity() const { return cap; }
    void capacity(int); 
    T operator[ ] (int) const; 
    T& operator[ ] (int); 
};

template <typename T>
DynamicArray<T>::DynamicArray(int cap) 
{
    this->cap = cap;
    value = new T[cap];

    for (int i = 0; i < cap; i++)
        value[i] = T();
}

template <typename T>
T DynamicArray<T>::operator[ ] (int index) const 
{
    if (index < 0 || index >= cap) return dummy;
    return value[index];
}

template <typename T>
T& DynamicArray<T>::operator[ ] (int index) 
{
    if (index < 0) return dummy;
    if (index >= cap) capacity(2 * index);
    return value[index];
}

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& original)
{
    cap = original.cap; 
    value = new T[cap]; 
    for (int i = 0; i < cap; i++) 
        value[i] = original.value[i]; 
    dummy = original.dummy; 
}

template <typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& original)
{
    if (this != &original) 
    {
     
        delete[] value;

        cap = original.cap; 
        value = new T[cap]; 
        for (int i = 0; i < cap; i++) 
            value[i] = original.value[i]; 
        dummy = original.dummy;
    }
    return *this;
}

template <typename T>
void DynamicArray<T>::capacity(int cap)
{
    T* temp = new T[cap];
    int limit = cap < this->cap ? cap : this->cap;

    for (int i = 0; i < limit; i++)
        temp[i] = value[i];

    for (int i = limit; i < cap; i++)
        temp[i] = T();

    delete[] value;
    value = temp;
    this->cap = cap;
}

#endif
