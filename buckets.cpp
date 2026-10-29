#include <bits/stdc++.h>
using namespace std;

int offs[] = {0,1,0,-1,1,0,-1,0};

int bfs(char(&m)[100],deque<uint32_t>&q){
	size_t mn=0;int vs[100]={0};
	vs[(q[0]>>16)*10+(q[0]&0xFFFF)]=1;
	while(true){
		size_t vi=q.size();
		while(vi--){
			uint32_t v=q.front();q.pop_front();
			int ni=v>>16,nj=v&0xFFFF;
			if(m[ni*10+nj]=='B')return mn-1;
			for(int o=0;o<7;o+=2){
				int nio=ni+offs[o],njo=nj+offs[o+1];int chk=nio*10+njo;
				if(nio<0||nio>9||njo<0||njo>9)continue;
				if(m[chk]=='R')continue;
				uint32_t cel=(uint32_t)(nio<<16)|(njo&0xFFFF);
				if(!vs[chk]){q.push_back(cel);vs[chk]=1;}
			}
		}
		mn++;
	}
}

int main(void){
	freopen("buckets.in", "r", stdin);
	freopen("buckets.out", "w", stdout);
	string ln;char m[100];int i=0,si,sj;
	while(getline(cin,ln)){
		for(int j=0;j<10;j++){
			if(ln[j]=='L'){si=i;sj=j;}
			m[i*10+j]=ln[j];
		}
		i++;
	}
	deque<uint32_t>q;q.push_back((uint32_t)(si<<16)|(sj&0xFFFF));
	cout<<bfs(m,q)<<'\n';
	return 0;
}
