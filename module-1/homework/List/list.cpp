#include <stdexcept>
#include "list.h"


namespace task {

list::list() {
    _head = nullptr;
    _tail = _head;
    _size = 0;
}

list::~list() {
    clear();
}

// constructs a list containing _count_ copies of _value_
list::list(size_t count, const int& value): list() {
    _head = new node(value);
    node* curr = _head;
    for (int i = 1; i < count; ++i) {
        node* next = new node(value);
        curr->setNext(next);
        curr = next;
    }
    _tail = curr;
    _size = count;
}

list& list::operator=(const list& other) {
    if (_head) delete _head;

    _head = new node(other._head->getValue());
    node* currSource = other._head->next;
    node* currDestination = _head;
    while (currSource) {
        node* next = new node(currSource->value);
        currDestination->setNext(next);

        currSource = currSource->next;
        currDestination = currDestination->next;
    }

    _tail = currDestination;
    _size = other.size();

    return *this;
}

size_t list::size() const {
    return _size;
}

int& list::front() {
    return _head->value;
}

const int& list::front() const {
    return _head->value;
}

int& list::back() {
    return _tail->value;
}

const int& list::back() const {
    return _tail->value;
}

bool list::empty() const {
    return _size == 0;
}

void list::push_back(const int& value) {
    node* next = new node(value);
    node* tmp = _tail;
    if (!tmp) {
        _head = next;
    }
    else {
        tmp->setNext(next);
    }
    _tail = next;
    ++_size;
}

void list::clear() {
    node* curr = _head;
    while (curr) {
        node* tmp = curr;
        curr = curr->next;
        delete tmp;
    }
    _size = 0;
}

void list::pop_back() {
    if (empty()) {
        throw std::logic_error("Can't pop from an empty list!");
    }
    if (_size == 1) {
        clear();
        return;
    }
    _tail = _tail->previous;
    delete _tail->next;
    --_size;
}

void list::push_front(const int& value) {
    node* newHead = new node(value);
    node* tmp = _head;
    if (!tmp) {
        _head = _tail = newHead;
    }
    else {
        newHead->setNext(_head);
        _head = newHead;
    }
    ++_size;
}

void list::pop_front() {
    if (empty()) {
        throw std::logic_error("Can't pop from an empty list!");
    }
    if (_size == 1) {
        clear();
        return;
    }
    _head = _head->next;
    delete _head->previous;
    --_size;
}

node* list::get(int index) const{
    if (index < 0 || index >_size) {
        throw std::invalid_argument("Index out of range");
    }
    if (empty()) {
        throw std::logic_error("List is empty!");
    }

    int count = 0;
    node* curr = _head;
    while (count < index) {
        curr = curr->next;
        ++count;
    }
    return curr;
}

// removes all elements equal to value
void list::remove(const int& value) {
    if (empty()) {
        throw std::logic_error("Can't remove from an empty list!");
    }

    node* curr = _head;
    while (curr) {
        node* tmp = curr->next;
        if (curr->value == value) {
            remove(curr);
            --_size;
        }
        curr = tmp;
    }
}

void list::remove(node* el) {
    el->previous->setNext(el->next);
    delete el;
}

// removes consecutive duplicate elements
void list::unique() {
    if (empty()) {
        throw std::logic_error("Can't remove from an empty list!");
    }

    node* curr = _head->next;
    int lastVal = _head->value;
    while (curr) {
        node* tmp = curr->next;
        if (curr->value == lastVal) {
            remove(curr);
        }
        else {
            lastVal = curr->value;
        }
        curr = tmp;
    }
}

void list::resize(size_t count) {
    if (count == 0) {
        clear();
        return;
    }

    if (count == _size) return;

    if (count < _size) {
        while (count < _size) {
            pop_back();
        }
    }
    else {
        while (count > _size) {
            push_back(0);
        }
    }
}


void list::swap(list &other) {
    node* tmp = _head;
    _head = other._head;
    other._head = tmp;

    int sz = _size;
    _size = other._size;
    other._size = sz;
}

void list::swap(node* n1, node* n2) {
    node* tmp = n2->next;
    n2->setNext(n1->next);
    n1->setNext(tmp);

    tmp = n2->previous;
    n1->previous->setNext(n2);
    tmp->setNext(n1);
}

void list::heapify(int size, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && get(left)->value > get(largest)->value) {
        largest = left;
    }
    if (right < size && get(right)->value > get(largest)->value) {
        largest = right;
    }

    if (largest != i) {
        swap(get(i), get(largest));
        heapify(size, largest);
    }
}

// implements heap sort
void list::sort() {
    for (size_t i = _size / 2 - 1; i >= 0; --i)
        heapify(_size, i);

    for (size_t i = _size - 1; i > 0; --i)
    {
        swap(get(0), get(i));
        heapify(i, 0);
    }
}


}
