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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        //so i can easily create a normal tree with parent-child relationship by making an adjacency list...then what i will get it every node will have either 1 or 2 child...and then the isleft will tell that if the child is in left or right
        map<int,bool>mp;
        map<int,bool>is_child;
        for(int i=0;i<descriptions.size();i++)
        {
            int par=descriptions[i][0];
            int child=descriptions[i][1];
            int is_left=descriptions[i][2];  
            mp[par]=true;
            is_child[child]=true;
        }
        //so the node which is not child of any node...i.e. only parent...is root node...the node which has no child is leaf node...so mp.size will be the number of nodes but i cannot make adjacency list with this..because node is not necessarily from 1 to n or 0 to n-1...it is arbitrary...so i need to make the tree from the map itself
        //it is easy i guess
        //if i create parents and child set..and then if i try to make the
        //i guess making tree is not the challenge here but finding parent is
        //yeah so first just let's find root...let the tree making problem be secondary
        //now i will just iterate through mp because every node is a parent...but one node is not child..so if i iterate through parents...and then i find one node which is not child..i.e is_child.counts(par)==false...then simply that is root node
        int root_val=-1;
        for(auto m:mp)
        {
            int par=m.first;
            if(!is_child.count(par))
            {
                root_val=par;
                break;
            }
        }

        //nice got the root node value..now just making tree is remaining which is easy
        map<int,TreeNode*>val_to_node;
        TreeNode* root=nullptr;
        for(int i=0;i<descriptions.size();i++)
        {
            int par=descriptions[i][0];
            int child=descriptions[i][1];
            int is_left=descriptions[i][2];  
            if(!val_to_node.count(par))val_to_node[par]=new TreeNode(par);
            if(par==root_val)root=val_to_node[par];
            if(!val_to_node.count(child))val_to_node[child]=new TreeNode(child);
            if(is_left==1)
            {
                val_to_node[par]->left=val_to_node[child];
            }
            else
            {
                val_to_node[par]->right=val_to_node[child];
            }
        }

        return root;

        
    }
};