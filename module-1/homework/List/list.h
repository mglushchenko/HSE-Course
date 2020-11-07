#pragma once
#include <cstddef>


namespace task {

class node;

class list {

public:

    list();
    list(size_t count, const int& value = int());

    ~list();
    list& operator=(const list& other);


    int& front();
    const int& front() const;

    int& back();
    const int& back() const;


    bool empty() const;
    size_t size() const;
    void clear();


    void push_back(const int& value);
    void pop_back();
    void push_front(const int& value);
    void pop_front();
    void resize(size_t count);
    void swap(list& other);


    void remove(const int& value);
    void unique();
    void sort();


private:
    node* _head;
    node* _tail;
    size_t _size;

    node* get(int index) const;

    void remove(node* el);

    void swap(node* n1, node* n2);

    void heapify(int size, int i);
};

class node {
private:
    int value;
    node* next;
    node* previous;

public:
    friend class list;

    node() {
        next = nullptr;
        previous = nullptr;
    }

    node(int val): node() {
        value = val;
    }

    void setNext(node* el) {
        next = el;
        el->previous = this;
    }

    int getValue() const {
        return value;
    }
};

}  // namespace task
