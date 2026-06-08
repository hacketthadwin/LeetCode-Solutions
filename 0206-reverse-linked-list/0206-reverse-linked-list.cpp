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
    ListNode* ans_rec=nullptr;
    ListNode* rec_head=nullptr;
    void rec(ListNode* head)
    {
        if(head->next==nullptr)
        {
            ans_rec=new ListNode(head->val);
            rec_head=ans_rec;
            return;
        }

        if(head->next!=nullptr)rec(head->next);
        ListNode* temp = new ListNode(head->val);
        ans_rec->next=temp;
        ans_rec=ans_rec->next;
    }
    ListNode* reverseList(ListNode* head) {
        //so the challenge here will be to reverse the linked list without extra memory (array)
        //and do in both recursive and iterative way
        //what can i do...for recursive i can do is keep on moving and when i reach the end..then i keep returning the values...and a listnode keeps adding those values
        //how can i do in iterative in O(n)
        //first let's do the recursive one
        if(head==nullptr)return nullptr;
        rec(head);
        return rec_head;
    }
};