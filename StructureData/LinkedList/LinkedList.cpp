#include "LinkedList.h"


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
    if (Node *current = m_head) {
    while(current->m_next != nullptr)
    {
        current = current->m_next;
    }
    current->m_next = new Node{t};
    m_tail = current->m_next;
    SIZE++;
    }
}

template <typename T>
void LinkedList<T>::pop_front()
{
    if (Node *temp = m_head) {
    m_head = temp->m_next;
    delete temp;
    SIZE--;
    }
}

template <typename T>
T LinkedList<T>::head() const
{
    return m_head->m_data;
}

template <typename T>
T LinkedList<T>::tail() const
{
    return m_tail->m_data;
}



template <typename T>
void LinkedList<T>::show() const
{
    if (Node *current = m_head) {
    while(current != nullptr)
    {
        std::cout << "current = " << current << "\ncurrent->m_data = "
                  << current->m_data << "\ncurrent->m_prev = "
                  << current->m_prev << "\ncurrent->m_next = "
                  << current->m_next << std::endl;
        current = current->m_next;
    }
    delete current;
    }

}



