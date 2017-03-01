/* ahmed akef*/

#include <bits/stdc++.h>
#define CCC(x,a,b) cout << ((x)?(a):(b))
#define all(v)			((v).begin()), ((v).end())
#define sz(v)			((int)((v).size()))
#define fa(a,n)   for(int i = 0; i < n; i++){cin>>a[i];}  //fill array /* akef */
#define clr(v, d) memset(v, d, sizeof(v))
#define rep(i,n) for(int i = 0; i < n; i++)
#define MX_Z 26

using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long         ll;

void setup();


bool adjMatrix[MX_Z][MX_Z];
bool visted[MX_Z];

vector<char>topsort;
vector< vector<int> >adjList;

void dfs(int node ){
    visted[node]=true;
    rep(i,sz(adjList[node])){
        int child = adjList[node][i];
        if(!visted[child])
            dfs(child);
    }
    topsort.push_back(node+'A');
}

int main()
{
    setup();
    string prev;

    while(cin>>prev){
        string current;
        deque<int> nodes;
        vector<bool> used(MX_Z,false);
        adjList.clear();
        adjList.resize(26);
        int flag=true;
        while(cin>>current && current!="#"){

            for(int i = 0; i < min(sz(prev),sz(current)); i++){
                int child  = prev[i] -'A';
                int parent = current[i] -'A';

                if(child!=parent){
                    adjList[parent].push_back(child);


                    if(!used[child]){
                        nodes.push_back(child);
                        used[child]=true;
                    }
                    if(!used[parent]){
                        nodes.push_back(parent);
                        used[parent]=true;
                    }
                    break;

                }
            }
            prev=current;

        }

        topsort.clear();
        clr(visted,false);


        rep(i,sz(nodes)){
            if(!visted[nodes[i]]){
                dfs(nodes[i]);
            }
        }

        for(int i = 0 ; i < sz(topsort) ; i++){
            cout<<topsort[i];
        }
        cout<<endl;
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

