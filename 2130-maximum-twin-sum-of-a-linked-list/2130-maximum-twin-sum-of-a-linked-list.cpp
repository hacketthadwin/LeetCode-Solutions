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
 //think like this 1->2->3->4
 //my base case returned 4
 //my temp took 4
 //then in that 4..i attach 3 to next of 4
 //so 4->3
 //now...ok so my reverse linked list will begin from new_head and not temp
 //small debugging session everytime
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
    int pairSum(ListNode* head) {
       ListNode* temp= reverse(head);
        int maxi=INT_MIN;
       while(head!=nullptr)
       {
            maxi=max(maxi, head->val+new_head->val);
            head=head->next;
            new_head=new_head->next;
       }

       return maxi;
    }
};