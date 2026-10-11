#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void sub(int* nums,int* slid,int* sums,int ns,int ss,int k,int m){
	if(ss==m){
		int sn=0,sm=0;
		for(int i=0;i<ss;i++){
			sm+=(i+1)*(*(slid+i)-sn);
			sn=*(slid+i);
		}
		*sums=*sums>sm?*sums:sm;return;
	}
	if(ss+ns-k<m)return;
	if(k==ns)return;
	*(slid+ss)=*(nums+k);
	sub(nums,slid,sums,ns,ss+1,k+1,m);
	sub(nums,slid,sums,ns,ss,k+1,m);
}

int main(){
	int t;scanf("%d",&t);	
	while(t--){
		int n,m,sums=INT_MIN;scanf("%d %d",&n,&m);
		int nums[n],slid[m];
		for(int i=0;i<n;i++){int x;scanf("%d",&x);nums[i]=x;}
		sub(nums,slid,&sums,n,0,0,m);
		printf("%d\n",sums);
	}
}
