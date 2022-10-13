struct Manacher {
  char str[MXN]; int p[MXN], len = 0;
  void init(string s) {
    MEM(p, 0);
    str[len++] = '$', str[len++] = '#';
    int sz = s.size();
    for(int i = 0; i < sz; ++i)
      str[len++] = s[i], str[len++] = '#';
    str[len] = '*';
    int mx = 0, id = 0;
    for(int i = 1; i < len; ++i) {
      p[i] = mx > i ? min(p[(id << 1) - i], mx - i) : 1;
      while(str[i + p[i]] == str[i - p[i]]) p[i]++;
      if(i + p[i] > mx) {
        mx = i + p[i];
        id = i;}}}
  int query(int l, int r) {
    int ans = 0;
    l = 2 * l + 2, r = 2 * r + 2;
    for(int i = l; i < r; i++)
      ans = max(ans, p[i]);
    return ans - 1;}};