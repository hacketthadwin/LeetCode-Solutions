/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
map<pair<TreeNode*,bool> , int>dp;
int rec(TreeNode* head,bool can_take)
{
    if(head==nullptr)return 0;
    if(dp.count({head,can_take}))return dp[{head,can_take}];
    int ans=0;
    if(can_take)
    {
        ans+=head->val;
        ans+=rec(head->left,false);
        ans+=rec(head->right,false);
    }
    else
    {
        //it can both possible that it takes or it not take
        //if it takes one or both..then
        ans=max(ans,rec(head->left,true)+rec(head->right,true));
        ans=max(ans,rec(head->left,false)+rec(head->right,true));
        ans=max(ans,rec(head->left,true)+rec(head->right,false));
        ans=max(ans,rec(head->left,false)+rec(head->right,false));

    }
    dp[{head,can_take}]=ans;
    return dp[{head,can_take}];

}
    int rob(TreeNode* root) 
    {
        int ans1=rec(root,true);
        dp.clear();
        int ans2=rec(root,false);
        return max(ans1,ans2);
    }
};