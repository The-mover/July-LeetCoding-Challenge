class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        vector<vector<int>>mat(16, vector<int> (8, 0));
        for(int j=1; j<16; j++) {
            vector<int> temp(8, 0);
            for(int i=0; i<8; i++) {
                if( i == 0 || i == 7 ) {
                    temp[i] = 0;
                }
                else {
                    if( cells[i-1] == cells[i+1] ) {
                        temp[i] = 1;
                    } else {
                        temp[i] = 0;
                    }
                }
            }
            cells = temp;
            mat[j] = temp;
        }
        int ans = N % 14;
        if( ans == 0 ) return mat[14];
        return mat[ans];
    }
};