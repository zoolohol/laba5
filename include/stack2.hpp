//Copyright 2019 <LinkIvan333>

#ifndef INCLUDE_STACK2_HPP_
#define INCLUDE_STACK2_HPP_
#include <memory>
#include <iostream>
#include <utility>
#include <type_traits>
#include <exception>
template <typename T>
class stack2
{
    protected:
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
    template <typename ... Args>
    void push_emplace(Args&& ... value) {
        auto node = Stack<T>::head;
        Stack<T>::head = new typename
                Stack<T>::Node{std::forward<Args>(value)..., node};
    }

    T pop() {
        if (Stack<T>::head) {
            auto node = Stack<T>::head->data;
            Stack<T>::head = Stack<T>::head->next;
            return node;
        } else {
            throw std::exception();
        }
    }
};


#endif // INCLUDE_STACK2_HPP_
