#include <iostream>
#include <stack>
#pragma once

using namespace std;

template<typename T>
class Node {
public:
    T data;
    Node* pLeft;
    Node* pRight;
    Node* pParent;
    Node(T data = T(), Node* pLeft = nullptr, Node* pRight = nullptr, Node* pParent = nullptr) {
        this->data = data;
        this->pLeft = pLeft;
        this->pRight = pRight;
        this->pParent = pParent;
    }
};

template<typename T>
class BinaryTree {
private:
    int Size;
    Node<T>* root;
public:
    class Iterator {
    private:

        Node<T>* current;

    public:
        Node<T>* GetCurrent()
        {
            return current;
        }
        void SetCurrent(Node<T>* node) {
            current = node;
        }

        Iterator(Node<T>* node = nullptr) : current(node) {}

        T& operator*()
        {
            return current->data;
        }


        Iterator& operator++()
        {
            if (current == nullptr) {
                return *this;
            }

            if (current->pParent == nullptr) {
                current = nullptr;
            }
            else if (current == current->pParent->pLeft && current->pParent->pRight != nullptr) {
                current = current->pParent->pRight;
                while (current->pLeft != nullptr || current->pRight != nullptr) {
                    if (current->pLeft != nullptr) {
                        current = current->pLeft;
                    }
                    else {
                        current = current->pRight;
                    }
                }
            }
            else {
                current = current->pParent;
            }

            return *this;
        }

        bool operator!=(const Iterator& other)
        {
            return current != other.current;
        }
    };

    BinaryTree();
    void Push(T data);
    void Clear();
    int GetSize() { return Size; }
    Iterator begin();
    Iterator end();
    void Print();
    void inOrderTraversal();
};