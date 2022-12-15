#include <bits/stdc++.h>
using namespace std;
int root_node = 0;
int main()
{
  int n;
  cin >> n;
  vector< vector<int> > nodes(n);
  // using a 2-D vector to map nodes to index in order to form the tree.
  queue<int> q;
  int a[n];
  for(int i=0;i<n;i++)
  {
	  cin >> a[i];
	  if(a[i] == -1) root_node = i;
	  else {
		  nodes[a[i]].push_back(i);
	  }
  }
  q.push(root_node);
  int height = 0;
  while(true)
  {
	  int node_count = q.size();
	  if(node_count == 0){
		  cout << height;
		  return 0;
	  }
	  height += 1;
	  while(node_count > 0){
		  int node = q.front();
		  q.pop();
          //q.push()
		  if(!nodes[node].empty()){
              // for(int i = 0;i <= nodes[node].size();i++) 
			  for(int i = 0;i < nodes[node].size();i++)
				  q.push(nodes[node][i]);
		  }
		  node_count--;
	  }
  }
    return 0;
}