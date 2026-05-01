#include <stdio.h>

int main(){
    float num1, num2;
    char op;
    printf("Insert first number: ");
    scanf("%f", &num1);
    getchar();
    printf("\n");
    printf("Insert second number: ");
    scanf("%f", &num2);
    printf("\n");
    getchar();
    printf("Choose operation(\"+\", \"-\", \"*\", \"/\"): ");
    scanf("%c", &op);
    printf("\n");

    switch (op)
    {
    case '+':
        printf("Result: %.2f + %.2f = %.2f\n", num1, num2, num1+num2);
        break;
    case '-':
        printf("Result: %.2f - %.2f = %.2f\n", num1, num2, num1-num2);
        break;
    case '*':
        printf("Result: %.2f * %.2f = %.2f\n", num1, num2, num1*num2);
        break;
    case '/':
        if(num2 == 0){
            printf("Cannot divide by 0");
            break;
        }
        printf("Result: %.2f / %.2f = %.2f\n", num1, num2, num1/num2);
        break;
    
    default:
        printf("Invalid operation\n");
        break;
    }
    
    return 0;
}
