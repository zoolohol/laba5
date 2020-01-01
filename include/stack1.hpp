// Copyright 2018 Your Name <your_email>

#ifndef INCLUDE_HEADER1_HPP_
#define INCLUDE_HEADER1_HPP_
#pragma once
#include <memory>
#include <iostream>
template <typename T>
class stack1
{
private:
    unsigned int size;
    std::unique_ptr<T> arr;
public:
    void push(T&& value);
    void push(const T& value);
    void pop();
    const T& head() const;
    stack1();
    ~stack1();
};

template <typename T>
stack1<T>::stack1(){
    this->size=0;
    this->arr.reset(new T[this->size]);
}

template <typename T>
stack1<T>::~stack1(){
    this->size=0;
    this->arr.release();
}

template <typename T>
void stack1<T>::pop() {
    if(this->size == 0) {
        std::cout << "Массив пуст";
        return;
    }
    this->size--;
    std::unique_ptr<T> new_arr(new int[this->size]);
    for(unsigned int i=0;i<this->size;i++){
        new_arr.get()[i]=this->arr.get()[i];
    }
    this->arr.swap(new_arr);
    new_arr.release();
}

template <typename T>
const T& stack1<T>::head() const{
        return this->arr.get()[this->size - 1];
}

template <typename T>
void stack1<T>::push(const T& value) {
this->size++;
 std::unique_ptr<T> new_arr(new int[this->size]);
 for(unsigned int i=0;i < (this->size-1);i++){
     new_arr.get()[i]=arr.get()[i];
 }
 new_arr.get()[this->size-1]=value;
 this->arr.swap(new_arr);
 new_arr.release();
}

template <typename T>
void stack1<T>::push(T&& value) {
    this->size++;
    std::unique_ptr<T> new_arr(new int[this->size]);
    for(unsigned int i=0;i < (this->size-1);i++){
        new_arr.get()[i]=arr.get()[i];
    }
    new_arr.get()[this->size-1]=std::move(value);
    this->arr.swap(new_arr);
    new_arr.release();
}

#endif // INCLUDE_HEADER1_HPP_
