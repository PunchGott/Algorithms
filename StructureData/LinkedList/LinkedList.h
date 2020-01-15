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

    inline const T& head() const;
    inline const T& tail() const;


    void show() const;
    inline size_t size() const;

    T& operator[](const size_t);
    const T& operator[](const size_t) const;
private:
    struct Node {
        explicit Node (const T& data = T{}) :
            m_data{data}, m_prev{nullptr}, m_next{nullptr} { }
        T m_data;
        Node *m_prev;
        Node *m_next;
    };

    Node *m_head, *m_tail;
    size_t SIZE;
};


template <typename T>
LinkedList<T>::LinkedList(const T& data) : SIZE{1}
{
    m_head = new Node{data};
    std::cout << "Constructor LinkedList\n" << "m_head = " << m_head
    << "\nm_data = " << m_head->m_data << "\nm_prev = " <<
       m_head->m_prev << "\nm_next = " << m_head->m_next << std::endl;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    while(SIZE)
    {
        pop_front();
    }
}

template <typename T>
void LinkedList<T>::push_back(const T& t)
{
    Node *current = m_head;
    while(current->m_next != nullptr)
    {
        current = current->m_next;
    }
    current->m_next = new Node{t};
    m_tail = current->m_next;
    m_tail->m_prev = current;
    SIZE++;
}

template <typename T>
void LinkedList<T>::pop_front()
{
    Node *temp = m_head;
    m_head = temp->m_next;
    SIZE--;
    delete temp;
}

template <typename T>
const T& LinkedList<T>::head() const
{
    return m_head->m_data;
}

template <typename T>
const T& LinkedList<T>::tail() const
{
    return m_tail->m_data;
}



template <typename T>
void LinkedList<T>::show() const
{
    Node *current = m_head;
    while(current != nullptr)
    {
        std::cout << "current = " << current << "\ncurrent->m_data = "
                  << current->m_data << "\ncurrent->m_prev = "
                  << current->m_prev << "\ncurrent->m_next = "
                  << current->m_next << std::endl;
        current = current->m_next;
    }
}

template <typename T>
size_t LinkedList<T>::size() const
{
    return SIZE;
}

template <typename T>
T& LinkedList<T>::operator[](const size_t index)
{
    return const_cast<T&>(static_cast<const LinkedList&>(*this)[index]);
}

template <typename T>
const T& LinkedList<T>::operator[](const size_t index) const
{
    if (index < 0 || index >= SIZE)
        throw "Out of range on LinkedList";
    Node *temp = m_head;
    if (index == 0) return temp->m_data;
    size_t count = 0;
    while(temp->m_next != nullptr)
    {
        if (count == index)
            return temp->m_data;
        count++;
        temp = temp->m_next;
    }
}



