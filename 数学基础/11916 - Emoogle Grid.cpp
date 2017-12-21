#include<cstdio>
#include<cmath>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

typedef long long ll;

const ll MOD=1e8+7;
const int maxb=500+5;

int id[maxb],num;
vector<int> blocks[maxb];

int get_id(int y)
{
    for(int i=0;i<num;i++)
        if(id[i]==y)
            return i;
    id[num]=y;
    return num++;
}

void ex_gcd(ll a,ll b,ll &d,ll &x,ll &y)
{
    if(!b)
    {
        d=a;x=1;y=0;
    }
    else
    {
         ex_gcd(b,a%b,d,y,x);
         y-=(a/b)*x;
    }
}

int mul_mod(int a,int b)
{
    return (int)((long long)a*b%MOD);
}

int pow_mod(int a,ll p)
{
    int x,ans;
    if(p==0)
        return 1;
    x=pow_mod(a,p/2);
    ans=(ll)x*x%MOD;
    if(p%2==1)
        ans=(ll)ans*a%MOD;
    return ans;
}

ll inverse(ll a)
{
    ll d,x,y;
    ex_gcd(a,MOD,d,x,y);
    return d==1?(x+MOD)%MOD:-1;
}

int log_mod(int a,int b)
{
    int m,e=1,inv;
    map<int,int> x;
    m=(int)sqrt(MOD+0.5);
    x[1]=0;
    for(int i=1;i<m;i++)
    {
        e=mul_mod(e,a);
        if(!x.count(e))
            x[e]=i;
    }
    inv=inverse(pow_mod(a,m));
    for(int i=0;i<m;i++)
    {
        if(x.count(b))
            return i*m+x[b];
        b=mul_mod(b,inv);
    }
    return -1;
}

int main()
{
    int t,n,k,b,r,id,len,nn,maxx,nn2,ans,p,inv,res,x,y,lb;
    scanf("%d",&t);
    for(int kase=0;kase<t;kase++)
    {
        scanf("%d %d %d %d",&n,&k,&b,&r);
        num=0;maxx=0;nn=n;lb=0;
        for(int i=0;i<b;i++)
        {
            scanf("%d %d",&x,&y);
            maxx=max(maxx,x);
            if(x==1)
                nn--;
            id=get_id(y);
            blocks[id].push_back(x);
        }
        for(int i=0;i<num;i++)
            sort(blocks[i].begin(),blocks[i].end());
        for(int i=0;i<num;i++)
        {
            len=blocks[i].size();
            for(int j=0;j<len-1;j++)
                if(blocks[i][j]==blocks[i][j+1]-1)
                    nn++;
            if(blocks[i][len-1]<maxx)
                nn++;
            else
                lb++;
        }
        printf("maxx:%d\n",maxx);
        nn2=maxx*n-nn-b;
        printf("nn,nn2:%d %d\n",nn,nn2);
        ans=(ll)pow_mod(k%MOD,nn)*pow_mod((k-1)%MOD,nn2)%MOD;
        printf("ans:%d\n",ansv
        printf("Case %d: ",kase+1);
        if(ans==r)
        {
            printf("%d\n",maxx);
            continue;
        }
        ans=(ll)ans*pow_mod(k%MOD,lb)%MOD;
        ans=(ll)ans*pow_mod((k-1)%MOD,n-lb)%MOD;
        if(ans==r)
        {
            printf("%d\n",maxx+1);
            continue;
        }
        p=pow_mod((k-1)%MOD,n);
        inv=inverse(ans);
        res=log_mod(p,mul_mod(inv,r));
        printf("%d\n",res);
    }
    return 0;
}
