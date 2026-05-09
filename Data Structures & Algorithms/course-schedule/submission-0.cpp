class Solution {
public:
//using BFS Khan's Algorithm(topo sort):
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        for(auto &p : prerequisites) {
            int u = p[0];
            int v = p[1];
            indegree[v]++;
            adj[u].push_back(v);
        }
        queue<int> q;
        for(int i = 0; i<n; i++) {
            if(indegree[i] == 0) q.push(i);
        }
        int count = 0;
        while(!q.empty()){
            count++;
            int node = q.front();
            q.pop();
            for(int it : adj[node]){
                if(--indegree[it] == 0) q.push(it);
            }
        }
        return numCourses == count;
    }
};