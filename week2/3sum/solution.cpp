class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        int last = INT_MIN;
        for(int i=0; i<n; i++) {
            int target = -nums[i];
            int start = i+1;
            int end = n - 1;
            if( nums[i] == last ) continue;
            last = nums[i];
            while( start < end ) {
                int sum = nums[start] + nums[end];
                if( sum == target ) {
                    vector<int> res{nums[i], nums[start], nums[end]};
                    ans.push_back(res);
                    while( nums[start] == res[1] && start < end) start++;
                    while( nums[end] == res[2] && start < end ) end--;
                    
                } else if( sum < target ) {
                    start++;
                } else {
                    end--;
                }
            }
        }
        return ans;
    }
};