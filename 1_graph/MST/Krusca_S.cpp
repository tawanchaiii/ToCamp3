#include<bits/stdc++.h>	///https://www.proprog.tk/tasks/street_light/descs/288
using namespace std;	///Krusca
const long long INF = 1e9;
long long  N,M,sum=0,shortt,countt=0;
vector<tuple<long long ,long long ,long long >> vec;
vector<tuple<long long ,long long ,long long >> vec2;
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
		long long T;
		scanf("%lld %lld",&N,&M,&T);
		sum = 0;
		vec.clear();
		iota(par,par+N,0);
		for(long long  i=0,st,en,light; i<M; i++) {
			scanf("%lld %lld %lld",&st,&en,&light);
			vec.emplace_back(light,st,en);
			graph[st].emplace_back(en);
			graph[en].emplace_back(st);
		}
		sort(vec.rbegin(),vec.rend());
		if(!bfs(1)){
			printf("-1\n");
			return 0;
		}
		for(auto v : vec) {
			long long  light,st,en;
			tie(light,st,en) = v;
			long long  a = findtop(st),b = findtop(en);
			if(a!=b) {
				par[a] = b;
				sum += light;
				countt++;
				//printf("%lld %lld %lld\n",st,en,light);
			}
			else{
				vec2.emplace_back(light,st,en);
			}
		}
		if(countt>N){
			printf("-1\n");
			return 0;
		}
		if(countt<N){
			for(auto v : vec2) {
				long long  light,st,en;
				tie(light,st,en) = v;
				sum += light;
				countt++;
				//printf("%lld %lld %lld\n",st,en,light);
				if(countt==N)	break;		
			}
		}
		
		printf("%lld\n",sum);

}
