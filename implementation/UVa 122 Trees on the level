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

bool myfunc(const pair<int,string> &a,const pair<int,string> &b);


main()
{
    setup();
    vector<pair<int ,string > > v;
    int n;
    string s;
    char c;
    string line;
    while(getline(cin,line)){
        istringstream iss(line);
        while(iss>>c>>n>>s){
            s=s.substr(1,sz(s)-2);
            v.push_back(make_pair(n,s));
        }
        int len = sz(line);
        if(line[len-2]=='(' && line[len-1]==')'){
            sort(all(v),myfunc);
            bool flag=true;
            if(v[0].second!=""){
                cout<<"not complete";
                flag=false;
            }else if(v[0].second=="" && sz(v)==1) {
                cout<<v[0].first;
                flag=false;
            }else{

                for (int i =1; i<sz(v) ;i++){
                    bool flag2=true;
                    string temp= v[i].second;
                    if( temp ==""){
                        flag=false;
                        flag2=false;
                        cout<<"not complete";
                        break;
                    }
                    if( (i==1 || i==2)){
                        if ( sz(temp)==1 ){
                            continue;
                        }else if( sz(temp)>2  ){
                            flag=false;
                            flag2=false;
                            cout<<"not complete";
                            break;
                        }else if(i==1 && sz(temp)>1 ){
                            flag=false;
                            flag2=false;
                            cout<<"not complete";
                            break;
                        }
                    }
                    temp = temp.substr(0,sz(temp)-1);
                    int cnt=0;
                    for (int j =0; j<i ;j++){
                        if(v[j].second == temp || v[j].second == v[i].second ){
                            cnt++;
                        }
                        if(j==i-1 && cnt!=1){
                            flag=false;
                            flag2=false;
                            cout<<"not complete";
                        }
                    }
                    if(flag2==false)
                        break;
                }

                if(flag){
                    for (int i =0; i<sz(v)-1 ;i++){
                        cout<< v[i].first <<" ";
                    }
                    cout<<v[sz(v)-1].first;
                }
            }
                cout<<"\n";
                v.clear();
            }
        }




    return 0;

}




bool myfunc(const pair<int, string> &a,const pair<int, string> &b){
    int a_z=sz(a.second);
    int b_z=sz(b.second);
     if(a_z== b_z){
        return a.second<b.second;
    }
    return a_z < b_z;
}





void setup()
{
    //ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("test.in","rt",stdin);
    freopen("s.out","wt",stdout);
#endif // ONLINE_JUDGE
}

