#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
class Node{
	public:
	string name;
	list<string>nbrs;

	Node(string name)
	{
		this->name = name;
	}
};
class Graph{
	unordered_map<string,Node*>m;
public:
	Graph(vector<string>cities)
	{
		for(auto city:cities)
		{
			m[city] = new Node(city);
		}
	}
	void addEdge(string x , string y , bool unDir = false)
	{
		m[x]->nbrs.push_back(y);
		if(unDir)
		{
			m[y]->nbrs.push_back(x);
		}
	}
	void printAdjList()
	{
		for(auto cityPair : m)
		{
			auto city = cityPair.first;
			Node*node = cityPair.second;
			cout << city << "-->";
			for(auto nbr : node->nbrs)
			{
				cout << nbr << ",";
			}
			cout << endl;
		}
	}

};
int main()
{

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt","r" ,stdin);
// 	freopen("output.txt","w" ,stdout);
// #endif
	vector<string>cities ;
	// cities = {"Delhi" , "London" , "Paris" , "NewYork"};
	cities.push_back("Delhi");
	cities.push_back("London");
	cities.push_back("Paris");
	cities.push_back("NewYork");
	Graph g(cities);
	g.addEdge("Delhi" , "London");
	g.addEdge("NewYork","London");
	g.addEdge("Delhi" , "Paris");
	g.addEdge("Paris" , "NewYork");
	g.printAdjList();


	
}