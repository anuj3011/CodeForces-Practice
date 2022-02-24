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
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* mid= getMid(head);
        ListNode* left=sortList(head);
        ListNode* right=sortList(mid);
        return merge(left,right);
    }
    ListNode* merge(ListNode* l1,ListNode* l2){
        ListNode* res=new ListNode(0);
        ListNode* ptr=res;
        while(l1 && l2){
            if(l1->val<l2->val){
                ptr->next=new ListNode(l1->val);
                l1=l1->next;
            }else{
                ptr->next=new ListNode(l2->val);
                l2=l2->next;
            }
            ptr=ptr->next;
        }
        if(l1) ptr->next=l1;
        else ptr->next=l2;
        return res->next;
    }
    ListNode* getMid(ListNode* head){
        ListNode* fast=head;
        ListNode* midPrev=nullptr;
        while(fast && fast->next){
            midPrev=(midPrev==nullptr) ? head:midPrev->next;
            fast=fast->next->next;
        }
        ListNode* mid= midPrev->next;
        midPrev->next=nullptr;
        return mid;
    }
};