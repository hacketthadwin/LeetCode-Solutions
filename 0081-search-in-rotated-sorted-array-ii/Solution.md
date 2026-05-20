# BEATS 100% IN RUNTIME, COMPLETE BINARY SEARCH CODE

EITHER THIS QUESTION WAS TOO TOUGH BY THE METHOD I AM TRYING OR I AM DUMB

SO THE CHANGES I MADE FROM THE COMMENTED OUT CODE TO ACCEPTED CODE

### 1. The Global Variable Trap

**What I changed:**

```cpp
// I added this right at the start of my search() function
is_equal = false;
is_equal_2 = false;

```

**Why I did this:**
I have to remember that LeetCode doesn't create a new `Solution` object for every test case. It creates *one* object and runs `search()` multiple times. If Testcase #1 sets `is_equal_2 = true`, Testcase #2 will start with it as `true` and completely ruin my logic. I have to manually reset my state variables right at the beginning of the function.

---

### 2. The Duplicate `r--` Bug in Phase 1 (Finding the Pivot)

**What I changed:**

```cpp
// FROM (my old commented code):
else {
    if(!is_equal) { r = m; }
    else { is_equal = false; r--; }
}

// TO:
if(nums[m] == nums[r]) {
    // if the current r is exactly the point where the drop happens, doing r-- blindly will skip the pivot entirely!
    if(r - 1 >= 0 && nums[r-1] > nums[r]) {
        // we found the exact break point, so bring l right behind r to terminate loop
        l = r - 1; 
    } else {
        r--;
    }
}

```

**Why it changed & How it fits my template:**
I am trying to find the point where the array breaks. In my template, I want the pattern to be `TTTTFFFF` where `T` means `nums[m] > nums[r]`. Since I want the **last `T**` (the highest index before the drop), my "highest `x`" template says `l` will be the answer.

However, duplicates (`nums[m] == nums[r]`) destroy my strict `TTTTFFFF` pattern. If the array is `[1, 1, 1, 2, 1, 1]`, and `m` and `r` both point to `1`, I don't know which side the `2` is on. Shrinking the window with `r--` is the standard fix for this.

**But here is the catch:** What if `r` shrinks so much that it lands *exactly* on the `1` right after the `2`? If I just blindly do `r--` again, I skip over the `2` (the pivot) entirely! So, before doing `r--`, I added a manual check: "Is `r` the actual drop point?" If it is, I bring `l` right behind it (`l = r - 1`) to terminate the loop safely without stepping over my answer.

---

### 3. The `val == 0` Unrotated Array Bug

**What I changed:**

```cpp
// FROM:
if(val <= 0 || target >= nums[0] && target <= nums[val-1])

// TO:
if(val > 0 && (target >= nums[0] && target <= nums[val-1]))

```

**Why I did this:**
If `val` (the pivot index) is `0`, it means my array was **never rotated** (e.g., `[1, 2, 3]`).
In my old code, if `val <= 0`, it evaluated to `true`, and set `l = -1, r = val` (which is `0`). This basically told Phase 2 to only search between index `-1` and `0`—meaning it only checked the very first element and ignored the rest of the array.

By changing it to `val > 0`, if the array is unrotated (`val == 0`), the `if` statement evaluates to `false`. It correctly jumps to my `else` block, which sets `l = -1` and `r = nums.size()`, allowing my binary search to span the entire array like it's supposed to.

---

### 4. Phase 2: Shifting from my "Highest `x`" to "Lowest `x`" Template

This is the most important change regarding how I apply my templates!

**What I changed:**

```cpp
// FROM (my old code trying to find last T):
if(nums[m] <= target) return true; // pattern: TTTTFFFF
// ... later ...
if(l >= 0 && nums[l] == target) return true; // checking l

// TO (shifting to find first F):
if(nums[m] == target) { is_equal_2 = true; return false; }
if(nums[m] < target) return true; // strictly less than
// ... later ...
if((r < nums.size()) && nums[r] == target) return true; // checking r

```

**Why it changed & How it fits my template:**
Originally, I wanted my pattern to be `TTTTFFFF` where `T` meant `nums[m] <= target`. I was using my **highest `x**` template, which means `l` lands on the **last `T**` (the highest number `<= target`). Then I checked if `nums[l] == target`.

But again, duplicates ruined this. Using `<=` makes the partition messy when there are repeating numbers.

So, I changed the condition to strictly `< target`. This creates a much cleaner `TTTTFFFF` pattern where `T` means `nums[m] < target`.
Since I am still executing the `l = m / r = m` logic from my **highest `x**` template, `l` lands on the **last `T**` (the highest number strictly *less* than my target).

Because `l` stops on the highest number *less* than the target, **`r` naturally lands on the very first number that is `>= target**`.

This perfectly bridges into my **lowest `x**` template! If I want the lowest `x` satisfying `nums[m] >= target`, my template says the answer sits at `r`. That is exactly why I changed my final check to look at `nums[r] == target` instead of `nums[l]`.

*(Side note: I also added `if(nums[m] == target)` to just flag it and early return out of the search logic, because there's no point in finishing the binary search if I randomly land exactly on the target mid-search).*

# Code
```cpp []
// class Solution {
// public:
// bool is_equal=false;
// bool check(int m,int r,vector<int>& nums)
// {
//     is_equal=false;
//     if(nums[m]>nums[r])
//     {
//         return true;
//     }
//     if(nums[m]==nums[r])
//     {
//         is_equal=true;
//         return false;
//     }
//     return false;
    
// }
// bool f(int m,vector<int>& nums, int target)
// {
//     if(m < 0) return true;
//     if(m >= nums.size()) return false;
//     if(nums[m]<=target)return true;
//     return false;
// }
//     bool search(vector<int>& nums, int target) {
//         //yeah so similar thought process here, what i want to find if the target exists in this nums or not
//         //as it is rotated, so it has 2 parts, first i will have to find the point where it breaks, then from that point i will find the point by finding in which part it exists
//         //so first finding the point
//         //the current number is keeps on increasing and it breaks at a certain point
//         //so first my job will be to find the point where it breaks
//         //for that what can be the pattern, it would be TTTTTFFFF where T denotes if the nums[m]>nums[r]
//         //now since it can be equal also so there will be three pointers, either <,>,==
//         //also as this pattern is finding last true, if my current mid is true, then i will want to go right, for going left, i will do l=mid
//         //and also as this pattern is highest x satisfying f(x), so it will have the numbers as l=0,r=nums.size(),m;
//         //i guess for now this one's correct
//         //as i am shifting l, so l will be my correct answer at last also (also a trick that whatever is in if statement is correct answer)
//         //also my edge case will be if r is nums.size(), i cannot compare the nums[r] because it will throw error, how do i tackle it
//         //i will do 
//         // int l=0,r=nums.size(),m;
//         //NOTE : THIS IS DIFFERENT FROM NORMAL BINARY SEARCH PROBLEMS THAT'S WHY I AM HAVING DIFFICULTY, IN NORMAL BS, WE DON'T TAKE r INTO CONSIDERATION HENCE, WE WRITE r=highest_possible_value+1, BUT SINCE HERE WE TOOK r IN CONSIDERATION, SO IT WILL BE r=nums.size()-1 AND FOR COUNTERING THAT, WE TAKE ONE STEP BEHIND AS VIRTUAL BOUNDARY l=-1. BUT THIS IS ONLY FOR THIS PROBLEM
        
//         int l=-1,r=nums.size()-1,m;
//         while(r-l>1)
//         {
//             m=l+(r-l)/2;
//             if(check(m,r,nums))
//             {
//                 l=m;
//             }
//             else
//             {
//                 if(!is_equal)
//                 {
//                     r=m;
//                 }
//                 else
//                 {
//                     is_equal=false;
//                     r--;
//                 }

//             }
//         }

//         //l is my last highest number, like including all its equal values too, r is the point from where second line starts
//         int val=r;
//         //so my first check will be from 0 to l, then second can be from r to nums.size()

//         //then for searching, i have been given limits of array, i have been given target, i just have to find target
//         //this is problem of finding target now, so how do we find target in array, we just do typically binary_search() function, but i want to do manually, so if nums[m]<=target, move right, else move left
//         //so my pattern would be TTTTTFFFFF and the last T will be my answer, so again this problem is of finding highest x satisfying f(x) and if my current mid is true, then i will want to go right, that is l=mid
//         if(val<=0 || target>=nums[0] && target<=nums[val-1])
//         {
//             l=-1,r=val;
//             while(r-l>1)
//             {
//                 m=l+(r-l)/2;
//                 if(f(m,nums,target))
//                 {
//                     l=m;
//                 }
//                 else
//                 {
//                     r=m;
//                 }
//             }

//             //then the final l will be my answer, so
//             if(l>=0 && nums[l]==target)return true;
//             return false;

//         }
//         else
//         {
//             l=val-1,r=nums.size();
//             while(r-l>1)
//             {
//                 m=l+(r-l)/2;
//                 if(f(m,nums,target))
//                 {
//                     l=m;
//                 }
//                 else
//                 {
//                     r=m;
//                 }
//             }

//             //then the final l will be my answer, so
//             if(nums[l]==target)return true;
//             return false;

//         }
//     }
// };

class Solution {
public:

bool is_equal=false;
bool is_equal_2=false;

bool check(int m,int r,vector<int>& nums)
{
    if(nums[m]>nums[r])
    {
        return true;
    }

    return false;
    
}

bool f(int m,vector<int>& nums, int target)
{
    //virtual true boundary
    if(m < 0) return true;

    //virtual false boundary
    if(m >= nums.size()) return false;

    //equal handled separately because equality destroys clean TTTTFFFF partition
    if(nums[m]==target)
    {
        is_equal_2=true;
        return false;
    }

    //changed <= to < because now pattern becomes proper TTTTFFFF
    if(nums[m]<target)return true;

    return false;
}

    bool search(vector<int>& nums, int target) {

        //so first thing i need to do is reset my global variables because leetcode creates one object and uses it for all test cases, so old true values will carry over and ruin my logic
        is_equal=false;
        is_equal_2=false;

        //yeah so similar thought process here, what i want to find if the target exists in this nums or not

        //as it is rotated, so it has 2 parts, first i will have to find the point where it breaks, then from that point i will find the point by finding in which part it exists

        //so first finding the point

        //the current number is keeps on increasing and it breaks at a certain point

        //so first my job will be to find the point where it breaks

        //for that what can be the pattern, it would be TTTTTFFFF where T denotes if the nums[m]>nums[r]

        //now since it can be equal also so there will be three pointers, either <,>,==

        //also as this pattern is finding last true, if my current mid is true, then i will want to go right, for going right, i will do l=mid

        //NOTE : THIS IS DIFFERENT FROM NORMAL BINARY SEARCH PROBLEMS THAT'S WHY I AM HAVING DIFFICULTY, IN NORMAL BS, WE DON'T TAKE r INTO CONSIDERATION HENCE, WE WRITE r=highest_possible_value+1, BUT SINCE HERE WE TOOK r IN CONSIDERATION, SO IT WILL BE r=nums.size()-1 AND FOR COUNTERING THAT, WE TAKE ONE STEP BEHIND AS VIRTUAL BOUNDARY l=-1. BUT THIS IS ONLY FOR THIS PROBLEM
        
        int l=-1,r=nums.size()-1,m;

        while(r-l>1)
        {
            m=l+(r-l)/2;

            //duplicates destroy monotonicity, cannot infer side safely
            if(nums[m]==nums[r])
            {
                //if the current r is exactly the point where the drop happens, doing r-- blindly will skip the pivot entirely!
                //the drop point is the ONLY place where the previous number is greater than current number
                if(r - 1 >= 0 && nums[r-1] > nums[r])
                {
                    //we found the exact break point, so we bring l right behind r to terminate the loop perfectly
                    l = r - 1; 
                }
                else
                {
                    r--;
                }
            }
            else if(check(m,r,nums))
            {
                l=m;
            }
            else
            {
                r=m;
            }
        }

        //pivot is first false
        int val=r;

        //left half is [0...val-1]
        //right half is [val...n-1]

        //then for searching, i have been given limits of array, i have been given target, i just have to find target

        //this is problem of finding target now

        //pattern becomes TTTTFFFF where T means nums[m]<target

        //i changed val==0 to val>0 here because if val is 0 then array is not rotated at all like [1,2,3], so if i keep it val==0 it will just search from -1 to 0 and fail, so i want it to go to else block to search whole array limits
        if(val>0 && (target>=nums[0] && target<=nums[val-1]))
        {
            //virtual true
            l=-1;

            //virtual false
            r=val;

            while(r-l>1)
            {
                m=l+(r-l)/2;

                is_equal_2=false;

                if(f(m,nums,target))
                {
                    l=m;
                }
                else
                {
                    //equal handled separately
                    if(is_equal_2)return true;

                    r=m;
                }
            }

            if((r<nums.size())&&(nums[r]==target))return true;

            return false;

        }
        else
        {
            //virtual true
            l=val-1;

            //virtual false
            r=nums.size();

            while(r-l>1)
            {
                m=l+(r-l)/2;

                is_equal_2=false;

                if(f(m,nums,target))
                {
                    l=m;
                }
                else
                {
                    //equal handled separately
                    if(is_equal_2)return true;

                    r=m;
                }
            }

            if((r<nums.size())&&(nums[r]==target))return true;

            return false;
        }
    }
};
```

SIMPLER BS WITHOUT PREDICATE FXN
```
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        
        while(l <= r)
        {
            int mid = l + (r-l) / 2;
            if (nums[mid] == target)
                return true;
			// with duplicates we can have this contdition, just update left & right
            if((nums[l] == nums[mid]) && (nums[r] == nums[mid]))
            {
                l++;
                r--;
            }
			// first half
			// first half is in order
            else if(nums[l] <= nums[mid])
            {
				// target is in first  half
                if((nums[l] <= target) && (nums[mid] > target))
                    r = mid - 1;
                else
                    l = mid + 1;
            }
			// second half
			// second half is order
			// target is in second half
            else
            {
                if((nums[mid] < target) && (nums[r]>= target))
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }
        return false;
    }
};
```