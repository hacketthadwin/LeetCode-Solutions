/**
 * @param {number[]} nums
 * @return {boolean}
 */
var containsDuplicate = function(nums) {
    var mp=new Map();
    for(var i=0;i<nums.length;i++)
    {
        if(mp.get(nums[i])!=undefined)
        {
            return true;
        }
        mp.set(nums[i],1);
    }
    return false;
    
};

/*what i learnt from this problem is
1. How to create instance of a map (in JS, map and unordered map are same)
2. How to check if a key is present in a map or not
3. make a key value pair in the map in JS
*/
