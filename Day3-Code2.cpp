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

 
void solve(){
    string input;
    string s;
    bool will_do = true;
    const string pat = "mul(";
    const int m = pat.size();

    const string find_do = "do()";
    const int sz_do = find_do.size();
    const string find_dont = "don't()";
    const int sz_dont = find_dont.size();

    while (getline(cin, input)) {
        s += input; 
    }

    int res = 0;
    int i = 0;
    while(i<s.size()-7){
    	if(s[i] == 'd') {
    		if(s.substr(i, sz_do) == find_do) { will_do = true; i+=sz_do; }
    		else if(s.substr(i, sz_dont) == find_dont) { will_do = false; i+= sz_dont; }
    	}
    	if(will_do){
    	if(i+3 < s.size() && s[i] == 'm' && s.substr(i,m) == pat){
    		i+=4;
    		int digCntr = 0;
    		int dig1 = 0;
    		int dig2 = 0;
    		bool fl = true;
    		while(isdigit(s[i])){
    			digCntr++;
    			dig1 = dig1*10 + (s[i]-'0');
    			i++;
    		}
    		fl = (digCntr <= 3) ? true : false;
    		if(s[i] == ',' && dig1 != 0 && digCntr <= 3){
    			i++;
    			digCntr = 0;
    			while(isdigit(s[i])){
	    			digCntr++;
	    			dig2 = dig2*10 + (s[i]-'0');
	    			i++;
    			}
    			fl = (digCntr <= 3) ? true : false;
    		}
    		if(s[i] == ')' && dig1 != 0 && dig2 != 0 && fl){
    			res += dig1*dig2;
    		}
    	}
       }
    	i++;
    }
    cout<<res;
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
