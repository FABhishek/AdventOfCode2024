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

set<pair<int,int>> vis;

vector<pair<int,int>> directions = {{-1,0},{0,1},{1,0},{0,-1}};


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
 
pair<int,int> findPosOfGuard(vector<string>&v){
	rep(i,0,v.size()){
		rep(j,0,v[i].size())
		   if(v[i][j]!= '#' && v[i][j] != '.')
		   	  return {i,j};
	}
	return {0,0};
}

vector<pair<int,int>> ans;

void dfs(vector<string>&v, int x, int y, int dir)
{
  if(x < 0 || y < 0 || x >= v.size() || y >= v[0].size())
  	 return;

  if(v[x][y] != '#'){
  	if(vis.find({x,y}) != vis.end())
  		ans++;
  	vis.insert({x,y});
  	ans.push_back({x,y});
  	x += directions[dir].first;
  	y += directions[dir].second;
  	dfs(v,x,y,dir);
  }
  else {
  	if(dir == 0) x++;
  	if(dir == 1) y--;
  	if(dir == 2) x--;
  	if(dir == 3) y++;
  	dir += 1;
  	dir %= 4;
  	x += directions[dir].first;
  	y += directions[dir].second;
  	dfs(v,x,y,dir);
  }

}

void solve(){
   string line;
   vector<string>v;
   while(getline(cin,line)){
   	 stringstream ss(line);
   	 v.push_back(line);
   }
   pair<int,int> pos;
   pos = findPosOfGuard(v);
   int x = pos.first, y = pos.second;
    
   dfs(v,x,y,0);
   cout<<vis.size();
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
