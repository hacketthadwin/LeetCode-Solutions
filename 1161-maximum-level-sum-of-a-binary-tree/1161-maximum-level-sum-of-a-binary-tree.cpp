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
     int height(TreeNode* node){
        if(node==NULL) return 0;
        return (1+max(height(node->left), height(node->right)));
    }
    void eachlevel(TreeNode* root,vector<int>&ans,int i)
    {
        if(root==NULL) return;
        ans[i]+=root->val;
        eachlevel(root->left,ans,i+1);   //i changed from postincrement to preincremenet
        eachlevel(root->right,ans,i+1);   //even doing preincrement didn't resolved the issue, the issue is only resolved by i+1
        return;
        
        
    }
    int maxLevelSum(TreeNode* root) {
        int h=height(root);
        vector<int>ans(h,0);
        int i=0;
        eachlevel(root,ans,i);
        int ind=0;
        int mini= INT_MIN;
        for(int i=0;i<h;i++)
        {
            if(ans[i]>mini)
            {
                mini=ans[i];
                ind=i;
            }

        }
        return ind+1;
        
    }
};