//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    bool checker(int src, int V, vector<int> adj[]){
        vector<bool> visited(V);
        vector<int> parent(V);
        stack<int> s;
        
        for(int i = 0; i<V; i++){
            visited[i] = false;
            parent[i] = -1;
        }
        
        s.push(src);
        visited[src] = true;
        
        while(!s.empty()){
            int top = s.top();
            s.pop();
            
            for(auto child: adj[top]){
                if(!visited[child]){
                    visited[child] = true;
                    parent[child] = top;
                    s.push(child);
                }
                else if(parent[top] != child){
                    return true;
                }
            }
        }
        
        return false;
    }
  
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> visited(V);
        
        //for components
        for(int i = 0; i<V; i++){
            if(!visited[i]){
                if(checker(i, V, adj))
                    return true;
                visited[i] = true;
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends