#include<bits/stdc++.h>
using namespace std;

bitset<8000000> check;

int main(){
	int N,countt=0,go=0;
	scanf("%d",&N);
	for(int i=2;;i++){
		if(check[i]==1)	continue;
		
		countt++;
		
		if(countt==N)	{
			printf("%d\n",i);
			break;
		}
		
		if(i*i>8000000)	go=1;
		
		if(go==0)
		for(int j=i*i;j<8000000;j+=i){
			check[j] = 1;
		}
	}
}
