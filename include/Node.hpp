// Blake Turman
#ifndef NODE_HPP
#define NODE_HPP

// template node class for a singly linked list
template <typename T>
class Node {
    public:
        // data default constructed, next set to nullptr
        Node() : data{}, next(nullptr) {}

        // input data, next set to nullptr
        Node(const T& data) 
            : data(data), next(nullptr) {}

        // returns data
        const T& getData() const { return data; }  
        
        // returns next pointer, return data is mutable for delete operation
        Node<T>* getNext() {  return next; }

        // sets next pointer to input, input data does not change
        void setNext(Node<T>* const& next) { this->next = next; }

    private:
        T data;
        Node<T>* next;
};


#endif