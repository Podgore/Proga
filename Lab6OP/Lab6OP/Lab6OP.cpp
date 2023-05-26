#include <iostream>
#include "Binar.h"
#include "Binar.cpp"


using namespace std;

int main()
{
    BinaryTree<int> tree;
    tree.Push(50);
    tree.Push(48);
    tree.Push(49);
    tree.Push(23);
    tree.Push(60);
    tree.Push(55);
    
    cout << "Tree contents: ";
    for (auto it = tree.begin(); it != tree.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "Tree size: " << tree.GetSize() << endl;

    tree.Clear();

    return 0;
}



