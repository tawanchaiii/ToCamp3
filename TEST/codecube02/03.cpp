#include<bits/stdc++.h>	///https://www.proprog.tk/tasks/street_light/descs/288
using namespace std;	///Krusca
const long long INF = 1e9;
long long  N,M,sum=0,shortt,countt=0;
vector<pair<long long ,long long >> vec;
vector<pair<long long ,long long >> vec2;
pair<long long,long long> st_en[200000];
vector<long long> graph[200000];
vector<long long> save;
long long  par[200000];


long long  findtop(long long  st) {
	if(par[st]==st) return st;
	long long  z = findtop(par[st]);
	par[st] = z;
	return z;
}

bool bfs(long long node){
	long long visit[200000] = {0};
	long long c=0;
	queue<long long> q;
	q.emplace(node);
	while(!q.empty()) 
    { 

        long long s = q.front(); 
        q.pop(); 
        if(visit[s]==0){
        	visit[s] = 1;
        	c++;
        	//cout << c;
		}
        for (long long i = 0; i < graph[s].size(); i++) 
        { 
            if (visit[graph[s][i]]==0) 
            { 
                visit[graph[s][i]] = 1; 
                c++;
                //cout << c;
                q.emplace(graph[s][i]); 
            } 
        } 
    }
    if(c==N)	return true;
    return false;
}

//findtop(int st) { return par[u] = u == par[u] ? u : findtop(par[u]); }

int main() {
		long long T,av;
		scanf("%lld %lld",&N,&M);
		sum = 0;
		vec.clear();
		iota(par,par+N,0);
		for(long long  i=0,st,en,light; i<M; i++) {
			scanf("%lld %lld %lld",&st,&en,&light);
			vec.emplace_back(light,i);
			graph[st].emplace_back(en);
			graph[en].emplace_back(st);
			st_en[i] = {st,en};
			av = st;
		}
		sort(vec.rbegin(),vec.rend());
		if(!bfs(av)){
			scanf("%lld",&T);
			printf("-1\n");
			return 0;
		}
		for(auto v : vec) {
			long long  light=v.first,i=v.second;
			long long  a = findtop(st_en[i].first),b = findtop(st_en[i].second);
			if(a!=b) {
				par[a] = b;
				sum += light;
				countt++;
				save.emplace_back(i);
				//printf("..%lld %lld %lld\n",st_en[i].first,st_en[i].second,light);
			}
			else{
				vec2.emplace_back(light,i);
			}
		}

		if(countt<N){
			for(auto v : vec2) {
				long long  light=v.first,i=v.second;
				sum += light;
				countt++;
				save.emplace_back(i);
				//printf("..%lld %lld %lld\n",st_en[i].first,st_en[i].second,light);
				if(countt==N)	break;		
			}
		}
		scanf("%lld",&T);
		printf("%lld\n",sum);
		if(T==2){
			for(auto v : save) {
				printf("%lld ",v+1);		
			}
		}

}
