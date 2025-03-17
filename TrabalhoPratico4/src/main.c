#include <stdio.h>
#include <stdlib.h>

//COMPLEXIDADE: O(n*m)


// struct que agrupa os dados de cada trabalho
typedef struct {

    int diff;
    int profit;

} Work;

//função para comparar dois valores
int cmpFunc(const void* a, const void* b){
    return ((Work*)b)->profit - ((Work*)a)->profit;
    }


int maxProfitAssignment(int* difficulty, int difficultySize, int* profit, int profitSize, int* worker, int workerSize) {

    int totalProfit = 0;
    int workSize = difficultySize;
    Work works[workSize];

    //agrupa os atributos dificuldade e lucro de cada trabalho em um vetor de structs;
    for ( int i = 0; i < workSize; i++ )
    works[i] = (Work){difficulty[i], profit[i]};

    //faz a ordenação dos trabalhos com base no lucro individual
    qsort (works, workSize, sizeof(Work), cmpFunc);

    //for de apoio para printar o vetor de trabalhos após a ordenação
    for ( int i = 0; i < workSize; i++)
    printf("work %i: %i, %i\n", i, works[i].diff, works[i].profit );

    //busca pelo melhor lucro disponível para cada empregado, pulando para o proximo assim que cada um encontre o seu valor
    for(int i = 0; i < workerSize; i++) {
        for(int j = 0; j < workSize; j++) {
            if(works[j].diff > worker[i]){
                    continue;
            }
            totalProfit += works[j].profit;
            break;
        }
    }

    return totalProfit;
}

int main() {

    int difficulty[] = {12312, 2131, 2345, 6346, 3425, 1235, 634, 67451, 1231, 5634};
    int profit[] = {1300, 8200, 3300, 4000, 400, 6200, 7090, 1800, 900, 1000};
    int worker[] = {3123, 7546, 3477, 7865, 985, 345, 24525, 6346, 745};

    int difficultySize = sizeof(difficulty) / sizeof(difficulty[0]);
    int profitSize = sizeof(profit) / sizeof(profit[0]);
    int workerSize = sizeof(worker) / sizeof(worker[0]);    

    int result = maxProfitAssignment(difficulty, difficultySize, profit, profitSize, worker, workerSize);

    printf("lucro total: %i\n", result);
    
    

    return 0;
}

