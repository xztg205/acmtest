//exgcd 
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int exgcd(ll a,ll b,ll &x,ll &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    ll x1,y1;
    ll d=exgcd(b,a%b,x1,y1);
    x=y1;
    y=x1-(a/b)*y1;
    return d;
}
int main()
{
    ll a,b,x,y;
    cin>>a>>b;
    exgcd(a,b,x,y);
    x=(x%b+b)%b;
    cout<<x;
    return 0;
}

//快速幂
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll binpow(ll a,ll b,ll p)
{
    ll res=1;
    while(b>0)
    {
        if(b&1)
        {
            res=res*a%p;
        }
        a=a*a%p;
        b>>=1;
    }
    return res;//
}
int main()
{
    ll a,b,p;
    cin>>a>>b>>p;
    ll d=binpow(a,b,p);
    cout<<a<<'^'<<b<<" mod "<<p<<'='<<d<<endl;
    return 0;
}


//dp1
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,m;
    cin>>t>>m;
    int time[101];
    int value[101];
    int dir[1001]={0};
    for(int i=0;i<m;i++)
    {
        cin>>time[i]>>value[i];
        for(int j=t;j>0;j--)
        {
            if(time[i]<=j)
            dir[j]=max(dir[j],dir[j-time[i]]+value[i]);
        }
    }
    cout<<dir[t]<<endl;
    return 0;
}


//dp2
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m;
    int t;
    cin>>t>>m;
    int time[10001];
    int value[10001];
    long long dir[10000001]={0};
    for(int i=0;i<m;i++)
    {
        cin>>time[i]>>value[i];
            for(int j=time[i];j<=t;j++)
        {
            dir[j]=max(dir[j],dir[j-time[i]]+value[i]);
        }   
    }
    cout<<dir[t]<<endl;
    return 0;
}


//欧拉筛
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define N 100000000
vector<ll> pri;
vector<bool> no_prime(N+1);
void per(ll n)
{
    for(ll i=2;i<=n;i++)
    {
        if(!no_prime[i])
        {
            pri.push_back(i);
        }
        for(ll pri_j:pri)
        {
            if(i*pri_j>n)
            {
                break;
            }
            no_prime[i*pri_j]=true;
            if(i%pri_j==0)
            {
                break;
            }
        }
    }
}
int main()
{
    ll n;
    cin>>n;
    per(n);
    cout<<pri.size()<<endl;
    return 0;
}


//欧拉筛+dp
#include<bits/stdc++.h>
using namespace std;
#define N 1005
vector<int> pri;
bool no_prime[N];
int n;
long long dp[N];
void per(int n)
{
    for(int i=2;i<=n;i++)
    {
        if(!no_prime[i])
        {
            pri.push_back(i);
        }
        for(int pri_j:pri)
        {
            if(pri_j*i>n)
            {
                break;
            }
            no_prime[i*pri_j]=true;
            if(i%pri_j==0)
            {
                break;
            }
        }
    }
}

int main()
{
    cin>>n;//
    per(n);
    dp[0]=1;
    for(int p:pri)
    {
        for(int i=p;i<=n;i++)
        {
            dp[i]+=dp[i-p];
        }
    }
    cout<<dp[n]<<endl;
    return 0;
} 
