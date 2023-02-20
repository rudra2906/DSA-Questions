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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        // edge case
        if(list1== NULL )
        {
            return list2;
        }
        if(list2 == NULL )
            return list1;
           
        ListNode* ans = new ListNode(-1);
        ListNode* temp = ans;
        ListNode* first = list1;
        ListNode* second = list2;
                
        while(first != NULL && second != NULL )
        {
            if( first-> val < second -> val )
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
        
        while( first!= NULL )
        {
            temp -> next = first ;
            temp = first;
            first = first -> next;
        }
        while(second!= NULL )
        {
            temp -> next = second;
            temp = second;
            second = second -> next;
        }
        
        ans = ans -> next;
        return ans;
    }
};