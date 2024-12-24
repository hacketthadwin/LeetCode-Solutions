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
       void eachlevel(TreeNode* root,vector<vector<int>>&ans,int i)
    {
        if(root==NULL) return;
        ans[i].push_back(root->val);
        eachlevel(root->left,ans,i+1);   //i changed from postincrement to preincremenet
        eachlevel(root->right,ans,i+1);   //even doing preincrement didn't resolved the issue, the issue is only resolved by i+1
        return;
        
        
    }
    vector<int> rightSideView(TreeNode* root) {
        int h=height(root);
        vector<vector<int>>ans(h);
        int i=0;
        eachlevel(root,ans,i);
        vector<int>ret;
        for(int i=0;i<h;i++)
        {
            ret.push_back(ans[i][ans[i].size()-1]);
        }
        return ret;
        
    }
};