#include<bits/stdc++.h>
#define x first 
#define y second 
using namespace std;
int graph[17][17];
int N;
int travllingSalesmanProblem(int s) 
{ 
	int V = N;
    // store all vertex apart from source vertex 
    vector<int> vertex; 
    for (int i = 0; i <= V; i++) 
        if (i != s) 
            vertex.push_back(i); 
    // store minimum weight Hamiltonian Cycle. 
    int min_path = INT_MAX; 
    do { 
        // store current Path weight(cost) 
        int current_pathweight = 0; 
        // compute current path weight 
        int k = s; 
        for (int i = 0; i < vertex.size(); i++) { 
            current_pathweight += graph[k][vertex[i]]; 
            k = vertex[i]; 
        } 
        current_pathweight += graph[k][s]; 
        // update minimum 
        min_path = min(min_path, current_pathweight); 
         
    } while (next_permutation(vertex.begin(), vertex.end())); 
  
    return min_path; 
} 


int main(){
	pair<int,int> home[17];
	scanf("%d %d",&home[0].x,&home[0].y);
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		scanf("%d %d",&home[i].x,&home[i].y);
		for(int j=i;j>=0;j--){
			graph[i][j] = abs(home[i].first - home[j].first) + abs(home[i].second - home[j].second);
			graph[j][i]	= graph[i][j];
			//cout << i << " " << j << " " << graph[i][j] << endl;
		}
	}
	cout << travllingSalesmanProblem(0) << endl; 
	
}
