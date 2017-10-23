#include<cstdio>
#include<cstring>
#include<cctype>
using namespace std;

const int maxn=100+10;

int a[maxn];

inline int readint()
{
	int x=0;
	char c=getchar();
	while(!isdigit(c))
		c=getchar();
	while(isdigit(c))
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}

char buffer[10];
inline void writeint(int x)
{
	int p=0;
	if(x==0)
		putchar('0');
	else
	{
		while(x)
		{
			buffer[p++]=x%10+'0';
			x/=10;     
		}
		for(int i=p-1;i>=0;i--)
			putchar(buffer[i]);
	}
}

int main()
{
	int n,t,first;
	while(n=readint())
	{
		memset(a,0,sizeof(a));
		for(int i=0;i<n;i++)
		{
			t=readint();
			a[t]++;
		}
		first=1;
		for(int i=1;i<=100;i++)
		{
			t=a[i];
			for(int j=0;j<t;j++)
			{
				if(!first)
					putchar(' ');
				writeint(i);
				first=0;
			}
		}
		putchar('\n');
	}
	return 0;	
}
