#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;

const int maxn=1e6+10;

int a[maxn];
set<int> snow;

int main()
{
    int t,n,ans,cn,j;
    scanf("%d",&t);
    for(int kase=0;kase<t;kase++)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        ans=0;cn=0;j=0;
        snow.clear();
        for(int i=0;i<n;i++)
        {
            if(!snow.count(a[i]))
            {
                cn++;
                ans=max(ans,cn);
                snow.insert(a[i]);
            }
            else
            {
                while(a[i]!=a[j])
                {
                    snow.erase(a[j]);
                    j++;
                    cn--;
                }
                j++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
