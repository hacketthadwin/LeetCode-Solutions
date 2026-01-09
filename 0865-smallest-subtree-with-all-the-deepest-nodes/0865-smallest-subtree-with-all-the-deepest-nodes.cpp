/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
typedef vector<int> vi;
class Solution {
public:
    void dfs1(TreeNode* curr,vi&maxDistInSubtree)  //this is used to assign value of maxDistInSubtree
    {
        maxDistInSubtree[curr->val]=0;
        if(curr->left==nullptr && curr->right==nullptr)return;
        if(curr->right!=nullptr)dfs1(curr->right,maxDistInSubtree);
        if(curr->left!=nullptr)dfs1(curr->left,maxDistInSubtree);   
       if(curr->right!=nullptr)  maxDistInSubtree[curr->val] = max(maxDistInSubtree[curr->val],1+maxDistInSubtree[curr->right->val]);
       if(curr->left!=nullptr) maxDistInSubtree[curr->val] = max(maxDistInSubtree[curr->val],1+maxDistInSubtree[curr->left->val]);
    }

    void dfs2(TreeNode* curr,vi&maxDistInSubtree, vi&maxDistAsLCA)
    {
        // Instead of diameter, we check if the max height reachable from left and right is equal
        int leftH = (curr->left != nullptr) ? maxDistInSubtree[curr->left->val] : -1;
        int rightH = (curr->right != nullptr) ? maxDistInSubtree[curr->right->val] : -1;

        if(leftH == rightH)
        {
            // If heights are equal, this node covers all deepest leaves in its subtree
            maxDistAsLCA[curr->val] = maxDistInSubtree[curr->val]; 
        }
        else
        {
            maxDistAsLCA[curr->val] = -1;
        }

        if(curr->right!=nullptr)
        {
            dfs2(curr->right,maxDistInSubtree,maxDistAsLCA);
        }
        if(curr->left!=nullptr)
        {
            dfs2(curr->left,maxDistInSubtree,maxDistAsLCA);
        }

    }

    TreeNode* dfs3(TreeNode* curr,int&value)
    {
        if(curr->val==value)return curr;
        if(curr->left==nullptr && curr->right==nullptr)return nullptr;
        TreeNode* finder = nullptr;
        TreeNode* righty=nullptr;
        TreeNode* lefty=nullptr;
        if(curr->right!=nullptr)
        {
           righty =dfs3(curr->right,value);
            
        }
        if(curr->left!=nullptr)
        {
            lefty=dfs3(curr->left,value);
        }
        if(righty!=nullptr)
        {
            finder=righty;
        }
        if(lefty!=nullptr)
        {
            finder=lefty;
        }

        return finder;

    }
    void dfs4(TreeNode* curr,int&n)
    {
        n=max(n,curr->val);
        if(curr->right!=nullptr)dfs4(curr->right,n);
        if(curr->left!=nullptr)dfs4(curr->left,n);   
    }


    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        //so basically i will have to find first the lca of all the deepest node, that will give the whole subtree automatically
        //instead of this i could use the logic of lca and diameter, so what does it says is consider every node as lca, then find longest distance between 2 nodes for the lca
        //how can i use that information?

        //let's code from scratch
        int n=-1;
        dfs4(root,n);

        vi maxDistInSubtree(n+1,-1);  //this stores maximum distance from current node to leaf node in the subtree 
        vi maxDistAsLCA(n+1,-1);  //max distance between two nodes considering current node as LCA

        dfs1(root,maxDistInSubtree);
        dfs2(root,maxDistInSubtree,maxDistAsLCA);

        int maxi=-1;
        int node=-1;

        // we search for the node where leftH == rightH AND it reaches the overall max height
        int totalMaxHeight = maxDistInSubtree[root->val];

        // start from root and move towards the deepest leaves
        TreeNode* crawler = root;
        while(crawler)
        {
            int leftH = (crawler->left) ? maxDistInSubtree[crawler->left->val] : -1;
            int rightH = (crawler->right) ? maxDistInSubtree[crawler->right->val] : -1;

            if(leftH == rightH)
            {
                // this is our LCA! Because it's the first time (highest up) the paths split
                // or the point where both paths are equally deep.
                node = crawler->val;
                break;
            }
            else if(leftH > rightH)
            {
                crawler = crawler->left;
            }
            else
            {
                crawler = crawler->right;
            }
        }

        //now i got the node value, i will just have to find the node which has same value as this node
        TreeNode* ans= dfs3(root,node);
        return ans;
    }
};