class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int> temp(n+1, 0);
        vector<int> ans;
        
        int carry = 0;
        
        for(int i=n-1; i>=0; i--) {
            if( i == n-1 ) {
                int val = digits[i] + 1;
                if( val == 10 ) {
                    carry = 1;
                    temp[i+1] = 0;
                } else {
                    temp[i+1] = val;
                    carry = 0;
                }
            } else {
                int val = digits[i] + carry;
                if( val == 10 ) {
                    carry = 1;
                    temp[i+1] = 0;
                } else {
                    temp[i+1] = val;
                    carry = 0;
                }
            }
        }
        
        if( carry ) temp[0] = 1;
        
        bool flag = false;
        
        for(int i=0; i<=n; i++) {
            if( temp[i] ) flag = true;
            if( flag ) ans.push_back(temp[i]);
        }
        
        return ans;
    }
};