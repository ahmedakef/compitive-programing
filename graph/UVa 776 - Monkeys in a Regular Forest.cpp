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

bool valid(int r,int c);
void floodFill(int r,int c, char ch,int cnt);
void solve();

int row=0,coulm=0;
int visted[MX_Z][MX_Z];
char world[MX_Z][MX_Z];
int nums[MX_Z][MX_Z];

vector<string> lake;




int main()
{
    setup();
    string s;
    clr(world,'.');
    clr(visted,false);
    while(getline(cin,s))
    {


        if(s=="%")
        {
            solve();
            clr(world,'.');
            clr(visted,false);
            row=0,coulm=0;
            continue;
        }

        istringstream iss(s);
        char c;
        while(iss>>c)
        {
            world[row][coulm]=c;
            coulm++;
        }
        row++;
        coulm=0;



    }
    solve();




    return 0;

}

void solve()
{
    int cnt=0;
    rep(i,MX_Z) // to get number of coulms
    {
        if(world[0][i]=='.')
        {
            coulm=i;
            break;
        }
    }
    rep(i,row) // do the flood fill
    {
        rep(j,coulm)
        {
            if(!visted[i][j])
            {
                char c= world[i][j];
                floodFill(i,j,c,++cnt);

            }

        }
    }
    vector<int> width(coulm); // to know the max width in
    int w;                    // every coulm

    rep(j,coulm){        // loop by coulum not by row
        int mx=0;
        rep(i,row){
            w= 1+ log10(nums[i][j]); // 1+ log10(n) get the lenth of number
            mx=max(mx,w);
        }
        width[j]=mx;
    }

    rep(i,row)
    {
        rep(j,coulm-1)
        {
            cout<<setw(width[j])<<nums[i][j]<<" ";
        }
        cout<<setw(width[coulm-1])<<nums[i][coulm-1]<<endl;
    }

    cout<<"%\n";

}



void floodFill(int r,int c, char ch, int cnt)
{
    if(!valid(r,c) || visted[r][c] || world[r][c]!=ch )
        return  ;

    visted[r][c]=true;
    nums[r][c]=cnt;

    floodFill(r+1,c,ch,cnt);
    floodFill(r-1,c,ch,cnt);
    floodFill(r,c+1,ch,cnt);
    floodFill(r,c-1,ch,cnt);
    floodFill(r+1,c+1,ch,cnt);
    floodFill(r-1,c+1,ch,cnt);
    floodFill(r+1,c-1,ch,cnt);
    floodFill(r-1,c-1,ch,cnt);

    return ;
}






bool valid(int r,int c)
{
    if(r>=row || c>=coulm ||r<0 ||c<0)
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

