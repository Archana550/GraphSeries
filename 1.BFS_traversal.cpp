#include<bits/stdc++.h>
using namespace std;

void bfsHelper(int src, vector<int> &vis, vector<int> &bfs, vector<int> adj[]){
        queue<int> q;
        q.push(src);
        vis[src] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            for(auto it : adj[node]){
                if(!vis[it]){
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
    }

vector<int> findBFS(int v, vector<int> adj[]){
    vector<int> vis(v, 0);
    vector<int> bfs;
    for(int i=0; i<v; i++){
        if(!vis[i]){
            bfsHelper(i, vis, bfs, adj);
        }
    }
    
    return bfs;
}
int main(){
    int n, m;
    cin>>n>>m;
    
    vector<int> adj[n];
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> ans = findBFS(n, adj);
    for(int i=0; i<n; i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}