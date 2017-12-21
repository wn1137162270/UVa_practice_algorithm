#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxv=100+10;
const int maxl=200+10;

bool graph[maxv][maxv];
int path[maxl],d[maxl][maxv];

int main()
{
    int t,n1,n2,n,u,v,minn,ans;
    scanf("%d",&t);
    for(int kase=0;kase<t;kase++)
    {
        scanf("%d %d",&n1,&n2);
        memset(graph,0,sizeof(graph));
        for(int i=0;i<n1;i++)
            graph[i][i]=1;
        for(int i=0;i<n2;i++)
        {
            scanf("%d %d",&u,&v);
            u--;v--;
            graph[u][v]=1;
            graph[v][u]=1;
        }
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&path[i]);
            path[i]--;
        }
        memset(d,0,sizeof(d));
        for(int i=1;i<=n;i++)
            for(int j=0;j<n1;j++)
            {
                if(path[i]!=j)
                    d[i][j]=1;
                minn=maxl;
                for(int k=0;k<n1;k++)
                    if(graph[j][k])
                        minn=min(minn,d[i-1][k]);
                d[i][j]+=minn;
            }
        ans=maxl;
        for(int j=0;j<n1;j++)
            ans=min(ans,d[n][j]);
        printf("%d\n",ans);
    }
    return 0;
}
