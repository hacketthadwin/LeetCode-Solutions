class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
     //so if i first sort it...then if i find any difference > 1, then i will simply put the value to a lower value...but wait which value...so i will change the next value...because if i will change current value it will affect previous value too

     sort(arr.begin(),arr.end());
     if(arr[0]!=1)
     {
        arr[0]=1;
     }
     for(int i=1;i<arr.size();i++)
     {
        if(arr[i]-arr[i-1]>1)
        {
            arr[i]=arr[i-1]+1;
        }
     }

     return arr.back();   
    }
};