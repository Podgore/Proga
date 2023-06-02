#include <iostream>
#include <stack>
#include "Binar.h"


using namespace std;

template<typename T>
BinaryTree<T>::BinaryTree()
{
    Size = 0;
    root = nullptr;
}

template<typename T>
void BinaryTree<T>::Push(T data)
{
    Size++;
    if (root == nullptr) {
        root = new Node<T>(data, nullptr, nullptr);
        return;
    }
    Node<T>* current = this->root;
    while (true) {
        if (current->data < data) {
            if (current->pRight != nullptr) {
                current = current->pRight;
            }
            else {
                current->pRight = new Node<T>(data, nullptr, nullptr, current);
                break;
            }
        }
        else {
            if (current->pLeft != nullptr) {
                current = current->pLeft;
            }
            else {
                current->pLeft = new Node<T>(data, nullptr, nullptr, current);
                break;
            }
        }
    }
}

template<typename T>
void BinaryTree<T>::Print()
{
    if (root == nullptr) {
        cout << "Binary tree is empty." << endl;
        return;
    }

    stack<pair<Node<T>*, string>> nodesStack;
    nodesStack.push(make_pair(root, ""));

    while (!nodesStack.empty()) {
        pair<Node<T>*, string> current = nodesStack.top();
        nodesStack.pop();

        for (int i = 0; i < current.second.length(); i++) {
            cout << "  "; // Indentation for better visualization
        }

        cout << current.first->data << endl;

        if (current.first->pRight != nullptr) {
            nodesStack.push(make_pair(current.first->pRight, current.second + "  "));
        }
        if (current.first->pLeft != nullptr) {
            nodesStack.push(make_pair(current.first->pLeft, current.second + "  "));
        }
    }
}



template<typename T>
void BinaryTree<T>::Clear()
{
    if (root == nullptr) {
        return;
    }

    Iterator it = begin();
    while (it != end()) {
        Node<T>* current = it.GetCurrent();

        if (current->pLeft == nullptr && current->pRight == nullptr) {
            delete current;
            it.SetCurrent(nullptr);
            ++it;
        }
        else {
            ++it;
            if (current->pParent != nullptr) {
                if (current == current->pParent->pLeft) {
                    current->pParent->pLeft = it.GetCurrent();
                }
                else {
                    current->pParent->pRight = it.GetCurrent();
                }
            }
        }
    }
    delete root;
    cout << "Binary tree was clear" << endl;
    root = nullptr;
    Size = 0;
}

template<typename T>
typename BinaryTree<T>::Iterator BinaryTree<T>::begin() {
    Node<T>* current = root;
    while (current != nullptr && current->pLeft != nullptr) {
        current = current->pLeft;
    }
    return Iterator(current);
}

template<typename T>
typename BinaryTree<T>::Iterator BinaryTree<T>::end() {
    return Iterator(nullptr);
}