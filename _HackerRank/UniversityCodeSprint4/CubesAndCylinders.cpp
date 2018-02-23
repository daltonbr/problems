/*
Cubes and Cylinders
https://www.hackerrank.com/contests/university-codesprint-4/challenges/cubes-and-cylinders
*/

#include <cstdio>
#include <vector>
#include <iostream>
#define RadiusToEdgeRatio 0.70710678
using namespace std;

int main()
{
    int n, m; cin >> n >> m;
/*
    s, denoting the edge-lengths of each package type,
    k, denoting the number of copies of each package type,
    r, denoting the radius of the opening of each container, and
    c, denoting the number of packages each container can contain,
*/
    vector<int> s, k, r, c;
    int maxPacks = 0;
    s.reserve(n);
    k.reserve(n);
    r.reserve(m);
    c.reserve(m);

    // inputing vectors
    for (int i = 0; i < n; i++) { cin >> s[i]; }
    for (int i = 0; i < n; i++) { cin >> k[i]; }
    for (int i = 0; i < m; i++) { cin >> r[i]; }
    for (int i = 0; i < m; i++) { cin >> c[i]; }

    // comparing edges
    for (int i = 0; i < n; i++)
    {
        int exactRadiusNeeded = RadiusToEdgeRatio * s[i];
        for (int j = 0; j < m; j++)
        {
            if (r[j] > exactRadiusNeeded)
            {
                // this ith package fits inside this jth cylinder

                // #packages vs cylinder capacity
                int packCopies = k[i];
                int capacity = c[j];

                if (capacity <= packCopies)
                {
                    c[j] -= capacity;
                    maxPacks += capacity;
                    k[i] -= capacity;
                }
                else
                {
                    c[j] -= packCopies;
                    maxPacks += packCopies;
                    k[i] = 0;
                }
            }
        }

    }
    cout << maxPacks;

    return 0;
}
