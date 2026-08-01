class Solution:

    def rec(self,i,j,text1,text2,dp):
        if i>=len(text1) or j>=len(text2):
            return 0
        if self.dp[i][j]!=-1:
            return self.dp[i][j]
        cnt=0
        if text1[i]==text2[j]:
            cnt=max(cnt,self.rec(i+1,j+1,text1,text2,dp)+1)
        cnt=max(cnt,self.rec(i+1,j,text1,text2,dp))
        cnt=max(cnt,self.rec(i,j+1,text1,text2,dp))

        self.dp[i][j]=cnt
        return cnt

    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        self.dp=[[-1] * 1001 for _ in range(1001)]
        return self.rec(0,0,text1,text2,self.dp)

        