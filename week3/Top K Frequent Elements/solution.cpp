class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        set<pair<int, int>> st;
        for(int num: nums) {
            mp[num]++;
        }
        vector<int> ans;
        for(auto it: mp) {
            st.insert({-it.second, it.first});
        }
        for(auto it: st) {
            if(  k ) {
                k--;
                ans.push_back(it.second);
            }
        }
        return ans;
    }
};