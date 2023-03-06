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
void Print_set(set<int>axe){
    for(auto t:axe){
        cout<<t<<' ';
    }
}
void ADD(vector<pa> &parent,vector<pa> &curr,int c){
    int black=1,white=1;
    if(c) white=0;
    else black=0;
    FOR(parent.sz){
        curr.pb(pa(parent[i].first+white,parent[i].second+black));
    }
}
vector<vector<pa>> Dijkstras(vector<vector<pa>> &Graph){
    vt p(Graph.sz,-1);
    vector<vector<pa>> dist(Graph.sz);
    int go_to,added_dist;
    dist[0].pb(pa(0,0));
    FORU(Graph.sz){
        FORV(Graph[u].sz){
            //Print(dist);
            ADD(dist[u],dist[Graph[u][v].first],Graph[u][v].second);
        }
    }
    return dist;
}
int Solve(vector<pa> &dest,int black,int white){
    vt solution;
    FOR(dest.sz){
        solution.pb(dest[i].first*black+dest[i].second*white);
    }
    sort(solution.begin(),solution.end());
    return solution[0];
}
int main(){
    int n,m,u,v,c,q,a,b,x;
    cin>>n>>m;
    vector<vector<pa>> Graph(n);
    FOR(m){
        cin>>u>>v>>c;
        Graph[u-1].pb(pa(v-1,c));
    }
    vector<vector<pa>> dist=Dijkstras(Graph);
   // cout<<endl;
    //PrintG(Graph);
    cin>>q;
    FOR(q){
        cin>>a>>b>>x;
        x--;
        cout<<Solve(dist[x],a,b)<<endl;
    }
    //a is black b is white
}