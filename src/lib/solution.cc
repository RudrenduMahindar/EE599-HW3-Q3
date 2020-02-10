#include "solution.h"
#include <vector>
#include <iostream>
using namespace std;

int SinglyLinkedList::size()
{
    ListNode* ptr=head_;
    int count_nodes=0;
    while(ptr!=nullptr)
    {
        count_nodes++;
        ptr=ptr->next;
    }
    return count_nodes;
}
bool SinglyLinkedList::empty()
{
    if(head_==nullptr)
        return true;
    else
        return false;
}
SinglyLinkedList::SinglyLinkedList(const std::vector<int> &inputs, int i)
{
    head_=nullptr;
    for(auto it=inputs.begin();it!=inputs.end();it++)
    {
       push_back(*it); 
    }
    if(i!=-1 || (i<=inputs.size()))
    {
        ListNode* ptr_end=GetBackPointer();
        ListNode* ptr_link=head_;
        i--;
        while(i>0)
        {
            ptr_link=ptr_link->next;
            i--;
        }
        ptr_end->next=ptr_link;
    }
}
void SinglyLinkedList::push_front(int i)
{
    ListNode* temp=new ListNode(i);
    temp->next=head_;
    head_=temp;
}
void SinglyLinkedList::insert_after(ListNode* p, int i)
{
    ListNode* new_item=new ListNode(i);
    ListNode* ptr=head_;
    ListNode* prev_ptr=nullptr; //if you take next ptr there may be a danger when next_ptr->next after ptr=nullptr i.e. the end
    while (ptr!=nullptr && ptr->val!=p->val)
    {
        prev_ptr=ptr;
        ptr=ptr->next;
    }
    if(ptr!=nullptr)
    {
        prev_ptr=ptr; //making prev_ptr current node after which new-node is inserted
        ptr=ptr->next;
        prev_ptr->next=new_item;
        new_item->next=ptr;
    }
}
void SinglyLinkedList::erase(ListNode* p)
{
    ListNode* ptr=head_;
    ListNode* prev_ptr=nullptr;
    while(ptr!=nullptr &&  ptr->val!=p->val)
    {
            prev_ptr=ptr;
            ptr=ptr->next;
    }
    if(ptr!=nullptr)
    {
        prev_ptr->next=ptr->next;
        delete ptr;
    }
}
void SinglyLinkedList::push_back(int i)
{
    ListNode* temp=new ListNode(i);
    if(head_==nullptr)
        head_=temp;
    else
    {
        ListNode* ptr=head_;
        while(ptr->next!=nullptr)
            ptr=ptr->next;
        ptr->next=temp;    
    }    
}
void SinglyLinkedList::pop_front()
{
    ListNode* temp=head_;
    if(!empty())
    {   
        head_=head_->next;
        delete temp;
    }
}
void SinglyLinkedList::pop_back()
{
    ListNode* temp=head_;
    ListNode* prev_temp=nullptr;
    if(!empty())
    {
        while(temp->next!=nullptr)
        {
            prev_temp=temp;
            temp=temp->next;
        }
        prev_temp->next=nullptr;
        delete temp;
    }    
}
int SinglyLinkedList::back()
{
    ListNode* ptr=head_;
    if(!empty())
    {
        while(ptr->next!=nullptr)
            ptr=ptr->next;
        return ptr->val;    
    }
    else
        return -1;
}
int SinglyLinkedList::front()
{
    if(!empty())
        return head_->val;
    else
        return -1;
}
ListNode* SinglyLinkedList::GetBackPointer()
{
    ListNode* ptr=head_;
    if(!empty())
    {
        while(ptr->next!=nullptr)
            ptr=ptr->next;
        return ptr;    
    }
    else
        return nullptr;
}
ListNode* SinglyLinkedList::GetIthPointer(int i)
{
    ListNode* ptr=head_;
    if(!empty())
    {   
        i--;
        while(i>0)
        {
            ptr=ptr->next;
            i--;
        }
        return ptr;
    }
    else
        return nullptr;
}
void SinglyLinkedList::print()
{
    ListNode* temp=head_;
    while(temp!=nullptr)
    {
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<"\n";
}