#include<bits/stdc++.h>
using namespace std;
long long MOD = 0;
long long result = 0;
long long powerX(long long X,long long N){
	long long result = 1,base = X;
    while(N>0){
    	if(N%2==0){
    		N /= 2;
    		base *= base;
    		base %= MOD;
		}
    	else{
	        N--;
			result = (result * base)% MOD;
			base *= base;
			base %= MOD;
			N /= 2;
		}
    }
    return result % MOD;
}
int main(){
	int N;
	scanf("%d",&N);
	while(N--){
		long long x,y,n;
		scanf("%lld %lld %lld",&x,&y,&n);
		MOD = n;
		printf("%lld\n",powerX(x,y));
	}
	
}
