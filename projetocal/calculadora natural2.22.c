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

        printf("Vamos calcular sua taxa metabólica basal.\n ");
        printf("Informe o seu peso:\n");
        scanf("%f", &users[num_users].peso);
        printf("Informe sua altura em centímetros:\n");
        scanf("%f", &users[num_users].altura);
        printf("Informe sua idade:\n");
        scanf("%d", &users[num_users].idade);
        
        int sexo_valido = 0;
        do {
            printf("Informe o seu sexo (M/F): ");
            scanf(" %c", &users[num_users].sexo);

            if (users[num_users].sexo == 'M' || users[num_users].sexo == 'm') {
                users[num_users].resultado = 88.362 + (13.397 * users[num_users].peso) + (4.799 * users[num_users].altura) - (5.677 * users[num_users].idade);
                printf("Sua taxa metabólica basal é: %.2f\n\n", users[num_users].resultado);

                printf("Perfeito! Vamos calcular seu percentual de gordura.\n\n");
                printf("Informe o valor da circunferência da cintura em cm: ");
                scanf("%f", &users[num_users].cintura);
                printf("Informe o valor da circunferência do pescoço em cm: ");
                scanf("%f", &users[num_users].pescoco);

                users[num_users].pg = 495.0 / (1.0324 - 0.19077 * log10(users[num_users].cintura - users[num_users].pescoco) + 0.15456 * log10(users[num_users].altura)) - 450.0;
                printf("Seu BF é: %.2f%%\n", users[num_users].pg);
                printf("Para calcular o seu BF, utilizamos uma técnica norte-americana que utiliza suas medidas para aproximar o valor real.\n");
                
                users[num_users].IMC = users[num_users].peso / ((users[num_users].altura / 100) * (users[num_users].altura / 100));
                
                printf("Baseado nos dados que já foram informados, seu IMC é: ");
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
                printf("Você deseja secar ou ganhar massa? Digite '1' para secar e '2' para ganhar massa:\n");
                scanf("%d", &users[num_users].objetivo);

                if (users[num_users].objetivo == 1) {
                    printf("Perfeito! Tudo que precisamos é garantir que seu gasto calórico seja maior do que o que você está ingerindo, obviamente \nvamos dar prioridades a proteína e deixar os carbos e gorduras de lado!\n\n");
                    printf("Podemos ver que sua taxa basal é de %.2f, portanto, juntando com dois cardios por dia, poderemos aumentar em até 600\n calorias no total!\n", users[num_users].resultado);
                    
                    if (users[num_users].resultado >= 2000 && users[num_users].resultado <= 3000 && users[num_users].objetivo == 1) {
                        printf("Perfeito! Iremos manter uma média de 2500 à 2700. A recomendação é de uma dieta com 1375kcal de carboidratos, 875kcal de proteína e 375kcal de gordura.\n");
                        printf("Para o cálculo da dieta, é possível utilizar o 'myfitnesspal' que possui uma variedade sobre valores nutricionais dos alimentos.\n");
                        printf("Lembre-se de realizar o cardio e o treino! Caso contrário, o peso pode voltar a aumentar.\n");
                    } else if (users[num_users].resultado > 3000 && users[num_users].resultado <= 4500 && users[num_users].objetivo == 1) {
                        printf("Perfeito! Iremos manter uma média de 3500 à 3700. A recomendação é de uma dieta com 1925kcal de carboidratos, 1225kcal de proteína e 500kcal de gordura.\n");
                        printf("Para o cálculo da dieta, é possível utilizar o 'myfitnesspal' que possui uma variedade sobre valores nutricionais dos alimentos.\n");
                        printf("Lembre-se de realizar o cardio e o treino! Caso contrário, o peso pode voltar a aumentar.\n");
                    } else if (users[num_users].resultado > 1000 && users[num_users].resultado <= 2000 && users[num_users].objetivo == 1) {
                        printf("Perfeito! Iremos manter uma média de 1600 à 1900. A recomendação é de uma dieta com 965kcal de carboidratos, 600kcal de proteína e 185kcal de gordura.\n");
                        printf("Para o cálculo da dieta, é possível utilizar o 'myfitnesspal' que possui uma variedade sobre valores nutricionais dos alimentos.\n");
                        printf("Lembre-se de realizar o cardio e o treino! Caso contrário, o peso pode voltar a aumentar.\n");
                    } else if (users[num_users].resultado > 1000 && users[num_users].objetivo == 2) {
                        printf("Bom! Para isso, manteremos uma dieta de 2000 calorias a mais que a sua taxa basal, tendo em vista que a quantidade de proteína será de 35%% da sua dieta, o carboidrato 55%% e o resto de gordura.\n");
                        printf("Lembre-se de realizar o cardio com moderação e elevar as cargas nos treinos, caso contrário o peso pode aumentar de forma ruim ou estagnar.\n\n");
                    } else {
                        printf("Objetivo não reconhecido.\n");
                        continue;
                    }

                    sexo_valido = 1;
                } else {
                    printf("Perfeito! Porém, daremos prioridade à massa eficaz, ganhar massa não significa comer tudo que tem pela frente!\n");
                    printf("Podemos ver que sua taxa basal é de %.2f, portanto, juntando com dois cardios por dia, iremos reduzir a chance de seu BF aumentar em grande quantidade durante o bulking!\n", users[num_users].resultado);
                }

                sexo_valido = 1;
            } else if (users[num_users].sexo == 'F' || users[num_users].sexo == 'f') {
                users[num_users].resultado = 447.593 + (9.247 * users[num_users].peso) + (3.098 * users[num_users].altura) - (4.330 * users[num_users].idade);
                printf("Sua taxa metabólica basal é: %.2f\n \n", users[num_users].resultado);

                printf("Perfeito! Vamos calcular seu percentual de gordura.\n\n");
                printf("Informe o valor da circunferência da cintura em cm: ");
                scanf("%f", &users[num_users].cintura);
                printf("Informe o valor da circunferência do pescoço em cm: ");
                scanf("%f", &users[num_users].pescoco);
                printf("Informe o valor da circunferência do quadril em cm: ");
                scanf("%f", &users[num_users].quadril);

                users[num_users].pg = 495.0 / (1.29579 - 0.35004 * log10(users[num_users].cintura + users[num_users].quadril - users[num_users].pescoco) + 0.22100 * log10(users[num_users].altura)) - 450.0;
                printf("Seu BF é: %.2f%%\n", users[num_users].pg);
                printf("Para calcular o seu BF, utilizamos uma técnica norte-americana que utiliza suas medidas para aproximar o valor real.\n");
                
                users[num_users].IMC = users[num_users].peso / ((users[num_users].altura / 100) * (users[num_users].altura / 100));
                
                printf("Baseado nos dados que já foram informados, seu IMC é: ");
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
                printf("Você deseja secar ou ganhar massa? Digite '1' para secar e '2' para ganhar massa:\n");
                scanf("%d", &users[num_users].objetivo);

                if (users[num_users].objetivo == 1) {
                    printf("Perfeito! Tudo que precisamos é garantir que seu gasto calórico seja maior do que o que você está ingerindo, obviamente \nvamos dar prioridades a proteína e deixar os carbos e gorduras de lado!\n\n");
                    printf("Podemos ver que sua taxa basal é de %.2f, portanto, juntando com dois cardios por dia, poderemos aumentar em até 600\n calorias no total!\n", users[num_users].resultado);
                    if (users[num_users].resultado >= 2000 && users[num_users].resultado <= 3000 && users[num_users].objetivo == 1) {
                        printf("Perfeito! Iremos manter uma média de 2500 à 2700. A recomendação é de uma dieta com 1375kcal de carboidratos, 875kcal de proteína e 375kcal de gordura.\n");
                        printf("Para o cálculo da dieta, é possível utilizar o 'myfitnesspal' que possui uma variedade sobre valores nutricionais dos alimentos.\n");
                        printf("Lembre-se de realizar o cardio e o treino! Caso contrário, o peso pode voltar a aumentar.\n");
                    } else if (users[num_users].resultado > 3000 && users[num_users].resultado <= 4500 && users[num_users].objetivo == 1) {
                        printf("Perfeito! Iremos manter uma média de 3500 à 3700. A recomendação é de uma dieta com 1925kcal de carboidratos, 1225kcal de proteína e 500kcal de gordura.\n");
                        printf("Para o cálculo da dieta, é possível utilizar o 'myfitnesspal' que possui uma variedade sobre valores nutricionais dos alimentos.\n");
                        printf("Lembre-se de realizar o cardio e o treino! Caso contrário, o peso pode voltar a aumentar.\n");
                    } else if (users[num_users].resultado > 1000 && users[num_users].resultado <= 2000 && users[num_users].objetivo == 1) {
                        printf("Perfeito! Iremos manter uma média de 1600 à 1900. A recomendação é de uma dieta com 965kcal de carboidratos, 600kcal de proteína e 185kcal de gordura.\n");
                        printf("Para o cálculo da dieta, é possível utilizar o 'myfitnesspal' que possui uma variedade sobre valores nutricionais dos alimentos.\n");
                        printf("Lembre-se de realizar o cardio e o treino! Caso contrário, o peso pode voltar a aumentar.\n");
                    } else if (users[num_users].resultado > 1000 && users[num_users].objetivo == 2) {
                        printf("Bom! Para isso, manteremos uma dieta de 2000 calorias a mais que a sua taxa basal, tendo em vista que a quantidade de proteína será de 35%% da sua dieta, o carboidrato 55%% e o resto de gordura.\n");
                        printf("Lembre-se de realizar o cardio com moderação e elevar as cargas nos treinos, caso contrário o peso pode aumentar de forma ruim ou estagnar.\n\n");
                    } else {
                        printf("Objetivo não reconhecido.\n");
                        continue;
                    }

                    sexo_valido = 1;
                } else {
                    printf("Perfeito! Porém, daremos prioridade à massa eficaz, ganhar massa não significa comer tudo que tem pela frente!\n");
                    printf("Podemos ver que sua taxa basal é de %.2f, portanto, juntando com dois cardios por dia, iremos reduzir a chance de seuBF aumentar em grande quantidade durante o bulking!\n", users[num_users].resultado);
                }

                sexo_valido = 1;
            } else {
                printf("Sexo inválido!\n");
                sexo_valido = 0;
            }
        } while (!sexo_valido);

        num_users++;

       if (num_users >= 1) {
            printf("Deseja calcular para outro usuário? Digite 1 para continuar ou outro valor para sair:\n");
            scanf("%d", &continuar);
        } else {
            printf("É necessário pelo menos um usuário completo para continuar.\n");
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

