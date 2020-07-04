class Solution {
public:
    int nthUglyNumber(int n) {
        vector<long long> store;
        long long mx = INT_MAX;
        for(long long a=1; a<=mx; a*=2) {
            for(long long b=a; b<=mx; b*=3) {
                for(long long c=b; c<=mx; c*=5) {
                    store.push_back(c);
                }
            }
        }
        sort(store.begin(), store.end());
        return store[n-1];
    }
};