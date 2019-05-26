#include<bits/stdc++.h>
using namespace std;

int main(){
	long long N,save=0;
	scanf("%lld",&N);
	long long arr[N+1]={0};
	long long check[N+1]={0};
	long long sum[N+1]={0};
	long long countt[N+1]={0};
	long long last[N+1] = {0};
	long long ch = 0;
	for(long long i=1;i<=N;i++){
		scanf("%lld",&arr[i]);
		if(arr[i]>=arr[i-1]){
			//check[i] = ch;
			//sum[ch] += arr[i];
			//countt[ch] ++;
			//last[ch] = arr[i];
			long long checklast = 1,bestj = ch;
			if(arr[i]>last[ch]){
				for(long long j=0;j<ch;j++){
					if(last[j]<=arr[i]&&countt[j]>=countt[bestj]){
						if(countt[j]==countt[bestj]){
							if(sum[j]>sum[bestj]){
								bestj = j;
							}
						}
						else{
							bestj = j;
						}
					}
				}
			}
			check[i] = bestj;
			sum[bestj] += arr[i];
			countt[bestj] ++;
			if(countt[bestj]>=countt[save]){
				if(countt[bestj]==countt[save]){
					if(sum[bestj]>sum[save]){
						save = bestj;
					}
				}
				else{
					save = bestj;
				}
			}
			last[bestj] = arr[i];
		}
		else{
			ch++;
			check[i] = ch;
			sum[ch] += arr[i];
			countt[ch] ++;
			last[ch] = arr[i];
		}
	}
	/*for(int i=1;i<=N;i++){
		printf("%d ",check[i]);
	}
	printf("\n");
	for(int i=0;i<=N;i++){
		printf("%d ",sum[i]);
	}
	printf("\n");
	for(int i=0;i<=N;i++){
		printf("%d ",countt[i]);
	}
	printf("\n");
	for(int i=0;i<=N;i++){
		printf("%d ",last[i]);
	}
	printf("\n");*/
	printf("%lld %lld\n",countt[save],sum[save]);
}

