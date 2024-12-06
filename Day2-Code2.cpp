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
   string line;
   int cnt = 0;
   while(getline(cin, line))
   {
   	 stringstream ss(line);
   	 vector<int> row;
   	 int num;
   	 while(ss >> num){
   	 	row.push_back(num);
   	 }

   	 //logic
   	 bool fl = true;
   	 int num1 = row[0];
   	 int num2 = row[1];
   	 int num3 = row[row.size()-2];
   	 int num4 = row[row.size()-1];
   	 int damp = 0;
   	 if(num1>num2 && num3>num4)
   	 {
	   	for(int i=1;i<row.size()-1;i++) {
	   	 	num1 = row[i];
	   	 	num2 = row[i+1];
	   	 	int diff = abs(num1-num2);
	   	 	
	   	 	if(diff > 3 || diff == 0 || num1<num2 && abs(row[i-1]-num2) <= 3){
	   	 		if(abs(row[i-1]-num2) <= 3 && abs(row[i-1]-num2) >0)
	   	 		  damp++;
	   	 		else {fl = false; break;}
	   	 	}
	  	}
	  }
	  else if(fl && num1<num2 && num3<num4){
	  	// cout<<'s';
	  	for(int i=1;i<row.size()-1;i++) {
	   	 	num1 = row[i];
	   	 	num2 = row[i+1];
	   	 	int diff = abs(num1-num2);

	   	 	if(diff>3 || diff == 0 || num1>num2)
	   	 		if(abs(row[i-1]-num2) <= 3 && abs(row[i-1]-num2) > 0)
	   	 		  damp++;
	   	 		else {fl = false; break;}
	    }
   	  }

   	  else{
   	  	vector<int>rowreverse(row);
   	  	if(!is_sorted(row.begin()+1, row.end()) && !is_sorted(row.begin(), row.end()-1) && 
   	  		!is_sorted(rowreverse.begin()+1, rowreverse.end()) && !is_sorted(rowreverse.begin()+1, rowreverse.end()-1))
   	  	{
   	  		fl = false;
   	  	}
   	  	if(fl){
	   	  	for(int i=1;i<row.size()-1;i++){
	   	  		if(abs(row[i]-row[i+1]) == 0 || abs(row[i]-row[i+1]) > 3){
	   	  			fl = false; break;
	   	  		}
	   	  	}
   	    }
   	  }

   	  if(damp>=2) {fl = false;}

   	 if(fl) {cnt++;}
   }

   cout<<cnt;
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
