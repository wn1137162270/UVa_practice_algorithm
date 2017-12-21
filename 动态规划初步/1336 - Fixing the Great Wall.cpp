#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=1000+10;
const int INF=1e9;

struct node
{
    int loc,cost,inc;
    bool operator <(const node &n)const
    {
        return loc<n.loc;
    }
};

node fixed[maxn];
double d[maxn][maxn][2];
double t[maxn][maxn][2];

int main()
{
    int n,v,x,ans,ln;
    scanf("%d %d %d",&n,&v,&x);
    while(!(n==0&&v==0&&x==0))
    {
        for(int i=0;i<n;i++)
            scanf("%d %d %d",&fixed[i].loc,&fixed[i].cost,&fixed[i].inc);
        fixed[n].loc=x;fixed[n].cost=0;fixed[n].inc=0;
        ans=0;
        for(int i=0;i<n;i++)
            ans+=fixed[i].cost;
        sort(fixed,fixed+n+1);
        ln=0;
        for(int i=0;i<=n;i++)
        {
            if(fixed[i].loc<x)
                ln++;
            else
                break;
        }
        for(int i=1;i<=ln;i++)
            for(int j=1;j<=n-ln;j++)
            {
                double ct0=t[i-1][j][0]+(double)(fixed[ln-i+1].loc-fixed[ln-i].loc)/v;
                double ct1=t[i-1][j][1]+(double)(fixed[ln+j].loc-fixed[ln-i].loc)/v;
                if(d[i-1][j][0]+ct0*fixed[ln-i].inc)
            }
        scanf("%d %d %d",&n,&v,&x);
    }
    return 0;
}
