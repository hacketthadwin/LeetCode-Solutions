class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        //so basically i cannot make sequences or even iterate through each m 
        //now the pattern is +5 / -1 or -1 / +5 in whichever i get maximum number at last...so 0,5,4,9
        //0 5 4 9 8
        //(n-1)/2 decrements of -1, n/2 increments of m
        long long temp = (long long)(n/2)*m;
        temp-=((long long)(n-2)/2);
        return temp+s;
    }
};