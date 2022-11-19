#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
using namespace std;
#define pb push_back
 
#define debug(x) cerr << #x << ": " << (x) << endl
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define dwn(i,a,b) for(int i=(a);i>=(b);i--)
#define all(x) (x).begin(), (x).end()
 
#define int long long
 
#define x first
#define y second
#define pii pair<int, int>
using ll = long long;
 
inline void read(int &x){
    int s=0; x=1;
    char ch=getchar();
    while(ch<'0' || ch>'9') {if(ch=='-')x=-1;ch=getchar();}
    while(ch>='0' && ch<='9') s=(s<<3)+(s<<1)+ch-'0',ch=getchar();
    x*=s;
}

const int N=5e5+5;

int n, need;
vector<pii> g[N];
int res;

void dfs(int u, int fa, int val){
	if(g[u].size()==1){
		if(val==need) res++;
	}
	
	for(pii e: g[u]){
		int go=e.x, w=e.y;
		if(go==fa) continue;
		dfs(go, u, val+w);
	}
}

signed main(){
	// memset(h, -1, sizeof h);
	cin>>n>>need;
	rep(i, 1, n-1){
		int u, v, w; read(u), read(v), read(w);

		g[u].pb({v, w}),g[u].pb({u,w});
	}
	dfs(1, -1, 0);
	cout<<res<<endl;
	return 0;
}