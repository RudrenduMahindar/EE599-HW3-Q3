#include "src/lib/solution.h"
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  int i=-1,n=0,p=2,x=6;
  vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  SinglyLinkedList s(v,i);
  s.print();
  if(s.empty())cout<<"empty"<<endl;
  else cout<<"not empty"<<endl;
  cout<<"nodes = "<<s.size()<<endl;
  s.push_front(n);
  s.print();
  s.pop_front();
  s.print();
  s.pop_back();
  s.print();
  cout<<"back="<<s.back()<<endl;
  cout<<"front="<<s.front()<<endl;
  ListNode* ptr=s.GetBackPointer();
  if(ptr!=nullptr)cout<<"backpointer->val = "<<ptr->val<<endl;
  ptr=s.GetIthPointer(p);
  if(ptr!=nullptr)cout<< p << "-Ithpointer->val = "<<ptr->val<<endl;
  ListNode *erase_node=s.GetIthPointer(x); //6th element val=6
  s.erase(erase_node);
  s.print();
  i=5;
  ListNode *insert_node=s.GetIthPointer(i); //positions of nodes in list is taken as: 1,2,3...  
  s.insert_after(insert_node,x);
  s.print();
  return EXIT_SUCCESS;
}