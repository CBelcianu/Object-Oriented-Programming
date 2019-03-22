#include <bits/stdc++.h>
using namespace std;
#define V 4

std::vector<int> travllingSalesmanProblem(int graph[][V], int s)
{
	vector<int> vertex;
	for (int i = 0; i < V; i++)
		if (i != s){
			vertex.push_back(i);
		}

    vector<int> path;
    vector<int> c;

	int min_path = INT_MAX;
	do {
		int current_pathweight = 0;
		int k = s;
		path.push_back(k);
		for (int i = 0; i < vertex.size(); i++) {
			current_pathweight += graph[k][vertex[i]];
			k = vertex[i];
			path.push_back(k);
		}
		current_pathweight += graph[k][s];
        if(current_pathweight<min_path)
            c=path;

		min_path = min(min_path, current_pathweight);
		path.clear();

	} while (next_permutation(vertex.begin(), vertex.end()));
    for(int i=0;i<c.size();i++)
        c[i]=c[i]+1;
    c.push_back(c[0]);
	return c;
}


int main()
{
	int graph[][V] = { { 0, 10, 15, 20 },
					{ 10, 0, 35, 25 },
					{ 15, 35, 0, 30 },
					{ 20, 25, 30, 0 } };
	int s = 0;
	vector<int> cv = travllingSalesmanProblem(graph, s);
	for(int i=0;i<cv.size();i++)
    	cout<< cv[i] << " ";
	return 0;
}
