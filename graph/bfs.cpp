#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fr first
#define sc second
#define srt(a) sort((a).begin(),(a).end());
#define dsrt(a) sort((a).begin(),(a).end(),greater<>())

class graph{
    int V;
    vector<std::vector<int>> arr;
public:
    graph(int V){
        this->V=V;
    
        arr.resize(V);

    }
    void addEdge(int u,int v){
        arr[u].pb(v);
       // arr[v].pb(u);
    }
    void bfs(int s){
        vector<bool> visited;
        visited.resize(V,false);
        queue<int> q;
        q.push(s);
        while(!q.empty()){
            s = q.front();
            q.pop();
            cout<<s<<" ";
            for(auto it:arr[s]){
                if(!visited[it]){
                    visited[it]=true;
                    q.push(it);
                }
            }

        }
    }


};

int main(){
    
    graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    int n;
    cin>>n;
    g.bfs(n);
    return 0;
}
