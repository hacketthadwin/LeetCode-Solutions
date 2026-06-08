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
        // i haven't appreciated the tortoise hare method back then...but now i realise how good it is in reality
        //this problem is really with tortoise hare solution (not intuitive at first though)

        if(head==nullptr || head->next==nullptr)return head;
        ListNode* fast=head->next;
        ListNode* slow=head;
        while(fast!=nullptr)
        {
            fast=fast->next;
            if(fast!=nullptr)fast=fast->next;
            slow=slow->next;
        }
        return slow;
        
    }
};