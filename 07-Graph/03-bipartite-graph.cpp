//check whether the graph is bipartite or not

////BFS////////////////////////////////////////////////////////////
//T.C - V+E
//S.C. V
class Solution {
  public:
    
    bool isBipartite(int V, vector<vector<int>> &edges) {
        vector<vector<int>>adj(V);
        for (auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int>color(V, -1); //-1 means no color, 0 means red, 1 means blue
        queue<int>q;
        
        q.push(0);
        color[0] = 0;
        
        while (!q.empty()){
            int node = q.front();
            q.pop();
            
            for (int j = 0; j < adj[node].size(); j++){
                //two cases can be there
                //color is not assigned to neighbour
                int neighbour = adj[node][j];
                
                if (color[neighbour] == -1){
                    color[neighbour] = (color[node] + 1) % 2;
                    q.push(neighbour);
                }
                
                //color is assigned
                else if (color[neighbour] == color[node]){
                    return 0;
                }
            }
        }
        
        return 1;
        
    }



////DFS solution ///////////////////////////////////////////////////////////////////////////////////////////////////////////
// T.C - V+E
// S.C. V
class Solution {
	public:
	bool check(int node, vector<vector<int>> &adj, vector<int>&color) {
		
		for (int j = 0; j < adj[node].size(); j++) {
			int neighbour = adj[node][j];
			if (color[neighbour] == -1) {
				color[neighbour] = (color[node] + 1)% 2;
				if (!check(neighbour, adj, color)) {
					return 0;
				}
			}
			
			else {
				if (color[neighbour] == color[node]) {
					return 0;
				}
			}
		}
		
		return 1;
	}
	
	bool isBipartite(int V, vector<vector<int>> &edges) {
		vector<vector<int>> adj(V);
		for (auto &edge : edges) {
			int u = edge[0];
			int v = edge[1];
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		
		vector<int>color(V, -1); // -1 means no color, 0 means red, 1 means blue
		
		for (int i = 0; i < adj.size(); i++) {
			if (color[i] == -1) {
				
				color[i] = 0;
				
				if (!check(i, adj, color)) {
					return 0;
				}
			}
		}
		
		return 1;
	}
};

};
