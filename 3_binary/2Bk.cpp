#include<bits/stdc++.h>
using namespace std;

int arr[1000][1000];
int sortt[1000000];
int visit[1000][1000];
int N,s=0,savei,savej,saveans = 1e9;
bool check = false;

void walk(int i,int j,int maxx){
	visit[i][j] = 1;
	//cout << i << " " << j << " " << maxx << " " << visit[i][j] << endl;
	if(arr[i][j]==0&&i!=savei&&j!=savej){
		check = true;
		return;
	}
	if(arr[i][j]<=maxx&&check==false){
		if(visit[i+1][j]==0&&i+1<N)	{
			//if(arr[i+1][j]<=maxx)
			walk(i+1,j,maxx);
		}
		if(visit[i-1][j]==0&&i-1>=0)	{
			//if(arr[i-1][j]<=maxx)
			walk(i-1,j,maxx);
		}
		if(visit[i][j+1]==0&&j+1<N)	{
			//if(arr[i][j+1]<=maxx)
			walk(i,j+1,maxx);
		}
		if(visit[i][j-1]==0&&j-1>=0)	{
			//if(arr[i][j-1]<=maxx)
			walk(i,j-1,maxx);
		}
	}
}

int main(){

	scanf("%d",&N);
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			scanf("%d",&arr[i][j]);
			if(arr[i][j]!=0){
				sortt[s] = arr[i][j];
				s++;
			}
			else{
				savei = i;
				savej = j;
			}
		}
	}
	sort(sortt,sortt+(N*N));
	int st=0, en= N*N-1,be=0;
	while(st<en){
		int mid = (st+en)/2;
		check = false;
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				visit[i][j] = 0;
			}
		}
		visit[savei][savej] = 1;
		walk(savei,savej,sortt[mid]);
		if(check == true){
			saveans = min(saveans,sortt[mid]);
			en=mid-1;
		}
		else{
			st=mid+1;
		}
	}
	printf("%d",saveans);
}
