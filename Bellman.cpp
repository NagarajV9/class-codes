#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

class Graph{
private:
        int V;
        vector<pair<int,pair<int,int> > > edges;
        bool hasNegativeCycle = false;
public:
    Graph(int V);
    void addEdge(int u,int v,int w);
    void bellmanFord(int src);
};

Graph::Graph(int V){
    this->V = V;
}

void Graph::addEdge(int u,int v,int w){
     edges.push_back({w,{u,v}});
}

void Graph::bellmanFord(int src)
{
    vector<int> dist(this->V,INF);
    dist[src] = 0;
    vector<pair<int,pair<int,int> > >::iterator it;
    for(int i=1;i<this->V;i++)
    {
        for(it = edges.begin();it!=edges.end();++it)
        {
            int u = it->second.first;
            int v = it->second.second;
            int w = it->first;
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
            }
        }
    }
    for(it = edges.begin();it!=edges.end();++it)
    {
        int u = it->second.first;
        int v = it->second.second;
        int w = it->first;
        if(dist[u] + w < dist[v]){
            this->hasNegativeCycle = true;
            //return false
        }
    } 
    if(!hasNegativeCycle){
        for(int i=0;i<V;i++){
            cout << i << " - " << dist[i] << endl;
        }
    }
}
int main(){
    int V;
    cout<<"Enter the no of vertices ";
    cin>>V;
    int E,i,j,w;
    Graph g(V);
    cout<<"\nEnter the no of edges ";
    cin>>E;
    while(E--)
    {
    cin>>i>>j>>w;
    g.addEdge(i,j,w);
    }
    cout<<"\nEnter the source ";
    cin>>E;
    g.bellmanFord(E);
    return 0;
}
