// 多人背包
for(int i = 1; i <= n; ++i) {
  for(int j = V; j >= v[i]; --j) {
    int c1 = 1, c2 = 2;
    for(int k = 1; k <= K; ++k) {
      if(dp[j][c1] > dp[j - v[i]][c2] + w[i])
        now[k] = f[j][c1], c1++;
      else
        now[k] = f[j - v[i]][c2] + w[i], c2++;
    }
    for(int k = 1; k <= K; ++k) f[j][k] = now[k];
  }
}

// 多重背包
for(int k = 0; k <= K; ++k) {
  while(!dq.empty() && 
    dq.front().first <= dp[d + k * w] - v * k) dq.pop_back();
  dq.push_back({dp[d + k * w] - v * k, k});
  while(!dq.empty() && dq.back().second > s) dq.pop_front();
  dp[d + k * w] = dq.front().first + v * k;
}