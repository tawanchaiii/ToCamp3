#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
vector<tuple<int,int,int> > vec;
vector<pair<int,int> > vec_t[200];
int par[200000];

int mst(int st,int en){
	int dis[200] = {0};
	int visit[200] = {0};
	queue<int> q;
	q.emplace(st);
	while(!q.empty()){
		int now = q.front();
		q.pop();
		if(visit[now]==1)	continue;
		visit[now] = 1;
		for(int i=0;i<vec_t[now].size();i++){
			int a = vec_t[now][i].first;
			if(visit[a]==1)	continue;
			dis[a] = max(vec_t[now][i].second,dis[now]);
			q.emplace(a);
			//printf("%d %d\n",now,a);
		}
		//printf("...\n");
	}
	return dis[en];
}

int findtop(int st) {
	if(par[st]==st) return st;
	int z = findtop(par[st]);
	par[st] = z;
	return z;
}

int main() {
	int cc=0;
	while(1) {
		cc++;
		int N,M,Q;
		scanf("%d %d %d",&N,&M,&Q);
		if(N==0&&M==0&&Q==0)	break;
		else {
			for(int i=0;i<200;i++)	vec_t[i].clear();
			vec.clear();
			iota(par,par+200000,0);
			for(int i=0; i<M; i++) {
				int u,v,w;
				scanf("%d %d %d",&u,&v,&w);
				vec.emplace_back(w,u,v);
			}
			sort(vec.begin(),vec.end());
			for(auto aa : vec) {
				int w,u,v;
				tie(w,u,v) = aa;
				int a = findtop(u),b = findtop(v);
				if(a!=b) {
					par[a] = b;
					vec_t[u].emplace_back(v,w);
					vec_t[v].emplace_back(u,w);
					//cout << u << " " << v << " " << w << endl;
				}
			}
			int ans[Q];
			for(int i=0; i<Q; i++) {
				int st,en;
				scanf("%d %d",&st,&en);
				int dis = mst(st,en);
				ans[i] = dis;
			}
			printf("\n");
			if(Q>0)	{
				printf("Case #%d\n",cc);
				for(int i=0; i<Q; i++) {
					if(ans[i]==0) printf("no path\n");
					else {
						printf("%d\n",ans[i]);
					}
				}
				printf("\n");
			}
		}
	}
}
