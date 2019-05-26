#include<bits/stdc++.h>
using namespace std;

int main(){
	long long n,S;
	long long arrN[100005],arrSum[100005];
	scanf("%lld%lld",&n,&S);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&arrN[i]);
	}
	long long start = 0, end = n, mid ,canbuy = 0,savesum = 0;
	while(start<=end){
		mid = (start+end)/2ll;
		for(long long i=1;i<=n;i++){
			arrSum[i] = arrN[i]+i*mid;
		}
		long long sum = 0;
		sort(arrSum+1,arrSum+1+n);
		for(long long i=1;i<=mid;i++){
			sum += arrSum[i];
		}
		if(S>=sum){
			savesum = sum;
			canbuy = mid;
			start = mid +1;
		}
		else{
			end = mid - 1;
		}
	}
	printf("%lld %lld",canbuy,savesum);
	
}
