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
// int subtree_sum(TreeNode* root)
// {
//     if(root==nullptr)return 0;
//     int sum=root->val;
//     if(root->left!=nullptr)sum+=subtree_sum(root->left);
//     if(root->right!=nullptr)sum+=subtree_sum(root->right);
//     return sum;
// }
int ans=0;
int sol(TreeNode* root)
{
    //as i have to go till lowest node in left and right first
    //LRN is best
    //i am going to lowest left node from current node
    int left_val=0;
    int right_val=0;
    if(root->left!=nullptr)left_val=max(0,sol(root->left));
    //i will get maximum value of a path in left subtree after performing the above operation
    //got the node
    if(root->right!=nullptr)right_val=max(0,sol(root->right));
    //i will get maximum value of a path in right subtree after performing the above operation
    //so basically the formula for max path sum is curr_node + max_left + max_right and what you will return is max(cur_node+max_right,max(curr_node+max_left,0));

    ans=max(ans, root->val+left_val+right_val);

    return max(0,root->val+max(left_val,right_val));
}
int maxPathSum(TreeNode* root) 
{
        //yeah so this is BT + DP problem, i am thinking to use inorder traversal which is LNR
        //i will go to left, do 2 things, either take that value or not take
        //if i take, then i have to take all values in one path 

        //yeah for each node, i will find maximum value of either left subtree or right subtree and then return it above part
        //by this i will ensure that i get only one path 
        //then i will find 3 values, (left, right, left + current_node + right, left+current, right+current) and return max of this to above
        //if only right was max or left was max, then i will have to break the thing i.e. i cannot take the current node and therefore the sequence will be broken, so a bool including_current is also required

        ans=root->val;
        int temp=sol(root);
        return ans;

        
}
};