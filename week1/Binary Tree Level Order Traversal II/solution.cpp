/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    vector<vector<int>> ans;
    void helper(TreeNode *root) {
        queue<TreeNode*> q;
        q.push(root);
        while( !q.empty() ) {
            int size = q.size();
            vector<int> level;
            for(int i=0; i<size; i++) {
                TreeNode *top = q.front();
                q.pop();
                level.push_back( top->val );
                if( top->left ) q.push(top->left);
                if( top->right ) q.push(top->right);
            }
            ans.push_back(level);
        }
    }
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if( !root ) return ans;
        helper(root);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};