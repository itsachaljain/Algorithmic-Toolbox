#include <bits/stdc++.h>

using namespace std;

int optimal_weight(int W, const vector<int> &w)
{
  vector<vector<int>> data(w.size() + 1, vector<int>(W + 1, 0));

  for (int i = 0; i <= w.size(); i++)
  {
    for (int j = 0; j <= W; j++)
    {
      if (i == 0 || j == 0)
      {
        data.at(i).at(j) = 0;
      }
      else if (w[i - 1] <= j)
      {
        data.at(i).at(j) = max(data.at(i - 1).at(j), w[i - 1] + data.at(i - 1).at(j - w[i - 1]));
      }
      else
      {
        data.at(i).at(j) = data.at(i - 1).at(j);
      }
    }
  }
  return data.at(w.size()).at(W);
}

int main()
{
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++)
  {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
