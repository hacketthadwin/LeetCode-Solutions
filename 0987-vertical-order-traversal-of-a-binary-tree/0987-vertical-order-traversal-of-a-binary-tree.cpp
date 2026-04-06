class Solution {
public:

int extreme_left(TreeNode* root)
{
    if(root==nullptr)return 0;
    int total_left=0;
    if(root->left!=nullptr) total_left = min(total_left, extreme_left(root->left)-1);
    if(root->right!=nullptr) total_left = min(total_left, extreme_left(root->right)+1);
    return total_left;
}

int extreme_right(TreeNode* root)
{
    if(root==nullptr)return 0;
    int total_right=0;
    if(root->right!=nullptr) total_right = max(total_right, extreme_right(root->right)+1);
    if(root->left!=nullptr) total_right = max(total_right, extreme_right(root->left)-1); 
    return total_right;
}

// Store a pair of {row, value} so we can sort properly later
//we should only sort by value if two nodes share both the exact same row and the exact same column.
map<int,vector<pair<int, int>>> mp_left, mp_right;

void sol_left(TreeNode* root,int curr_row,int curr_col)
{
    if(root==nullptr)return;

    // Push both the current row and the value
    mp_left[curr_col].push_back({curr_row, root->val});

    if(root->left!=nullptr) sol_left(root->left, curr_row+1, curr_col-1);   
    if(root->right!=nullptr) sol_left(root->right, curr_row+1, curr_col+1); 
}

void sol_right(TreeNode* root,int curr_row,int curr_col)
{
    if(root==nullptr)return;

    //Push both the current row and the value
    mp_right[curr_col].push_back({curr_row, root->val});

    if(root->right!=nullptr) sol_right(root->right, curr_row+1, curr_col+1); 
    if(root->left!=nullptr) sol_right(root->left, curr_row+1, curr_col-1);   
}

vector<vector<int>> verticalTraversal(TreeNode* root) {

    int total_left = extreme_left(root);
    int total_right = extreme_right(root);

    // Update temporary vectors to hold the pairs
    vector<vector<pair<int, int>>> left_part;
    vector<vector<pair<int, int>>> right_part;
    vector<vector<pair<int, int>>> merged_pairs;
    vector<vector<int>> ans;
    
    // root goes to both → duplication, so handle carefully
    sol_left(root,0,0);
    sol_right(root,0,0);

    for(int i=total_left;i<=0;i++)
    {
        left_part.push_back(mp_left[i]);
    }
    
    for(int i=0;i<=total_right;i++)
    {
        right_part.push_back(mp_right[i]);
    }

    // merge (avoid duplicating column 0)
    for(auto &v : left_part) merged_pairs.push_back(v);

    for(int i=1;i<right_part.size();i++) // skip 0th column
        merged_pairs.push_back(right_part[i]);

    // Sort the pairs (sorts by row first, then value) and extract just the values
    for(int i=0;i<merged_pairs.size();i++)
    {
        sort(merged_pairs[i].begin(), merged_pairs[i].end());
        
        vector<int> col_vals;
        for(auto &p : merged_pairs[i]) {
            col_vals.push_back(p.second); // p.second is the actual node value
        }
        ans.push_back(col_vals);
    }
    return ans;
}
};