#include<iostream>
#include <list>
using namespace std;

class Graph
{
    int V;   
    list<int> *adj;   
    void DFSUtil(int v, bool visited[]); 
    list <int> topologicalOrder;
public:
    Graph(int V);  
    void addEdge(int v, int w); 
    void BFS(int s);  
    void DFS(int v);
    list <int> getTopologicalOrder()    
    {
        if (topologicalOrder.empty())
         this->DFS(0);

        return topologicalOrder;
    }

    void printTopologicalOrder()    
    {
        if (topologicalOrder.empty())
            this->DFS(0);

        printf("Topological Order :");
        for (list<int>::iterator it = topologicalOrder.begin(); it != topologicalOrder.end(); it++)
            printf(" %d", *it);
        printf("\n");
    }
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}
 
void Graph::BFS(int s)
{
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
    list<int> queue;
    visited[s] = true;
    queue.push_back(s);
    list<int>::iterator i;
    while(!queue.empty())
    {
   
        s = queue.front();
        cout << s << " ";
        queue.pop_front();
        for(i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if(!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

void Graph::DFSUtil(int v, bool visited[])
{
   
    visited[v] = true;
    cout << v << " ";
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
     topologicalOrder.push_front(v);
}

void Graph::DFS(int v)
{
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    DFSUtil(v, visited);
}

int main()
{
    Graph g(4);
    int n,i,j;
    cout<<"Enter the no of edges ";
    cin>>n;
    while(n--)
    {
    cin>>i>>j;
    g.addEdge(i, j);
    }
    cout<<"Enter the source vertex ";
    cin>>n;
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex "<<n<<") \n";
    g.BFS(n);
    cout << "Following is Depth First Traversal "
         << "(starting from vertex "<<n<<") \n";
    g.DFS(n);
     g.printTopologicalOrder();
    return 0;
}
