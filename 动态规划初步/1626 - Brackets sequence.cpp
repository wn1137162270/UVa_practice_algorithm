#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=100+10;
const int INF=1<<30;

char s[maxn];
int d[maxn][maxn];

void print(int i,int j)
{
	int l,next;
	l=j-i+1;
	if(l==0)
		return;
	if(l==1)
	{
		if(s[i]=='('||s[i]==')')
			printf("()");
		else
			printf("[]");
		return;
	}
	if((s[i]=='('&&s[j]==')')||(s[i]=='['&&s[j]==']'))
	{
		next=i+1<=j-1?d[i+1][j-1]:0;
		if(d[i][j]==next)
		{
			printf("%c",s[i]);
			print(i+1,j-1);
			printf("%c",s[j]);
			return;
		}
	}
	for(int k=i;k<j;k++)
	{
		if(d[i][j]==d[i][k]+d[k+1][j])
		{
			print(i,k);
			print(k+1,j);
			return;
		}
	}
}

int main()
{
	int t,len,j,k;
	scanf("%d",&t);
	getchar();
	for(int kase=0;kase<t;kase++)
	{
		gets(s);gets(s);
		len=strlen(s);
		for(int l=1;l<=len;l++)
			for(int i=0;i+l-1<len;i++)
			{
				j=i+l-1;
				if(l==1)
					d[i][j]=1;
				else
				{
					d[i][j]=INF;
					if((s[i]=='('&&s[j]==')')||(s[i]=='['&&s[j]==']'))
						d[i][j]=min(d[i][j],i+1<=j-1?d[i+1][j-1]:0);
					for(int k=i;k<j;k++)
						d[i][j]=min(d[i][j],d[i][k]+d[k+1][j]);
				}
			}
		print(0,len-1);
		printf("\n");
		if(kase<t-1)
			printf("\n");
	}
	return 0;	
} 
