#include<bits/stdc++.h>
#include <chrono>
using namespace std;

#ifdef LOCAL // ======== Local ======== g++ -DLOCAL ...
void dbg() { cerr << '\n'; }
template<class T, class ...U> void dbg(T a, U ...b) { 
  cerr << a << ' ', dbg(b...); } 
template<class T> void org(T l, T r) { 
  while (l != r) cerr << *l++ << ' '; cerr << '\n'; } 
#define DEBUG(args...) \
  (dbg("#> (" + string(#args) + ") = (", args, ")"))
#define ORANGE(args...) \
  (cerr << "#> [" + string(#args) + ") = ", org(args))
#else            // ======== OnlineJudge ========
#define DEBUG(...) ((void)0)
#define ORANGE(...) ((void)0)
#endif

#define ll long long
#define ld long double
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define NINF 0xc1c1c1c1
#define NLLINF 0xc1c1c1c1c1c1c1c1
#define X first
#define Y second
#define PB emplace_back
#define pll pair<ll, ll>
#define MEM(a,n) memset(a, n, sizeof(a))
#define io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MXN = + 5;
mt19937 rng(chrono::sQteady_clock::now().time_since_epoch().count());

void sol(){}
int main(){
  io int t=1;
  // cin >> t;
  while(t--){ sol(); } }
