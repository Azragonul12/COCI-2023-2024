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
const int nMax = 55;
char arr[nMax][nMax];
long long find(long long x, long long y){
	long long count = 0;
	long long minCount = 1e9 + 5;
	long long pivx , pivy;
	pivx = x-1;
	pivy = y;
	while(x >= 0 && arr[pivx][pivy] == '|'){
		pivx--;
		count++;
	}
	minCount = min(minCount, count);
	count = 0;
	pivx = x+1;
	pivy = y;
	while(arr[pivx][pivy] == '|'){
		pivx++;
		count++;
	}
	minCount = min(minCount, count);
	count = 0;
	pivx = x;
	pivy = y-1;
	while(y >= 0 && arr[pivx][pivy] == '-'){
		pivy--;
		count++;
	}
	minCount = min(minCount, count);
	count = 0;
	pivx = x;
	pivy = y+1;
	while(arr[pivx][pivy] == '-'){
		pivy++;
		count++;
	}
	minCount = min(minCount, count);
	count = 0;
	pivx = x-1;
	pivy = y-1;
	while(y >= 0 && x >= 0 && (int)arr[pivx][pivy] == 92){
		pivy--;
		pivx--;
		count++;
	}
	minCount = min(minCount, count);
	count = 0;
	pivx = x+1;
	pivy = y+1;
	while((int)arr[pivx][pivy] == 92){
		pivy++;
		pivx++;
		count++;
	}
	minCount = min(minCount, count);
	count = 0;
	pivx = x+1;
	pivy = y-1;
	while(y >= 0 && arr[pivx][pivy] == '/'){
		pivy--;
		pivx++;
		count++;
	}
	minCount = min(minCount, count);
	count = 0;
	pivx = x-1;
	pivy = y+1;
	while(x >= 0 && arr[pivx][pivy] == '/'){
		pivy++;
		pivx--;
		count++;
	}

	minCount = min(minCount, count);
	return minCount;

}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n,m,topCount, count;
	string str;
	count = 0;
	topCount = -1;
	cin>>n>>m;
	for(long long i=0;n>i;i++){
		cin>>str;
		for(long long j=0; m>j;j++){
			arr[i][j] = str[j];
		}
	}
	for(long long i=0;n>i;i++){
		for(long long j=0; m>j;j++){
			if(arr[i][j] == '+'){
				topCount = max(find(i,j) , topCount);
			}
		}
	}
	cout<<topCount;


}
/*
5 6
\.\|/.
---+--
/./|\.
./.|.\
/..|.. */



/*
7 7
\.|./..
.\|/...
--+--..
./|\...
/.|.\|/
....-+-
..../|\
*/
