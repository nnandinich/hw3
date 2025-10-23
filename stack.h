#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack: private std::vector<T>
{
public:
    //default ctor
    Stack() : std::vector<T>() {}
    //default dtor
    ~Stack() {}

    //checks if empty
    bool empty() const{
        return std::vector<T>::empty();
    }

    //checks size
    size_t size() const {
        return std::vector<T>::size();
    }

    //adds elements
    void push(const T& item){
        std::vector<T>::push_back(item);
    }

    //removes elements
    void pop() { // throws std::underflow_error if empty
        if (empty()==true){
            throw std::underflow_error("pop on empty stack");
        }
        else{
           std::vector<T>::pop_back();
        }
    }

    //finds top element
    const T& top() const { // throws std::underflow_error if empty
        if (empty()==true){
            throw std::underflow_error("top on empty stack");
        }
        else{
            return std::vector<T>::back();
        }
    }
    // Add other members only if necessary
};


#endif