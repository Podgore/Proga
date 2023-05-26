#include <iostream>
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

