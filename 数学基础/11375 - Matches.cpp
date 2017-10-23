#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

const int maxn=2000+10;
const int c[10]={6,2,5,5,4,5,6,3,7,6};

struct BigInteger
{
	static const int BASE=1e8;
	static const int WIDTH=8;
	vector<int> s;
	
	BigInteger (int num=0)
	{
		*this=num;
	}
	
	BigInteger operator =(int num)
	{
		s.clear();
		do
		{
			s.push_back(num%BASE);
			num/=BASE;
		}while(num>0);
		return *this;
	}
	
	BigInteger operator	+(const BigInteger &b)const
	{
		int len1,len2;
		BigInteger c;
		c.s.clear();
		len1=s.size();len2=b.s.size();
		for(int i=0,g=0;g!=0||i<len1||i<len2;i++)
		{
			int x=g;
			if(i<len1)
				x+=s[i];
			if(i<len2)
				x+=b.s[i];
			c.s.push_back(x%BASE);
			g=x/BASE;
		}
		return c;
	}
	
	BigInteger operator	+=(const BigInteger &b)
	{
		*this=*this+b;
		return *this;
	}
	
	void print()
	{
		int len=s.size();
		printf("%d",s[len-1]);
		for(int i=len-2;i>=0;i--)
			printf("%08d",s[i]);
		printf("\n");
	}
};

BigInteger d[maxn],s[maxn];

int main()
{
	int n;
	for(int i=0;i<maxn;i++)
		d[i]=0;
	d[0]=1;
	for(int i=0;i<maxn;i++)
		for(int j=0;j<10;j++)
			if(!(i==0&&j==0)&&i+c[j]<maxn)
				d[i+c[j]]+=d[i];
	s[1]=d[1];
	for(int i=2;i<maxn;i++)
	{
		s[i]=s[i-1]+d[i];
		if(i==6)
			s[i]+=1; 
	}
	while(scanf("%d",&n)!=EOF)
		s[n].print();
	return 0;	
} 
