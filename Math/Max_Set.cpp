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
void Print_set(set<int>axe){
    for(auto t:axe){
        cout<<t<<' ';
    }
}
void Pretty_Print(vector<vector<set<int>>> v){
    cout<<"   ";
    FOR(v.sz) {
        cout<<i;
        if(i>=10) cout<<" ";
        else cout<<"  ";    
    }
    cout<<endl;
    FOR(v.sz){
        cout<<i;
        if(i>=10) cout<<" ";
        else cout<<"   ";  
        FORJ(v[i].sz){
            Print_set(v[i][j]);  
        }
        cout<<endl;
    }
}
bool Union(set<int> x, set<int> y){
    x.insert(y.begin(),y.end());
    for(auto first: x ){
        for(auto second : x){
            if(first%second!=0) return false;
        }
    }
    return true;
}
void DP(int L,int R){

}
void Max_Set_Size(int L,int R){
    //max size of set is k
    //x x*2 x*2^2 x*2^3 x*2^k-1
    //find x*2^k-1 (take it as a var named Peak)
    int Peak=L;
    int k=1;
    while(Peak*2<=R){
        Peak*=2;
        k++;
    }
    cout<<k<<' ';
    Peak/=L;
    int ans = R/Peak-L+1;
    Peak/=2;
    Peak*=3;
    cout<<max(0,ans+(R/Peak-L+1)*((k-1)))<<endl;
}
int main(){
    int t=0;
    cin>>t;
    FORV(t){
        int L,R;
        cin>>L>>R;
        Max_Set_Size(L,R);
    }
}