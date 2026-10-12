#include <bits/stdc++.h>
using namespace std;

void solve(unordered_map<int,vector<int>>&dp,int&n,int&t,unordered_set<int>vst,int cb,int jmp,int&ans){	
	if(cb==t){ans=min(ans,jmp);return;}
	if(jmp>=n)return;
	if(!vst.insert(cb).second)return;
	for(int b:dp[cb])solve(dp,n,t,vst,b,jmp+1,ans);
	
}

int main(){
	int n,m;cin>>n>>m;
	unordered_map<int,vector<int>>dp;
	for(int i=0;i<m;i++){
		int u,v;cin>>u>>v;
		dp[u].push_back(v);
		dp[v].push_back(u);
	}
	int s,t,ans=INT_MAX;cin>>s>>t;	
	solve(dp,n,t,{},s,0,ans);
	ans=ans==INT_MAX?0:ans;
	cout<<ans<<endl;
	return 0;
}
