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
void floodFill(int r,int c , char ch);
bool myfunc(const pair<char, int> &a,const pair<char, int> &b);

int h,w;


int main()
{
    setup();
    int T;  cin>>T;
    for(int Case=1 ; Case<=T ;Case++ ){
        cin>>h>>w;

        string s;

        rep(i,h){
            cin>>s;
            world.push_back(s);
        }


        clr(visted,false);
        map<char,int> mp;

        rep(i,h){
            rep(j,w){
                if(!visted[i][j]){
                    char c= world[i][j];
                    if(mp.find(c)==mp.end())
                        mp[c]=1;
                    else
                        mp[c]++;

                    floodFill(i,j,c);
                }

            }
        }
        vector< pair<char,int> > v(mp.begin(),mp.end());

        sort(v.begin(),v.end(),myfunc);

        cout<<"World #"<<Case<<endl;
        rep(i,sz(v)){
            cout<<v[i].first<<": "<<v[i].second<<endl;
        }
        world.clear();


    }




    return 0;

}


void floodFill(int r,int c , char ch){
    if(!valid(r,c) || visted[r][c] || world[r][c]!=ch)
        return ;

    visted[r][c]=true;

    floodFill(r+1,c,ch);
    floodFill(r-1,c,ch);
    floodFill(r,c+1,ch);
    floodFill(r,c-1,ch);


    return ;
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

