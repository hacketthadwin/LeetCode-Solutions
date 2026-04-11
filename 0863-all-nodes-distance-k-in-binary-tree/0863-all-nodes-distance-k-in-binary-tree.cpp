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
// void bfs(TreeNode* root,map<int,int>&mp) //should have passed by value
// {
//     if(root==nullptr)return;
//     if(root->left!=nullptr)
//     {
//         mp[root->left->val]=mp[root->val]+1;
//         bfs(root->left,mp);
//     }
//     if(root->right!=nullptr)
//     {
//         mp[root->right->val]=mp[root->val]+1;
//         bfs(root->right,mp);
//     }
// }
//     vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
//         // as all nodes are unique, i will just write the distance of each node from current node, nodes above target will be counted differently, nodes below target will be treated differently
//         //left from root will be saved in another left array with position count 1,2....till the end
//         //similarly right from root will be saved in another right array with position count 1,2,....til the end
//         //bfs will work
 
//         map<int,int>right,left;
//         right[root->val]=0;
//         left[root->val]=0;
//         if(root->left!=nullptr)bfs(root->left,left);
//         if(root->right!=nullptr)bfs(root->right,right);
        
//         bool is_in_left=false;
//         int pos=-1;
//         bool is_in_right=false;
//         for(auto m:left)
//         {
//             if(m.first==target->val)
//             {
//                 pos=m.second;
//                 is_in_left=true;
//                 break;
//             }
//         }
//         for(auto m:right)
//         {
//             if(m.first==target->val)
//             {
//                 pos=m.second;
//                 is_in_right=true;
//                 break;
//             }
//         }

//         //now for all mp, first in the one part, whichever 
//         if(k==0)
//         {
//             return {target->val};
//         }
//         vector<int>ans;
//         if(pos==0)
//         {
//             //find the numbers at position k in both the maps
//             for(auto m:left)
//             {
//                 if(m.second==k)
//                 {
//                     ans.push_back(m.first);
//                 }
//             }
//             for(auto m:right)
//             {
//                 if(m.second==k)
//                 {
//                     ans.push_back(m.first);
//                 }

//             }
//             return ans;
//         }
//         if(pos>=k)
//         {
//             //it means in the same branch i.e. left or right including root
//             int lesser_one = pos-k;
//             int greater_one = pos+k;
//             if(is_in_right)
//             {
//                 for(auto m:right)
//                 {
//                     if(m.second==greater_one)
//                     {
//                         ans.push_back(m.first);
//                     }
//                     if(m.second==lesser_one)
//                     {
//                         ans.push_back(m.first);
//                     }
//                 }
//             }
//             if(is_in_left)
//             {
//                 for(auto m:left)
//                 {
//                     if(m.second==greater_one)
//                     {
//                         ans.push_back(m.first);
//                     }
//                     if(m.second==lesser_one)
//                     {
//                         ans.push_back(m.first);
//                     }
//                 }

//             }
            
//         }
//         else
//         {
//             //it means we have to check the other part too
//             int second_part=k-pos;
//             int first_part = k+pos;
//             if(is_in_right)
//             {
//                 for(auto m:right)
//                 {
//                     if(m.second==first_part)
//                     {
//                         ans.push_back(m.first);
//                     }
//                 }
//                 for(auto m:left)
//                 {
//                     if(m.second==second_part)
//                     {
//                         ans.push_back(m.first);
//                     }
//                 }
//             }
//             if(is_in_left)
//             {
//                 for(auto m:left)
//                 {
//                     if(m.second==first_part)
//                     {
//                         ans.push_back(m.first);
//                     }
//                 }
//                 for(auto m:right)
//                 {
//                     if(m.second==second_part)
//                     {
//                         ans.push_back(m.first);
//                     }
//                 }

//             }
//         }

//         return ans;

//     }
// };

// never ever think of using depth as the solution if asking distance from one node to another because same depth can have any distance not just 0
//and why my approach failed, let's first discuss that
// I am using depth as a metric to find the distance from current node to other node but that is wrong approach because for a tree like the example 7 and 4 is on same level and as 2 is not root, hence we will get our answer as distance 0, but in reality the distance is 2
//i thought to generalise this for all nodes but even after doing it, it will most probably throw tle
//so the next approach will be to simply use dfs/bfs and finding the nodes in 2 parts, first the downwards portion where all nodes below the target, then all nodes above the target


class Solution {
public:
    vector<int>ans;
    void dfs(TreeNode* root,int curr_k, int k)
    {
        if(root==nullptr)
        {
            return;
        }
        if(curr_k==k)
        {
             ans.push_back(root->val);
             return;   
        }

        if(root->left!=nullptr)
        {
            dfs(root->left,curr_k+1,k);
        }
        if(root->right!=nullptr)
        {
            dfs(root->right,curr_k+1,k);
        }
        
    }

    bool dfs2(TreeNode* root,TreeNode* target,vector<TreeNode*>&v)
    {
        //this will find the number of target node
        if(root == nullptr) return false;

        v.push_back(root);

        if(root==target)
        {
            return true;
        }
        bool is_found=false;
        // v.push_back(root);  i initially kept it here, but this was not including the target itself
        if(root->left!=nullptr)
        {
           is_found |= dfs2(root->left,target,v);
        }
        if(root->right!=nullptr)
        {
           is_found |= dfs2(root->right,target,v);
        }
        if(!is_found)
        {
            v.pop_back();
        }
        return is_found;
    }
    // void dfs3(TreeNode* root,int curr_k, int k, TreeNode* target)  
    // {
    //     if(root==nullptr || root==target)
    //     {
    //         return;
    //     }
    //     if(curr_k==k)
    //     {
    //          ans.push_back(root->val);
    //     }

    //     if(root->left!=nullptr)
    //     {
    //         dfs3(root->left,curr_k+1,k,target);
    //     }
    //     if(root->right!=nullptr)
    //     {
    //         dfs3(root->right,curr_k+1,k,target);
    //     }
        
    // }
    //this was my initial dfs3, but there is a redundancy in this, i.e. first we travel when we are at parents of target, then we again travel when we are grandparents of the target and similarly for all we keep travelling and hence this is like doing extra labour for no worth

    void dfs3(TreeNode* root,int curr_k, int k, TreeNode* block)  
    {
        if(root==nullptr || root==block)
        {
            return;
        }
        if(curr_k==k)
        {
             ans.push_back(root->val);
             return;   
        }

        if(root->left!=nullptr)
        {
            dfs3(root->left,curr_k+1,k,block);
        }
        if(root->right!=nullptr)
        {
            dfs3(root->right,curr_k+1,k,block);
        }
        
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        dfs(target,0,k);
        vector<TreeNode*>v;
        dfs2(root,target,v);
        //i got every parent of current node, so i will first reverse it, then from every node, i will assign it as numbers i.e. 1,2,3
        reverse(v.begin(),v.end());
        TreeNode* block = target;
        for(int i = 1;i<v.size();i++)
        {
            int pos=i;
            dfs3(v[i], pos, k, block);  //intitially i was using target instead of block but that gave me error which is explained below the commented dfs3
            block = v[i];

        }
        return ans;
        //successfully got the answer part 1,now i will start from root node and then start doing the dfs
    }
};