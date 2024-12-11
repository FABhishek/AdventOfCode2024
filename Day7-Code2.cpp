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

ll concat(ll num1, ll num2) {
	 return stoll(to_string(num1) + to_string(num2));
}

bool dfs(ll x, vector<ll>v, int ind, ll curr){
	if(curr>x) return false;
	if(ind == v.size()){
		if(curr == x){
			return true;
		}
		return false;
	}
	if(ind == 0) {
		 return dfs(x, v, ind+1, v[ind]);
	}
	else{
		 
		 return 
		 dfs(x,v,ind+1,curr+v[ind]*1ll) || dfs(x,v,ind+1, curr*v[ind]*1ll) || dfs(x,v,ind+1, concat(curr, v[ind])*1ll);
	}

}
 
void solve(){
   string line;
   int mx = 0;
   ll ans = 0;
   while(getline(cin, line)){

	    ll x = 0;
	    int i = 0;
	  	ll y;
	   	for(i=0;i<line.length();i++)
	   	{
	   		if(line[i] != ':')
	   		  x = x*10 + (line[i] - '0');
	   		else break;
	   	}
	   	// cout<<x<<' ';
	   	mx = max(mx,i);
	   	vector<ll> values;
	   	stringstream ss(line.substr(i+1,line.length()));
	   	while(ss >> y){
	   			values.push_back(y);
	   	}

	   if(dfs(x, values, 0, 0)){
   	 	 ans += x;
   	 }
   }

   cout<<ans;

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
