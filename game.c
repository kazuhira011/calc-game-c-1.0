#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int dificuldade;
    int valor1;
    int valor2;
    int operacao;
    int resultado;
} Calcular;

void jogar();
void mostrarInfo(Calcular calc);

int somar(int resposta, Calcular calc);
int diminuir(int resposta, Calcular calc);
int multiplicar(int resposta, Calcular calc);

int pontos = 0;

int main(){

    srand(time(NULL));
    jogar();
    return 0;
}

void jogar(){

    Calcular calc;
    int dificuldade;

    printf("Informe o nivel de dificuldade desejada [1, 2, 3 ou 4]: \n");
    scanf("%d", &dificuldade);
    calc.dificuldade = dificuldade;

    calc.operacao = rand() % 3; // gera um valor inteiro randômico entre 0 e 2

    if(calc.dificuldade == 1){
        // fácil
        calc.valor1 = rand() % 11; // 0 a 10
        calc.valor2 = rand() % 11;
    }

    else if(calc.dificuldade == 2){
        // médio
        calc.valor1 = rand() %101; // 0 a 100
        calc.valor2 = rand() %101;
    }

    else if(calc.dificuldade == 3){
        // difícil
        calc.valor1 = rand() %1001; // 0 a 1000
        calc.valor2 = rand() %1001;
    }

    else if(calc.dificuldade == 4){
        // insano
        calc.valor1 = rand() % 10001; // 0 a 10000
        calc.valor2 = rand() % 10001;
    }

    else{
        // ultra (dificuldade secreta)
        calc.valor1 = rand() % 100001; // 0 a 10000
        calc.valor2 = rand() % 100001;
    }

    int resposta;
    printf("Informe o resultado para a seguinte operacao: \n");

    // somar
    if(calc.operacao == 0){
        printf( "%d + %d \n", calc.valor1, calc.valor2);
        scanf("%d", &resposta);

        if(somar(resposta, calc)){
            pontos += 1;
            printf("Voce tem %d ponto(s). \n", pontos);
        }
    }

    // diminuir
    else if(calc.operacao == 1){
        printf("%d - %d \n", calc.valor1, calc.valor2);
        scanf("%d", &resposta);
        pontos += 1;
        printf("Voce tem %d ponto(s). \n", pontos);
    }

    //multiplicar
    else if(calc.operacao == 2){
        printf("%d * %d \n", calc.valor1, calc.valor2);
        scanf("%d", &resposta);
        pontos += 1;
        printf("Voce tem %d ponto(s). \n", pontos);
    }

    //desconhecida
    else{
        printf("A operacao %d nao e reconhecida. \n", calc.operacao);
    }

    // mostrarInfo
    mostrarInfo(calc);

    // Recomeçar o jogo?
    printf("Deseja continuar jogando? [1 - sim, 0 - nao] \n");
    int continuar;
    scanf("%d", &continuar);

    if(continuar){
        jogar();
    }

    else{
        printf("Voce finalizou com %d ponto(s). \n", pontos);
        printf("Ate a proxima! \n");
        exit(0);
    }

}

void mostrarInfo(Calcular calc){

char op[25];

if(calc.operacao == 0){ // 0 == somar
    sprintf(op, "Somar");
}

else if(calc.operacao == 1){ // 1 == diminuir
    sprintf(op, "Diminuir");
}

else if(calc.operacao == 2){ // 2 == multiplicar
    sprintf(op, "Multiplicar");
}

else{
    sprintf(op, "Operacao desconhecida");
}

printf(" Valor 1: %d \n Valor 2: %d \n Dificuldade: %d \n Operacao: %s \n \n", calc.valor1, calc.valor2, calc.dificuldade, op);

}

int somar(int resposta, Calcular calc){

    int resultado = calc.valor1 + calc.valor2;
    calc.resultado = resultado;
    int certo = 0; // 0 == errou | 1 == acertou

    if(resposta == calc.resultado){
        printf("Resposta correta! \n");
        certo = 1;
    }
    
    else{
        printf("Resposta errada! \n");
    }

    printf("%d + %d = %d \n", calc.valor1, calc.valor2, calc.resultado);

    return certo;

}

int diminuir(int resposta, Calcular calc){

    int resultado = calc.valor1 - calc.valor2;
    calc.resultado = resultado;
    int certo = 0; // 0 == errou | 1 == acertou

    if(resposta == calc.resultado){
        printf("Resposta correta! \n");
        certo = 1;
    }
    
    else{
        printf("Resposta errada! \n");
    }

    printf("%d - %d = %d \n", calc.valor1, calc.valor2, calc.resultado);

    return certo;

}

int multiplicar(int resposta, Calcular calc){

    int resultado = calc.valor1 * calc.valor2;
    calc.resultado = resultado;
    int certo = 0; // 0 == errou | 1 == acertou

    if(resposta == calc.resultado){
        printf("Resposta correta! \n");
        certo = 1;
    }
    
    else{
        printf("Resposta errada! \n");
    }

    printf("%d * %d = %d \n", calc.valor1, calc.valor2, calc.resultado);

    return certo;

}