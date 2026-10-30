#include <random>
#include <algorithm>
#include <iostream>
#include <chrono>

using namespace std;
typedef pair<int, int> PII;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); //梅森随机数

int a[100];

PII partition(int l, int r, int x) {
    int first = l, last = r, i = l;
    while (i <= last) {
        if (a[i] == x) i++; //相等的时候就 i++，左边界不更新
        else if (a[i] < x) swap(a[first++], a[i++]);    //小于的时候先交换，再更新左边界和 i
        else swap(a[last--], a[i]); //先交换，但是不需要更新 i，因为不确定交换过来的是a[i]与 x 的大小关系，需要再等待一次循环判断
    }
    return {first, last};   //[first, last]的闭区间就是等于 x 的范围
}

void quickSort(int l, int r) {
    if (l >= r) return;

    int x = a[l + rng() % (r - l + 1)]; //  随机划分，期望才能收敛到O(nlogn)
    PII mid = partition(l, r, x); //    荷兰国旗划分问题，三路划分

    quickSort(l, mid.first - 1);
    quickSort(mid.second + 1, r);
}

int rngArray(int n) {
    if (n > 100) return -1;

    for (int i = 0; i < n; i++) a[i] = rng() % 100;
    return 0;
}

void hoare(int l, int r) {
    if (l >= r) return;

    int tag = a[l + r >> 1];
    int i = l - 1, j = r + 1;
    while (i < j) {
        while (a[++i] < tag);
        while (a[--j] > tag);
        if (i < j) swap(a[i], a[j]);
    }

    hoare(l, j);
    hoare(j + 1, r);
}

signed main() {

    rngArray(20);
    for (int i = 0; i < 20; i ++) cout << a[i] << ' ';
    cout << '\n';
    hoare(0, 19);
    for (int i = 0; i < 20; i ++) cout << a[i] << ' ';
    cout << '\n';

}