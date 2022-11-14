ll bell[MXN][MXN];

void bellf(int n) {
  bell[1][1] = 1;
  for(int i = 2; i <= n; ++i) {
    bell[i][1] = bell[i - 1][i - 1];
    for(int j = 2; j <= i; ++j) {
      bell[i][j] = bell[i - 1][j - 1] + bell[i][j - 1];
    }
  }
}