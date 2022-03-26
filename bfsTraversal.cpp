#include<bits/stdc++.h>
using namespace std;
class Graph{

	int V;
	list<int>*l;
public:
	Graph(int v)
	{
		V=v;
		l = new list<int>[v];
	}
	void addEdge(int i , int j , bool unDir = true)
	{
		l[i].push_back(j);
		if(unDir) l[j].push_back(i);
	}

	//BREADTH FIRST SEARCH

	void bfs(int source , int destination=-1)
	{
	queue<int>q;
	bool*visited = new bool[V];
	int*parent = new int[V];
	for(int i = 0; i < V ; i++)
	{
		parent[i] = -1;
	}
	int*dist = new int[V];
	for (int i = 0; i < V; ++i)
	{
		dist[i] = 0;
	}
	for(int i =0  ; i < V ; i++)
	{
		visited[i]=false;
	}
	q.push(source);
	visited[source] = true;
	dist[source] = 0;
	parent[source] = source;
	while(!q.empty())
	{
		int f = q.front();
		cout << f << endl;
		q.pop();
		for(auto nbrs: l[f])
		{
			if(!visited[nbrs])
			{
				q.push(nbrs);
				dist[nbrs] = dist[f]+1;
				parent[nbrs] = f; 
				visited[nbrs] = true;

			}
		}
		//print the shortest distance
		for(int i = 0 ; i < V ; i++)
		{
			cout << "Shortest dist to " << i << " is " << dist[i] << endl;
		}
	}
	//PRint the path from source to destinations
		if(destination!=-1)
		{
			int temp = destination;
			while(temp!=source)
			{
				cout <<temp<<"--";
				temp = parent[temp];
			}
			cout << source << endl;
		}
	}

};

int main()
{

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt","r" ,stdin);
// 	freopen("output.txt","w" ,stdout);
// #endif
	Graph g(7);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,5);
	g.addEdge(5,6);
	g.addEdge(4,5);
	g.addEdge(0,4);
	g.addEdge(3,4);
	g.bfs(1,6);


	
}
