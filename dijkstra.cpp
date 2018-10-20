#include<iostream>
#include<queue>
#include<stack>
#include <limits>
using namespace std;

class Graph 
{
private:
      int **adjMatrix;
      int vertexCount;
	  int *key;
	  int *distance;
	  int *parent;
public:
    Graph(int vertexCount);
    ~Graph();
	void addEdgeDirectedWeight(int i, int j, int cost);
	void removeEdgeUndirected(int i, int j);
    int isEdge(int i, int j);
    void display();
	void initializeState();
	void showBasicInfo();
	void Dijkstra(int startNode);
	int isAllKeyTrue(); 
  int findMinDistanceNode();
};

Graph::Graph(int vertexCount)
{
  this->vertexCount = vertexCount;
	this->key = new int[vertexCount];
	this->distance = new int[vertexCount];
	this->parent = new int[vertexCount];
    adjMatrix = new int*[vertexCount];
    for (int i = 0; i < vertexCount; i++)
    {
        adjMatrix[i] = new int[vertexCount];
           for (int j = 0; j < vertexCount; j++)
              adjMatrix[i][j] = 0;
    }
}

Graph::~Graph()
{
    for (int i = 0; i < vertexCount; i++)
         delete[] adjMatrix[i];
            delete[] adjMatrix;
}

void Graph::initializeState()
{
	for(int i=0; i<this->vertexCount; i++)
  {
		this->key[i] = 0; 
    this->distance[i]= INT_MAX;
		this->parent[i] = -1;
	}
}

void Graph::addEdgeDirectedWeight(int i, int j, int cost)
{
    if (i >= 0 && i < vertexCount && j >= 0 && j < vertexCount)
		adjMatrix[i][j] = cost;
}

void Graph::removeEdgeUndirected(int i, int j) {
    if (i >= 0 && i < vertexCount && j >= 0 && j < vertexCount) {
		adjMatrix[i][j] = 0;
		adjMatrix[j][i] = 0;
    }
}

int Graph::isEdge(int i, int j) 
{
    if (i >= 0 && i < vertexCount && j >= 0 && j < vertexCount)
        return adjMatrix[i][j];
    else
  {
		cout<<"Invalid vertex number.\n";
		return 0;
	}
}

void Graph::display()
{
    int  u,v; 
	cout<<"\t   ";
	for(u=0; u<vertexCount; u++)
		cout<<u<<" ";
  for(u=0; u<vertexCount; u++)
    {
        cout << "\nNode[" << (char) (u+48) << "] -> ";
        for(v=0; v<vertexCount; ++v) 
        {
            cout << " " << adjMatrix[u][v];
        }
    }
    cout << "\n\n";
}

void Graph::showBasicInfo(){
	for(int i=0; i<vertexCount; i++){
		cout<<"node: "<<i<<" Key: "<<key[i]<<" distance: "<<distance[i]<<" parent: "<<parent[i]<<"\n";
	}
}

int Graph::isAllKeyTrue()
{
	for(int i=0; i<this->vertexCount; i++)
  {
		if(this->key[i]==0)
			return 0; 
	}
	return 1;
}

int Graph::findMinDistanceNode(){
	int minDistant=INT_MAX;
	int minDistantNode;
	for(int i=0; i<vertexCount; i++)
  {
		if(minDistant > this->distance[i] && this->key[i]==0)
		{ 
			minDistantNode = i;
			minDistant = this->distance[i];
		}
	}
	return minDistantNode;
}

void Graph::Dijkstra(int startNode)
{
	cout<<"\nDijkstra Shortest Path starts . . . \n";
	this->distance[startNode]=0; //start node's distance is 0
	int minDistanceNode, i;
	while(!this->isAllKeyTrue())
  {
		minDistanceNode = findMinDistanceNode();
		this->key[minDistanceNode] = 1;  // this node's shortes path is done
		cout<<"Shortest Path: "<<this->parent[minDistanceNode]<<"->"
			<<minDistanceNode<<", Destination Node's cost is: "<<distance[minDistanceNode]<<"\n";
		for(i=0; i<vertexCount; i++)
    {
			if(this->isEdge(minDistanceNode, i) && this->key[i]==0 ){
                //Below is the code for relaxation
				if(this->distance[i] > this->distance[minDistanceNode]
					                   + adjMatrix[minDistanceNode][i]){
					this->distance[i] = this->distance[minDistanceNode]
						                + adjMatrix[minDistanceNode][i];
					this->parent[i] = minDistanceNode;
				}
			}
		}
	}
}

int main(){
	Graph g(5);
  int n,i,j,w;
  cout<<"Enter the no of edges ";
  cin>>n;
  while(n--)
  {
  cin>>i>>j>>w;
	g.addEdgeDirectedWeight(i, j, w);
  }
	g.display();
	g.initializeState();
	int startNode = 0;
	g.Dijkstra(startNode);
	return 0;
}
