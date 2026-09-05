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
    ListNode* ans;
    ListNode* finans;
    ListNode* temp;
    void rec(ListNode* temp)
    {
        if(temp->next==nullptr)
        {
            ans= new ListNode(temp->val);
            finans=ans;
            return;
        }
        rec(temp->next);
        ans->next=new ListNode(temp->val);
        ans=ans->next;
    }
    ListNode* reverseList(ListNode* head) {
        //yeah i remember this problem was badd....i needed to first save the original pointer somewhere...then keep going...yeah yeah recursion...now i know
        if(head==nullptr)return nullptr;
        temp=head;
        rec(temp);
        return finans;

    }
};