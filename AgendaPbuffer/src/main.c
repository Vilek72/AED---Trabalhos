#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PESSOAS 100
#define NOME_SIZE 50
#define EMAIL_SIZE 50
#define PESSOA_SIZE ( NOME_SIZE + sizeof( int ) + EMAIL_SIZE )

void *pBuffer;

void AdicionarContato( ) {
    int *numPessoas = ( int * )pBuffer;
    char *buffer = ( char * )pBuffer;

    if ( *numPessoas >= MAX_PESSOAS ) {
        printf( "Agenda cheia!\n" );
        return;
    }

    char *nome = buffer + sizeof( int ) + ( *numPessoas ) * PESSOA_SIZE;
    int *idade = ( int * )( nome + NOME_SIZE );
    char *email = ( char * )( idade + 1 );

    printf( "Nome: " );
    scanf( "%s", nome );
    printf( "Idade: " );
    scanf( "%d", idade );
    printf( "Email: " );
    scanf( "%s", email );

    ( *numPessoas )++;
}

void RemoverContato( ) {
    int *numPessoas = ( int * )pBuffer;
    char *buffer = ( char * )pBuffer;

    char *nomeRemover = ( char * ) ( buffer + sizeof ( int ) + ( *numPessoas ) * PESSOA_SIZE ); // Usando espaço temporário no buffer
    printf( "Nome da pessoa a ser removida: " );
    scanf( "%s", nomeRemover );

    // Cria um buffer temporário para percorrer a lista
    char *temp = buffer + sizeof( int );
    //percorre a lista
    while ( temp < buffer + sizeof( int ) + ( *numPessoas ) * PESSOA_SIZE ) {
        if ( strcmp( temp, nomeRemover ) == 0 ) {
            while ( temp < buffer + sizeof( int ) + ( *numPessoas - 1 ) * PESSOA_SIZE ) {
                memcpy( temp, temp + PESSOA_SIZE, PESSOA_SIZE );
                temp += PESSOA_SIZE;
            }
            ( *numPessoas )--;
            printf( "Pessoa removida com sucesso!\n" );
            return;
        }
        temp += PESSOA_SIZE;
    }

    printf( "Pessoa nao encontrada!\n" );
}

void BuscarContato( ) {
    int *numPessoas = ( int * )pBuffer;
    char *buffer = ( char * )pBuffer;

    char *nomeBuscar = ( char * ) ( buffer + sizeof( int ) + ( *numPessoas ) * PESSOA_SIZE ); // Usando espaço temporário no buffer
    printf( "Nome da pessoa a ser buscada: " );
    scanf( "%s", nomeBuscar );


    // Cria um buffer temporário para percorrer a lista
    char *temp = buffer + sizeof( int );
    while ( temp < buffer + sizeof( int ) + ( *numPessoas ) * PESSOA_SIZE ) {
        if ( strcmp( temp, nomeBuscar ) == 0 ) {
            int *idade = ( int * )( temp + NOME_SIZE );
            char *email = ( char * )( idade + 1 );
            printf( "Nome: %s, Idade: %d, Email: %s\n", temp, *idade, email );
            return;
        }
        temp += PESSOA_SIZE;
    }

    printf("Pessoa não encontrada!\n");
}

void ListarContato( ) {
    int *numPessoas = ( int * )pBuffer;
    char *buffer = ( char * )pBuffer;

    char *temp = buffer + sizeof( int );
    while (temp < buffer + sizeof( int ) + ( *numPessoas ) * PESSOA_SIZE) {
        int *idade = ( int * )( temp + NOME_SIZE );
        char *email = ( char * )( idade + 1 );
        printf( "Nome: %s, Idade: %d, Email: %s\n", temp, *idade, email );
        temp += PESSOA_SIZE;
    }
}

int main( ) {
    // Aloca o buffer de memória
    pBuffer = malloc( sizeof(int)* MAX_PESSOAS * PESSOA_SIZE );
    if ( pBuffer == NULL ) {
        printf("Erro ao alocar memória!\n");
        return 0;
    }

    // Inicializa o número de pessoas
    int *numPessoas = ( int * )pBuffer;
    *numPessoas = 0;

    // Inicializa o ponteiro para a seleção do menu
    int *opcao = ( int * )( ( char * )pBuffer + sizeof( int ) + MAX_PESSOAS * PESSOA_SIZE ); 

    while ( *opcao != 5 ) {
        printf( "\nMenu:\n" );
        printf( "1- Adicionar Pessoa\n" );
        printf( "2- Remover Pessoa\n" );
        printf( "3- Buscar Pessoa\n" );
        printf( "4- Listar todos\n" );
        printf( "5- Sair\n" );
        printf( "Escolha uma opcao: " );
        scanf("%d", opcao);

        if ( *opcao == 1 ) AdicionarContato( );
        else if ( *opcao == 2 ) RemoverContato( );
        else if ( *opcao == 3 ) BuscarContato( );
        else if ( *opcao == 4 ) ListarContato( );
        else if ( *opcao == 5 ) break;
        else printf( "Opcao invalida!\n" );
    }

    printf( "Saindo...\n" );

    // Libera o buffer de memória
    free( pBuffer );
    return 0;
}
