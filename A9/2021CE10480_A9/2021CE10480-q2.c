#include <stdio.h> // mandatory include

float time_angle(int XX, int YY){   // function you have to implement
    float result;                   // sample variable - you can change this according to your need
    if(XX>=12){
        XX = (XX - 12);
    }

    float hrsAngle = (XX * 30) + (((float)YY / 60) * 30);
    float minAngle = ((float)YY / 60) * 360;

    if(hrsAngle>minAngle){
        result = hrsAngle - minAngle;
    }else{
        result = minAngle - hrsAngle;
    }

    if(result>180){
        result = 360 - result;
    }

    return result;                 // return statment
}

int main()                       // mandatory main function
{
    int XX, YY;                 // variable denoting hours and minutes
    scanf("%d", &XX);           // hour input
    scanf("%d", &YY);           // minute input
    // printf("%d:%d",XX,YY);
    int result = time_angle(XX, YY);  // calling function
    printf("%d",result);               // printing result
    return 0;                   // return statment
}
