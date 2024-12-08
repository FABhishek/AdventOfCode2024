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
const string mas = "MAS";
const string sam = "SAM";
unordered_map<int,int>mp;
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
 

void diagUpRight(int st_r,int st_c, vector<string>&v, int row, int col) {
	if(st_r < 2 || col - st_c < 3 || (mas[0] != v[st_r][st_c] && sam[0] != v[st_r][st_c])) return; 
	int cnt = 1;
	int i = st_r-1, j = st_c+1;
	int temp_i = 0, temp_j = 0;
	bool fl = false;
	if(sam[0] == v[st_r][st_c]){
		for(i,j; i>=0 && j<col; i--, j++){
			if(sam[cnt] == v[i][j]) {
				if(sam[cnt] == 'A') {mp[i*row+j]--; temp_i = i, temp_j = j;}
				cnt++;
			}
			else break;
		}
 	} else {
 		for(i,j; i>=0 && j<col; i--, j++){
			if(mas[cnt] == v[i][j]) {
				if(mas[cnt] == 'A') {mp[i*row+j]--; temp_i = i, temp_j = j;}
				cnt++;
			}
			else break;
		}
 	}
 	if(cnt == 2) {mp[temp_i*row + temp_j]++;}
}

void diagDownRight(int st_r,int st_c, vector<string>&v, int row, int col){
	if(row - st_r < 2 || col - st_c < 3 || (mas[0] != v[st_r][st_c] && sam[0] != v[st_r][st_c])) return;
	
	int cnt = 1;
	int i = st_r+1, j = st_c+1;
	int temp_i = 0, temp_j = 0;
	if(sam[0] == v[st_r][st_c]){
		for(i,j; i<row && j<col; i++, j++){
			if(sam[cnt] == v[i][j]){
				if(sam[cnt] == 'A') {mp[i*row+j]--; temp_i = i, temp_j = j;}
				cnt++;
			}
			else break;
		}
	}
	else{
		for(i,j; i<row && j<col; i++, j++){
			if(mas[cnt] == v[i][j]){
				if(mas[cnt] == 'A') {mp[i*row+j]--; temp_i = i, temp_j = j;}
				cnt++;
			}
			else break;
		}
	}
	if(cnt == 2) mp[temp_i*row + temp_j]++; 
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

   int a_cntr = 0;
   int ans = 0;
   int row = v.size();
   int col = v[0].size();
      
    rep(i,0,row){
      	rep(j,0,col){
      		if(v[i][j] == 'A'){
      			a_cntr++;
      			mp[i*row+j] = 2;
      		}
      	}
    }

   for(int i = 0;i<row;i++){
   	for(int j = 0; j<col;j++){
   		diagUpRight(i, j, v, row, col);
   		diagDownRight(i, j, v, row, col);
   	}
   }
   
   for(auto i:mp){
   	if(i.second == 0){
   		cnt++;
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
