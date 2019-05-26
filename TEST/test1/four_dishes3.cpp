#include<bits/stdc++.h>
using namespace std;

unordered_map<long long,long long > m(1000000);

int main() {
	long long N,S,countt=0;
	scanf("%lld %lld",&N,&S);
	long long arr[N];
	for(long long i=0; i<N; i++) {
		scanf("%lld",&arr[i]);
	}
	for(long long i=0; i<N; i++) {
		for(long long j=i+1; j<N; j++) {
			m[arr[i]+arr[j]]++;
		}
	}
	for(long long i=0; i<N; i++) {
		for(long long j=i+1; j<N; j++) {
			m[arr[i]+arr[j]]--;
		}
		for(long long j=0; j<i; j++) {
			countt += m[S - arr[i] - arr[j]];
		}
	}
	printf("%lld\n",countt*24ll);
	
}
