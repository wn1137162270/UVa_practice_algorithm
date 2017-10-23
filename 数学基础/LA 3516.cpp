#include<cstdio>
#include<cstring>

const int maxn=300+10;
const int MOD=1e9;
typedef long long ll;

char s[maxn];
int d[maxn][maxn];

int main()
{
	while(scanf("%s",s)!=EOF)
	{
		int j,len=strlen(s);
		memset(d,0,sizeof(d));
		for(int i=0;i<len;i++)
			d[i][i]=1;
		for(int l=2;l<=len;l++)
			for(int i=0;i+l-1<len;i++)
			{
				j=i+l-1;
				if(s[i]!=s[j])
					continue;
				for(int k=i+1;k<=j;k++)
					if(s[k]==s[i])
						d[i][j]=((i+1<=k-1?(ll)d[i+1][k-1]:0LL)*(ll)d[k][j]+d[i][j])%MOD;
			}
		printf("%d\n",d[0][len-1]);
	}
	return 0;
} 
