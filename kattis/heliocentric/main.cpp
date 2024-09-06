// https://open.kattis.com/problems/heliocentric
#include <bits/stdc++.h>

const int EARTH_CYCLE = 365;
const int MARS_CYCLE = 687;

int main()
{
    int e, m;

    int caseCount = 1;

    while ((scanf("%d %d", &e, &m)) == 2)
    {
        int total = 0;

        while (e != 0 || m != 0)
        {
            int diff_e_to_loop = EARTH_CYCLE - e;
            int diff_m_to_loop = MARS_CYCLE - m;

            int diff_days = std::min(diff_e_to_loop, diff_m_to_loop);

            e = (e + diff_days) % EARTH_CYCLE;
            m = (m + diff_days) % MARS_CYCLE;

            total += diff_days;
        }

        std::cout << "Case " << caseCount++ << ": " << total << '\n';
    }
}
