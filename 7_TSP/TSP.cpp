#include <bits/stdc++.h> 
using namespace std; 
int N;
int travllingSalesmanProblem(int graph[17][17], int s) 
{ 
    vector<int> vertex; 
    for (int i = 0; i < N; i++) 
        if (i != s) 
            vertex.push_back(i); 
  	int min_path = 1e9; 
    do { 
  		int current_pathweight = 0; 
        int k = s; 
        for (int i = 0; i < vertex.size(); i++) { 
            current_pathweight += graph[k][vertex[i]]; 
            k = vertex[i]; 
        } 
        current_pathweight += graph[k][s]; 
  		min_path = min(min_path, current_pathweight); 
    } while (next_permutation(vertex.begin(), vertex.end())); 
    return min_path; 
} 
int main() 
{ 
    int graph[17][17];
    int s = 0; 
    int x[17],y[17];
    scanf("%d %d %d",x,y,&N);
    for(int i=1;i<=N;i++){
    	scanf("%d %d",x+i,y+i);
	}
	for(int i=0;i<=N;i++){
    	for(int j=0;j<=N;j++){
    		graph[i][j] = abs(x[i]-x[j]) + abs(y[i]-y[j]); 
		}
	}
	for(int i=0;i<=N;i++){
    	for(int j=0;j<=N;j++){
    		printf("%d ",graph[i][j]);
		}
		printf("\n");
	}
    cout << travllingSalesmanProblem(graph, s) << endl; 
    return 0; 
} 
