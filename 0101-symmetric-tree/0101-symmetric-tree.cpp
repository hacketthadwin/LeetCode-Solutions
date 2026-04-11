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
    bool match(TreeNode* left_side,TreeNode* right_side)
    {
        if((left_side==nullptr && right_side!=nullptr)||(left_side!=nullptr && right_side==nullptr))return false;
        if(left_side==nullptr && right_side==nullptr)return true;
        if(left_side->val != right_side->val)
        {
            return false;
        }
        bool ans=true;
        ans&=match(left_side->left,right_side->right);
        ans&=match(left_side->right,right_side->left);
        return ans;
    }
    bool isSymmetric(TreeNode* root) {
        TreeNode* left_side=nullptr;
        if(root->left!=nullptr)left_side = root->left;
        TreeNode* right_side=nullptr;
        if(root->right!=nullptr)right_side = root->right;
        if(match(left_side,right_side))
        {
            return true;
        }
        return false;


    }
};