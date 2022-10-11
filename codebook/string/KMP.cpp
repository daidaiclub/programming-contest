const int MXN = 2e7 + 5;
int fail[MXN]; vector<int> mi;
void kmp(string &t, string &p){ // O(n), 0-base
  // pattern match in target, idx store in mi
  if (p.size() > t.size()) return;
  for (int i = 1, j = fail[0] = -1; i < p.size(); ++i){
    while (j >= 0 && p[j + 1] != p[i]) j = fail[j];
    if (p[j + 1] == p[i]) j++;
    fail[i] = j; }
  for (int i = 0, j = -1; i < t.size(); ++i){
    while (j >= 0 && p[j + 1] != t[i]) j = fail[j];
    if (p[j + 1] == t[i]) j++;
    if (j == p.size() - 1)
      j = fail[j], mi.PB(i - p.size() + 1) } }
