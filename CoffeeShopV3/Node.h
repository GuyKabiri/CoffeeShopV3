#ifndef __NODE_H__
#define __NODE_H__

T should have:
1 operator==
2 operator<<
3 default copy c'tor
*/
    Node& operator=(Node<T>&& other) = delete;


template <class T>
Node<T>::Node(T data)

Node<T>::Node(const Node<T>& other)

template <class T>
void Node<T>::setNext(Node<T>* node)