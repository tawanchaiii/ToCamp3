#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

long long power2(long long N){
	long long result = 1,base = 2;
    while(N>0){
    	if(N%2==0){
    		N /= 2;
    		base *= base;
    		base %= MOD;
		}
    	else{
	        N--;
			result = (result * base) % MOD;
			base *= base;
			base %= MOD;
			N /= 2;
		}
    }
    return result % MOD;
}

int main(){
	long long T;
	scanf("%lld",&T);
	while(T--){
		long long N;
		scanf("%lld",&N);
		printf("%lld\n",power2(N)-1);
	}
}
