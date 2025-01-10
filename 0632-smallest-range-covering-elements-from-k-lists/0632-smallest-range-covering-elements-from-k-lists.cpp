class Solution {
public:
//pattern based, observe this pattern (got from discussions)
// [4,10,15,24,26] [0,9,12,20] [5,18,22,30] 0, 5
// [4,10,15,24,26] [9,12,20] [5,18,22,30] 4, 9
// [10,15,24,26] [9,12,20] [5,18,22,30] 5, 10
// [10,15,24,26] [9,12,20] [18,22,30] 9, 18
// [10,15,24,26] [12,20] [18,22,30] 10, 18
// [15,24,26] [12,20] [18,22,30] 12, 18
// [24,26] [20] [18,22,30] 18, 24
// [24,26] [20] [22,30] 20, 24
// [24,26] [] [22,30]  stop
    vector<int> smallestRange(vector<vector<int>>& nums) 
{
priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
//first value is the minimum from the array from all rows
//second value is pair which will give position that is row and column of that minimum, so that for that row and column, i will push {row, col+1} as the next value from that row(or vector)

//take care of implementation part carefully, i put maxi-mini check at last and was getting wrong answer because maxi already gets changed before and we don't need any for loop for the problem because at start we already find the maxi and mini and then we change mini and maxi only for the vector which contained the mini, we find if nums[row][col+1] is greater than current maxi and if it is then we change and similarly we check if nums[row][col+1] is mini by pushing it to priority queue
//3 Star problem 
int maxi=INT_MIN;
for(int i=0;i<nums.size();i++)
{
    pq.push({nums[i][0],{i,0}});
    if(nums[i][0]>maxi)maxi=nums[i][0];
}
int i=0;
int currst=0;
int currend=INT_MAX;
while(true)
{
    int mini=pq.top().first;
    int row=pq.top().second.first;
    int col=pq.top().second.second;
    pq.pop();
    if((maxi-mini)<(currend-currst))     
    {
        currst=mini;
        currend=maxi;
    }
    if(col+1==nums[row].size())break;
    if(nums[row][col+1]>maxi)
    {
        maxi=nums[row][col+1];
    }
    pq.push({nums[row][col+1],{row,col+1}});

}
return {currst,currend};
}
};