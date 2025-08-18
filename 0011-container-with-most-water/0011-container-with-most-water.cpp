class Solution {
public:
    int maxArea(vector<int>& arr) {
        int n=arr.size();
        int temp=0;
        int maxi=0;
        for(int i=0,j=n-1;i<j;)
        {
            if(arr[i]<arr[j])
            {
                temp=arr[i]*(j-i);
                i++;
            }
            else if(arr[i]>arr[j])
            {
                temp=arr[j]*(j-i);
                j--;
            }
            else
            {
                temp=arr[j]*(j-i);
                i++;
                j--;
            }

            maxi=max(maxi,temp);
        }

        return maxi;
    }
};