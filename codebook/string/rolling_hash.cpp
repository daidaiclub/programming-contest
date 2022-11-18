struct RollingHash { // 0-base, need MOD
  const int p1 = 44129; // 65537, 40961, 90001, 971651
  int n; vector<ll> pre, ppow;
  void init(string s) { // O(n)
    n = s.size();
    pre.resize(n + 1); ppow.resize(n + 1);
    pre[0] = 0, ppow[0] = 1;
    for (int i = 0; i < n; i++)
      pre[i + 1] = (pre[i] * p1 + s[i]) % MOD,
      ppow[i + 1] = ppow[i] * p1 % MOD;
  }
  ll query(int l, int r) { // [l, r], O(1)
    ll ret = pre[r + 1] - pre[l] * ppow[r - l + 1];
    return (ret % MOD + MOD) % MOD; } };
