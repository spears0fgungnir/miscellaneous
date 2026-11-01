#include <bits/stdc++.h>
using namespace std;
// 3n + 1 Problem

int main(void){
	int i,j,mxc=0;cin>>i>>j;
	for(int n=i;n<=j;n++){
		int c=0,tn=n;
		while(tn!=1){
			tn=tn%2==0?tn/2:3*tn+1;
			c++;
		}
		mxc=max(mxc,c+1);
	}
	cout<<i<<" "<<j<<" "<<mxc<<'\n';
	return 0;
}
