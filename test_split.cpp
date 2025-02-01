/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>

void printList(Node* head) {
    if (head != nullptr) {
        std::cout << head->value << " ";
        if (head->next != nullptr) {
            printList(head->next);
        }
    }
}

void freeList(Node* head) {
    if (!head)
        return;
    freeList(head->next);
    delete head;
}

int main(int argc, char* argv[])
{
    // Test case 1: Empty list
    Node* in1 = nullptr;
    Node* odds1 = nullptr;
    Node* evens1 = nullptr;
    split(in1, odds1, evens1);
    std::cout << "Test case 1 -\nOdds: ";
    printList(odds1);
    std::cout << std::endl << "Evens: ";
    printList(evens1);
    std::cout << std::endl;

    // Test case 2: Single element (odd)
    Node* in2 = new Node(1, nullptr);
    Node* odds2 = nullptr;
    Node* evens2 = nullptr;
    split(in2, odds2, evens2);
    std::cout << "Test case 2 -\nOdds: ";
    printList(odds2);
    std::cout << std::endl << "Evens: ";
    printList(evens2);
    std::cout << std::endl;

    // Test case 3: Single element (even)
    Node* in3 = new Node(2, nullptr);
    Node* odds3 = nullptr;
    Node* evens3 = nullptr;
    split(in3, odds3, evens3);
    std::cout << "Test case 3 -\nOdds: ";
    printList(odds3);
    std::cout << std::endl << "Evens: ";
    printList(evens3);
    std::cout << std::endl;

    // Test case 4: Multiple elements
    Node* in4 = new Node(1, new Node(2, new Node(3, new Node(4, nullptr))));
    Node* odds4 = nullptr;
    Node* evens4 = nullptr;
    split(in4, odds4, evens4);
    std::cout << "Test case 4 -\nOdds: ";
    printList(odds4);
    std::cout << std::endl << "Evens: ";
    printList(evens4);
    std::cout << std::endl;

    // Test case 5: All odds
    Node* in5 = new Node(1, new Node(3, new Node(5, nullptr)));
    Node* odds5 = nullptr;
    Node* evens5 = nullptr;
    split(in5, odds5, evens5);
    std::cout << "Test case 5 -\nOdds: ";
    printList(odds5);
    std::cout << std::endl << "Evens: ";
    printList(evens5);
    std::cout << std::endl;

    // Test case 6: All evens
    Node* in6 = new Node(2, new Node(4, new Node(6, nullptr)));
    Node* odds6 = nullptr;
    Node* evens6 = nullptr;
    split(in6, odds6, evens6);
    std::cout << "Test case 6 -\nOdds: ";
    printList(odds6);
    std::cout << std::endl << "Evens: ";
    printList(evens6);
    std::cout << std::endl;

    freeList(evens1);
    freeList(odds1);
    freeList(evens2);
    freeList(odds2);
    freeList(evens3);
    freeList(odds3);
    freeList(evens4);
    freeList(odds4);
    freeList(evens5);
    freeList(odds5);
    freeList(evens6);
    freeList(odds6);

    return 0;
}
