#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxl=1000+10;

char s[maxl];
int d[maxl][26],num[maxl];
bool vis[maxl][26];

int main()
{
    int t,k,len,minn,ans;
    scanf("%d",&t);
    for(int kase=0;kase<t;kase++)
    {
        scanf("%d %s",&k,s);
        len=strlen(s);
        memset(vis,0,sizeof(vis));
        memset(num,0,sizeof(num));
        for(int i=0;i<len;i+=k)
            for(int j=0;j<k;j++)
                if(!vis[i/k+1][s[i+j]-'a'])
                {
                    vis[i/k+1][s[i+j]-'a']=1;
                    num[i/k+1]++;
                }
        memset(d,-1,sizeof(d));
        for(int i=1;i<=len/k;i++)
            for(int j=0;j<26;j++)
                if(vis[i][j])
                {
                    d[i][j]=num[i];
                    if(i==1)
                        continue;
                    minn=maxl;
                    for(int k=0;k<26;k++)
                        if(d[i-1][k]!=-1)
                        {
                            if((num[i]==1&&k==j)||(num[i]>1&&vis[i][k]&&j!=k))
                                minn=min(minn,d[i-1][k]-1);
                            else
                                minn=min(minn,d[i-1][k]);
                        }
                    d[i][j]+=minn;
                }
        ans=maxl;
        for(int j=0;j<26;j++)
            if(d[len/k][j]!=-1)
                ans=min(ans,d[len/k][j]);
        printf("%d\n",ans);
    }
    return 0;
}
