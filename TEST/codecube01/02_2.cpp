#include<bits/stdc++.h>
using namespace std;

int main(){
	long long M,K;
	vector<pair<long long,long long> > vec;
	scanf("%lld %lld",&M,&K);
	for(long long i=0;i<M;i++){
		long long n;
		scanf("%lld",&n);
		if(vec.empty()){
			if(n==1){
				vec.emplace_back(2,3000000000);
			}
			else{
				vec.emplace_back(1,n-1);
				vec.emplace_back(n+1,3000000000);
			}
		}
		else{
			for(int i=0;i<vec.size();i++){
				//cout << vec[i].first << " " << vec[i].second << endl;
				if(vec[i].first<=n&&n<=vec[i].second){
					if(n==vec[i].first&&n==vec[i].second){
						vec[i].first = 9e9;
						vec[i].second = 9e9;
					}
					else if(n==vec[i].first){
						vec[i].first = n + 1;
					}
					else if(n==vec[i].second){
						vec[i].second = n - 1;
					}
					else{
						vec.emplace_back(n+1,vec[i].second);
						vec[i].second = n - 1;
					}
					break;
				}
			}
		}
	}
	sort(vec.begin(),vec.end());
	/*for(int i=0;i<vec.size();i++){
		cout << vec[i].first << " " << vec[i].second << endl;	
	}*/
	for(long long i=0;i<K;i++){
		long long n;
		scanf("%lld",&n);
		long long countt = 0;
		for(int i=0;i<vec.size();i++){
			if(vec[i].second-vec[i].first+1+countt>=n){
				if(vec[i].second-vec[i].first+1+countt==n){
					printf("%lld ",vec[i].second);
				}
				else{
					printf("%lld ",vec[i].first-1+n-countt);
				}
				break;
			}
			else{
				countt += vec[i].second-vec[i].first+1;
			}
		}
	}
}
