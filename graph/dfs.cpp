#include<iostream>
#include<stack>
#include<vector>
using namespace std;
struct edge{
	int src;
	int des;
};
class graph{

	public:
		vector<int> *adjlist;
		stack<int> stk;
		graph(vector<edge> edgeset,int N,int initial){
			adjlist=new vector<int>[N];
			for(edge e:edgeset)
			{
				adjlist[e.src-1].push_back(e.des);
				adjlist[e.des-1].push_back(e.src);			
			}
			stk.push(initial);	
		}
		~graph(){
			delete [] adjlist;
		}
		void dfs(vector<bool> &visited){
			if(stk.empty())
			{
				return;
			}
			int x=stk.top();
			stk.pop();
			cout<<x<<endl;
			for(int u:adjlist[x-1])
			{
				if(visited[u-1]==false)
				{
					stk.push(u);
					visited[u-1]=true;
				}
			}
			dfs(visited);
		}
};
int main(){
	vector<edge> edgeset={{1,2},{1,3},{2,4},{2,5},{3,6},{3,7},{4,8},{5,8},{6,8},{7,8}};
	graph g(edgeset,8,1);
	vector<bool> visited(8,false);
	visited[0]=true;
	g.dfs(visited);
}		
