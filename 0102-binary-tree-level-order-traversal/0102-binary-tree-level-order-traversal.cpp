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
    if(root->left!=nullptr ) curr = max(curr, 1 + height(root->left));
    if(root->right!=nullptr ) curr = max(curr, 1 + height(root->right));
    return curr;
}

void level(TreeNode* root, int curr_height,vector<vector<int>>&ans)
{
    ans[curr_height].push_back(root->val);
    if(root->left!=nullptr)level(root->left,curr_height+1,ans);
    if(root->right!=nullptr)level(root->right,curr_height+1,ans);
}
    vector<vector<int>> levelOrder(TreeNode* root) {
        //keep going down until you reach final node, push in the vector of vector, first of all we need to find height of this so that we can define the size of vector,
        if(root==nullptr)return {};
        int h=height(root);
        vector<vector<int>>ans(h);
        //now as we have found height, we can find the level order traversal also
        //we will go by height and for each height, we will push that value into the vector of that height
        level(root,0,ans);
        return ans;
    }
};