#include<bits/stdc++.h>
using namespace std;

int main(){
	int N,M,P,countt=0,st=0;
	scanf("%d %d %d",&N,&M,&P);
	int now=0,sum=0,pass=0;
	for(int i=0;i<N;i++){
		scanf("%d",&now);
		if(i>0){
			sum = now - pass;
		}
		//cout << sum[i] << " ";
		if(st+sum<P){
			st += sum;
		}
		else{
			countt++;
			st = 0;
		}
		pass = now;
		//cout << countt << " ";
	}
	printf("%d",countt+1);
}
