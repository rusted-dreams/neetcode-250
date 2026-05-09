class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        for(auto &p : prerequisites) {
            int a = p[0];
            int b = p[1];
            indegree[a]++;
            adj[b].push_back(a);
        }
        queue<int> q;
        for(int i = 0; i<n; i++) {
            if(indegree[i] == 0) q.push(i);
        }
        vector<int> order;
        while(!q.empty()){
            int node = q.front();
            order.push_back(node);
            q.pop();
            for(int it : adj[node]){
                if(--indegree[it] == 0) q.push(it);
            }
        }
        if (order.size() == n) return order;
        else return {};
    }
};