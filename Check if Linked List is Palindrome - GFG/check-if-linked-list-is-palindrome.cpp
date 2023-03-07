//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
  
    //Function to reverse a linked list
    Node* reverseList(Node* head){
        if(!head || !(head->next))
            return head;
        
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        
        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        if(!head || !(head->next)){
            return true;
        }
        
        Node* slow = head;
        Node* fast = head->next;
        
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        Node* mid = slow;
        Node* left = head;
        Node* right = mid->next;
        mid->next = NULL;
        
        right = reverseList(right);
        
        while(left!=NULL && right!=NULL){
            if(left->data != right->data)
                return false;
            left = left->next;
            right = right->next;
        }
        
        return true;
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends