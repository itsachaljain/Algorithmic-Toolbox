#include <bits/stdc++.h>

using namespace std;

vector<int> coins = {1, 3, 4};

int get_change(int m)
{
  vector<int> table(m + 1);

  table[0] = 0;

  for (int i = 1; i <= m; i++)
  {
    table[i] = INT_MAX;
  }

  for (int i = 1; i <= m; i++)
  {
    for (int j = 0; j <= m; j++)
    {
      if (coins[j] <= i)
      {
        int remove = table[i - coins[j]];
        if (remove != INT_MAX && remove + 1 < table[i])
        {
          table[i] = remove + 1;
        }
      }
    }
  }

  return table[m];
}

int main()
{
  int m;
  cin >> m;
  cout << get_change(m) << '\n';
}
