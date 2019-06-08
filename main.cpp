#include "binarySearchTree.h"
#include "binarySearchTree.cpp"
#include <iostream>

using namespace std;

int main()
{
    treeType<int> a;
    int val;
    bool found;

    cout << "......Task 1......\n" << endl;

    if(a.isEmpty())
        cout << "Tree is empty...!" << endl;
    else
        cout << "Tree is not empty...!" << endl;

    cout << "Insert ten items: " << endl;
    for(int i=0; i<10; i++)
    {
        cin >> val;
        a.insertItem(val);
    }

    if(a.isEmpty())
        cout << "Tree is empty...!" << endl;
    else
        cout << "Tree is not empty...!" << endl;

    cout << "\n......Task 2......\n" << endl;

    cout << "Length: " << a.lengthIs() << endl;

    cout << "Enter item to retrieve: ";
    cin >> val;
    a.retrieveItem(val, found);

    if(found)
        cout << "Item is found...!" << endl;
    else
        cout << "Item is not found...!" << endl;

    cout << "\n......Task 3......\n" << endl;

    a.resetTree(IN_ORDER);
    cout << "In Order: ";
    a.print();
    cout << endl;

    a.resetTree(PRE_ORDER);
    cout << "Pre Order: ";
    a.preOrderPrint();
    cout << endl;

    a.resetTree(POST_ORDER);
    cout << "Post Order: ";
    a.postOrderPrint();
    cout << endl;

    a.makeEmpty();

    cout << "\n......Task 4......\n" << endl;

    a.insertItem(8);
    a.insertItem(3);
    a.insertItem(10);
    a.insertItem(14);
    a.insertItem(13);
    a.insertItem(1);
    a.insertItem(6);
    a.insertItem(4);
    a.insertItem(7);

    cout << "Minimum: " << a.findMin() << endl;
    cout << "Maximum: " << a.findMax() << endl;
    cout << "Range Length: " << a.rangeLength() << endl;
    cout << "Number of leaves: " << a.numLeaves() << endl;
    cout << "Internal nodes: " << a.numInternalNodes() << endl;

    return 0;
}
