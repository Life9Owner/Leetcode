#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
#define N 1005
struct node{
    int ux,uy,w;
};
int n,m,x,y,ans,cnt;
int mx,my,tx,ty;
char a[N][N];
int vis[N][N],sum[N][N];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
void bfs(int opt)
{
    int pd=0;
    memset(vis,0,sizeof vis);
    queue<node> q;
    if(opt==1)
    {
        q.push({mx,my,0}),pd=x;
    }
    else 
    {
        q.push({tx,ty,0}),pd=y;
    }
    while(q.size())
    {
        node u=q.front();
        q.pop();
        if(vis[u.ux][u.uy])continue;
        if(a[u.ux][u.uy]=='C')
        {
            if(!sum[u.ux][u.uy])
            {
                ans++;
                cnt+=u.w;
                sum[u.ux][u.uy]=u.w;
            }
            else{
                if(u.w<sum[u.ux][u.uy])
                {
                    cnt-=sum[u.ux][u.uy];
                    cnt+=u.w;
                }
            }
        }
         vis[u.ux][u.uy]=1;
         for(int i=0;i<4;i++)
        {
            int ax=u.ux+dx[i],ay=u.uy+dy[i];
            if(ax<1||ax>n||ay<1||ay>m)continue;
            if(vis[ax][ay]||a[ax][ay]=='#')continue;
            if(u.w==pd)continue;
            q.push({ax,ay,u.w+1});
        }

    }
}
int main()
{
    cin>>n>>m>>x>>y;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
            if(a[i][j]=='M')
            {
                mx=i,my=j;
            }
            else if(a[i][j]=='T')
            {
                tx=i,ty=j;
            }
        }
        
    }
    bfs(1);
    bfs(2);
    cout<<ans<<" "<<cnt;
    return 0;
}