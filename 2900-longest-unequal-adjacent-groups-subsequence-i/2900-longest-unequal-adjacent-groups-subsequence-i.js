/**
 * @param {string[]} words
 * @param {number[]} groups
 * @return {string[]}
 */
var rec = (index, words, groups,dp) => {
    // Base case
    if (index === words.length) return [];

    let currbin = groups[index];
    let maxSubsequence = [];
    if(dp[index].length!=0)return dp[index];
    // Compute and transition
    for (let i = index + 1; i < words.length; i++) {
        if (groups[i] !== currbin) 
        {
            let nextSubsequence = rec(i, words, groups,dp);
            if (nextSubsequence.length > maxSubsequence.length) {
                maxSubsequence = nextSubsequence;
            }
        }
    }

    dp[index]=[words[index], ...maxSubsequence];
    return [words[index], ...maxSubsequence];
};

var getLongestSubsequence = function(words, groups) {
    let longestSubsequence = [];
    let dp = Array.from({ length: words.length+2 }, () => []);
    for (let i = 0; i < words.length; i++) {
        let subsequence = rec(i, words, groups,dp);
        if (subsequence.length > longestSubsequence.length) {
            longestSubsequence = subsequence;
        }
    }

    return longestSubsequence;
};