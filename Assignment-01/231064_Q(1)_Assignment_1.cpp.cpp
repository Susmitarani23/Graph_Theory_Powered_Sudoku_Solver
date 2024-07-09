#include <bits/stdc++.h>
using namespace std;

class Solution {
  private: 
    void dfs(int node, vector<int> adj[], vector<bool> &vis, vector<int> &ls) {
        vis[node] = true; 
        ls.push_back(node); 
        // traverse all its neighbours
        for(auto it : adj[node]) {
            if(!vis[it]) {
                dfs(it, adj, vis, ls); 
            }
        }
    }
  public:
    vector<int> dfsOfGraph(int V, vector<int> adj[], int start) {
        vector<bool> vis(V, false); 
        vector<int> ls; 
        dfs(start, adj, vis, ls); 
        return ls; 
    }
};

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printAns(const vector<int> &ans) {
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() 
{
    int V = 15;  // Total number of vertices from 0 to 15
    vector<int> adj[V];

    addEdge(adj,1,3);
    addEdge(adj,1,4);
    addEdge(adj,3,7);
    addEdge(adj,3,8);
    addEdge(adj,4,9);
    addEdge(adj,9,13);
    addEdge(adj,9,14);
    addEdge(adj,1,0);
    addEdge(adj,0,2);
    addEdge(adj,2,5);
    addEdge(adj,2,10);
    addEdge(adj,5,10);
    addEdge(adj,2,6);
    addEdge(adj,6,11);
    addEdge(adj,6,12);
    
    Solution obj;
    
    int startVertex = 4; // My roll no. is 231064.

    vector<int> ans = obj.dfsOfGraph(V, adj, startVertex);  // Passing the start vertex
    printAns(ans);

    return 0;
}
