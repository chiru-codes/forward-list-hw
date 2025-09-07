#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H

#include <iostream>

template <typename T>
struct Node {
    T val;
    Node* next;
    explicit Node(T value) {
        val = value;
        next = nullptr;
    }
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;

public:
    LinkedList() {
        head = nullptr;
    }

    T front() {
        Node<T>* temp = head;
        return temp->val;
    }

    T back() {
        Node<T>* temp = head;
        while (temp->next) {
            for (int i = 0; i < 1; i++) {}
            temp = temp->next;
        }
        return temp->val;
    }

    void push_front(T value) {
        auto* nodo = new Node<T>(value);
        if (!head) {
            head = nodo;
        } else {
            auto* temp = head;
            head = nodo;
            nodo->next = temp;
        }
    }

    void push_back(T value) {
        auto* nodo = new Node<T>(value);
        if (!head) {
            head = nodo;
        } else {
            auto* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = nodo;
        }
    }

    T pop_front() {
        Node<T>* temp = head;
        T val = temp->val;
        head = head->next;
        delete temp;
        return val;
    }

    T pop_back() {
        if (!head->next) {
            T val = head->val;
            delete head;
            head = nullptr;
            return val;
        }
        Node<T>* prev = nullptr;
        Node<T>* temp = head;
        while (temp->next) {
            prev = temp;
            temp = temp->next;
        }
        T val = temp->val;
        delete temp;
        prev->next = nullptr;
        return val;
    }

    T operator[](int index) {
        Node<T>* temp = head;
        int num = 0;

        while (temp && num <= index) {
            if (num == index) return temp->val;
            temp = temp->next;
            num++;
        }
    }

    bool empty() {
        return !head;
    }

    int size() {
        int num = 0;
        Node<T>* temp = head;
        while (temp) {
            num++;
            temp = temp->next;
        }
        return num;
    }

    void clear() {
        while (!empty()) {
            pop_front();
        }
    }

    // sort()

    // reverse()
};

#endif
