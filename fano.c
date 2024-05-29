#include <stdio.h>
#include <math.h>
void sort(double a[], int n){
    for(int i = 0; i < n - 1; i++){
        int maxpos = i;
        for(int j = i + 1; j < n; j++){
            if(a[maxpos] < a[j]){
                maxpos = j;
            }
        }
        double tmp = a[i];
        a[i] = a[maxpos];
        a[maxpos] = tmp;
    }
}
/*5
 0.3 0.125 0.125 0.25 0.2*/
/*8
 0.0625 0.125 0.0625 0.125 0.25 0.0625 0.0625 0.25*/
/*6
 0.3 0.3 0.125 0.0625 0.0625 0.1 0.05*/
/*10
 0.125 0.125 0.125 0.0625 0.0625 0.0625 0.0625 0.125 0.125 0.125*/
void find(double a[], int n, int part){
    int var = 0; //Bien luu vi tri ranh gioi giua 0 và 1
    double check = (double)1/(part*2);
    for(int i = 0; i < n; i++){
        int moc = i;
        double find = 0; //Tong xac suat can chia doi
    for(int j = 0; j <= i; j++){
        find += a[j];
        }
        double tmp = find + a[i];
        if(find <= check && tmp >= check){
            var = moc + 1;
            break;
        }
    }
    int in = var / 2; // Bien luu vi tri dien "0"
    printf("|");
    for(int i = 0; i < 2*(in+1); i++){
        printf("    ");
    }
    for(int i = 0; i < 2*in + 1; i++){
        printf(" ");
    }
    printf("0");
    for(int i = 0; i < 2*(in+1); i++){
        printf("    ");
    }
    for(int i = 0; i < 2*in + 1; i++){
        printf(" ");
    }
    printf("|");
    for(int i = 0; i < (n - in - 2); i++){
        printf("    ");
    }
    for(int i = 0; i < (n - in - 3); i++){
        printf(" ");
    }
    printf("1");
    for(int i = 0; i < (n - in - 2); i++){
        printf("    ");
    }
    for(int i = 0; i < (n - in - 3) ; i++){
        printf(" ");
    }
    printf("|");
}
double Ixi(double x){
    return log(1/x)/log(2);
}
int main(void) {
    int n;
    printf("Nhap so luong xac suat: ");
    scanf("%d", &n);
    double fano[n];
    for(int i = 0; i < n; i++){
        scanf("%lf", &fano[i]);
    }
    sort(fano, n);
    printf("           ");
    for(int i = 0 ; i < n ; i++){
        printf("_________ ");
    }
    printf("\n");
    printf("Ki hieu   ");
    for(int i = 0; i < n; i++){
        printf("|   x.%d   ", i);
    }
    printf("|\n");
    printf("Xac suat  ");
    for(int i = 0; i < n; i++){
        printf("| %.5lf ", fano[i]);
    }
    printf("|\n");
    
    
    
    printf("Lan1(i=1):");
    find(fano, n, 1);
    
    
    printf("\n");
    printf("ni        ");
    printf("|");
    for(int i = 0; i < n; i++){
        printf("    %.0lf    |", ceil(Ixi(fano[i])));
    }
    printf("\n");
    printf("I(xi)     ");
    printf("|");
    for(int i = 0; i < n; i++){
        printf("  %.3lf  |", Ixi(fano[i]));
    }
    printf("\n");
    printf("          ");
    for(int i = 0 ; i < n ; i++){
        printf("|_________");
    }
    printf("|\n\n");
    printf("p(xi)I(xi)|");
    for(int i = 0; i < n; i++){
        printf("  %.3lf  |", fano[i]*Ixi(fano[i]));
    }
    printf("\n");
    printf("           ");
    for(int i = 0 ; i < n ; i++){
        printf("--------- ");
    }
    printf("\n");
    printf("p(xi)ni   |");
    for(int i = 0; i < n; i++){
        printf("  %.3lf  |", fano[i]*ceil(Ixi(fano[i])));
    }
    printf("\n\n");
    printf("H(X) = p(x0) + p(x1) + ... + p(x%d)\n", n - 1);
    printf("     = ");
    double sum = 0;
    for(int i = 0; i < n - 1; i++){
        sum += fano[i]*Ixi(fano[i]);
        printf("%.3lf +", fano[i]*Ixi(fano[i]));
    }
    sum += fano[n - 1]*Ixi(fano[n - 1]);
    printf(" %.3lf\n     = %.3lf\n\n", fano[n - 1]*Ixi(fano[n - 1]), sum);
    printf("n tb = ");
    double sum2 = 0;
    printf("n1 + n2 + ... + n%d\n     = ", n-1);
    for(int i = 0; i < n - 1; i++){
        sum2 += fano[i]*ceil(Ixi(fano[i]));
        printf("%.3lf +", fano[i]*ceil(Ixi(fano[i])));
    }
    sum2 += fano[n - 1]*ceil(Ixi(fano[n - 1]));
    printf(" %.3lf\n     =", fano[n - 1]*ceil(Ixi(fano[n - 1])));
    printf("%.3lf\n", sum2);
    printf("He so toi uu K(t) = H(X)/ntb = %.3lf\n", sum/sum2);
    return 0;
}
