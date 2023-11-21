#include<iostream>
#include<algorithm>
using namespace std;
#define N 100005
int n,m,x,y,ans;
int a[N];
int main()
{
    cin>>n>>m>>x>>y;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i];
	}
    sort(a+1,a+1+m);
    int w=x+y,r=1;
    for(int i=1;i<=m;i++)
    {
        while(a[r]-a[i]<=w&&r<=m)r++;
        ans=max(r-i,ans);
    }
    cout<<ans;
    return 0;
}