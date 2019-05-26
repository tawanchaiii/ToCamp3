#include<bits/stdc++.h>
using namespace std;


int main(){
	long long N;
	long double M,countt=0,ch=0;
	//scanf("%lld %llf",&N,&M);
	cin >> N >> M;
	long double arr[N];
	for(long long i=0;i<N;i++){
		//scanf("%llf",&arr[i]);
		cin >> arr[i];
	}
	sort(arr,arr+N);
	for(long long i=0;i<N;i++){
		if(arr[i]>=M){
			if(i>=2){
				countt += (i)*(i-1)/2;
			}
		}
	}
	long double n =(long double)N;
	ch = (n)*(n-1)*(n-2)/6;
	//cout << countt << " " << ch;
	printf("%Lf",countt/ch);
}
