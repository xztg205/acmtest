//逆元
//exgcd方法 
int ex_gcd(int a,int b,int &x,int &y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return a;	
	}
	int d=ex_gcd(b,a%b,y,x);
	y-=(a/b)*x;
	return d;
 } 
int inv(int a,int b)
{
	int x,y;
	exgcd(a,b,x,y);
	return (x%b+b)%b;
}
//快速幂方法 
const ll MOD=1e9+7;/////
int binpow(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1)
		{
			res=res*a%MOD;
		}
		a=a*a%MOD;
		b>>=1;
	}
	return res;
 } 
 int inv(int a,int b)
 {
 	return binpow(a,b-2);
 }
 //线性方法 
const int MAXN=1e6;
using ll=long long;
int inv[MAXN];
inv[1]=1;
for(int i=2;i<=n;i++)
{
	inv[i]=(ll)(p-p/i)*inv[p%i]%p;
}
//同余方程
ll ex_gcd(ll a,ll b,ll &x,ll &y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return a;
	}
	int d=ex_gcd(b,a%b,x,y);
	y-=(a/b)*x;
	return d;
}
ll scle(ll a,ll b,ll p)
{
	ll x,y;
	ll d=ex_gcd(a,p,x,y);
	if(b%d) return -1;
	p=p/d;
	return ((long long)x*(b/d)%p+p)%p;
}
 
//组合数
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=1e9+7;
const int MAXN=1e6+5;
ll fact[MAXN];
ll invfact[MAXN];
ll binpow(ll a,ll b)
{
	ll res=1; 
	while(b)
	{
		if(b&1) res=res*a%MOD;
		a=a*a%MOD;
		b>>=1;
	}
	return res;
}
void init_fact( )
{
	fact[0]=1;
	for(int i=1;i<MAXN;i++)
	{
		fact[i]=fact[i-1]*i%MOD;
	}
	invfact[MAXN-1]=binpow(fact[MAXN-1],MOD-2);
	for(int i=MAXN-1;i>0;i--)
	{
		invfact[i-1]=invfact[i]*i%MOD;
	}
}
ll C(int n,int m)
{
	if(m<0||m>n) return -1;
	return fact[n]*invfact[m]%MOD*invfact[n-m];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	init_fact();
 } 
//分解质因数
vector <int>spf(int n)
{
	vector<int> result;
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			while(n%i==0)
			{
				n/=i;
			}
			result.push_back(i);
		}
	}
	if(n!=1)
	{
		result.push_back(n);
	}
	return result;
 } 
 //公约数
 //初始化
 #define N 1000000
 vector<int> pri;
 bool no_prime[N];
 int spf[N];
 void init() 
 {
 	for(int i=2;i<N;i++)
 	{
 		if(!no_prime[i])
 		{
 			pri.push_back(i);
 			spf[i]=i;
		 }
		 for(int pri_j:pri)
		 {
		 	if(pri_j*i>=N)
		 	{
		 		break;
			 }
			 no_prime[i*pri_j]=true;
			 spf[i*pri_j]=pri_j;
			 if(i%pri_j==0)
			 {
			 	break;
			 }
		 }
	 }
 }
 //个数
  int get_count(int n)
  {
  	int ans=1;
  	while(n>1)///
  	{
  		int p=spf[n];
  		int cnt=0;
  		while(n%p==0)
  		{
  			n/=p;
  			cnt++;
		  }
		  ans*=(cnt+1);
	}
	return ans;
  }
//个数和
int get_sum(int n)
{
	int ans=1;
	while(n>1)///
	{
		int p=spf[n];
		int cnt=0;
		while(n%p==0)
		{
			n/=p;
			cnt++;
		}
		int sum=1;
		int power=1;
		for(int i=0;i<cnt;i++)
		{
			power*=p;
			sum+=power;
		}
		ans*=sum;
	}
	return ans;
 } 
 //欧拉函数
 //模板一
 int ohi(int n)
 {
 	int ans=n;
 	for(int i=2;i*i<=n;i++)
 	{
 		if(n%i==0)
 		{
 			ans=ans*i/(i-1);//等价ans=ans/i*(i-1) 
 			while(n%i==0) n/=i;
		 }
	 }
	 if(n>1) ans=ans*n/(n-1);
	 return ans;
  } 
  //模板二
  #define N 1000000
  vector<int> pri;
  bool no_prime[N];
  int phi[N];
  void init_phi( )
  {
  	phi[1]=1;/////
  	for(int i=2;i<N;i++)
  	{
  		if(!no_prime[i])
  		{
  			pri.push_back(i);
  			phi[i]=i-1;
		  }
		  for(int pri_j:pri)
		  {
		  	if(pri_j*i>=N)
		  	{
		  		break;
			  }
			  no_prime[i*pri_j]=true;
			  if(i%pri_j==0)
			  {
			  	phi[i*pri_j]=phi[i]*pri_j;
			  	break;
			  }
			  else
			  {
			  	phi[i*pri_j]=phi[i]*(pri_j-1);
			  }
		  }
	  }
   } 
   int main()
   {
   	ios::sync_with_stdio(false);
   	cin.tie(nullptr);
   	init_phi();
   	return 0;
   }
 
 //向下取整
 int get_floor(int a,int b)
 {
 	if(b<0)
 	{
 		a=-a;
 		b=-b;
	 }
	 if(a>=0)
	 {
	 	return a/b;
	 }
	 else
	 {
	 	return (-(-a+b-1)/b);
	 }
  } 
//向上取整
int get_ceil(int a,int b)
{
	if(b<0)
	{
		a=-a;
		b=-b;
	}
	if(a>=0)
	{
		return (a+b-1)/b;
	}
	else
	{
		return a/b;
	}
 } 


