#include<bits/stdc++.h>
using namespace std;
long long C(long long n,long long r) {
	long long ans = 1;
	if(n-r < r) r = n-r;
	for(int i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
	}
    return ans;
}
int main() {
	long long T;
	scanf("%lld",&T);
	while(T--) {
		long long N,X,P;
		scanf("%lld %lld %lld",&N,&X,&P);
		long long n = X-(N*(P-1ll))-1ll;
		//cout << n << endl;
		long long r = N - 1ll;
		printf("%lld\n",C(n,r));
	}

}
