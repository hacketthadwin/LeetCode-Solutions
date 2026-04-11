/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  * };
//  */
// class Solution {
// public:

// bool finding(TreeNode* root, int num, vector< TreeNode* >&arr)
// {
//     arr.push_back(root);
//     if(root->val==num)return true;
//     bool is_found=false;
//     if(root->left!=nullptr)
//     {
//         is_found |= finding(root->left,num,arr);
//     }
//     if(is_found)return true;
//     if(root->right!=nullptr)
//     {
//         is_found |= finding(root->right,num,arr);
//     }
//     if(!is_found)
//     {
//         arr.pop_back();
//     }

//     return is_found;

// }
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         // ok so there is 2 methods to solve this, one is the simple approach that is intuitive
//         // second is the optimised approach (space optimised to be precise)
//         //what is the first approach?
//         //let's suppose you have to find lca of 6 and 4
//         //you will have to write down the whole path for both 6 and 4 in the vector
//         //for 6 it will be [3,5,6], for 4 it will be [3,5,2,4]
//         //now check at which number the number is same i.e. [3,5] i.e. 5 is the last number where both are same, so 5 is lca

//         //now this approach is good but it require 2*o(n) time and 2*o(n) space
//         //now we will think of the approach which will give us o(n) time and o(1) space
//         //in this, we will use dfs, will go to each node, wherever i will find either 4 or 6, i will return that otherwise i will return null
//         //now between a number and null, we will return the number
//         //when we recieve number from both side, then i will conclude that the node is lca of both 4 and 6
//         //first let's code up our brute force
//         vector< TreeNode* >num1,num2;
//         finding(root,p->val,num1);
//         finding(root,q->val,num2);
//         int i=0;
//         for(;i<min(num1.size(),num2.size())-1;i++)
//         {
//             if((num1[i+1]->val)!=(num2[i+1]->val))
//             {
//                 return num1[i];
//             }
//         }
//         //if one is ancestor of other
//         if(i==(num1.size()-1))
//         {
//             return num1[i];
//         }
//         if(i==(num2.size()-1))
//         {
//             return num2[i];
//         }
//         return root;
//     }
// };
class Solution {
public:
TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if(root==p)return p;
    if(root==q)return q;

    TreeNode* first_call=nullptr;
    if(root->left!=nullptr)first_call=dfs(root->left,p,q);
    TreeNode* second_call=nullptr;
    if(root->right!=nullptr)second_call=dfs(root->right,p,q);

    if(first_call!=nullptr && second_call!=nullptr)return root;
    if(first_call==nullptr && second_call!=nullptr)return second_call;
    if(first_call!=nullptr && second_call==nullptr)return first_call;
    return nullptr;
}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //now we will use the optimised approach which is that once you find any one of the number, else return null, when you get both of the numbers at one node, that one node is the answer
            return dfs(root,p,q);
    }
};