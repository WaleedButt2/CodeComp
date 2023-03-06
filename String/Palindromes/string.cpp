#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define l long
#define sz size()
#define vt vector<int>
#define pa pair<int,int>
#define FOR(n) for (int i = 0; i < n; i++)
#define FORV(n) for (int v = 0; v < n; v++)
#define FORU(n) for (int u = 0; u < n; u++)
#define FORJ(n) for (int j = 0; j < n; j++)
#define RFOR(n) for (int i = n - 1; i >= 0; i--)
void Print(vector<int> v){
    FOR(v.sz) cout<<v[i]<<' '; 
    cout<<endl;
}
void Print(vector<bool> x){
    FOR(x.sz) if(x[i]) cout<<"1 ";
    else cout<<"0 ";
    cout<<endl;
}
void Print(vector<vector<pa>> v){
    FOR(v.sz) {
        cout<<i<<"  ";
    FORJ(v[i].sz){
        cout<<v[i][j].first<<' '<<v[i][j].second<<"   ";

    }cout<<endl;
    }
}
void PrintG(vector<vector<pa>> v){
    FOR(v.sz) {
        cout<<i<<"  ";
    FORJ(v[i].sz){
        cout<<v[i][j].first<<' ';

    }cout<<endl;
    }
}
void PrintMat(vector<vt> Matrix){
    for(int i=0;i<Matrix.size();i++){ 
    for(int j=0;j<Matrix[i].size();j++)
    cout<<Matrix[i][j]<<' ';
    cout<<endl;
    }
    cout<<endl;
}
void Print(vector<vt> v){
    FOR(v.sz) {
        cout<<i<<"  ";
        FORJ(v[i].sz){
            cout<<v[i][j]<<' ';

        }
    cout<<endl;
    }
}
void Print(vector<vector<string>>axe){
    FOR(axe.sz){
        FORV(axe[i].sz){
            cout<<axe[i][v]<<"  ";
        }
        cout<<endl;
    }
    }
void Print_set(set<int>axe){
    for(auto t:axe){
        cout<<t<<' ';
    }
}
bool check_palin(string s, string b){
    FOR(s.sz){
        if(!(s[i]==b[s.length()-i-1])){
            return false;
        }
    }
    return true;
}
bool Solve(vector<string> ss,int size){
    vector<vector<string>> Lengths(size+1);
    FOR(ss.sz){
        Lengths[ss[i].length()].pb(ss[i]);
    }
    FOR(Lengths.sz){
        int count=0;
        FORJ(Lengths[i].sz){
            count++;
        }
        if(count==3) return false; 
    }
    // exit(0);
    //Print(Lengths);
    if(!check_palin(Lengths[size-1][0],Lengths[size-1][1]))return false;
    else return true;
     FOR(Lengths.sz){
        if(Lengths[i].sz==0) continue;
         if(!check_palin(Lengths[i][0],Lengths[i][1])){
            return false;
        }
    }
    return true;
}
int main(){
    int t;
    cin>>t;
    FORV(t){
        int n;
        cin>>n;
        vector<string> ss(n*2-2);
        FOR(n*2-2){
            cin>>ss[i];
        }
        if(Solve(ss,n)) cout<<"YES\n";
        else cout<<"NO\n";
    }
}