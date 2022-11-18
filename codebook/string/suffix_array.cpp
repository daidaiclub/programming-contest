const int MXN = 1e6;
// sa[i]: idx of ith rank, rk[i]: rank of idx
// he[i]: sa[i], sa[i - 1] 前he[i]個字元相同
int ct[MXN], he[MXN], rk[MXN];
int sa[MXN], tsa[MXN], tp[MXN][2];
void suffix_array(string ip){ // 0-base
  int len = ip.size();
  int alp = 256;
  MEM(ct, 0);
  for(int i = 0; i < len; i++) ct[ip[i] + 1]++;
  for(int i = 1; i < alp; i++) ct[i] +=ct[i - 1];
  for(int i = 0; i < len; i++) rk[i] = ct[ip[i]];
  for(int i = 1; i < len; i *= 2){
    for(int j = 0; j < len; j++){
      if(j + i >= len) tp[j][1] = 0;
      else tp[j][1] = rk[j + i] + 1;
      tp[j][0] = rk[j];
    }
    memset(ct, 0, sizeof(ct));
    for(int j = 0; j < len; j++) ct[tp[j][1] + 1]++;
    for(int j = 1; j < len+2; j++) ct[j] += ct[j - 1];
    for(int j = 0; j < len; j++) tsa[ct[tp[j][1]]++]=j;
    memset(ct, 0, sizeof(ct));
    for(int j = 0; j < len; j++) ct[tp[j][0] + 1]++;
    for(int j = 1; j < len+1; j++) ct[j] += ct[j - 1];
    for(int j = 0; j < len; j++)
      sa[ct[tp[tsa[j]][0]]++] = tsa[j];
    rk[sa[0]] = 0;
    for(int j = 1; j < len; j++){
      if( tp[sa[j]][0] == tp[sa[j - 1]][0] &&
          tp[sa[j]][1] == tp[sa[j - 1]][1] )
        rk[sa[j]] = rk[sa[j - 1]];
      else
        rk[sa[j]] = j; } }
  for(int i = 0, h = 0; i < len; i++){
    if(rk[i] == 0) h = 0;
    else{
      int j = sa[rk[i] - 1];
      h = max(0, h - 1);
      for(; ip[i + h] == ip[j + h]; h++); }
    he[rk[i]] = h; } }
