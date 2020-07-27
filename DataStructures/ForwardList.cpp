#include "ForwardList.h"
#include <stdexcept>

ForwardList::ForwardList() :
    head(nullptr), tail(nullptr) {}

ForwardList::~ForwardList() {
    freeMemory();
}

ForwardList::ForwardList(const ForwardList &other) :
    head(nullptr), tail(nullptr) {
    copyFromOther(other);
}

ForwardList& ForwardList::operator=(const ForwardList &rhs) {
    if(this != &rhs) {
        freeMemory();
        copyFromOther(rhs);
    }
    return *this;
}

ForwardList::ForwardList(ForwardList &&other) {
    head = other.head;
    tail = other.tail;
    other.head = other.tail = nullptr;
}

ForwardList::ForwardList(std::initializer_list<int> initList) :
    head(nullptr), tail(nullptr) {
    copyFromInitList(initList);
}

ForwardList& ForwardList::operator=(std::initializer_list<int> initList) {
    freeMemory();
    copyFromInitList(initList);
    return *this;
}

bool ForwardList::empty() const {
    return head == nullptr;
}

void ForwardList::push_front(const int &value) {
    Node *n = new Node(value);
    n->next = head;
    head = n;
    if(tail == nullptr)
        tail = head;
}

void ForwardList::pop_front() {
    if(head == nullptr)
        throw std::runtime_error("pop_front from empty ForwardList");
    Node *n = head;
    head = head->next;
    delete n;
    if(head == nullptr)
        tail = nullptr;
}

void ForwardList::push_back(const int &value) {
    Node *n = new Node(value);
    if(tail == nullptr)
        head = tail = n;
    else {
        tail->next = n;
        tail = n;
    }
}

void ForwardList::pop_back() {
    if(head == nullptr)
        throw std::runtime_error("pop_back from empty ForwardList");
    if(head == tail) {
        Node *n = head;
        head = tail = nullptr;
        delete n;
    }
    else {
        Node *current = head;
        while(current->next->next) {
            current = current->next;
        }
        Node *n = current->next;
        current->next = nullptr;
        tail = current;
        delete n;
    }
}

int& ForwardList::operator[](size_t index) {
    return getNodeAtIndex(index)->value;
}

const int& ForwardList::operator[](size_t index) const {
    return getNodeAtIndex(index)->value;
}

ForwardList::ForwardListIterator ForwardList::begin() {
    return ForwardListIterator(head);
}

ForwardList::ForwardListIterator ForwardList::end() {
    return ForwardListIterator(nullptr);
}

const ForwardList::ForwardListIterator ForwardList::begin() const {
    return ForwardListIterator(head);
}

const ForwardList::ForwardListIterator ForwardList::end() const {
    return ForwardListIterator(nullptr);
}

ForwardList::Node::Node(const int &newValue, Node *newNext) :
    value(newValue), next(newNext) {}

ForwardList::Node::~Node() {}

ForwardList::ForwardListIterator::ForwardListIterator(Node *n) :
    node(n) {}

ForwardList::ForwardListIterator& ForwardList::ForwardListIterator::operator++() {
    if(node == nullptr)
        throw std::runtime_error("increment past end of ForwardListIterator");
    node = node->next;
    return *this;
}

ForwardList::ForwardListIterator ForwardList::ForwardListIterator::operator++(int) {
    if(node == nullptr)
        throw std::runtime_error("increment past end of ForwardListIterator");
    ForwardListIterator source = *this;
    node = node->next;
    return source;
}

bool ForwardList::ForwardListIterator::operator==(ForwardListIterator rhs) const {
    return this->node == rhs.node;
}

bool ForwardList::ForwardListIterator::operator!=(ForwardListIterator rhs) const {
    return this->node != rhs.node;
}

int& ForwardList::ForwardListIterator::operator*() {
    if(this->node == nullptr)
        throw std::runtime_error("dereferencing of end ForwardListIterator");
    return this->node->value;
}

const int& ForwardList::ForwardListIterator::operator*() const {
    if(this->node == nullptr)
        throw std::runtime_error("dereferencing of end ForwardListIterator");
    return this->node->value;
}

ForwardList::Node* ForwardList::getNodeAtIndex(size_t index) const {
    Node *current = head;
    while(index--)
        current = current->next;
    return current;
}

void ForwardList::freeMemory() {
    while(head) {
        Node *n = head;
        head = head->next;
        delete n;
    }
    head = tail = nullptr;
}

void ForwardList::copyFromOther(const ForwardList &other) {
    if(!other.empty()) {
        head = new Node(other.head->value);
        Node *current = head;
        Node *otherNode = other.head->next;
        while(otherNode) {
            current->next = new Node(otherNode->value);
            current = current->next;
            otherNode = otherNode->next;
        }
        tail = current;
    }
}

void ForwardList::copyFromInitList(std::initializer_list<int> initList) {
    auto initListIter = initList.begin();
    if(initListIter != initList.end()) {
        head = new Node(*initListIter);
        Node *current = head;
        while(++initListIter != initList.end()) {
            current->next = new Node(*initListIter);
            current = current->next;
        }
        tail = current;
    }
}
