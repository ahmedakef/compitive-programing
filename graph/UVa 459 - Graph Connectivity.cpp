/* ahmed akef*/

#include <bits/stdc++.h>
#define CCC(x,a,b) cout << ((x)?(a):(b))
#define all(v)			((v).begin()), ((v).end())
#define sz(v)			((int)((v).size()))
#define fa(a,n)   for(int i = 0; i < n; i++){cin>>a[i];}  //fill array /* akef */
#define clr(v, d) memset(v, d, sizeof(v))
#define rep(i,n) for(int i = 0; i < n; i++)
#define MX_Z 100

using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long         ll;

void setup();




bool visted[MX_Z];
vector< vector<int> > adjList;

void dfs(int node ){
    visted[node]=true;

    int SZ=adjList[node].size();

    rep(i,SZ){
        int child= adjList[node][i];
        if(!visted[child])
            dfs(child);
    }
}



main()
{
    setup();
    int T;  cin>>T;
    for(int Case=1 ; Case<=T ;Case++ ){
        char c; cin>>c;

        int n=c-'A'+1;

        string s;
        getline(cin,s);

        adjList=vector< vector<int> >(n);

        while(getline(cin,s) && s!=""){
            int from = s[0]-'A';
            int to   = s[1]-'A';
            adjList[from].push_back(to);
            adjList[to].push_back(from);
        }

        clr(visted,false);

        int cnt=0;

        rep(i,n){
            if(!visted[i]){
                cnt++;
                dfs(i);
            }
        }
        if(Case==T) cout<<cnt<<"\n";
        else        cout<<cnt<<"\n\n";

    }




    return 0;

}







void setup()
{
    ios_base::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
        freopen("test.in","rt",stdin);
        freopen("s.out","wt",stdout);
    #endif // ONLINE_JUDGE
}
