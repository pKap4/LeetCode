//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    bool dfs_checker(int src, int V, vector<int> adj[], vector<bool> &visited, 
    vector<bool> &pathVisited){
        
        //mark current as visited
        visited[src] = true;
        pathVisited[src] = true;
        
        for(auto neighbour: adj[src]){
            if(!visited[neighbour]){
                if(dfs_checker(neighbour, V, adj, visited, pathVisited))
                return true;
            }
            else if(visited[neighbour] && pathVisited[neighbour]){
                return true;
            }
        }
        
        pathVisited[src] = false;
        return false;
        
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool> visited(V);
        
        for(int i = 0; i<V; i++){
            if(!visited[i]){
                visited[i] = true;
                vector<bool> pathVisited(V);
                if(dfs_checker(i, V, adj, visited, pathVisited)){
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends