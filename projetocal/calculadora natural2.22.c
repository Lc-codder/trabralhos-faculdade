#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

#define titulo "BEM VINDO A CALCULADORA NATURAL!"
#define fim "OBRIGADO. ESPERO TER AJUDADO!"
#define MAX_USERS 10

struct User {
    char nome[50];
    float peso, altura, resultado, IMC, cintura, pescoco, quadril, pg;
    int idade, objetivo;
    char sexo;
};

int main() {
    setlocale(LC_ALL, "Portuguese");
    struct User users[MAX_USERS];
    int num_users = 0;
    int continuar = 1;

    do {
        printf("%s\n\n", titulo);

        printf("Vamos calcular sua taxa metab�lica basal.\n ");
        printf("Informe o seu peso:\n");
        scanf("%f", &users[num_users].peso);
        printf("Informe sua altura em cent�metros:\n");
        scanf("%f", &users[num_users].altura);
        printf("Informe sua idade:\n");
        scanf("%d", &users[num_users].idade);
        
        int sexo_valido = 0;
        do {
            printf("Informe o seu sexo (M/F): ");
            scanf(" %c", &users[num_users].sexo);

            if (users[num_users].sexo == 'M' || users[num_users].sexo == 'm') {
                users[num_users].resultado = 88.362 + (13.397 * users[num_users].peso) + (4.799 * users[num_users].altura) - (5.677 * users[num_users].idade);
                printf("Sua taxa metab�lica basal �: %.2f\n\n", users[num_users].resultado);

                printf("Perfeito! Vamos calcular seu percentual de gordura.\n\n");
                printf("Informe o valor da circunfer�ncia da cintura em cm: ");
                scanf("%f", &users[num_users].cintura);
                printf("Informe o valor da circunfer�ncia do pesco�o em cm: ");
                scanf("%f", &users[num_users].pescoco);

                users[num_users].pg = 495.0 / (1.0324 - 0.19077 * log10(users[num_users].cintura - users[num_users].pescoco) + 0.15456 * log10(users[num_users].altura)) - 450.0;
                printf("Seu BF �: %.2f%%\n", users[num_users].pg);
                printf("Para calcular o seu BF, utilizamos uma t�cnica norte-americana que utiliza suas medidas para aproximar o valor real.\n");
                
                users[num_users].IMC = users[num_users].peso / ((users[num_users].altura / 100) * (users[num_users].altura / 100));
                
                printf("Baseado nos dados que j� foram informados, seu IMC �: ");
                if (users[num_users].IMC <= 18.5) {
                    printf("%.2f: baixo peso.\n", users[num_users].IMC);
                } else if (users[num_users].IMC > 18.5 && users[num_users].IMC <= 24.9) {
                    printf("%.2f: peso adequado.\n", users[num_users].IMC);
                } else if (users[num_users].IMC > 25 && users[num_users].IMC <= 29.9) {
                    printf("%.2f: Sobrepeso.\n", users[num_users].IMC);
                } else if (users[num_users].IMC > 30 && users[num_users].IMC <= 34.9) {
                    printf("%.2f: Obesidade grau I.\n", users[num_users].IMC);
                } else if (users[num_users].IMC > 35 && users[num_users].IMC <= 39.9) {
                    printf("%.2f: Obesidade grau II.\n", users[num_users].IMC);
                } else {
                    printf("%.2f: Obesidade grau III.\n", users[num_users].IMC);
                }

                printf("Agora vamos estipular as calorias da sua dieta.\n");
                printf("Voc� deseja secar ou ganhar massa? Digite '1' para secar e '2' para ganhar massa:\n");
                scanf("%d", &users[num_users].objetivo);

                if (users[num_users].objetivo == 1) {
                    printf("Perfeito! Tudo que precisamos � garantir que seu gasto cal�rico seja maior do que o que voc� est� ingerindo, obviamente \nvamos dar prioridades a prote�na e deixar os carbos e gorduras de lado!\n\n");
                    printf("Podemos ver que sua taxa basal � de %.2f, portanto, juntando com dois cardios por dia, poderemos aumentar em at� 600\n calorias no total!\n", users[num_users].resultado);
                    
                    if (users[num_users].resultado >= 2000 && users[num_users].resultado <= 3000 && users[num_users].objetivo == 1) {
                        printf("Perfeito! Iremos manter uma m�dia de 2500 � 2700. A recomenda��o � de uma dieta com 1375kcal de carboidratos, 875kcal de prote�na e 375kcal de gordura.\n");
                        printf("Para o c�lculo da dieta, � poss�vel utilizar o 'myfitnesspal' que possui uma variedade sobre valores nutricionais dos alimentos.\n");
                        printf("Lembre-se de realizar o cardio e o treino! Caso contr�rio, o peso pode voltar a aumentar.\n");
                    } else if (users[num_users].resultado > 3000 && users[num_users].resultado <= 4500 && users[num_users].objetivo == 1) {
                        printf("Perfeito! Iremos manter uma m�dia de 3500 � 3700. A recomenda��o � de uma dieta com 1925kcal de carboidratos, 1225kcal de prote�na e 500kcal de gordura.\n");
                        printf("Para o c�lculo da dieta, � poss�vel utilizar o 'myfitnesspal' que possui uma variedade sobre valores nutricionais dos alimentos.\n");
                        printf("Lembre-se de realizar o cardio e o treino! Caso contr�rio, o peso pode voltar a aumentar.\n");
                    } else if (users[num_users].resultado > 1000 && users[num_users].resultado <= 2000 && users[num_users].objetivo == 1) {
                        printf("Perfeito! Iremos manter uma m�dia de 1600 � 1900. A recomenda��o � de uma dieta com 965kcal de carboidratos, 600kcal de prote�na e 185kcal de gordura.\n");
                        printf("Para o c�lculo da dieta, � poss�vel utilizar o 'myfitnesspal' que possui uma variedade sobre valores nutricionais dos alimentos.\n");
                        printf("Lembre-se de realizar o cardio e o treino! Caso contr�rio, o peso pode voltar a aumentar.\n");
                    } else if (users[num_users].resultado > 1000 && users[num_users].objetivo == 2) {
                        printf("Bom! Para isso, manteremos uma dieta de 2000 calorias a mais que a sua taxa basal, tendo em vista que a quantidade de prote�na ser� de 35%% da sua dieta, o carboidrato 55%% e o resto de gordura.\n");
                        printf("Lembre-se de realizar o cardio com modera��o e elevar as cargas nos treinos, caso contr�rio o peso pode aumentar de forma ruim ou estagnar.\n\n");
                    } else {
                        printf("Objetivo n�o reconhecido.\n");
                        continue;
                    }

                    sexo_valido = 1;
                } else {
                    printf("Perfeito! Por�m, daremos prioridade � massa eficaz, ganhar massa n�o significa comer tudo que tem pela frente!\n");
                    printf("Podemos ver que sua taxa basal � de %.2f, portanto, juntando com dois cardios por dia, iremos reduzir a chance de seu BF aumentar em grande quantidade durante o bulking!\n", users[num_users].resultado);
                }

                sexo_valido = 1;
            } else if (users[num_users].sexo == 'F' || users[num_users].sexo == 'f') {
                users[num_users].resultado = 447.593 + (9.247 * users[num_users].peso) + (3.098 * users[num_users].altura) - (4.330 * users[num_users].idade);
                printf("Sua taxa metab�lica basal �: %.2f\n \n", users[num_users].resultado);

                printf("Perfeito! Vamos calcular seu percentual de gordura.\n\n");
                printf("Informe o valor da circunfer�ncia da cintura em cm: ");
                scanf("%f", &users[num_users].cintura);
                printf("Informe o valor da circunfer�ncia do pesco�o em cm: ");
                scanf("%f", &users[num_users].pescoco);
                printf("Informe o valor da circunfer�ncia do quadril em cm: ");
                scanf("%f", &users[num_users].quadril);

                users[num_users].pg = 495.0 / (1.29579 - 0.35004 * log10(users[num_users].cintura + users[num_users].quadril - users[num_users].pescoco) + 0.22100 * log10(users[num_users].altura)) - 450.0;
                printf("Seu BF �: %.2f%%\n", users[num_users].pg);
                printf("Para calcular o seu BF, utilizamos uma t�cnica norte-americana que utiliza suas medidas para aproximar o valor real.\n");
                
                users[num_users].IMC = users[num_users].peso / ((users[num_users].altura / 100) * (users[num_users].altura / 100));
                
                printf("Baseado nos dados que j� foram informados, seu IMC �: ");
                if (users[num_users].IMC <= 18.5) {
                    printf("%.2f: baixo peso.\n", users[num_users].IMC);
                } else if (users[num_users].IMC > 18.5 && users[num_users].IMC <= 24.9) {
                    printf("%.2f: peso adequado.\n", users[num_users].IMC);
                } else if (users[num_users].IMC > 25 && users[num_users].IMC <= 29.9) {
                    printf("%.2f: Sobrepeso.\n", users[num_users].IMC);
                } else if (users[num_users].IMC > 30 && users[num_users].IMC <= 34.9) {
                    printf("%.2f: Obesidade grau I.\n", users[num_users].IMC);
                } else if (users[num_users].IMC > 35 && users[num_users].IMC <= 39.9) {
                    printf("%.2f: Obesidade grau II.\n", users[num_users].IMC);
                } else {
                    printf("%.2f: Obesidade grau III.\n", users[num_users].IMC);
                }

                printf("Agora vamos estipular as calorias da sua dieta.\n");
                system("pause");
                printf("Voc� deseja secar ou ganhar massa? Digite '1' para secar e '2' para ganhar massa:\n");
                scanf("%d", &users[num_users].objetivo);

                if (users[num_users].objetivo == 1) {
                    printf("Perfeito! Tudo que precisamos � garantir que seu gasto cal�rico seja maior do que o que voc� est� ingerindo, obviamente \nvamos dar prioridades a prote�na e deixar os carbos e gorduras de lado!\n\n");
                    printf("Podemos ver que sua taxa basal � de %.2f, portanto, juntando com dois cardios por dia, poderemos aumentar em at� 600\n calorias no total!\n", users[num_users].resultado);
                    if (users[num_users].resultado >= 2000 && users[num_users].resultado <= 3000 && users[num_users].objetivo == 1) {
                        printf("Perfeito! Iremos manter uma m�dia de 2500 � 2700. A recomenda��o � de uma dieta com 1375kcal de carboidratos, 875kcal de prote�na e 375kcal de gordura.\n");
                        printf("Para o c�lculo da dieta, � poss�vel utilizar o 'myfitnesspal' que possui uma variedade sobre valores nutricionais dos alimentos.\n");
                        printf("Lembre-se de realizar o cardio e o treino! Caso contr�rio, o peso pode voltar a aumentar.\n");
                    } else if (users[num_users].resultado > 3000 && users[num_users].resultado <= 4500 && users[num_users].objetivo == 1) {
                        printf("Perfeito! Iremos manter uma m�dia de 3500 � 3700. A recomenda��o � de uma dieta com 1925kcal de carboidratos, 1225kcal de prote�na e 500kcal de gordura.\n");
                        printf("Para o c�lculo da dieta, � poss�vel utilizar o 'myfitnesspal' que possui uma variedade sobre valores nutricionais dos alimentos.\n");
                        printf("Lembre-se de realizar o cardio e o treino! Caso contr�rio, o peso pode voltar a aumentar.\n");
                    } else if (users[num_users].resultado > 1000 && users[num_users].resultado <= 2000 && users[num_users].objetivo == 1) {
                        printf("Perfeito! Iremos manter uma m�dia de 1600 � 1900. A recomenda��o � de uma dieta com 965kcal de carboidratos, 600kcal de prote�na e 185kcal de gordura.\n");
                        printf("Para o c�lculo da dieta, � poss�vel utilizar o 'myfitnesspal' que possui uma variedade sobre valores nutricionais dos alimentos.\n");
                        printf("Lembre-se de realizar o cardio e o treino! Caso contr�rio, o peso pode voltar a aumentar.\n");
                    } else if (users[num_users].resultado > 1000 && users[num_users].objetivo == 2) {
                        printf("Bom! Para isso, manteremos uma dieta de 2000 calorias a mais que a sua taxa basal, tendo em vista que a quantidade de prote�na ser� de 35%% da sua dieta, o carboidrato 55%% e o resto de gordura.\n");
                        printf("Lembre-se de realizar o cardio com modera��o e elevar as cargas nos treinos, caso contr�rio o peso pode aumentar de forma ruim ou estagnar.\n\n");
                    } else {
                        printf("Objetivo n�o reconhecido.\n");
                        continue;
                    }

                    sexo_valido = 1;
                } else {
                    printf("Perfeito! Por�m, daremos prioridade � massa eficaz, ganhar massa n�o significa comer tudo que tem pela frente!\n");
                    printf("Podemos ver que sua taxa basal � de %.2f, portanto, juntando com dois cardios por dia, iremos reduzir a chance de seuBF aumentar em grande quantidade durante o bulking!\n", users[num_users].resultado);
                }

                sexo_valido = 1;
            } else {
                printf("Sexo inv�lido!\n");
                sexo_valido = 0;
            }
        } while (!sexo_valido);

        num_users++;

       if (num_users >= 1) {
            printf("Deseja calcular para outro usu�rio? Digite 1 para continuar ou outro valor para sair:\n");
            scanf("%d", &continuar);
        } else {
            printf("� necess�rio pelo menos um usu�rio completo para continuar.\n");
            continuar = 1; 
        }

    } while (continuar == 1 && num_users < MAX_USERS);

    printf("%s\n", fim);
    printf("           .-==+*#%@%=.\n");
    printf("         .=#@%**+=--:+@*\n");
    printf("       :*@%+::::::::::=@*.\n");
    printf("     :*@#-:::=::*+:+*-:#@.\n");
    printf("   -@#--+-:=@*:*%%==%*:+@-\n");
    printf("  .=@=::#@-:@#:+@+-%#-*@=+#=\n");
    printf(" .+%=::-%%%@@%@@@%@@@@#--*@+\n");
    printf(" .+%=::::---===-===-=+*%%@%:\n");
    printf(" .+%=::::::------+%@%#=-::\n");
    printf(".+@=::::--*%%%%@@+.\n");
    printf(":%%:::::--*@*::.\n");
    printf("=@+:::::---@#\n");
    printf(".#%-::::::--%@.\n");
    printf(":@*:::::::--#@-         =@@@@@@@@@@@@@=\n ");
    printf(":@*:::::::--#@-         =@@@@@@@@@@@@@=\n ");
    printf("+@=:::::::--+@=     .#@@#.:::::::::---#@@%: \n");
    printf("#%::::::::--=@*   :%@*::::::::::::::-----*@@= \n");
    printf("@#::::::::---@# .*@*:::::::::::::::::------+%@- \n ");
    printf(":@*::::::::----::#%=::::::::::::::::::--------*@*.\n");
    printf("=@+:::::::::---=%%-:::::::::::::::::::---------+@+\n");
    printf("*@=:::::::::---#%=::::::::::::::::::::----------@@\n");
    printf("#@-:::::::::--*@+::::::::::::::::::-+@@=--------@%\n");
    printf("%@::::::::::--##:::::::::::::::-=*@@%=---------*@=\n");
    printf("%@::::::::::-:::::::*@@@@@@@@@%%#+:::--------=%@= \n");
    printf("@@.::::::::::::::::::::::::::::::::::------+%@*.\n ");
    printf("@%:::::::::::::::::::::::::::::::::::--=+%@#=.\n ");
    printf("@%:::::::::::::::::::::::::::::::::-=#@@#=.\n ");
    printf("@@:::::::::::::::::::::::::::-==*%@%#+: \n ");
    printf("+@+:::::::::::-----==++*##%@@%#+=: \n ");
    printf("=%@@@@@@@@@@%%%%###**+=--:.\n");
    system("pause");
}

