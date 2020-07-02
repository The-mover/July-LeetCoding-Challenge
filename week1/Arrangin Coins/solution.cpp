class Solution {
public:
    int arrangeCoins(int n) {
        if( n <= 1 ) return n;
        
        long long lo = 1, hi = n, val, mid;
        
        while( lo < hi ) {
            mid =  lo + ((hi - lo) / 2);
            val = (mid * (mid + 1)) / 2;
            if( val > n ) {
                hi = mid;
            }
            else if( val <= n ) {
                lo = mid + 1;
            }
        }
        
        return lo-1;
    }
};