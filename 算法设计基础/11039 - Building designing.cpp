#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;

const int maxv=1e6+10;
const int INF=1<<30;

bool record[2][maxv];

int main()
{
    int t,n,f,af,maxx,minn,p,ans;
    scanf("%d",&t);
    for(int kase=0;kase<t;kase++)
    {
        scanf("%d",&n);
        memset(record,0,sizeof(record));
        maxx=0;minn=INF;p=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&f);
            af=abs(f);
            maxx=max(maxx,af);
            if(af<minn)
            {
                minn=af;
                p=f>0?1:0;
            }
            if(f>0)
                record[1][f]=1;
            else
                record[0][-f]=1;
        }
        ans=0;
        for(int i=1;i<=maxx;i++)
        {
            if(record[p][i])
            {
                ans++;
                p^=1;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
