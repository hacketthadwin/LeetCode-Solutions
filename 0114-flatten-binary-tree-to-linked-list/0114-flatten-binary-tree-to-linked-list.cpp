// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     void going_to_right_end(TreeNode* root, TreeNode* node_to_attach)
//     {
//         if (root == nullptr) return;
//         TreeNode* curr = root;
//         while (curr->right != nullptr) 
//         {
//             curr = curr->right;
//         }
//         curr->right = node_to_attach;
//     }
//     void core_flatten(TreeNode* root)
//     {
//         //make the right side in the right side, make the left side completely to right side first
//         //go till the left end of the tree, go to its parent, then take that node, add it to the right side after the current right side
//         if((root==nullptr) || (root->left==nullptr))return;
//         if(root->left->left!=nullptr) core_flatten(root->left);
//         TreeNode* preserved_right=root->right;
//         root->right=root->left;
//         root->left = nullptr;
//         //now i will go the end of this and attach the right side into that
//         going_to_right_end(root->right,preserved_right);
//         if(root->right->left!=nullptr) core_flatten(root->right);
        
//     }
//     void flatten(TreeNode* root) {
//         //flatten the left subtree
//         //flatten the right subtree
//         //root->left flattend->right flattend
//         TreeNode* lefty= nullptr;
//         if(root->left!=nullptr)lefty=root->left;
//         core_flatten(lefty);
//         TreeNode* righty= nullptr;
//         if(root->right!=nullptr)righty=root->right;
//         core_flatten(righty);
//         root->right=lefty;
//         going_to_right_end(root->right,righty);
//         //now at the end of this 
//         // we will add the righty node
//     }
// };

class Solution {
public:
    void going_to_right_end(TreeNode* root, TreeNode* node_to_attach)
    {
        if (root == nullptr || node_to_attach == nullptr) return;
        TreeNode* curr = root;
        while (curr->right != nullptr) 
        {
            curr = curr->right;
        }
        curr->right = node_to_attach;
    }

    void core_flatten(TreeNode* root)
    {
        //make the right side in the right side, make the left side completely to right side first
        //go till the left end of the tree, go to its parent, then take that node, add it to the right side after the current right side
        if (root == nullptr) return;
        // come to node, attach the left node to right node, then again go to right and perform the operation as much as required
        if (root->left != nullptr) 
        {
            TreeNode* preserved_right = root->right;
            root->right = root->left;
            root->left = nullptr; 
            
            //now i will go the end of this and attach the right side into that
            going_to_right_end(root->right, preserved_right);
        }
        core_flatten(root->right);
    }

    void flatten(TreeNode* root) {
        //flatten the left subtree
        //flatten the right subtree
        //root->left flattend->right flattend
        if (root == nullptr) return;

        TreeNode* lefty = root->left;
        core_flatten(lefty);

        TreeNode* righty = root->right;
        core_flatten(righty);
        //now at the end of this 
        // we will add the righty node
        if (lefty != nullptr) 
        {
            root->right = lefty;
            root->left = nullptr;
            going_to_right_end(root->right, righty);
        }
        else 
        {
            root->right = righty;
        }

    }
};