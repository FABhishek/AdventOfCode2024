#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp> 
using namespace std;
using namespace __gnu_pbds;
// Policy based data structure 
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 
#define ll long long int
#define pii pair<ll,ll>
#define rep(i,st,en) for(ll i=st;i<en;i++)
#define vi vector<ll>
#define vii vector<pii>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define eb emplace_back
#define yes cout<<"YES"<<endl; return;
#define no cout<<"NO"<<endl; return;
#define flus fflush(stdout);
#define gin(x) cerr<<#x<<" : "<<x<<" ";
#define fin cerr<<endl;
#define F first
#define S second
#define np next_permutation
#define pb push_back
#define inf 1e18
#define mod 1000000007
#define N 200009
#define PI 3.14159265358979323846
#define minpq priority_queue <ll, vector<ll>, greater<ll>>
#define maxpq priority_queue<ll> 
const string xmas = "XMAS";
void sout(){
	cout<<endl;
}
template <typename T,typename... Types>
void sout(T var1,Types... var2){
	cout<<var1<<" ";
	sout(var2...);
}
 
bool sortBySec(const pair<int,int> &a, const pair<int,int> &b)
 {
   return (a.second<b.second);
 }
 

bool right(int st_r,int st_c, vector<string>&v, int row, int col){
	if(col - st_c <  4 || xmas[0] != v[st_r][st_c]) return false; 
	int cnt = 1;
	for(int j = st_c+1; j<col;j++){
		if(xmas[cnt] == v[st_r][j])
			cnt++;
		else break;
	}
	if(cnt == 4) return true;
	else return false;
}


bool left(int st_r,int st_c, vector<string>&v, int row, int col){
	if(st_c < 3 || xmas[0] != v[st_r][st_c]) return false; 
	int cnt = 1;
	for(int j = st_c-1; j>=0;j--){
		if(xmas[cnt] == v[st_r][j])
			cnt++;
		else break;
	}
	if(cnt == 4) return true;
	else return false;
}

bool down(int st_r,int st_c, vector<string>&v, int row, int col){
	if(row - st_r < 4 || xmas[0] != v[st_r][st_c]) return false; 
	int cnt = 1;
	for(int j = st_r+1; j<row;j++){
		if(xmas[cnt] == v[j][st_c])
			cnt++;
		else break;
	}
	if(cnt == 4) return true;
	else return false;
}

bool up(int st_r,int st_c, vector<string>&v, int row, int col){
	if(st_r < 3 || xmas[0] != v[st_r][st_c]) return false; 
	int cnt = 1;
	for(int j = st_r-1; j>=0;j--){
		if(xmas[cnt] == v[j][st_c])
			cnt++;
		else break;
	}
	if(cnt == 4) return true;
	else return false;
}

bool diagUpLeft(int st_r,int st_c, vector<string>&v, int row, int col){
	if(st_r < 3 || st_c < 3 || xmas[0] != v[st_r][st_c]) return false; 
	int cnt = 1;
	int i = st_r-1, j = st_c-1;
	for(i,j; i >= 0 && j >= 0; i--, j--){
		if(xmas[cnt] == v[i][j])
			cnt++;
		else break;
	}
	if(cnt == 4) return true;
	else return false;
}

bool diagUpRight(int st_r,int st_c, vector<string>&v, int row, int col){
	if(st_r < 3 || col - st_c < 4 || xmas[0] != v[st_r][st_c]) return false; 
	int cnt = 1;
	int i = st_r-1, j = st_c+1;
	for(i,j; i>=0 && j<col; i--, j++){
		if(xmas[cnt] == v[i][j])
			cnt++;
		else break;
	}
	if(cnt == 4) return true;
	else return false;
}

bool diagDownRight(int st_r,int st_c, vector<string>&v, int row, int col){
	if(row - st_r < 4 || col - st_c < 4 || xmas[0] != v[st_r][st_c]) return false; 
	int cnt = 1;
	int i = st_r+1, j = st_c+1;
	for(i,j; i<row && j<col; i++, j++){
		if(xmas[cnt] == v[i][j])
			cnt++;
		else break;
	}
	if(cnt == 4) return true;
	else return false;
}

bool diagDownLeft(int st_r,int st_c, vector<string>&v, int row, int col){
	if(row - st_r < 4 || st_c < 3 || xmas[0] != v[st_r][st_c]) return false; 
	int cnt = 1;
	int i = st_r+1, j = st_c-1;
	for(i,j; i<row && j>=0; i++, j--){
		if(xmas[cnt] == v[i][j])
			cnt++;
		else break;
	}
	if(cnt == 4) return true;
	else return false;
}



void solve(){
   string line;
   vector<string>v;
   int i = 0;
   int cnt = 0;
   while(getline(cin, line)){
   	stringstream ss(line);
 	v.push_back(line);
   	i++;
   }

   int ans = 0;
   int row = v.size();
   int col = v[0].size();
   for(int i = 0;i<row;i++){
   	for(int j = 0; j<col;j++){
   		//will brute force in every direction;
   		//vertical and horizontal
   		cnt += right(i,j,v,row,col);
   		cnt += left(i,j,v,row,col);
   		cnt += down(i,j,v,row,col);
   		cnt += up(i,j,v,row,col);
   		//diagonals
   		cnt += diagUpLeft(i, j, v, row, col);
   		cnt += diagUpRight(i, j, v, row, col);
   		cnt += diagDownLeft(i, j, v, row, col);
   		cnt += diagDownRight(i, j, v, row, col);
   	}
   }
   cout<<cnt;
   return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	clock_t t1=clock();
	int t;
	// cin>>t;
	t=1;
	while(t--){
		solve();
	}
	cerr<<"Time elapsed: "<<(double)(clock()-t1)/1000<<" s"<<endl;
}
