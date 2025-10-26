/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
 function compare(a,b){
    return a[0] - b[0];
 }

var twoSum = function(nums, target) {

    // var arr = [];
    // for (var i = 0; i < nums.length; i++) {
    //     arr.push([nums[i], i]);
    // }

    //another method is
    var arr = nums.map((a,b)=>[a,b]);

    arr.sort(compare)
    var n=arr.length
    for(var i=0, j=n-1;i<j;)
    {
        if((arr[i][0] + arr[j][0])>target)
        {
            j--;
        }
        else if((arr[i][0] + arr[j][0])<target)
        {
            i++;
        }
        else
        {
            return [arr[i][1],arr[j][1]]
        }
    }

    return [];
    
};

//so summary of what i learnt from this problem

/*1. .map() can take upto 3 arguments automatically assigning first one to value, second one to index and third one to length
2. sorting of number requires a compare function 
3. To make a deep copy, i can use map also
*/

