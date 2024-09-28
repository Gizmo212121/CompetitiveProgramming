# std::setprecision(x)

You can set the precision of decimals when printing by sending std::setprecision(x) to standard output:

```cpp
#include <bits/stdc++.h>

int main()
{
    long long input;
    std::cin >> input;

    std::cout << std::setprecision(10) << 4 * sqrt(input) << '\n';
}
```
