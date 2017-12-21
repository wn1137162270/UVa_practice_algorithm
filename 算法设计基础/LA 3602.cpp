#include<cstdio>
#include<cstring>

const int maxm=50+5;
const int maxn=1000+10;

char s[maxm][maxn],ans[maxn];
int rec[26][maxn];

int main()
{
    int t,m,n,maxx,cnt;
    scanf("%d",&t);
    for(int kase=0;kase<t;kase++)
    {
        scanf("%d %d",&m,&n);
        for(int i=0;i<m;i++)
            scanf("%s",s[i]);
        memset(rec,0,sizeof(rec));
        cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                rec[s[j][i]-'A'][i]++;
            maxx=0;
            for(int j=0;j<26;j++)
                if(rec[j][i]>maxx)
                {
                    ans[i]=j+'A';
                    maxx=rec[j][i];
                }
            cnt+=m-maxx;
        }
        ans[n]='\0';
        printf("%s\n%d\n",ans,cnt);
    }
    return 0;
}
