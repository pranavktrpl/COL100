#include <stdio.h> // mandatory include

int Divfactorial(int a, int b){
    long long int fact = 1;
    for(int i = b+1; i<=a; i++){
        fact = fact * i;
    }
    return fact;
}

int factorial(int a){
    long long int fact = 1;
    for(int i=1;i<=a;i++){
        fact = i * fact;
    }
    return fact;
}

int food(int x, int y, int m, int n){   // function you have to implement
    long long int result;          // sample variable - you can change this according to your need
    //printf("(%d,%d) and (%d,%d) \n",x,y,m,n);
    if(x<y){
        int c = x;
        x = y;
        y = c;
    }
    long long int Steps_xy = (Divfactorial(x + y, x)) / factorial(y);
    long long int Steps_mn_xy = (Divfactorial(m + n - x - y, m - x)) / factorial(n - y);

    result = Steps_xy * Steps_mn_xy;

    return result;                 // return statment
}

int main()                       // mandatory main function
{
    int x, y, m, n;             // variable denoting coordinate of restaurant and delivery location
    scanf("%d", &x);           // x coordinate of restaurant
    scanf("%d", &y);            // y coordinate of restaurant
    scanf("%d", &m);           // x coordinate of delivery location
    scanf("%d", &n);            // y coordinate of delivery location
    //printf("(%d,%d) and (%d,%d) \n",x,y,m,n);
    int result = food(x, y, m, n);  // calling function
    printf("%d",result);               // printing result
    return 0;                   // return statment
}
