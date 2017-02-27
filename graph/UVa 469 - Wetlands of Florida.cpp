/* ahmed akef*/
/* i have learned from this solution : https://github.com/Diusrex/UVA-Solutions/blob/master/469%20Wetlands%20of%20Florida.cpp */
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

bool valid(int r,int c);
int floodFill(int r,int c);

int rows,coulms;
int visted[MX_Z][MX_Z];

vector<string> lake;




main()
{
    setup();
    int T;  cin>>T>>ws;
    for(int Case=1 ; Case<=T ;Case++ ){


        string s;
        lake.clear();

        while(isalpha(cin.peek())){
            cin>>s>>ws;
            lake.push_back(s);
        }
        rows=lake.size();
        coulms=lake[0].size();


        while(isdigit(cin.peek())){
            clr(visted,false);
            int r,c;    cin>>r>>c>>ws;
            cout<<floodFill(r-1,c-1)<<endl;
        }

        if(Case!=T)    cout<<endl;

    }




    return 0;

}


int floodFill(int r,int c){
    if(!valid(r,c) || lake[r][c] == 'L' || visted[r][c])
        return 0;
    visted[r][c]=true;

    int cnt=1;
    cnt+=floodFill(r+1,c);
    cnt+=floodFill(r-1,c);
    cnt+=floodFill(r,c+1);
    cnt+=floodFill(r,c-1);
    cnt+=floodFill(r+1,c+1);
    cnt+=floodFill(r-1,c+1);
    cnt+=floodFill(r+1,c-1);
    cnt+=floodFill(r-1,c-1);

    return cnt;
}






bool valid(int r,int c){
    if(r>=rows || c>=coulms ||r<0 ||c<0)
        return 0;
    return 1;

}






void setup()
{
    ios_base::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
        freopen("test.in","rt",stdin);
        freopen("s.out","wt",stdout);
    #endif // ONLINE_JUDGE
}
