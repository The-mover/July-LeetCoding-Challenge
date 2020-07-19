class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.size();
        int m = b.size();
        
        int len = max(n, m);
        
        if( n != len ) {
            int dif = len - n;
            string pre(dif, '0');
            a = pre + a;
        } else if( m != len ) {
            int dif = len - m;
            string pre(dif, '0');
            b = pre + b;
        }
        
        int carry = 0;
        string ans(len, '0');
        
        for(int i=len; i>=0; i--) {
            int x = a[i] - '0';
            int y = b[i] - '0';
            int sum = x + y + carry;
            if( sum == 1 ) {
                ans[i] = '1';
                carry = 0;
            } 
            else if( sum == 2 ) {
                //cout << "ok\n";
                carry = 1;
            } 
            else if( sum == 3 ) {
                ans[i] = '1';
                carry = 1;   
            }
        }
        if( carry ) return '1' + ans;
        return ans;
    }
};