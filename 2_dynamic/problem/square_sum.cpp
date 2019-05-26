#include<bits/stdc++.h>
using namespace std;
long long w[101];
long long  check[10005];


void fill_check(){
	for(long long  i=0;i<101;i++){
		w[i] = i*i;
	}
	for(long long  i=0;i<10005;i++){
		check[i] = i;
	}
	for(long long i=2;i<101;i++){
		check[w[i]] = 1;
		for(long long j=w[i]+1;j<10005;j++){
			check[j] = min(check[j],check[j-w[i]]+check[w[i]]);
		}
	}
	
}


int main(){
	fill_check();
	long long T;
	scanf("%lld",&T);
	while(T--){
		long long N;
		scanf("%lld",&N);
		printf("%lld\n",check[N]);
	}
}
