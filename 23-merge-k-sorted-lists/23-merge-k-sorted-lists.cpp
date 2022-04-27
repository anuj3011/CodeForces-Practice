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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto list: lists){
            ListNode* temp=list;
            while(temp){
                pq.push(temp->val);
                temp=temp->next;
            }
        }
        // cout<<pq.size();
        ListNode* list= new ListNode(0);
        ListNode* curr= list;
        while(pq.size()>0){
            curr->next= new ListNode(pq.top());
            curr=curr->next;
            pq.pop();
        }
        return list->next;
    }
};