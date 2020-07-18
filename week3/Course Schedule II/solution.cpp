class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<int> ans;
        vector<int> indegree(numCourses, 0);
        
        for(auto sub: prerequisites) {
            int u = sub[0];
            int v = sub[1];
            adj[v].push_back(u);
            indegree[u]++;
        }
        
        queue<int> q;
        for(int i=0; i<numCourses; i++) {
            if( !indegree[i] ) {
                q.push(i);
            }
        }
        
        while( !q.empty() ) {
            int u = q.front();
            q.pop();
            ans.push_back(u);
            for(auto v: adj[u]) {
                indegree[v]--;
                if( !indegree[v] ) {
                    q.push(v);
                }
            }
        }
        
        if( ans.size() == numCourses ) return ans;
        else return vector<int>();
        
    }
};