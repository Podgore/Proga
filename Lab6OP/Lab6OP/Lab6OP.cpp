#include <iostream>
#include "Binar.h"
#include "Binar.cpp"


using namespace std;

int main()
{
    BinaryTree<int> tree;
    while (true) {
        int choice = 0;
        int value = 0;
        cout << "What do you want to do?" << endl;
        cout << "1 - Add new value" << endl;
        cout << "2 - Get size of binary tree" << endl;
        cout << "3 - Show tree content(using an iterator)" << endl;
        cout << "4 - Clear tree" << endl;
        cout << "5 - Exit" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1: 
            cout << "Type Value" << endl;
            cin >> value;
            tree.Push(value);
            continue;
        case 2:
            cout << "Tree size: " << tree.GetSize() << endl;
            continue;
        case 3:
            cout << "Tree contents: ";
            for (auto it = tree.begin(); it != tree.end(); ++it) {
                cout << *it << " ";
            }
            cout << endl;
            continue;
        case 4:
            tree.Clear();
            continue;
        case 5:
            return 0;
        }

    }
    
    
    
    


    return 0;
}



