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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode* dummy=new ListNode(0);
        ListNode* curr=dummy;
        ListNode* ptr1=l1;
        ListNode* ptr2=l2;
        while(ptr1 || ptr2){
            int x=(ptr1!=NULL)?ptr1->val:0;
            int y=(ptr2!=NULL)?ptr2->val:0;
            int sum=x+y+carry;
            carry=sum/10;
            cout<<sum<<" ";
            curr->next= new ListNode(sum%10);
            curr=curr->next;
            if(ptr1) ptr1=ptr1->next;
            if(ptr2) ptr2=ptr2->next;
        }
        if(carry>0)
            curr->next=new ListNode(carry);
        return dummy->next;
    }
};