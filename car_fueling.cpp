#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::max;
using std::vector;

int compute_min_refills(int dist, int tank, vector<int> &stops)
{
    int base = 0, currpos = 0, i = 0, refi = -1;
    stops.push_back(dist);

    while (true)
    {
        if (dist <= currpos + tank)
        {
            return base;
        }
        if (tank < stops[i] - currpos)
        {
            refi = i - 1;
            if (currpos == stops[refi])
            {
                return -1;
            }
            base++;
            currpos = stops[i - 1];
            i--;
            continue;
        }
        i++;
    }

    return -1;
}

int main()
{
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
