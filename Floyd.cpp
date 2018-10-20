#include<bits/stdc++.h>
using namespace std;
#define INF 99999

class Graph
{
    int V;
    int graph[4][4],dist[4][4];
    public:
    Graph(int a,int ar[4][4])
    {
        V=a;
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            graph[i][j]=ar[i][j];
        }
    }
    void printSolution()
   {
    cout<<"Following matrix shows the shortest distances between every pair of vertices \n";
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf ("%7d", dist[i][j]);
        }
        printf("\n");
    }
   }
   
   void floydWarshall ()
{
    int  i, j, k;
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];
    for (k = 0; k < V; k++)
    {
        for (i = 0; i < V; i++)
        {
            for (j = 0; j < V; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    printSolution();
}

};
 
int main()
{
   int arr[4][4]={ {0,   5,  INF, 10},
                        {INF, 0,   3, INF},
                        {INF, INF, 0,   1},
                        {INF, INF, INF, 0}
                      };
    Graph g(4,arr);
    g.floydWarshall();
    return 0;
}
