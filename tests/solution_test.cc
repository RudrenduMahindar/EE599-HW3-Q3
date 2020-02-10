#include "src/lib/solution.h"
#include "gtest/gtest.h"
#include <vector>
using namespace std;

TEST(Checkempty, Returnsfalse) {
  int i=-1;
  vector<int> v={1,2,3,4,5,6,7,8,9,10};
  SinglyLinkedList s(v,i);   
  bool actual = s.empty();
  bool expected = false;
  EXPECT_EQ(expected, actual);
}
TEST(Checksize, ReturnsTen) {
  int i=-1;
  vector<int> v={1,2,3,4,5,6,7,8,9,10};
  SinglyLinkedList s(v,i);   
  int actual = s.size();
  int expected = 10;
  EXPECT_EQ(expected, actual);
}
TEST(Checkpushback, ReturnsLisofElevenElements) {
  int i=-1,x=11;
  vector<int> v={1,2,3,4,5,6,7,8,9,10};
  SinglyLinkedList s(v,i);   
  s.push_back(x);
  i=1;
  ListNode* ptr=s.GetIthPointer(i);
  vector<int> v1;
  while(ptr!=nullptr)
  {
    v1.push_back(ptr->val);
    ptr=ptr->next;
  }
  v.push_back(11);
  vector<int> actual = v1;
  vector<int> expected = v;
  EXPECT_EQ(expected, actual);
}
TEST(Checkpushfront, ReturnsLisofElevenElements) {
  int i=-1,x=0;
  vector<int> v={1,2,3,4,5,6,7,8,9,10};
  SinglyLinkedList s(v,i);   
  s.push_front(x);
  i=1;
  ListNode* ptr=s.GetIthPointer(i);
  vector<int> v1;
  while(ptr!=nullptr)
  {
    v1.push_back(ptr->val);
    ptr=ptr->next;
  }
  v.insert(v.begin(),0);
  vector<int> actual = v1;
  vector<int> expected = v;
  EXPECT_EQ(expected, actual);
}
TEST(Checkinsertafter, ReturnsLisofElevenElements) {
  int i=-1,x=11;
  vector<int> v={1,2,3,4,5,6,7,8,9,10};
  SinglyLinkedList s(v,i);
  int pos=5;   
  ListNode* insert_pos=s.GetIthPointer(pos);
  s.insert_after(insert_pos,x);
  i=1;
  ListNode* ptr=s.GetIthPointer(i);
  vector<int> v1;
  while(ptr!=nullptr)
  {
    v1.push_back(ptr->val);
    ptr=ptr->next;
  }
  v.insert(v.begin()+pos,11);
  vector<int> actual = v1;
  vector<int> expected = v;
  EXPECT_EQ(expected, actual);
}
TEST(Checkerase, ReturnsLisofNineElements) {
  int i=-1,x=5;
  vector<int> v={1,2,3,4,5,6,7,8,9,10};
  SinglyLinkedList s(v,i);
  int pos=4;   
  ListNode* erase_node=new ListNode(x);
  s.erase(erase_node);
  i=1;
  ListNode* ptr=s.GetIthPointer(i);
  vector<int> v1;
  while(ptr!=nullptr)
  {
    v1.push_back(ptr->val);
    ptr=ptr->next;
  }
  v.erase(v.begin()+pos);
  vector<int> actual = v1;
  vector<int> expected = v;
  EXPECT_EQ(expected, actual);
}
TEST(Checkpop_front, ReturnsLisofNineElements) {
  int i=-1;
  vector<int> v={1,2,3,4,5,6,7,8,9,10};
  SinglyLinkedList s(v,i);
  s.pop_front();
  i=1;
  ListNode* ptr=s.GetIthPointer(i);
  vector<int> v1;
  while(ptr!=nullptr)
  {
    v1.push_back(ptr->val);
    ptr=ptr->next;
  }
  v.erase(v.begin());
  vector<int> actual = v1;
  vector<int> expected = v;
  EXPECT_EQ(expected, actual);
}
TEST(Checkpop_back, ReturnsLisofNineElements) {
  int i=-1;
  vector<int> v={1,2,3,4,5,6,7,8,9,10};
  SinglyLinkedList s(v,i);
  s.pop_back();
  i=1;
  ListNode* ptr=s.GetIthPointer(i);
  vector<int> v1;
  while(ptr!=nullptr)
  {
    v1.push_back(ptr->val);
    ptr=ptr->next;
  }
  v.erase(v.end()-1);
  vector<int> actual = v1;
  vector<int> expected = v;
  EXPECT_EQ(expected, actual);
}
TEST(Checkback, ReturnsTen) {
  int i=-1;
  vector<int> v={1,2,3,4,5,6,7,8,9,10};
  SinglyLinkedList s(v,i);   
  int actual = s.back();
  int expected = 10;
  EXPECT_EQ(expected, actual);
}
TEST(Checkfront, ReturnsOne) {
  int i=-1;
  vector<int> v={1,2,3,4,5,6,7,8,9,10};
  SinglyLinkedList s(v,i);   
  int actual = s.front();
  int expected = 1;
  EXPECT_EQ(expected, actual);
}
TEST(CheckGetBackPointer, ReturnsNodeValueTen) {
  int i=-1;
  vector<int> v={1,2,3,4,5,6,7,8,9,10};
  SinglyLinkedList s(v,i);   
  ListNode* ptr=s.GetBackPointer();
  int actual = ptr->val;
  int expected = 10;
  EXPECT_EQ(expected, actual);
}
TEST(CheckGetIthPointer, ReturnsNodeValueFour) {
  int i=-1;
  vector<int> v={1,2,3,4,5,6,7,8,9,10};
  SinglyLinkedList s(v,i);
  int pos=4;   
  ListNode* ptr=s.GetIthPointer(pos);
  int actual = ptr->val;
  int expected = 4;
  EXPECT_EQ(expected, actual);
}