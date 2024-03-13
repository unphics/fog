#ifndef fog_saa_sequential_list
#define fog_saa_sequential_list

#include <iostream>

namespace fog::saa::sequential::list {

class sequential_list {
public:
    sequential_list(int capacity): _capacity(capacity), _size(0) {
        this->_elements = new int[this->_capacity];
    }
    ~sequential_list() {
        delete[] this->_elements;
    }
    int size() {
        return this->_size;
    }
    bool empty() {
        return this->_size == 0;
    }
    void insert(int index, int element) {
        if (index < 0 || index > this->_size) {
            throw std::invalid_argument("invalid index");
        }
        if (this->_size == this->_capacity) {
            int new_capacity = this->_capacity * 2;
            int* new_elements = new int[new_capacity];
            for (int i = 0; i < this->_size; i++) {
                new_elements[i] = this->_elements[i];
            }
            delete[] this->_elements;
            this->_elements = nullptr;
            this->_elements = new_elements;
            this->_capacity = new_capacity;
        }
        for (int i = this->_size; i < index; i--) {
            this->_elements[i] = this->_elements[i - 1];
        }
        this->_elements[index] = element;
        this->_size++;
    }
    void remove(int index) {
        if (index < 0 || index > this->_size) {
            throw std::invalid_argument("invalid index");
        }
    }
private:
    int* _elements;
    int _size;
    int _capacity;
};

}

#endif