#include <bits/stdc++.h>
#define N int (1e7)
using namespace std;
int p[N+2];
int n;
void sangngto (int n) //sang nguyen to
{
    fill(p,p+n+1,1); //phu toan bo mang p voi gia tri 1
    p[0]=p[1]=0;
    for(int i=2;i*i<=n;i++)
    {
        if(p[i]==1)
        for(int j=i*i;j<=n;j+=i) p[j]=0;
    }
}
int f[10001];
int smax=1;
int dem=0;
int A[10001];
int main()
{
    cin>>n;
    sangngto(10000);
    for(int i=1;i<=n;i++)
    cin>>A[i];
    for(int i=1;i<=n;i++)
    {
        if(p[A[i]]==1)
            f[i]=1;
        else f[i]=0;
    }
    for(int i=2;i<=n;i++)
    {
        if(f[i]==f[i-1] && f[i]==1)
        dem++;
        else    
        {
            if(dem>smax)smax=dem;
            dem=1;
        }
    }
    cout<<smax;
}
