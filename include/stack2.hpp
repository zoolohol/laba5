//Copyright 2019 <LinkIvan333>

#ifndef INCLUDE_HEADER2_HPP_
#define INCLUDE_HEADER2_HPP_
#pragma once
#include <memory>
#include <iostream>
template <typename T>
class stack2
{
private:
    unsigned int size;
    std::unique_ptr<T> arr;
public:
    stack2();
    template <typename ... Args>
    void push_emplace(Args&&... value);
    void push(T&& value);
    void push(const T& value);
    const T& head() const;
    void pop();
};

template<typename T>
stack2<T>::stack2() {
    this->size = 0;
    this->arr.reset(new T[this->size]);
}

template<typename T>
template <typename ... Args>
void stack2<T>::push_emplace(Args&&... value){
    T args[]={value...};
for (const auto& e:args)
    this->push(e);
}

template <typename T>
void stack2<T>::push(const T& value) {
    this->size++;
    std::unique_ptr<T> new_arr(new int[this->size]);
    for (unsigned int i = 0; i < (this->size-1); i++){
        new_arr.get()[i] = arr.get()[i];
    }
    new_arr.get()[this->size-1] = value;
    this->arr.swap(new_arr);
    new_arr.release();
}

template <typename T>
void stack2<T>::pop() {
    if (this->size == 0) {
        std::cout << "Массив пуст";
        return;
    }
    this->size--;
    std::unique_ptr<T> new_arr(new int[this->size]);
    for (unsigned int i = 0; i < this->size; i++){
        new_arr.get()[i] = this->arr.get()[i];
    }
    this->arr.swap(new_arr);
    new_arr.release();
}

template <typename T>
const T& stack2<T>::head() const{
    return this->arr.get()[this->size-1];
}

template <typename T>
void stack2<T>::push(T&& value) {
    this->size++;
    std::unique_ptr<T> new_arr(new int[this->size]);
    for (unsigned int i = 0; i < (this->size-1); i++){
        new_arr.get()[i] = arr.get()[i];
    }
    new_arr.get()[this->size-1] = std::move(value);
    this->arr.swap(new_arr);
    new_arr.release();
}

#endif // INCLUDE_HEADER2_HPP_
