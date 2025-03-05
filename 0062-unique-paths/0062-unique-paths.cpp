//Adarsh Jha
//lowest < current < greatest
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
#define ll long long 
#define endl "\n"
typedef pair<int, int> pii;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
#define repn(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define rep(n) repn(i, 0, n)
#define repi(i,n) repn(i, 0, n)
#define pb push_back
#define ALL(v) v.begin(), v.end()
#define ALLA(arr, sz) arr, arr + sz
#define SORTA(arr, sz) sort(ALLA(arr, sz))
#define REVERSEA(arr, sz) reverse(ALLA(arr, sz))
#define PERMUTE next_permutation
#define TC(t) while (t--)
#define mod 1000000007
#define count_set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
const int N=1e5+1;
#define maxa(arr,n) *max_element(arr, arr+n)
#define mina(arr,n) *min_element(arr, arr+n)
#define pn cout << "NO\n";
#define py cout << "YES\n";
int lcm(int a,int b){return ((a/__gcd(a,b))*b);}
bool isprime(int n){if(n==1||n==0)return false;for(int i=2;i*i<=n;i++){if(n%i==0) return false;}return true;}
void prime_factor(vector<pii> &factorization,int n){for(int i=2; i*i <= n; i++) {int count = 0;while(n % i == 0) {count++;n /= i;}if(count > 0) {factorization.push_back({i, count});}}if(n != 1) {factorization.push_back({n, 1});}}
void divisor(vi &div,int n){for(int i=1;i*i<=n;i++){if(n%i == 0){if(i == n/i)div.push_back(i);else{div.push_back(i);div.push_back(n/i);}}}}
int ncr(int n , int r){  int num =1, deno =1;if(r==0)return 1;    else{while(r>0){num*= n;deno*= r; int temp = __gcd(num , deno);num/= temp;deno/= temp;n--;r--;}}    return num;}
int ceel(int a,int b){if(a%b==0) return a/b;else return a/b+1;}
void convertToLowercase(string &str) {for (char &c : str) {if (c >= 'A' && c <= 'Z') {c = c + 32;}}}    
int maximumrepitationofarray(int n,int arr[]){int count=0;int maxcount=1;int c= arr[0];rep(n){if(arr[i]==c){count++;if(count>maxcount){maxcount=count;}}else{count=1;c=arr[i];}}return maxcount;}
bool poweroftwo(int n) {return !(n & (n - 1));}
int power(int A, int B) {int res = 1;while (B > 0) {if (B % 2 == 1) {    res *= A;}A *= A;B /= 2;}return res;}
/*REMOVE LEADING ZEROES
size_t pos = result.find_first_not_of('0');
result = (pos == std::string::npos) ? "0" : result.substr(pos);
*/
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;  //you can use less/greater/less_equal/greater_equal instead of less<int> as per your requirement
class Solution {
public:
long long combination(int n, int r) {
    if (r > n - r) {
        r = n - r;  // C(n, r) = C(n, n-r), pick the smaller r
    }
    long long result = 1;
    for (int i = 1; i <= r; i++) {
        // Multiply by (n-r+i) first to keep the intermediate as large as possible
        result = result * (n - r + i) / i;
    }
    return result;
}

// Computes number of unique paths in an m x n grid
long long uniquePathsu(int m, int n) {
    // We want C((m-1)+(n-1), (m-1)) = C(m+n-2, m-1)
    return combination(m + n - 2, m - 1);
}
    int uniquePaths(int m, int n) {
        return uniquePathsu(m, n);
    }
};