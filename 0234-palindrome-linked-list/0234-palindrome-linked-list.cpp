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
    ListNode* new_head= nullptr;
    ListNode* reverse(ListNode* head)
    {
        if(head->next==nullptr)
        {
            //base case
            new_head=new ListNode(head->val);
            return new_head;
        }

        ListNode* temp = reverse(head->next);
        temp->next=new ListNode(head->val);
        return temp->next;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* temp=reverse(head);
        while(head!=nullptr)
        {
            if(new_head->val!=head->val)
            {
                return false;
            }
            head=head->next;
            new_head=new_head->next;
        }
        return true;
    }
};