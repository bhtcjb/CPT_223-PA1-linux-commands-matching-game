// Blake Turman
#ifndef LINKED_LIST_TPP
#define LINKED_LIST_TPP

#ifndef LINKED_LIST_HPP
#error "LinkedList.tpp should only be included in LinkedList.hpp"
#endif


template <typename T>
inline LinkedList<T>::~LinkedList() {
    while (!isEmpty()) {
        Node<T>* temp = head;

        head = head->getNext();

        delete temp;
        temp = nullptr;
        --size;
    }
}

template <typename T>
inline const T& LinkedList<T>::peek() const {
    
    if (!isEmpty()) {
        return head->getData();
    }
    else {
        throw std::out_of_range("LinkedList<T>::peek() attempted to access data from empty list");
    }
    
}

template <typename T>
inline const T& LinkedList<T>::peek(const size_t& index) const {

    if (!isEmpty()) {
        Node<T>* curr = head;

        for (size_t i = 0; i < index && curr->getNext() != nullptr; ++i) {
            curr = curr->getNext();
        }

        return curr->getData();
    }
    else {
        throw std::out_of_range("LinkedList<T>::peek() attempted to access data from empty list");
    }
}

template <typename T>
inline bool LinkedList<T>::insert(const T& data) {

    Node<T>* newNode = new(std::nothrow) Node<T>(data);
    bool success = false;
    
    if (newNode != nullptr) {

        success = true;

        if (isEmpty()) {
            head = newNode;
        }
        else {
            newNode->setNext(head);
            head = newNode;
        }

        ++size;
    }

    return success;
}

template <typename T>
inline bool LinkedList<T>::insert(const T& data, const size_t& index) {

    Node<T>* newNode = new(std::nothrow) Node<T>(data);
    bool success = false;

    if (newNode != nullptr) {

        success = true;

        if (isEmpty()) {
            head = newNode;
        }
        else {
            Node<T>* curr = head,
                *prev = nullptr;

            for (size_t i = 0; i < index && curr != nullptr; ++i) {
                prev = curr;
                curr = curr->getNext();
            }

            if (prev == nullptr) {
                newNode->setNext(head);
                head = newNode;
            }
            else {
                newNode->setNext(curr);
                prev->setNext(newNode);
            }


        }

        ++size;

    }

    

    return success;

}

template <typename T>
inline T LinkedList<T>::remove() {

    if (!isEmpty()) {
        Node<T>* temp = head;

        T data = temp->getData();

        head = head->getNext();

        delete temp;
        temp = nullptr;
        --size;

        return data;
    }
    else {
        throw std::out_of_range("LinkedList<T>::remove() attempted to access data from empty list");
    }

}

template <typename T>
inline T LinkedList<T>::remove(const size_t& index) {

    if (!isEmpty()) {

        Node<T>* curr = head,
            *prev = nullptr;

        for (size_t i = 0; i < index && curr->getNext() != nullptr; ++i) {
            prev = curr;
            curr = curr->getNext();
        }

        if (prev == nullptr) {
            head = curr->getNext();
        }
        else {
            prev->setNext(curr->getNext());
        }

        T data = curr->getData();

        delete curr;
        curr = nullptr;
        --size;

        return data;
    }
    else {
        throw std::out_of_range("LinkedList<T>::remove() attempted to access data from empty list");
    }

}

template <typename T>
inline size_t LinkedList<T>::search(const T& data) const {
    size_t index = 0;
    bool found = false;

    for (Node<T>* curr = head; curr != nullptr && !found; curr = curr->getNext()) {
        if (curr->getData() == data) {
            found = true;
        }
        else {
            ++index;
        }
        
    }

    if (!found) {
        index = static_cast<size_t>(-1);
    }

    return index;
}

template <typename T>
template <typename M>
inline size_t LinkedList<T>::search(const M T::*member, const M& value) const {
    size_t index = 0;
    bool found = false;

    for (Node<T>* curr = head; curr != nullptr && !found; curr = curr->getNext()) {
        if (curr->getData().*member == value) {
            found = true;
        }
        else {
            ++index;
        }
    }

    if (!found) {
        index = static_cast<size_t>(-1);
    }

    return index;
}

template <typename T>
inline bool LinkedList<T>::printList() const {

    bool success = false;

    if (!isEmpty()) {
        success = true;

        for (Node<T>* curr = head; curr != nullptr; curr = curr->getNext()) {
            std::cout << curr->getData() << std::endl;
        }
    }

    return success;

}

#endif