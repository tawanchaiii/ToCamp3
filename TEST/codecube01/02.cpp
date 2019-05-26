#include<bits/stdc++.h>
using namespace std;

int main(){
	vector<long long> vec,ans;
	for(long long i=0;i<1000000;i++){
		vec.emplace_back(i);
	}
	//cout << vec[3] << endl;
	long long M,K;
	scanf("%lld %lld",&M,&K);
	for(long long i=0;i<M;i++){
		long long n;
		scanf("%lld",&n);
		vec[n] = 1e9+7;
		//cout << vec[n] << endl;
	}
	sort(vec.begin(),vec.end());
	for(long long i=0;i<K;i++){
		long long n;
		scanf("%lld",&n);
		ans.emplace_back(vec[n]);
	}
	for(long long i=0;i<K;i++){
		printf("%lld ",ans[i]);
	}
}
