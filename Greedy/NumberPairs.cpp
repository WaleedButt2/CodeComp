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
int main(){
    int t,n,c;
    cin>>t;
    string s;
    FORV(t){
        cin>>n>>c;
        vt ccc(256,0);
        cin>>s;
        FOR(s.length()){
            ccc[s[i]]++;
        }
        int cost=0;
        FOR(91){
            if(i<63) continue;
            if(ccc[i]!=0){
               // cout<<i<<' '<<ccc[i]<<' '<<ccc[i+32]<<endl;
            }
            int ass=min(ccc[i+32],ccc[i]);
            cost+=ass;
            ccc[i+32]-=ass,ccc[i]-=ass;
        }
        //c is cost to use
        FOR(91){
            if(i<63) continue;
            if(c<=0) break;
            int add=min(c,max(ccc[i],ccc[i+32])/2);
            cost+=add;c-=add;
        }
        cout<<cost<<endl;
        //Print(ccc);
    }
}