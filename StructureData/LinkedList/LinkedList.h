#pragma once

#include <iostream>
#include <exception>

template<typename T>
class LinkedList {
public:

    class Iterator {
        Iterator begin() const;
        Iterator end() const;
        bool operator==(const Iterator* it) const;
        bool operator!=(const Iterator* it) const;
        T operator*() const;
        void operator++();
        void operator--();
    };

    LinkedList(const T& = T{});
    ~LinkedList();

    void push_back(const T& = T{});
    void pop_front();

    inline T head() const;
    inline T tail() const;


    // Получить размер списка
    void show() const;
    inline size_t size() const;

    T& operator[](const size_t);
    T operator[](const size_t) const;
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

