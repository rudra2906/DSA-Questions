//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{

  private:
  //approach using slow and fast
  Node* middleLinkedList(Node* head)
  {
    Node* slow = head;
    Node* fast = head;
    
    while(fast -> next == NULL && fast -> next -> next != NULL )
    {
        slow = slow -> next ;
        fast = fast -> next -> next;
    }
    return slow;
  }
  
    Node* mergeTwoLists(Node* list1, Node* list2) {
        
        // edge case
        if(list1== NULL )
        {
            return list2;
        }
        if(list2 == NULL )
            return list1;
           
        Node* ans = new Node(-1);
        Node* temp = ans;
        Node* first = list1;
        Node* second = list2;
        
        // temp me add karwadenge jo chota node chota hoga aur usko aage barda denge        
        while(first != NULL && second != NULL )
        {
            if( first-> data < second -> data )
            {
                temp -> next = first ;
                temp = first;
                first = first -> next;
            }
            else
            {
                temp -> next = second;
                temp = second;
                second = second-> next;
            }
        }
        
        // second complete ho jaye or first bache
        while( first!= NULL )
        {
            temp -> next = first ;
            temp = first;
            first = first -> next;
        }
        
        // first complete ho jaye or secod bache srif to temp ke last me add karwdenge
        while(second!= NULL )
        {
            temp -> next = second;
            temp = second;
            second = second -> next;
        }
        
        ans = ans -> next;
        return ans;
    }
    
    
  public:
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        
        // base case
        if( head == NULL || head -> next == NULL )
            return head;
        
        // divide a head into two parts from middle node
        Node* middleNode = middleLinkedList(head); 
        
        // inititlize first from head till middle next and second from middle next till null 
        Node* first = head;
        Node* second = middleNode-> next;
        middleNode -> next = NULL;
        
        first = mergeSort(first);
        
        second = mergeSort(second);
        
        // merge 2 sorted linkedlist
        Node* ans = mergeTwoLists(first, second);
        
        return ans;
    }
};


//{ Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
// } Driver Code Ends