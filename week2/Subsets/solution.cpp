class Solution {
private:
    void allSubset(int idx, vector<int>& nums, vector<int>& subset, vector<vector<int>>& ans) {
        ans.push_back(subset);
        for(int i=idx; i<nums.size(); i++) {
            subset.push_back(nums[i]);
            allSubset(i + 1, nums, subset, ans);
            subset.pop_back();
        }
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        allSubset(0, nums, subset, ans);
        
        return ans;
    }
};