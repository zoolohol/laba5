//Copyright 2019 <LinkIvan333>

#ifndef INCLUDE_STACK1_HPP_
#define INCLUDE_STACK1_HPP_
#include <memory>
#include <iostream>
#include <type_traits>
#include <exception>
template <typename T>
class stack1
{
 struct Node {
        T data;
        Node *next;
    };
    Node *head;

public:
    Stack() = default;

    ~Stack() {
        while (head) {
            auto *act = head;
            head = act->next;
            delete act;
        }
    }

    void push(T&& value) {
        if (head == nullptr) {
            auto node = new Node{std::move(value), nullptr};
            head = node;
        } else {
            auto node = new Node{std::move(value), head};
            head = node;
        }
    }

    const T& Head() {
        if (!head)
            throw std::exception();
        return head->data;
    }
    void push(const T& value) {
        auto node = new typename Stack<T>::Node{value, Stack<T>::head};
        Stack<T>::head = node;
    }

    void pop() {
        if (Stack<T>::head)
            Stack<T>::head = Stack<T>::head->next;
        else
            throw std::exception();
    }
};

#endif // INCLUDE_STACK1_HPP_
