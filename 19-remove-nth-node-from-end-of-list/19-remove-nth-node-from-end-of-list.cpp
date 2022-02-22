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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        int size=0;
        while(temp){
            size++;
            temp=temp->next;
        }
        if(size==n){
            return head->next;
        }
        temp=head;
        n=size-n;
        size=0;
        while(temp){
            size++;
            if(size==n){
                temp->next=temp->next->next;
                break;
            }else
                temp=temp->next;
        }
        return head;
    }
};