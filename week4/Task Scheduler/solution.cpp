class Solution {
private:
    int cnt[26];
    
public:
    int leastInterval(vector<char>& tasks, int n) {
        int mx = 0;
        for(char c: tasks) {
            cnt[c-'A']++;
            mx = max(mx, cnt[c-'A']);
        }
        
        int ans = (mx - 1) * (n + 1);
        for(int i=0; i<26; i++) {
            if( cnt[i] == mx ) ans++;
        }
        
        
        ans = max(ans, (int)tasks.size());
        return ans;
    }
};