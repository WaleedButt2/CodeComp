#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define l long
#define sz size()
#define vt vector<int>
#define FOR(n) for (int i = 0; i < n; i++)
#define FORV(n) for (int v = 0; v < n; v++)
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
void Print(vector<vector<pair<int,int>>> v){
    FOR(v.sz) {
        cout<<i+1<<' ';
    FORJ(v[i].sz){
        cout<<v[i][j].second<<' ';

    }cout<<endl;
    }
}
void Print(vector<vt> v){
    FOR(v.sz) {
        FORJ(v[i].sz){
            cout<<v[i][j]<<' ';

        }
    cout<<endl;
    }
}
string prettyPrint(int x){
    string s="";
    vt cnt;
    FOR(x){
        if((i+1)%3==0 && (i+1)%5==0){
            s+="FB";
            cnt.pb(i+1);
            cnt.pb(i+1);
        }
        else if((i+1)%5==0){
            s+='B';
            cnt.pb(i+1);
        }
        else if((i+1)%3==0){
            s+='F';
            cnt.pb(i+1);
        }
    }
    return s;
}
int main(){
    int t=0;
    cin>>t;
    string s=prettyPrint(500);
    FORV(t){
        int n;
        cin>>n;
        string f;
        cin>>f;
        if(s.find(f)!=string::npos){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}
