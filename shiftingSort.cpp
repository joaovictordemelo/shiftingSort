#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
typedef std::vector<int> vi;
typedef std::vector<char> vc;
typedef std::vector<long long> vl;
#define f first 
#define s second

//based on Colin
//commented by Mello



using namespace std;


void test(){

	int n;
	cin >> n;
	int a[n];
	for(ll i = 0; i < n; i++) cin >> a[i]; //we read the array a
	//below we have a pair of pairs, the pair<ll, ll> is left and right indices
	vector<pair<pair<ll, ll>, ll>> ops; //the second element ll is d, number of ops


	for(ll i = 0; i < n; i++){ //we will find minimum in a[0...n-1] then a
		ll mv = 1e12, mi = -1; //mi is an index while mv is an element both for min
		for(ll j = i; j < n; j++){

			if(a[j] < mv){     //ex.: a[0] < 1e12 yes, then mv = a[0], mi = 0 
				mv = a[j];     //doing this mv next time will be a[1] if smaller
				mi = j;		   //so we are really picking the smallest

			}
		}
		if(mi != i){
			ops.push_back({make_pair(i,mi), mi-i}); //mi - i is the number of operations
			//to go back from the extreme right position to the extreme left

			for(ll j = mi - 1; j >= i; j--){ //we move the element to the left

				swap(a[j], a[j + 1]);       //swapping each time with near element

			}
		}


	}
	cout << ops.size() << '\n'; //number of operations
	for(pair<pair<ll, ll>, ll> x: ops){
		//below we have the x.f.f representing the "left" element of pair<ll, ll> + 1
		//because indices start with 0, the same occurs with x.f.s
		cout << x.f.f + 1 << " " << x.f.s + 1 << " " << x.s << '\n';
		//here we print the left and right part indexes and the number of operations

	}

}

int main(){

  int t;
    cin >> t;
    while(t--){
        
        test();
    }
    

}