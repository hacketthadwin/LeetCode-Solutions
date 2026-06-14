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

    ListNode* deleteMiddle(ListNode* head) {
        int sz=0;
        
        ListNode* saved_head=head;
        ListNode* saved_head2=head;
        while(head!=nullptr)
        {
            sz++;
            head=head->next;
        }
        if(sz==1)
        {
            return nullptr;
        }
        if(sz==2)
        {
            saved_head2->next=nullptr;
            return saved_head2;
        }
        int middle=(sz/2)-1;
        while(middle--)
        {
            if(saved_head->next!=nullptr)saved_head=saved_head->next;
        }

        saved_head->next=saved_head->next->next;
        return saved_head2;
    }
};