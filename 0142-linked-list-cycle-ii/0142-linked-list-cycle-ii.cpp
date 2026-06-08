/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectLoop(ListNode *head)
    {
        ListNode *fast = head ; 
        ListNode *slow = head ;
        if(head == NULL || head -> next == NULL)
        {
            return NULL; 
        }

        while (slow != NULL && fast != NULL)
        {
            fast = fast -> next ; 
            if(fast != NULL)
            {
                fast = fast -> next ; 
            }
            slow = slow -> next ; 

            if(slow == fast)
            {
                return slow ; 
            }
        }
        return NULL ; 
    }

    ListNode *detectCycle(ListNode *head) {
        //i really didn't know this concept of floyd's cycle detection algorithm...it uses the same tortoise hare thing of 2 pointers..where fast is same moving twice as speed as slow pointer...but to find the head of the cycle...is a bit of tideous task...Currently our fast and slow pointers are at the point where both these pointers coincide/intersect in the loop.
// We return this node of coincidence and save it's address in a pointer named intersection.
// Now, we place out slow pointer at the head of the linked list.
// According to Floyd Loop Detection Algorithm, now when we iterate both these pointers 1 step at a time, the point where they meet is the starting node of the loop.

//AWESOME THING
        ListNode *intersection = detectLoop(head) ;
        ListNode *slow = head ; 
        if(intersection == nullptr)
        {
            return nullptr ;
        }
        while (slow != intersection)
        {
            slow = slow -> next ; 
            intersection = intersection -> next ; 
        }
        return slow ; 



    }
};