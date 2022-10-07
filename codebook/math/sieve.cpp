const int MXN = 2e9 + 5; // 2^27 約0.7s, 2^30 約6~7s
bool np[MXN]; // np[i] = 1 -> i is'n a prime
vector<int> plist; // prime list
void sieveBuild(int n){
  MEM(np, 0);
  for(int i = 2, sq = sqrt(n); i <= sq; ++i)
    if(!np[i])
      for(int j = i * i; j <= n; j += i) np[j] = 1;
  for(int i = 2; i <= n; ++i) if(!np[i]) plist.PB(i); }
