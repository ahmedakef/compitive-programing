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




int visted[MX_Z][MX_Z];
vector<string> world;

bool valid(int r,int c);
int floodFill(int r,int c , char ch);
bool myfunc(const pair<char, int> &a,const pair<char, int> &b);

int h,w;


int main()
{
    setup();
    int Case=0;
    while(cin>>h>>w && h|w !=0 ){

        Case++;
        string s;

        rep(i,h){
            cin>>s;
            world.push_back(s);
        }


        clr(visted,false);
        vector< pair<char,int> > v;

        rep(i,h){
            rep(j,w){
                if(!visted[i][j]){
                    char c= world[i][j];
                    if(c=='.')  continue;

                    int n=floodFill(i,j,c);
                    v.push_back(make_pair(c,n));

                }

            }
        }

        sort(v.begin(),v.end(),myfunc);

        cout<<"Problem "<<Case<<":"<<endl;
        rep(i,sz(v)){
            cout<<v[i].first<<" "<<v[i].second<<endl;
        }
        world.clear();


    }




    return 0;

}


int floodFill(int r,int c , char ch){
    if(!valid(r,c) || visted[r][c] || world[r][c]!=ch )
        return 0 ;

    visted[r][c]=true;

    int cnt=1;
    cnt+=floodFill(r+1,c,ch);
    cnt+=floodFill(r-1,c,ch);
    cnt+=floodFill(r,c+1,ch);
    cnt+=floodFill(r,c-1,ch);


    return cnt;
}






bool valid(int r,int c){
    if(r>=h || c>=w ||r<0 ||c<0)
        return 0;
    return 1;

}


bool myfunc(const pair<char, int> &a,const pair<char, int> &b){
    if (a.second != b.second)
        return a.second>b.second;
    return a.first < b.first;
}




void setup()
{
    ios_base::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
        freopen("test.in","rt",stdin);
        freopen("s.out","wt",stdout);
    #endif // ONLINE_JUDGE
}

