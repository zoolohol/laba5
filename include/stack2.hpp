//Copyright 2019 <LinkIvan333>

#ifndef INCLUDE_HEADER2_HPP_
#define INCLUDE_HEADER2_HPP_
#include <memory>
#include <iostream>
template <typename T>
class stack2
{
private:
    unsigned int *size=new unsigned int;
    std::unique_ptr<T> arr;
public:
    stack2();
    ~stack2();
    template <typename ... Args>
    void push_emplace(Args&&... value);
    void push(T&& value);
    void push(const T& value);
    const T& head() const;
    void pop();
};

template<typename T>
stack2<T>::stack2() {
    *size = 0;
    arr.reset(new T[*size]);
}
template<typename T>
stack2<T>::~stack2(){
    delete size;
    arr.reset();
}
template<typename T>
template <typename ... Args>
void stack2<T>::push_emplace(Args&&... value){
   T args[]={value...};
for (auto e : args)
    this->push(e);
}

template <typename T>
void stack2<T>::pop() {
    if (*size == 0) {
        std::cout << "Массив пуст";
        return;
    }
    (*size)--;
    std::unique_ptr<T> new_arr(new T[*size]);
    for (unsigned int i = 0; i < *size; ++i){
        new_arr.get()[i]  =  arr.get()[i];
    }
    arr.swap(new_arr);
    new_arr.reset();
}

template <typename T>
const T& stack2<T>::head() const{
    return arr.get()[*size - 1];
}

template <typename T>
void stack2<T>::push(const T& value) {
    (*size)++;
    std::unique_ptr<T> new_arr(new T[*size]);
    for (unsigned int i = 0; i < (*size-1); ++i){
        new_arr.get()[i] = arr.get()[i];
    }
    new_arr.get()[*size-1] = value;
    arr.swap(new_arr);
    new_arr.reset();
}

template <typename T>
void stack2<T>::push(T&& value) {
    size++;
    std::unique_ptr<T> new_arr(new T[*size]);
    for (unsigned int i = 0; i < (*size-1); ++i){
        new_arr.get()[i] = arr.get()[i];
    }
    new_arr.get()[*size-1] = std::move(value);
    arr.swap(new_arr);
    new_arr.reset();
}


#endif // INCLUDE_HEADER2_HPP_
