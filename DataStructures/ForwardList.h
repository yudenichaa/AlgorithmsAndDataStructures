#pragma once
#include <initializer_list>
#include <cstdlib>

class ForwardList {
private:
    struct Node {
        Node(const int &newValue, Node *newNext = nullptr);
        ~Node();
        int value;
        Node *next;
    };

public:
    class ForwardListIterator {
    public:
        ForwardListIterator(Node *n);
        ForwardListIterator(const ForwardListIterator &other) = default;
        ~ForwardListIterator() = default;
        ForwardListIterator& operator++();
        ForwardListIterator operator++(int);
        bool operator==(ForwardListIterator rhs) const;
        bool operator!=(ForwardListIterator rhs) const;
        int& operator*();
        const int& operator*() const;

    private:
        Node *node;
    };

public:
    ForwardList();
    ~ForwardList();
    ForwardList(const ForwardList &other);
    ForwardList& operator=(const ForwardList &rhs);
    ForwardList(ForwardList &&other);
    ForwardList(std::initializer_list<int> initList);
    ForwardList& operator=(std::initializer_list<int> initList);
    bool empty() const;
    void push_front(const int &value);
    void pop_front();
    void push_back(const int &value);
    void pop_back();
    int& operator[](size_t index);
    const int& operator[](size_t index) const;
    ForwardListIterator begin();
    ForwardListIterator end();
    const ForwardListIterator begin() const;
    const ForwardListIterator end() const;

private:
    Node* getNodeAtIndex(size_t index) const;
    void freeMemory();
    void copyFromOther(const ForwardList &other);
    void copyFromInitList(std::initializer_list<int> initList);

    Node *head;
    Node *tail;
};
