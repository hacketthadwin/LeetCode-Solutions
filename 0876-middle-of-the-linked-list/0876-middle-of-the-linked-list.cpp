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
    ListNode* middleNode(ListNode* head) {
        //so there are 2 methods for this...first find total size and only visit till n/2
        //second is slow and fast pointer...the slow pointer will be moving 1 step and the fast pointer will move 2 steps
        if(head==nullptr || head->next==nullptr)return head;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=nullptr && fast->next!=nullptr)
        {
            if(slow->next!=nullptr)slow=slow->next;
            if(fast->next!=nullptr)fast=fast->next;
            if(fast->next!=nullptr)fast=fast->next;
        }
        return slow;
    }
};