class Solution {
public:
    int hammingDistance(int x, int y) {
        int xx = x ^ y;
        int ans = 0;
        for(int i=0; i<32; i++) {
            ans += (xx >> i) & 1;
        }
        return ans;
    }
};