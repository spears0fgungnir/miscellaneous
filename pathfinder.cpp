#include <bits/stdc++.h>
using namespace std;	

void track(vector<int>&L,vector<int>&R,int&n,int&s,int&t,int&mnt,int cs,int cst,int mvs){
	if(mvs==n)return;
	if(cs==t){mnt=min(mnt,cst);return;}
	for(int i=cs+1;i<=n;i++)
		track(L,R,n,s,t,mnt,i,cst+R[cs-1],mvs+1);
	for(int i=1;i<cs;i++)
		track(L,R,n,s,t,mnt,i,cst+L[cs-2],mvs+1);
}

int main(){
	int n,q;cin>>n>>q;vector<int>L,R;
	for(int i=0;i<n-1;i++){int x;cin>>x;L.push_back(x);}
	for(int i=0;i<n-1;i++){int x;cin>>x;R.push_back(x);}
	while(q--){
		int s,t,mnt=INT_MAX;cin>>s>>t;
		track(L,R,n,s,t,mnt,s,0,0);
		cout<<mnt<<endl;
	}
}
