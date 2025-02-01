/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

/* Add a prototype for a helper function here if you need */
void split_recursive(Node*& in, Node*& odds, Node*& evens, Node*& evenHead, Node*& oddHead);

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
    //Case 1: Empty List
    if(in == nullptr){
      return;
    }
    Node* evenHead = nullptr;
    Node* oddHead = nullptr;
    //Recursive Step
    split_recursive(in, odds, evens, evenHead, oddHead);
    //Clean-up dangling next pointers in certain scenarios:
    if (odds != nullptr && odds->next != nullptr) {
      odds->next = nullptr;
    }
    if (evens != nullptr && evens->next != nullptr) {
      evens->next = nullptr;
    }
    odds = oddHead;
    evens = evenHead;
  //At the end: we don't want in anymore.
  in=nullptr;
}

/* If you needed a helper function, write it here */
void split_recursive(Node*& in, Node*& odds, Node*& evens, Node*& evenHead, Node*& oddHead) {
  Node*& basis = (in->value % 2 == 0) ? evens : odds; //Checks if even, and operates on correct list.
  if ( basis != nullptr) { //List already started
    basis->next = in; //Add to next inlist
  } else {
    (&basis == &evens ? evenHead : oddHead) = in; // Else, start the list by pointing head
  }
  basis = in; //Update list pointer to new element
  if ( in->next != nullptr) {
    split_recursive(in->next, odds, evens, evenHead, oddHead);
  }
}
