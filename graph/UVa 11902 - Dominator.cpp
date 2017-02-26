/* ahmed akef*/

#include <bits/stdc++.h>
#define CCC(x,a,b) cout << ((x)?(a):(b))
#define all(v)			((v).begin()), ((v).end())
#define sz(v)			((int)((v).size()))
#define fa(a,n)   for(int i = 0; i < n; i++){cin>>a[i];}  //fill array /* akef */
#define clr(v, d) memset(v, d, sizeof(v))
#define rep(i,n) for(int i = 0; i < n; i++)

using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long         ll;

void setup();

#define MX_Z 100


int n;
bool adjMatrix[MX_Z][MX_Z];
bool visted[MX_Z];
bool dominates[MX_Z][MX_Z];


void dfs(int node ){
    visted[node]=true;
    rep(i,n){
        if(adjMatrix[node][i] && !visted[i])
            dfs(i);
    }
}

void printLine(){
    cout<<"+";
    rep(i,2*n-1)    cout<<"-";
    cout<<"+\n";
}


main()
{
    setup();
    int T;  cin>>T;
    for(int c=1 ; c<=T ;c++ ){
        cin>>n;
        rep(i,n)rep(j,n)    cin>>adjMatrix[i][j];

        clr(dominates,false);

        for(int removed_node =1 ; removed_node<n ; removed_node++){
            clr(visted,false);
            visted[removed_node]=true;
            dfs(0);
            rep(i,n){
                if(!visted[i])  dominates[removed_node][i]=true;
            }
            dominates[removed_node][removed_node]=true;
        }
        clr(visted,false);
        memset(dominates, true , sizeof(bool)*n);
        dfs(0);

        cout<<"Case "<<c<<":\n";
        rep(i,n){
            printLine();
            rep(j,n){
                cout<<( (dominates[i][j] && visted[j] ) ? "|Y":"|N");
            }
            cout<<"|\n";
        }
        printLine();
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
