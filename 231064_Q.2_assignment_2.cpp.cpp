#include<bits/stdc++.h>
using namespace std;
 
const long long INF = INT_MAX;
 
void dijkstra(int n, vector<vector<pair<int, int>>> &graph, vector<long long> &dist, int source) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
  // greater is use for ensure that the priority queue store in  min-heap(smallest  element appear in front/first)
    dist[source] = 0;
    pq.push({0, source});
 
    while (!pq.empty()) {
        long long current_dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();    // Remove the element with highest priority
 
        if (current_dist > dist[u]) continue;
 
        for (auto &[v, weight] : graph[u]) {
            long long distance = current_dist + weight;
            if (distance < dist[v]) {
                dist[v] = distance;
                pq.push({distance, v});
            }
        }
    }
}
 
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n + 1);
    
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].emplace_back(b, c);   // weight is c between city "a" to city "b"
    }
 
    vector<long long> dist(n + 1, INF);  // INF means infinity or maximum number
    dijkstra(n, graph, dist, 1);
 
    for (int i = 1; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;
 
    return 0;
}

