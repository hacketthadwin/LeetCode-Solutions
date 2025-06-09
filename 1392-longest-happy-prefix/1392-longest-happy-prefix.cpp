#define ll long long
ll mod_mul(ll a, ll b, ll mod) {
    return (a % mod * b % mod) % mod;
}

ll mod_sub(ll a, ll b, ll mod) {
    return (a - b + mod) % mod;
}

ll binpow(ll a, ll b, ll mod) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

ll mminvprime(ll a, ll mod) {
    return binpow(a, mod - 2, mod);
}
#define sz(x) (int)(x).size()

struct Hashing{
    string s;
    int n;
    int primes;
    vector<ll> hashPrimes = {1000000009, 100000007};
    const ll base = 31;
    vector<vector<ll>> hashValues;
    vector<vector<ll>> powersOfBase;
    vector<vector<ll>> inversePowersOfBase;
    Hashing(string a){
        primes = sz(hashPrimes);
        hashValues.resize(primes);
        powersOfBase.resize(primes);
        inversePowersOfBase.resize(primes);
        s = a;
        n = s.length(); 
        for(int i = 0; i < sz(hashPrimes); i++) {
            powersOfBase[i].resize(n + 1);
            inversePowersOfBase[i].resize(n + 1);
            powersOfBase[i][0] = 1;
            for(int j = 1; j <= n; j++){
                powersOfBase[i][j] = (base * powersOfBase[i][j - 1]) % hashPrimes[i];
            }
            inversePowersOfBase[i][n] = mminvprime(powersOfBase[i][n], hashPrimes[i]);
            for(int j = n - 1; j >= 0; j--){
                inversePowersOfBase[i][j] = mod_mul(inversePowersOfBase[i][j + 1], base, hashPrimes[i]);
            } 
        }
        for(int i = 0; i < sz(hashPrimes); i++) {
            hashValues[i].resize(n);
            for(int j = 0; j < n; j++){
                hashValues[i][j] = ((s[j] - 'a' + 1LL) * powersOfBase[i][j]) % hashPrimes[i];
                hashValues[i][j] = (hashValues[i][j] + (j > 0 ? hashValues[i][j - 1] : 0LL)) % hashPrimes[i];
            }
        }
    }
    vector<ll> substringHash(int l, int r){
        vector<ll> hash(primes);
        for(int i = 0; i < primes; i++){
            ll val1 = hashValues[i][r];
            ll val2 = l > 0 ? hashValues[i][l - 1] : 0LL;
            hash[i] = mod_mul(mod_sub(val1, val2, hashPrimes[i]), inversePowersOfBase[i][l], hashPrimes[i]);
        }
        return hash;
    }
};
class Solution {
public:
    string longestPrefix(string s) {
        int i=0;
        int n=s.size();
        Hashing hs= Hashing(s);   //we can also do only Hashing hs(s);
        vector<ll>hash_values1;
        vector<ll>hash_values2;
        string ans="";
        int maxlen=0;
        for(int i=0;i<n-1;i++)  //till n-1 for bette
        {
            hash_values1=hs.substringHash(0,i);
            hash_values2=hs.substringHash(n-i-1,n-1);
            if(hash_values1[0]==hash_values2[0] && hash_values1[1]==hash_values2[1])
            {
                maxlen=i+1;
            }
        }
        ans=s.substr(0,maxlen);
        return ans;
    }
};

//i thought to do this
// if (hash matches) {
//     ans += s[i];
// }
//but this code has error because consider
//if at i=0, in second case, it will check like if('a'=='b') but this is not same, so it will not append character 'a' because hash values is not same, so due to this answer will be wrong