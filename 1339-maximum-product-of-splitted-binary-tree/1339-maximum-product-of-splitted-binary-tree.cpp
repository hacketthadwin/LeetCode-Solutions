class Solution {
public:
    int dfs1(TreeNode* curr, TreeNode* parent)
    {
        if(curr == nullptr) return 0;
        if(curr->right==nullptr && curr->left==nullptr)return curr->val;
        int sum=0;
        sum+=curr->val;
        if(curr->right!=nullptr)sum+=dfs1(curr->right,curr);
        if(curr->left!=nullptr)sum+=dfs1(curr->left,curr);
        return sum;
    }

    long long max_prod=0;
    int total_sum=0;

    int dfs2(TreeNode* curr, TreeNode* parent)
    {
        if(curr==nullptr)return 0;
        int sum1=0;
        int sum2=0;
        if(curr->left!=nullptr)sum1=dfs2(curr->left,curr);
        if(curr->right!=nullptr)sum2=dfs2(curr->right,curr);
        // sum1 represents the total subtree sum rooted at the left child
        if(curr->left!=nullptr)
        {
            long long temp1=1LL*sum1*(total_sum-sum1);
            max_prod=max(max_prod, temp1);
        }
        // sum2 represents the total subtree sum rooted at the right child
        if(curr->right!=nullptr)
        {
            long long temp2=1LL*sum2*(total_sum-sum2);
            max_prod=max(max_prod,temp2);
        }
        // Return the total sum of the subtree rooted at curr
        return curr->val+sum1+sum2;
    }

    int maxProduct(TreeNode* root) {
        total_sum=dfs1(root,nullptr);
        //our target is to keep finding maximum product of sum for each node we visit
        dfs2(root,nullptr);
        return (max_prod%(1000000007));
    }
};