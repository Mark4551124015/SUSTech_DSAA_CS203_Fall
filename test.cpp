#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e6+5;
struct node{
    ll a;
    int p;
}a[maxn];
bool cmp(node a,node b){
    if(a.a==b.a) return a.p>b.p;
    else return a.a<b.a;
}
int main(){
    a[0].a=0,a[0].p=0;
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i].a);
        a[i].a+=a[i-1].a;
        a[i].p=i;
    }
    
	sort(a,a+n+1,cmp);

	for (int i = 0; i <= n; i++) {
        printf("%lld ", a[i].a);
    }
    int p=a[0].p;
    int ans=0;
    for(int i=1;i<=n;i++){
        if(a[i].p>p){
            ans=max(ans,a[i].p-p);
        }else{
            p=a[i].p;
        }
    }
    printf("%d\n",ans);
    return 0;
}