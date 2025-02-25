#include "btree.hpp"
#include <iostream>

int main() {
    btree<int> tree;

    //tree
    tree.insert(8);
    tree.insert(4);
    tree.insert(55);
    tree.insert(1);
    tree.insert(7);
    tree.insert(16);
    tree.insert(87);
    tree.insert(2);
    tree.insert(9);
    tree.insert(64);
    tree.insert(99);

    std::cout << "Inorder Traversal: ";
    tree.inorder(std::cout);
    std::cout << "\n";

    std::cout << "Preorder Traversal: ";
    tree.preorder(std::cout);
    std::cout << "\n";

    std::cout << "Postorder Traversal: ";
    tree.postorder(std::cout);
    std::cout << "\n";

    std::cout << "Depth of 8: " << tree.findDepth(8) << "\n"; //should be 0
    std::cout << tree.find(8);
    std::cout << "Depth of 2: " << tree.findDepth(2) << "\n";   //should be 3
    std::cout << tree.find(2);
    std::cout << "Depth of 55: " << tree.findDepth(55) << "\n"; //should be 1
    std::cout << tree.find(55);
    std::cout << "Depth of 64: " << tree.findDepth(64) << "\n"; //should be 3
    std::cout << tree.find(64);
    std::cout << tree.find(200);

}