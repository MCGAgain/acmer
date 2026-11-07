#include <stdio.h>
#include <math.h>

int main() {
    float p = 0.0f, r = 0.0f;
    float s_sum = 0.0f, s_fu = 0.0f;
    int n = 0;

    printf("输入本金，利率，存款期限：");
    
    scanf("%f,%f,%d", &p, &r, &n);

    s_sum = p * (1 + r * n);
    s_fu = p * pow(1 + r, n);

    printf("单利为%.2f，复利为%.2f\n", s_sum, s_fu);

    return 0;
}
