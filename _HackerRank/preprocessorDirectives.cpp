/*
Preprocessor Directives
https://www.hackerrank.com/challenges/preprocessor-solution/problem
*/

#define FUNCTION(unused1, unused2)
#define minimum(a, b) a=(a<b?a:b)
#define maximum(a, b) a=(a>b?a:b)
#define INF 2147483647 // The value of this constant is 2,147,483,647; that is, hexadecimal 0x7FFFFFFF.
#define io(v) cin >> v
#define toStr(s) "Result ="
#define foreach(v, i) for(int i=0;i<v.size();i++)

#include <iostream>
#include <vector>
using namespace std;

#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
#error Missing preprocessor definitions
#endif 

FUNCTION(minimum, <)
FUNCTION(maximum, >)

int main(){    
	int n; cin >> n;
	vector<int> v(n);
	foreach(v, i) {
		io(v)[i];
	}

	int mn = INF;
	int mx = -INF;
	foreach(v, i) {
		minimum(mn, v[i]);
		maximum(mx, v[i]);
	}    
	int ans = mx - mn;
	cout << toStr(Result =) <<' '<< ans;
	return 0;

}