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

    int difficulty[] = {2, 4, 6, 8, 10};
    int profit[] = {30, 20, 30, 40, 50};
    int worker[] = {4, 5, 6, 7};

    int difficultySize = sizeof(difficulty) / sizeof(difficulty[0]);
    int profitSize = sizeof(profit) / sizeof(profit[0]);
    int workerSize = sizeof(worker) / sizeof(worker[0]);

    int result = maxProfitAssignment(difficulty, difficultySize, profit, profitSize, worker, workerSize);

    printf("lucro total: %i\n", result);

    return 0;
}

