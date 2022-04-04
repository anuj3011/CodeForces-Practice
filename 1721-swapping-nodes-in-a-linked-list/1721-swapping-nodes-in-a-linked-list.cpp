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
    ListNode* swapNodes(ListNode* head, int k) 
    {
        ListNode *first;
        ListNode *p=head;
        
        while(--k) p=p->next;            // loop run k-1 times
        
        first=p;
        ListNode *second=head;
        while(p->next)
        {
            p=p->next;
            second=second->next;
        }
        swap(first->val,second->val);
        return head;
        
    }
};