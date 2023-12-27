#include <bits/stdc++.h>

using namespace std;

vector<int> parent;


void path(int vertex, vector<int> parent , int des)
{
 
    if (vertex == -1 ) {
        return;
    }
    path(parent[vertex],parent,des);
    if( vertex == des )
    {
       cout << vertex ;
    }
    else
      cout << vertex << "  ->  ";
}

void dijkstra_algorithm( vector<vector<int>> adjlist[] ,int n , int src)
{
   vector<int> distance( n ,1e9);
   distance[src] = 0;

   parent.resize(n,0);
   priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
   pq.push({0,0});
   parent[0] = -1;

   while( !pq.empty() )
   {
      int dis = pq.top().first;
      int u = pq.top().second;
      pq.pop();

      for( auto it : adjlist[u] )
      {
        int v = it[0];
        int km = it[1];
        if( dis + km < distance[v] )
        {
            distance[v] = dis + km;
            parent[v] = u;
            pq.push({ dis + km , v });
        }
      }
   }
   
}

int main()
{
  
  int n;
  cout << "The number of cities : ";   // nodes are starting from index 0
  cin >> n;

  int e;
  cout << "The number of paths :  ";
  cin >> e;

  vector<vector<int>> graph;           

  for(int i=0 ; i<e ; i++)
  {
    vector<int> vec;
    int u;
    int v;
    int km;
    cout<<"\nEnter the node1 : ";
    cin >> u ;
    cout <<"Enter the node2 : ";
    cin>> v ;
    cout <<"Enter the distance between node1 and node2 : ";
    cin>> km;
    vec.push_back(u);
    vec.push_back(v);
    vec.push_back(km);

    graph.push_back(vec);
  }

  vector<vector<int>> adjlist[n];
  
  for(int i=0 ; i<e ; i++)
  {
    vector <int> p;
    int u = graph[i][0];
    int v = graph[i][1];
    int km = graph[i][2];
    p.push_back(v);
    p.push_back(km);
    adjlist[ graph[i][0] ].push_back(p);
    vector<int> q;
    q.push_back(u);
    q.push_back(km);
    adjlist[graph[i][1]].push_back(q);
  }
   
  int src;
  cout << "\nEnter the source : ";
  cin >> src;
  int dest;
  cout << "Enter the destination : ";
  cin >> dest;


  dijkstra_algorithm(adjlist,n,src);
  cout << endl;
  path( dest , parent ,dest);

}