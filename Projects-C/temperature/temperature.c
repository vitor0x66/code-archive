#include <stdio.h>

float CtoK(float t);
float CtoF(float t);
float FtoK(float t);
float FtoC(float t);
float KtoF(float t);
float KtoC(float t);

int main(){
    float t;
    int opt;
    printf("Type temperature to convert: ");
    scanf("%f", &t);
    printf("\n");
    printf("1) Celsius to Kelvin\n");
    printf("2) Celsius to Fahrenheit \n");
    printf("3) Fahrenheit to Kelvin\n");
    printf("4) Fahrenheit to Celsius\n");
    printf("5) Kelvin to Fahrenheit \n");
    printf("6) Kelvin to Celsius\n");
    printf("Option: ");
    scanf("%d", &opt);
    printf("\n");

    float (*functions[])(float) = {CtoK, CtoF, FtoK, FtoC, KtoF, KtoC};
    
    if(opt > 6 || opt < 1){
        printf("Invalid choice\n");
        return 1;
    }
    printf("Result: %.2f\n", functions[opt - 1](t));
    
    return 0;
}

float CtoK(float t){
    return t + 273.15f;
}
float CtoF(float t){
    return (t * (9.0f / 5.0f)) + 32.0f;
}
float FtoK(float t){
    return (t - 32.0f) * (5.0f / 9.0f) + 273.15f;
}
float FtoC(float t){
    return (t - 32.0f) * (5.0f / 9.0f);
}
float KtoF(float t){
    return (t - 273.15f) * (9.0f / 5.0f) + 32.0f;
}
float KtoC(float t){
    return t - 273.15f;
}
