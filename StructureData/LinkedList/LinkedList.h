#pragma once

#include <iostream>

template<typename T>
class LinkedList {
public:

    class Iterator {

    };

    LinkedList(const T& = T{});
    ~LinkedList();

    void push_back(const T& = T{});
    void pop_front();

    T head() const;
    T tail() const;
//    Iterator begin() const;
//    Iterator end() const;

    // Получить размер списка
    void show() const;
    size_t size() const;
private:
    struct Node {
        explicit Node (const T& data = T{}) :
            m_data{data}, m_prev{nullptr}, m_next{nullptr} { }
        ~Node() { delete m_prev; delete m_next; }
        T m_data;
        Node *m_prev;
        Node *m_next;
    };

    Node *m_head, *m_tail;
    size_t SIZE;
};

