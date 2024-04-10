#include <stdio.h>
#include <math.h>
void sapxep(double a[], int n){
    for(int i = 0; i < n - 1; i++){
        int minpos = i;
        for(int j = i + 1; j < n; j++){
            if( a[minpos] < a[j]){
                minpos = j;
            }
        }
        double tmp = a[i];
        a[i] = a[minpos];
        a[minpos] = tmp;
    }
}
int chieudaituma(double a){
    return log(1/a) / log(2);
}
void tuma(double num, int l) {
    int count = 0;
    double fracPart = num - (int)num;
    while (fracPart > 0) {
        if (fracPart * 2 >= 1) {
            count++;
            printf("1");
            fracPart = fracPart * 2 - 1;
        } else {
            count++;
            printf("0");
            fracPart *= 2;
        }
    }
    int cnt = 0;
    for(int i = 1; i <= l - count; i++){
        cnt++;
        printf("0");
    }
    for(int i = 0; i < 11 - count - cnt; i++){
        printf(" ");
    }
}
void nhiphan(double num) {
    printf("0.");
    int count = 0;
    double fracPart = num - (int)num;
    while (fracPart > 0) {
        if (fracPart * 2 >= 1) {
            count++;
            printf("1");
            fracPart = fracPart * 2 - 1;
        } else {
            count++;
            printf("0");
            fracPart *= 2;
        }
    }
    for(int i = 0; i < 10 - count; i++){
        printf(" ");
    }
}
int main(void) {
    int n;
    printf("Nhap so luong xac suat: ");
    scanf("%d", &n);
    double xacsuatbandau[n];
    for(int i = 0; i < n; i++){
        scanf("%lf", &xacsuatbandau[i]);
    }
    sapxep(xacsuatbandau, n);
    double xacsuatgop[n];
    for(int i = 0; i < n; i++){
        xacsuatgop[i] = 0;
    }
    for(int i = 1 ; i < n; i++){
        for(int j = 0; j <= i - 1; j++){
            xacsuatgop[i] += xacsuatbandau[j];
        }
    }
    printf("\nBang tinh toan bang ma Shannon\n\n");
    printf("_____________________________________________________________\n");
    printf("| xi |   p(xi)   |   Gop   |   Binary   |   l   |   Tu ma   |\n");
    printf("-------------------------------------------------------------\n");
    double H = 0;
    double ltb = 0;
    for(int i = 0; i < n; i++){
        printf("| x%d |", i);
        printf("%lf   |", xacsuatbandau[i]);
        printf("%lf |", xacsuatgop[i]);
        nhiphan(xacsuatgop[i]); printf("|");
        printf("%d",chieudaituma(xacsuatbandau[i])); printf("      |");
        tuma(xacsuatgop[i], chieudaituma(xacsuatbandau[i])); printf("|");
        printf("\n");
    }
    printf("-------------------------------------------------------------\n");
    for(int i = 0; i < n; i++){
        ltb += (xacsuatbandau[i] * chieudaituma(xacsuatbandau[i]));
        H += xacsuatbandau[i] * (log(1/xacsuatbandau[i]) / log(2));
    }
    printf("\n\nEntropy trung binh la: %.2lf\n", H);
    printf("\nChieu dai tu ma trung binh la: %.2lf\n", ltb);
    double kt = H / ltb;
    if(kt <= 1){
        printf("\nHe so nen: K(t) = %.2lf\n\n", kt);
    }
    else if( kt > 1 ){
        printf("\nFailed\n");
    }
    return 0;
}
