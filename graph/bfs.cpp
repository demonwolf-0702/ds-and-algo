#include<iostream>
#include<queue>
#include<vector>
using namespace std;
//structure for storing an edge in a graph.
struct Edge{
	int src;
	int des;
};
// class for the graph.
class graph{
	public:
	//adjaceny list is used for graph representation.
		vector<int> *adjlist;
		queue<int> q;
		graph(vector<Edge> edgeset,int N,int initial){
			adjlist=new vector<int>[N];
	//initialization of graph.
			for(int i=0;i<edgeset.size();++i)
			{
				adjlist[edgeset[i].src-1].push_back(edgeset[i].des);
				adjlist[edgeset[i].des-1].push_back(edgeset[i].src);
			}
	//initially pushing the starting vertex into the queue.
			q.push(initial);
		}
  //removing the dynamically allocated space for the vectors.
		~graph(){
			delete[] adjlist;
		}
 		//function for performing bfs
		void bfs(vector<bool> visited){
			# if the queue is empty then return 
			if(q.empty()){
				return;			
			}	
			int x=q.front();
			cout<<x; 
			q.pop();
		//for each neighbour of current node do as follows.
			for(int u:adjlist[x-1])
			{
				if(visited[u-1]==false)
				{
					q.push(u);
					visited[u-1]=true;				
				}			
			}
		// recursive call to the function bfs.
			bfs(visited);
		}
};
int main(){
//the edge set represented as a structure with two variables: source and destination.
	vector<Edge> edgeset={{1,4},{1,8},{2,4},{2,5},{4,6},{4,7},{5,7},{6,8}};
// graph initialization
	graph g(edgeset,8,1);
//initialization if a vector to keep track of the vertex already explored or not.
	vector<bool> visited(8,false);
	visited[0]=true;
	g.bfs(visited);
}
