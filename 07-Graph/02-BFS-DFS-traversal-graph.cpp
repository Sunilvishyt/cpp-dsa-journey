////BFS traversal/////////////////////////////////////////////////////////////////////////////////////////////////// 
//T.C. o(V+E)
//S.C. O(V)
class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        queue<int>q;
        q.push(0);
        
        vector<int>ans;
        vector<bool>visited(adj.size(),0);
        visited[0] = 1;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            ans.push_back(node);
            
            for (int i = 0; i < adj[node].size(); i++){
                if (!visited[adj[node][i]]){
                    q.push(adj[node][i]);
                    visited[adj[node][i]] = 1;
                }
            }
        }
        
        return ans;
    }
};


////DFS traversal///////////////////////////////////////////////////////////////////////////////////////////
//same time complexity
class Solution {
  public:
    void DFS(int node, vector<bool>&visited, vector<int>&ans, vector<vector<int>>& adj){
        visited[node] = 1;
        ans.push_back(node);
        
        for (int i = 0; i < adj[node].size(); i++){
            if (!visited[adj[node][i]]){
                DFS(adj[node][i],visited, ans, adj);
            }
        }
    }
    
    vector<int> dfs(vector<vector<int>>& adj) {
        vector<int>ans;
        vector<bool>visited(adj.size(),0);
        DFS(0, visited, ans, adj);
        return ans;
    }
};
