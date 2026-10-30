#include <iostream>
signed main() { int n; std::cin >> n; std::cout << (1 << (31 - __builtin_clz(n))) << '\n'; }