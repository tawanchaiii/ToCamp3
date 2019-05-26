#include<bits/stdc++.h>
using namespace std;
vector<int> vec[200001];
int main(){
	int M,N,countt=0;
	scanf("%d %d",&M,&N);
	int arr[M],check[N];
	
	for(int i=0;i<M;i++){
		scanf("%d",&arr[i]);
		vec[0].emplace_back(i);
	}
	for(int i=0;i<N;i++){
		scanf("%d",&check[i]);
		for(int j=0;j<vec[i].size();j++){
			if(arr[vec[i][j]]%check[i]==0){
				//cout << vec[i][j] << ".." << arr[vec[i][j]] << " ";
				if(i==N-1)	countt++;
				else{
					if(vec[i][j]+1<M){
						//cout << "go ";
						vec[i+1].emplace_back(vec[i][j]+1);
					}
				}
			}
		}
		//cout << endl;
	}
	
	printf("%d",countt);
}
