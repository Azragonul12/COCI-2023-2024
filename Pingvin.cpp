#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<map>
#include<string>
#include<queue>
#include<stack>
#include<numeric>
#include<utility>
#include<set>
#include<bitset>
using namespace std;
const int nMax = 105;
long long arr[nMax][nMax][nMax];
long long bfs[nMax][nMax][nMax];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n,fx,fy,fz,lx,ly,lz;
	memset(bfs,-1,sizeof(bfs));
	memset(arr,-1,sizeof(arr));
	string str;
	cin>>n;
	cin>>fx>>fy>>fz;
	cin>>lx>>ly>>lz;
	for(long long i=1; n>= i ;i++){
		for(long long j=1; n>= j;j++){
			cin>>str;
			for(long long k=1; n>=k ;k++){
				if(str[k-1] == '1')
				arr[j][k][i] = 1;
				if(str[k-1] == '0')
				arr[j][k][i] = 0;
			}
		}
	}
	bfs[fx][fy][fz] = 0;
	queue < array <long long , 3> > que;
	array <long long , 3> pushie;
	pushie[0] = fx;
	pushie[1] = fy;
	pushie[2] = fz;
	que.push(pushie);
	while(que.size()){
		long long pivx,pivy,pivz;
		pivx = que.front()[0];
		pivy = que.front()[1];
		pivz = que.front()[2];
		que.pop();
	//	cout<<pivx<<" "<<pivy<<" "<<pivz<<"\n";
		if(pivx > 0 && arr[pivx-1][pivy][pivz] == 0){
			if(bfs[pivx-1][pivy][pivz] == -1){
				bfs[pivx-1][pivy][pivz] = bfs[pivx][pivy][pivz] + 1;
				pushie[0] = pivx-1;
				pushie[1] = pivy;
				pushie[2] = pivz;
				que.push(pushie);
			}
		}
		if(pivx < n && arr[pivx+1][pivy][pivz] == 0){
			if(bfs[pivx+1][pivy][pivz] == -1){
				bfs[pivx+1][pivy][pivz] = bfs[pivx][pivy][pivz] + 1;
				pushie[0] = pivx+1;
				pushie[1] = pivy;
				pushie[2] = pivz;
				que.push(pushie);
			}
			
		}
		if(pivy > 0 && arr[pivx][pivy-1][pivz] == 0){
			if(bfs[pivx][pivy-1][pivz] == -1){
				bfs[pivx][pivy-1][pivz] = bfs[pivx][pivy][pivz] + 1;
				pushie[0] = pivx;
				pushie[1] = pivy-1;
				pushie[2] = pivz;
				que.push(pushie);
			}
			
		}
		if(pivy < n && arr[pivx][pivy+1][pivz] == 0){
			if(bfs[pivx][pivy+1][pivz] == -1){
				bfs[pivx][pivy+1][pivz] = bfs[pivx][pivy][pivz] + 1;
				pushie[0] = pivx;
				pushie[1] = pivy+1;
				pushie[2] = pivz;
				que.push(pushie);
			}
			
		}
		if(pivz > 0 && arr[pivx][pivy][pivz-1] == 0){
			if(bfs[pivx][pivy][pivz-1] == -1){
				bfs[pivx][pivy][pivz-1] = bfs[pivx][pivy][pivz] + 1;
				pushie[0] = pivx;
				pushie[1] = pivy;
				pushie[2] = pivz-1;
				que.push(pushie);
			}
			
		}
		if(pivz < n && arr[pivx][pivy][pivz+1] == 0){
			if(bfs[pivx][pivy][pivz+1] == -1){
				bfs[pivx][pivy][pivz+1] = bfs[pivx][pivy][pivz] + 1;
				pushie[0] = pivx;
				pushie[1] = pivy;
				pushie[2] = pivz+1;
				que.push(pushie);
			}
			
		}
	}
	cout<<bfs[lx][ly][lz];
	
}

