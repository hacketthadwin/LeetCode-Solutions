class Solution {
public:
int reversal(int num){
    string reversed= to_string(num);
    reverse(reversed.begin(),reversed.end());
    int numi = stoi(reversed);
    return numi;
}
    int minMirrorPairDistance(vector<int>& nums) {
       vector<int>reversed(nums.size());
       for(int i=0;i<nums.size();i++){
           reversed[i]=reversal(nums[i]);
       }
       int mini=INT_MAX;
       unordered_map<int,int>mp;
       unordered_map<int,int>mp2;
       for(int i=0;i<nums.size();i++)
       {
           if(mp2.count(nums[i]))
           {
                mini=min(mini,i-mp2[nums[i]]);
           }
           mp2[reversed[i]]=i;
       }
       
       if(mini==INT_MAX)return -1;
       return mini;
    }
};