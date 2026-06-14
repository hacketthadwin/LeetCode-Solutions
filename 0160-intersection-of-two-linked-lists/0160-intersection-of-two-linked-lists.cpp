/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* saved_headA=headA;
        ListNode* saved_headB=headB;
        //so they are merging...it means   until and unless there size is different...i can simply keep moving forward and checking...if there size is different...i will be moving the pointer of more sized linked list until the remaining size becomes same...if during that loop...somewhere they get merged..nice..i will return it...else once there size becomes equal i will again keep iterating together till end and if they match anywhwere i will return it...else it means they are not never merged so return nullptr
        int sizeA=0;
        int sizeB=0;
        while(saved_headA!=nullptr)
        {
            sizeA++;
            saved_headA=saved_headA->next;
        }
        while(saved_headB!=nullptr)
        {
            sizeB++;
            saved_headB=saved_headB->next;
        }
        saved_headA=headA;
        saved_headB=headB;
        if(sizeA>sizeB)
        {
            int diff=sizeA-sizeB;
            while(diff>0)
            {
                if(saved_headA==saved_headB)
                {
                    return saved_headA;
                }
                saved_headA=saved_headA->next;
                diff--;
            }
        }
        else if(sizeB>sizeA)
        {
            int diff=sizeB-sizeA;
            while(diff>0)
            {
                if(saved_headA==saved_headB)
                {
                    return saved_headA;
                }
                saved_headB=saved_headB->next;
                diff--;
            }
        }
        while(saved_headA!=nullptr&&saved_headB!=nullptr)
        {
            if(saved_headA==saved_headB)
            {
                return saved_headA;
            }
            saved_headA=saved_headA->next;
            saved_headB=saved_headB->next;
        }
        return nullptr;
    }
};