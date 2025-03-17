/**
 * @param {number[]} nums
 * @return {boolean}
 */
var divideArray = function(nums) {
    let mymap= new Map();
    nums.sort();
    for(let i=0;i<nums.length;)
    {
        let cnt=0;
        let curr=nums[i];
        while(curr===nums[i])
        {
            cnt++;
            i++;
        }
        if(cnt%2!=0)
        {
            return false;
        }
    }
    return true;
};