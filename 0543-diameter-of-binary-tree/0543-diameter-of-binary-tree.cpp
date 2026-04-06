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
int height(TreeNode* root)
{
    if(root==nullptr)return 0;
    int curr=1;
    if(root->left!=nullptr)curr=max(curr,1+height(root->left));
    if(root->right!=nullptr)curr=max(curr,1+height(root->right));
    return curr;
}
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr)return true;
        int ans=0;
        int height_left=height(root->left);
        int height_right=height(root->right);
        ans=abs(height_left+height_right);
        if(root->left!=nullptr)ans=max(ans,diameterOfBinaryTree(root->left));
        if(root->right!=nullptr)ans=max(ans,diameterOfBinaryTree(root->right));
        return ans;
    }
};