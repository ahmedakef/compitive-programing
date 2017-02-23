/*  by : ahmed akef */
#include <bits/stdc++.h>
#define CCC(x,a,b) cout << ((x)?(a):(b))
#define all(v)			((v).begin()), ((v).end())
#define sz(v)			((int)((v).size()))
#define fa(a,n)   for(int i = 0; i < n; i++){cin>>a[i];}  //fill array /* akef */
#define clr(v, d) memset(v, d, sizeof(v))
#define rep(i,n) for(int i = 0; i < n; i++)
typedef long long         ll;

using namespace std;
void setup();

vector<bool> isPrime(1e6+7,true);
vector<int> getsumDigits(1e6+7);
vector<int> cntDigitPrime(1e6+7);
int n;
void sieve();
int sumDigits(int n);
void Digitprime();
void sums();

int main()
{
    setup();
    sieve();
    sums();
    Digitprime();
    int n;
    scanf("%d",&n);
    int l,r;
    while(n--){
        scanf("%d %d",&l,&r);
        if(l== 0) l=1;
        if(r== 0) r=1;
        printf("%d\n",cntDigitPrime[r]-cntDigitPrime[l-1]);
    }
    return 0;

}

void sieve(){
    isPrime[0]=false;
    isPrime[1]=false;

    for(int i = 2 ; i*i <= 1e6+7 ;i++){
        if(isPrime[i]){
            for(int j= i*i ; j<=1e6+7  ; j+=i)
                isPrime[j]=false;
        }
    }
}


void sums(){
    for(int i = 0 ; i <= 1e6+5 ;i++){
        getsumDigits[i]=sumDigits(i);
    }
}




int sumDigits(int n){
    int res=0;
    while(n){
        res+= n%10;
        n/=10;
    }

    return res;
 }


void Digitprime(){
    cntDigitPrime[0]=0;
    for(int i=1 ; i<=1e6+5 ; i++){
        cntDigitPrime[i] = cntDigitPrime[i-1]+ (isPrime[i] && isPrime[getsumDigits[i]] ) ;
    }
}



void setup()
{
    //ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("test.in","rt",stdin);
    //freopen("s.out","wt",stdout);
#endif // ONLINE_JUDGE
}
