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
void Print(vector<vector<string>> v){
    FOR(v.sz) {
        FORJ(v[i].sz){
            cout<<v[i][j]<<' ';

        }
    cout<<endl;
    }
}
bool comp(string a, string b){
    if(a.length()<b.length()) return true;
    return false;
}
//chose string or not choose
string LCS(string X, string Y , int m , int n,string hold){
    //if match of Both m-1 n-1
    if(m==-1||n==-1){
        return hold;
    }
    if(X[m]==Y[n]){
        hold=LCS(X,Y,m-1,n-1,X[m]+hold);
    }
    //if match of none do either m-1 or n-1 
    hold=max(hold,max(LCS(X,Y,m-1,n,""),LCS(X,Y,m,n-1,""),comp),comp);
    //cout<<hold<<endl;
    return hold;
}
//Common sub array
string CSA_DP_string(string X, string Y){
    int n=X.length(),m=Y.length();
    vector<vector<string>> CSA(n+1,vector<string>(m+1,""));
    int res=0;
    string seq="";
    FOR(n+1){
        FORJ(m+1){
            if(i==0 || j==0){
                CSA[i][j]="";
            }
            else if(X[i-1]==Y[j-1]){
                CSA[i][j]=CSA[i-1][j-1]+X[i-1];
                if(CSA[i][j].length()==2) return CSA[i][j];
            }
        }
    }
    string ass;
    FOR(n+1){
        FORJ(m+1){
            ass = max(ass, CSA[i][j],comp);
        }
    }
    return ass;
}
string LCS_DP_string(string X, string Y){
    int n=X.length(),m=Y.length();
    vector<vector<string>> DP(n+1,vector<string>(m+1,""));
    int res=0;
    string seq="";
    FOR(n+1){
        FORJ(m+1){
            if(i==0 || j==0){
                DP[i][j]="";
            }
            else if(X[i-1]==Y[j-1]){
                DP[i][j]=DP[i-1][j-1]+X[i-1];
            }
            else{
                DP[i][j]=max(DP[i-1][j],DP[i][j-1],comp);
            }
        }
    }
    Print(DP);

    return DP[n][m];
}
int LCS_DP(string X, string Y){
    int n=X.length(),m=Y.length();
    vector<vt> DP(n+1,vt(m+1,0));
    int res=0;
    FOR(n+1){
        FORJ(m+1){
            if(i==0 || j==0){
                DP[i][j]=0;
            }
            else if(X[i-1]==Y[j-1]){
                DP[i][j]=DP[i-1][j-1]+1;
                
            }
            else{
                DP[i][j]=max(DP[i-1][j],DP[i][j-1]);
            }
        }
    }
    //Print(DP);
    return DP[n][m];
}

int main(){
    int t;
    cin>>t;
    string a="code";
    string b="forcecoder";
    // try to achive *x x* or *xx*
    FORV(t){
        cin>>a>>b;
        string s=CSA_DP_string(a,b);
        //string s =LCS(a,b,a.length(),b.length(),"");
        if(a==b) cout<<"YES"<<endl<<a<<endl;
        else if((a[0]==b[0]||a.back()==b.back())){
            cout<<"YES\n";
            if(a[0]==b[0]) cout<<a[0]<<"*"<<endl;
            else if(a.back()==b.back())cout<<'*'<<b.back()<<endl;
        }
        else if(s.length()>=2){
            cout<<"YES"<<endl;
            cout<<'*'<<s<<'*'<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}