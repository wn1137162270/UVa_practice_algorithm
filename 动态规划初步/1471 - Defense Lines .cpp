#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;

const int maxn=2*1e5+10;

struct node
{
    int a,g;
    bool operator <(const node &n)const
    {
        return a<n.a;
    }
};

int a[maxn],f[maxn],g[maxn];
set<node> st;

int main()
{
    int t,n,ans,res;
    scanf("%d",&t);
    for(int kase=0;kase<t;kase++)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        g[0]=1;
        for(int i=1;i<n;i++)
            if(a[i]<=a[i-1])
                g[i]=1;
            else
                g[i]=g[i-1]+1;
        f[n-1]=1;
        for(int i=n-2;i>=0;i--)
            if(a[i]>=a[i+1])
                f[i]=1;
            else
                f[i]=f[i+1]+1;
        st.clear();
        ans=0;
        for(int i=0;i<n;i++)
        {
            res=f[i];
            node cn=(node){a[i],g[i]};
            set<node>::iterator it=st.lower_bound(cn);
            bool flag=true;
            if(it!=st.begin())
            {
                node last=*(--it);
                it++;
                res=f[i]+last.g;
                if(last.g>=g[i])
                    flag=false;
            }
            if(flag)
            {
                bool ins=true;
                if(it!=st.end()&&(*it).a==a[i]&&(*it).g>g[i])
                    ins=false;
                while(it!=st.end()&&(*it).g<=g[i])
                    st.erase(it++);
                if(ins)
                    st.insert(cn);
            }
            ans=max(ans,res);
        }
        printf("%d\n",ans);
    }
    return 0;
}
