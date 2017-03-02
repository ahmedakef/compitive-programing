/* ahmed akef*/

#include <bits/stdc++.h>
#define CCC(x,a,b) cout << ((x)?(a):(b))
#define all(v)			((v).begin()), ((v).end())
#define sz(v)			((int)((v).size()))
#define fa(a,n)   for(int i = 0; i < n; i++){cin>>a[i];}  //fill array /* akef */
#define clr(v, d) memset(v, d, sizeof(v))
#define rep(i,n) for(int i = 0; i < n; i++)
#define MX_Z 101

using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long         ll;

void setup();



vector< vector<int> > adjList(MX_Z);
int visted[MX_Z];

vector<int> topsort;

void dfs(int node){
    visted[node]=true;

    rep(i,sz(adjList[node])){

        int child= adjList[node][i];
        if(!visted[child])
            dfs(child);

    }

    topsort.push_back(node);
}


int main()
{
    setup();
    int n,m;
    while(cin>>n>>m && n|m !=0 ){

        int i,j;
        while(m--){
            cin>>i>>j;
            adjList[i].push_back(j);
        }

        clr(visted,false);
        for(int i = 1; i <= n; i++){
            if(!visted[i])
                dfs(i);
        }


        for(int i = sz(topsort)-1 ; i>=1 ;i--){
            cout<<topsort[i]<<" ";
        }
        cout<<topsort[0]<<endl;

        topsort.clear();
        adjList=vector< vector<int> >(MX_Z);
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

