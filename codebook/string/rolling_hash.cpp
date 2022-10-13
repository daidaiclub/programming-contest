struct RollingHash {
  const int p1 = 44129; // 65537, 40961, 90001, 971651
  vector<ll> pre;
  void init(string s) {
    pre.resize(s.size() + 1); pre[0] = 0;
    for (int i = 0; i < (int)s.size(); i++)
      pre[i + 1] = (pre[i] * p1 + s[i]) % MOD;
  }
  ll query(int l, int r) {return (pre[r + 1] - pre[l] * fpow(p1, r - l + 1));}
};