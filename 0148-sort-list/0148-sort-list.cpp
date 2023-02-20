/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

//approach one - sorting using merge sort

class Solution {
    private:
    ListNode* middleLinkedList(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while( fast -> next != NULL && fast -> next -> next != NULL )
        {
            slow = slow -> next;
            fast = fast -> next-> next;
            
        }
        return slow;
    }

    ListNode* mergeLinkedList(ListNode* first , ListNode* second )
    {
        // edge case
        if( first == NULL )
            return second ;
        if( second == NULL )
            return first ;
        
        ListNode *ans= new ListNode(-1);
        
        ListNode *temp = ans;
        
        while( first!= NULL && second != NULL )
        {
            if( first->val < second -> val)
            {
                temp -> next = first;
                temp = first;
                first = first -> next;
                
            }
            else
            {
                temp -> next = second ;
                temp = second;
                second = second-> next;
            }
            
        }
        while( first != NULL )
        {
            temp -> next = first;
            temp = first;
            first = first -> next;
        }
        while(second != NULL )
        {
            temp -> next = second;
            temp = second;
            second = second -> next;
        }
        ans = ans-> next;
        return ans;
    }
    
public:
    ListNode* sortList(ListNode* head) {
        
        // base case
        if( head == NULL || head -> next == NULL )
            return head;
        
        // find middle node
        ListNode* middleNode = middleLinkedList(head);
        
        // initilize first and second node 
        ListNode* first = head;
        ListNode* second = middleNode->next;
        middleNode-> next = NULL;
        
        // call sorlist
        first = sortList(head);
        second = sortList(second);
        
        //merge two sorte linked list
        ListNode* ans = mergeLinkedList(first , second );
        
        return ans;
        
        
    }
};