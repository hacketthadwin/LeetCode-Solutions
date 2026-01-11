class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>forward;
stack<int>backward;
vector<int>fw(heights.size(),heights.size());
vector<int>bw(heights.size(),-1);
for(int i=0;i<heights.size();i++)
{
	while(!forward.empty() && heights[forward.top()]>heights[i])
	{
		fw[forward.top()]= i;
		forward.pop();
	}
	forward.push(i);
}
for(int i=heights.size()-1;i>=0;i--)
{
	while(!backward.empty() && heights[backward.top()]>heights[i])
	{
		bw[backward.top()]=i;
		backward.pop();
	}
	backward.push(i);
}
int maxi=0;
int current=0;
for(int i=0;i<heights.size();i++)
{
	current= heights[i]*(fw[i]-bw[i]-1);
	maxi= max(current,maxi);
}
return maxi;

        
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row= matrix.size();
        int col= matrix[0].size();
        vector<int>onerow(col,0);
        int ans=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(matrix[i][j]=='0')
                {
                    onerow[j]=0;
                }
                else
                {
                    onerow[j]+=1;
                }
                

            }
           ans=max(ans,largestRectangleArea(onerow)) ;

        }
        return ans;

    }
};