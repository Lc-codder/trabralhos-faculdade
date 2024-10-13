#include <stdio.h>
#include <math.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "potuguese");
    double num1, num2;
    
    printf("Digite um número para calcular a raiz quadrada: ");
    scanf("%lf", &num1);
    printf("A raiz quadrada de %.2f é %.2f\n", num1, sqrt(num1));
    
    printf("Digite dois números para calclar a potência: ");
    scanf("%lf $lf", &num1, &num2);
    printf("%.2f elevado a %.2f é igual a %.2f\n", num1, num2, pow(num1,num2));
    
    printf("Digite um ângulo em graus para calcular o seno: ");
    scanf("%lf", &num1);
    printf("o seno de %.2f graus é %.2f\n", num1, sin(num1 * M_PI / 180.0));
    
    printf("Digite um ângulo em graus para calcular o cosseno: ");
    scanf("%f", &num1);
    printf("o cosseno de %.2f graus é %.2f\n", num1, cos(num1 * M_PI / 180.0));
    
    printf("Digite um ângulo em graus para calcular a tangente: ");
    scanf("%lf", &num1);
    printf("A tangente de %.2f graus é %.2f\n", num1, tan(num1 * M_PI / 180.0));
}