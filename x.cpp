/*
 * https://github.com/ZeyadKhattab/Competitive-Programming/blob/master/Problems/IOI%2017-mountains.cpp
*/
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#include <bits/stdc++.h>
using namespace std;
#define sqr 270
//#define mp make_pair
#define mid (l+r)/2
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define era erase
#define C continue
#define mem(dp,i) memset(dp,i,sizeof(dp))
#define mset multiset
#define all(x) x.begin(), x.end()
#define gc getchar_unlocked
typedef long long ll;
typedef short int si;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
const ll inf=1e18;
const ll mod=1e9+7;
const ld pai=acos(-1);
#include "mountains.h"
pll a [2009] ;
int dp [2009][2009] ;
bool seen ( pll a , pll b , pll c ) {
	return ( ( (b.fi - a.fi) * (c.se - a.se) - (b.se - a.se) * (c.fi - a.fi) ) >= 0 ) ;
}
int maximum_deevs ( vi v ) {
	int n = v.size () ;
	for ( int i = 0 ; i < n ; i ++ ) {
		a[i] .fi = i ;
		a[i] .se = v [i] ; 
	}
	for ( int r = 0 ; r < n ; r ++ ) {
		int sum = 0 , last = r ;
		dp [r][r] = 1 ;
		for ( int l = r - 1 ; l >= 0 ; l -- ) {
			dp [l][r] = dp [l][r-1] ;
			if ( seen ( a [l] , a [last] , a [r] ) ) {
				sum += dp [l+1][last-1] ;
				last = l ;	
			}
			dp [l][r] = max ( dp [l][r] , dp [l][last-1] + sum + 1 ) ;
		}
	}
	return dp [0][n-1] ;
}
