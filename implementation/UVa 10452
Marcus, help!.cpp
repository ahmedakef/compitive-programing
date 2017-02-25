/* ahmed akef*/
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



main()
{
    setup();
    int T;  cin>>T;
    string word="IEHOVA#";
    string r="right";
    string l="left";
    string f="forth";
    string dir;
    while(T--){
        int n,m;    cin>>n>>m;
        int k=n;
        vector<string> arr(n);
        while(k--){
            cin>>arr[k];
        }
        int now = arr[0].find('@');
        k=0;
        bool flag=true;
        rep(i,n){
            int cnt;
            int found = arr[i].find(word[k]);
            if(found==now){
                if(k<6)     k++;
                else{
                    flag=false;
                    break;
                }
                found = arr[i].find(word[k]);
            }
            while(found !=string::npos ){
                cnt=found-now;
                now=found;
                if(cnt>0)   dir=r;
                else        dir=l;
                rep(j,abs(cnt)){
                    if(k==6)     cout<<dir;
                    else         cout<<dir<<" ";
                }

                if(k<6){
                  k++;
                  found = arr[i].find(word[k]);
                }else{
                    flag=false;
                    break;
                }

            }
            if(flag==false)
                break;

            if(k==6)     cout<<f;
            else         cout<<f<<" ";
        }
        cout<<endl;
        arr.clear();
    }



    return 0;

}







void setup()
{
    //ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("test.in","rt",stdin);
    freopen("s.out","wt",stdout);
#endif // ONLINE_JUDGE
}
