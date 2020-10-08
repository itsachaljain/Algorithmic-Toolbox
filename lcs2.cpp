#include <bits/stdc++.h>

using namespace std;

int lcs2(vector<int> &a, vector<int> &b)
{
  int m = a.size();
  int n = b.size();

  vector<vector<int>> table(m + 1, vector<int>(n + 1, 0));

  for (int i = 0; i <= m; i++)
  {
    for (int j = 0; j <= n; j++)
    {
      if (i == 0 || j == 0)
      {
        table[i][j] = 0;
      }
      else if (a[i - 1] == b[j - 1])
      {
        table[i][j] = table[i - 1][j - 1] + 1;
      }
      else
      {
        table[i][j] = max(table[i - 1][j], table[i][j - 1]);
      }
    }
  }
  return table[m][n];
}

int main()
{
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++)
  {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++)
  {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
