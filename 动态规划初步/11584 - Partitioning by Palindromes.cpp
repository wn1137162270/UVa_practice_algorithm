#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=1000+10;
const int INF=maxn;

char s[maxn];
bool pal[maxn][maxn];
int d[maxn];

int main()
{
	int t,len;
	scanf("%d",&t);	
	for(int kase=0;kase<t;kase++)
	{
		scanf("%s",s);
		memset(pal,0,sizeof(pal));
		len=strlen(s);
		for(int i=0;i<len;i++)
			for(int j=0;i-j>=0&&i+j<len;j++)
				if(s[i-j]==s[i+j])
					pal[i-j][i+j]=1;
				else
					break;
		for(int i=0;i<len-1;i++)
			for(int j=0;i-j>=0&&i+1+j<len;j++)
				if(s[i-j]==s[i+1+j])
					pal[i-j][i+1+j]=1;
				else
					break;
		for(int i=0;i<len;i++)
		{
			d[i]=INF;
			for(int j=0;j<=i;j++)
				if(pal[j][i])
				{
					if(j==0)
						d[i]=1;
					else
						d[i]=min(d[i],d[j-1]+1);
				}
		}
		printf("%d\n",d[len-1]);
	}
} 
