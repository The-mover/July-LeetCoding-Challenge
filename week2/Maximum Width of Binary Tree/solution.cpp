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
public:
    int widthOfBinaryTree(TreeNode* root) {
        if( !root ) return 0;
        queue<pair<TreeNode*, unsigned int>> q;
        q.push({root, 1});
        unsigned int mx = 0;
        while( !q.empty() ) {
            unsigned int size = q.size();
            unsigned int L = q.front().second;
            unsigned int R = q.front().second;
            for(int i=0; i<size; i++) {
                TreeNode *top = q.front().first;
                R = q.front().second;
                q.pop();
                if( top->left ) q.push({top->left, R * 2});
                if( top-> right ) q.push({top->right, R * 2 + 1});
            }
            unsigned int val = R - L + 1;
            mx = max(mx, val);
        }
        
        return mx;
    }
};