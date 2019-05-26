#include<bits/stdc++.h>
using namespace std;
long long arr[1000000];
vector<pair<long long,long long> > vec;

int main()
{
    long long N,Q;
    scanf("%lld %lld",&N,&Q);
    vec.resize(N+1);
    vec[0] = {0,0};
    for(long long i=1;i<=N;i++){
        scanf("%lld",&vec[i].first);
        vec[i].first += vec[i-1].first;
        vec[i].second = i;
    }
    sort(vec.begin(),vec.end());
    for(long long i=1;i<=N;i++){
    	vec[i].second = max(vec[i].second,vec[i-1].second);
        //printf("%d %d\n",vec[i].first,vec[i].second);
    }
    for(long long i=0;i<Q;i++){
        long long want;
        scanf("%lld",&want);
        long long end = N, start = 0, check = 0;
        while(end>start){
        	long long mid = (start+end)/2;
        	if(vec[mid].first > want)	end = mid -1 ;
        	else{
        		if(mid == N){
        			printf("%lld\n",vec[mid].second);
        			check = 1;
        			break;
				}
        		if(vec[mid+1].first > want){
        			printf("%lld\n",vec[mid].second);
        			check = 1;
        			break;
				}
        		start = mid + 1;
			}
		}
		if(check==0)	printf("%lld\n",vec[start].second);
    }

}
