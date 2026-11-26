    #include <iostream>
    #include <algorithm>
    #define int long long
    #define endl '\n'

    using namespace std;

    const int N = 1.1e7 + 10;

    char ss[N << 1];
    int p[N << 1];
    int n;
    string s;

    // 初试化回文串
    void init() {
        n = s.size() * 2 + 1;
        for (int i = 0, j = 0; i < n; i++) {
            ss[i] = ((i & 1) == 0) ? '#' : s[j++]; //偶数位置放'#'奇数位置填充原字符，填充到 n 为止。
        }
    }

    // manacher 0base 注意是 0 base
    int manacher() {
        
        int ans = 0;

        for (int i = 0, c = 0, r = 0, len; i < n; i++) {
            /*
            i 在大回文中的时候有三种情况，即对称点的回文在大回文内，边界，外
            前两种都可以直接取对称点的半径，第三种应是点到大回文边界的距离。所以取一个 min 即可
            虽然我们区分了，第二种和第三种实际上都不需要继续判断了，已经确定了，否则大回文不止到 r。
            但是为了代码的统一性，我们进行一次试判也无妨，反正都会失败也不会进循环。
            而对于不在大回文内的 i 回文半径就是 1 也就是他本身的字符长度。后续在 while 中扩展即可
            需要注意，这里的 r 不仅仅是指回文半径，同时也是大回文的右边界的下一个位置，这就是0base 的好处
            同理 i + len 也是指向的边界的下一个位置。这就是0base 的巧妙之处，0base 不含本位的 kmp 也是这个写法
            */
            len = i < r ? min(p[2 * c - i], r - i) : 1;

            while (i - len >= 0 && i + len < n && ss[i - len] == ss[i + len]) len++;

            if (i + len > r) {  //如果新的回文扩展到了 r 以外的地方，那么就更新回文半径与回文中心，我们只记录第一次使他更新的点
                c = i;
                r = i + len;
            }

            ans = max(ans, len);
            p[i] = len; //记得要设置当前 i 的回文半径
        }

        return ans - 1;
    }

    signed main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        cin >> s;
        init();
        cout << manacher() << endl;
    }