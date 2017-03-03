/* ahmed akef*/
#include <bits/stdc++.h>
#define CCC(x,a,b) cout << ((x)?(a):(b))
#define all(v)			((v).begin()), ((v).end())
#define sz(v)			((int)((v).size()))
#define fa(a,n)   for(int i = 0; i < n; i++){cin>>a[i];}  //fill array /* akef */
#define clr(v, d) memset(v, d, sizeof(v))
#define rep(i,n) for(int i = 0; i < n; i++)
#define MX_Z 1000

using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long         ll;

void setup();




int main()
{
    setup();
    int T;  cin>>T;
    while(T--){
        int a,b;
        while(cin>>a>>b){
            if(a>b)         cout<<">\n";
            else if(a<b)    cout<<"<\n";
            else            cout<<"=\n";
        }
    }
    return 0;

}





void setup()
{
    ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("test.in","rt",stdin);
    //freopen("s.out","wt",stdout);
#endif // ONLINE_JUDGE
}

