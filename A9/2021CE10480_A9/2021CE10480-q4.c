#include <stdio.h> // mandatory include

int incrmntday(int day, int n){
    if(n==2){
        if(day ==7){
            day = 2;
        }else if(day == 6){
            day = 1;
        }else{
            day = day+2;
        }
    }else{
        if(day == 7){
            day = 1;
        }else{
            day = day + 1;
        }
    }
    return day;
}

int cntlast(int XX, int YY, int ZZZZ, int AA, int BB, int CCCC){
    int cnt;
    if(XX == 29 && YY == 2){
        if(CCCC%4 == 0){
                    
        }else{
            XX = 01;
            YY = 03;
        }
    }   
    if(BB>YY){
        cnt = 1;
        return cnt;
    }else if(BB == YY){
        if(XX < AA){
            cnt = 1;
            return cnt;
        }else{
            cnt = 0;
            return cnt;
        }
    }else{
        cnt = 0;
        return cnt;
    }

}

int birt(int XX, int YY, int ZZZZ, int AA, int BB, int CCCC){   // function you have to implement
    int counter = 0;          // sample variable - you can change this according to your need
    //printf("%d-%d-%d and %d-%d-%d \n",XX, YY, ZZZZ, AA, BB, CCCC);
    int day = 6;
    int end;
        if (cntlast(XX, YY, ZZZZ, AA, BB, CCCC) == 1){
            end = CCCC;
        }else{
            end = CCCC - 1;
        }
    if(YY<=2 && XX!=29){
        for(int i = ZZZZ+1; i<=end; i++){
            if(i%4 == 1){
                day = incrmntday(day, 2);
            }else{
                day = incrmntday(day,1);
            }
            if(day == 1){
                counter++;
            }
        }
    }
    if(YY>2){
        for(int i = ZZZZ+1; i<=end; i++){
            if(i%4 == 0){
                day = incrmntday(day, 2);
            }else{
                day = incrmntday(day,1);
            }
            if(day == 1){
                counter++;
            }
        }
    }
    if(YY == 2 && XX == 29){
        for(int i = ZZZZ+1; i<=end; i++){
            if(i%4 == 1){
                day = incrmntday(day, 2);
            }else{
                day = incrmntday(day,1);
            }
            if(day == 1){
                counter++;
            }
        }
    }
    return counter;                 // return statment
}

int main()                       // mandatory main function
{
    int XX, YY, ZZZZ, AA, BB, CCCC;             // variable 
    scanf("%d", &XX);           // input of Date of birth
    scanf("%d", &YY);            // input of Month of birth
    scanf("%d", &ZZZZ);           // input of Year of birth
    scanf("%d", &AA);           // input of Date of death
    scanf("%d", &BB);            // input of Month of death
    scanf("%d", &CCCC);            // input of Year of death
    //printf("%d-%d-%d and %d-%d-%d \n",XX, YY, ZZZZ, AA, BB, CCCC);
    int result = birt(XX, YY, ZZZZ, AA, BB, CCCC);  // calling function
    printf("%d",result);               // printing result
    return 0;                   // return statment
}
