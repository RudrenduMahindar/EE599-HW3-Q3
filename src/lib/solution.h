#ifndef TEMPLATE_SOLUTION_H
#define TEMPLATE_SOLUTION_H

#include <string>
#include <vector>

struct ListNode{
  int val;
  ListNode *next;
  ListNode(int x):val(x),next(nullptr){}
};

class SinglyLinkedList {
public:
  SinglyLinkedList();
  SinglyLinkedList(const std::vector<int> &inputs, int i);
  ~SinglyLinkedList(); // destructor, cleans up
  bool empty();
  int size();
  void push_back(int i); // inserts at the back
  void push_front(int i);
  void insert_after(ListNode* p, int i); // inserts value i after p
  void erase(ListNode* p); // Erases node p
  void pop_front(); // removes the first item
  void pop_back(); // removes the last item
  int back(); // returns the value of last item
  int front(); // returns the value of first item
  ListNode *GetBackPointer(); // Returns pointer to last item
  // Returns pointer to i(th) element
  ListNode *GetIthPointer(int i);
  // Prints the list: ex. Empty list: {}. List with items: {1, 2, 3}
  void print();
  ListNode *head_; // Pointer to the first element
};

#endif