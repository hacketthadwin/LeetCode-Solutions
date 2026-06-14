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
    int pairSum(ListNode* head) {
        vector<int>arr;
        while(head!=nullptr)
        {
            arr.push_back(head->val);
            head=head->next;
        }
        int maxi=INT_MIN;
        for(int i=0;i<arr.size();i++)
        {
            maxi=max(arr[i]+arr[arr.size()-1-i],maxi);
        }
        return maxi;
    }
};