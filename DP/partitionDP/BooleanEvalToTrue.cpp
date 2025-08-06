#include<bits/stdc++.h>
#define ll long long
const int mod=1e9+7;

int f(int i,int j,int isTrue,string& exp,vector<vector<vector<ll>>>& dp){
    if(i>j) return 0;
    if(i==j){
        if(isTrue){
            return exp[i]=='T';
        }
        else{
            return exp[i]=='F';
        }
    }

    if(dp[i][j][isTrue]!=-1) return dp[i][j][isTrue];
    
    ll ans=0;
    for(int k=i+1;k<j;k+=2){
        ll lt=f(i,k-1,1,exp,dp);
        ll lf=f(i,k-1,0,exp,dp);
        ll rt=f(k+1,j,1,exp,dp);
        ll rf=f(k+1,j,0,exp,dp);

        if(exp[k]=='&'){
            if(isTrue){
                ans=(ans+(lt*rt)%mod)%mod;
            }
            else{
                ans=(ans+(lt*rf)%mod+(rt*lf)%mod+(lf*rf)%mod)%mod;
            }
        }
        else if(exp[k]=='|'){
            if(isTrue){
                ans=(ans+(lt*rt)%mod+(lt*rf)%mod+(lf*rt)%mod)%mod;
            }
            else{
                ans=(ans+(rf*lf)%mod)%mod;
            }
        }
        else if(exp[k]=='^'){
            if(isTrue){
                ans=(ans+(lt*rf)%mod+(lf*rt)%mod)%mod;
            }
            else{
                ans=(ans+(lt*rt)%mod+(lf*rf)%mod)%mod;
            }
        }
    }
    return dp[i][j][isTrue]=ans;
}
int evaluateExp(string & exp) {
    // Write your code here.
    int n=exp.size();
    vector<vector<vector<ll>>> dp(n,vector<vector<ll>>(n,vector<ll>(2,-1)));
    return f(0,n-1,1,exp,dp);
}
