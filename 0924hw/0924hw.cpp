#include <iostream>
#include <exception>

using namespace std;

class SinglyLinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node(int val) {
            data = val;
            next = nullptr;
        }
    };

    Node* _head;
    int _size;

public:
    SinglyLinkedList() {
        _head = nullptr;
        _size = 0;
    }

    ~SinglyLinkedList() {
        Clear();
    }

    void PushFront(int val) {
        Node* newNode = nullptr;
        try {
            newNode = new Node(val);
        }
        catch (const bad_alloc& e) {
            throw;
        }
        newNode->next = _head;
        _head = newNode;
        _size++;
    }

    void PopFront() {
        if (_head == nullptr) {
            throw underflow_error("List is empty");
        }
        Node* temp = _head;
        _head = _head->next;
        delete temp;
        _size--;
    }

    int GetFront() const {
        if (_head == nullptr) {
            throw underflow_error("List is empty");
        }
        return _head->data;
    }

    bool IsEmpty() const {
        return _head == nullptr;
    }

    int GetSize() const {
        return _size;
    }

    void Clear() {
        while (_head != nullptr) {
            Node* temp = _head;
            _head = _head->next;
            delete temp;
        }
        _size = 0;
    }
};