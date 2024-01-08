class BinomCalculator
{
public:
    
    vector<int64_t> fac;
    vector<int64_t> facinv;
    int mod;
    
    template <typename T>
    static T PowWithModule(T base, T exp, T modulus) 
    {
        base %= modulus;
        T result = 1;
        while (exp > 0) 
        {
            if (exp & 1) result = (result * base) % modulus;
            base = (base * base) % modulus;
            exp >>= 1;
        }
        
        return result;
    }
  
    BinomCalculator(){}
    
    BinomCalculator(int n, int tmod)
    {
        mod = tmod;
        fac = {1, 1};
        for (int64_t i = 2; i < n + 1; ++i)    
            fac.push_back( fac.back() * i % mod );
            
        for (int i = 0; i < fac.size(); ++i)
        {
            facinv.push_back( BinomCalculator::PowWithModule<int64_t>(fac[i], mod - 2, mod) );
        }
    }
    
    int64_t Binom(int n, int k)
    {
        return fac[n] * facinv[n - k] % mod * facinv[k] % mod;
    }
};
   

class Solution {
public:
    int mod = 1e9 + 7;
    int countGoodSubsequences(string s) {
        vector<int64_t> cnts(26, 0);
        for (auto& c : s)
        {
            cnts[ c - 'a' ]++;
        }

         BinomCalculator bc(10000, mod);

        vector< vector<int64_t> > dp(26, vector<int64_t>(10005, 0));
        int64_t res = 0;
        for (int i = 0; i < 26; ++i)
        {            
            for (int t = 1; t <= 10000; ++t)
            {
                if (i - 1 >= 0) dp[i][t] = dp[i - 1][t];
                if (t <= cnts[i])
                {
                    dp[i][t] += bc.Binom(cnts[i], t);
                    //cout << dp[i][t] << endl;
                    if (i - 1 >= 0) dp[i][t] += (bc.Binom(cnts[i], t) * dp[i - 1][t]) % mod;                        
                    dp[i][t] %= mod;
                }                
            }            
        }


        for (int t = 1; t <= 10000; ++t)
        {
            res += dp[25][t];
            res %= mod;
        }

        return res;
    }
};