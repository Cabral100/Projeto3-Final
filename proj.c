#include <stdio.h>
#include <string.h>
#include "proj.h"

//Essa funçao cria tarefas
int criarTarefa(ListaDeTarefas *lt) {
  //analisa a quantidade de tarefas ja registradas , caso seja maior do que 100 , da o print ("A lista de tarefas está cheia.")
    if (lt->qtd >= 100) {
        printf("A lista de tarefas está cheia.\n");
        return 1;
    }
    //Pede para o usuario todas as informaçoes necessarias para que a tarefas seja criada
    printf("Tarefa: ");
    scanf("%s", lt->tarefas[lt->qtd].tarefa);
    printf("Descricao da Tarefa: ");
    scanf("%s", lt->tarefas[lt->qtd].descricao);
    printf("Prioridade da Tarefa: ");
    scanf("%d", &lt->tarefas[lt->qtd].prioridade);
    printf("Estado da Tarefa (0 - Nao Iniciado, 1 - Em Andamento, 2 - Completo): ");
    scanf("%d", &lt->tarefas[lt->qtd].estado);
    printf("Categoria da Tarefa: ");
    scanf("%s", lt->tarefas[lt->qtd].categoria);

    lt->qtd += 1;
    return 0;
}
  //Funçao de deletar a tarefa
void deletarTarefa(ListaDeTarefas *lt) {
    int opcao;
    printf("Qual tarefa deseja deletar? ");
    scanf("%d", &opcao);

    if (opcao < 1 || opcao > lt->qtd) {
        printf("Numero invalido.\n");
        return;
    }
    //"For" que realiza a deleçao de uma tarefa ja existente
    for (int i = opcao - 1; i < lt->qtd - 1; i++) {
        lt->tarefas[i] = lt->tarefas[i + 1];
    }

    lt->qtd--;
    printf("Tarefa %d excluida com sucesso!\n", opcao);
}
  //funçao que lista todas as tarefas ja criadas anteriomente
int listarTarefa(ListaDeTarefas lt) {
    if (lt.qtd == 0) {
        printf("A lista de tarefas está vazia.\n");
        return 1;
    }
  //"For" que faz com que a funçao funcione, ou seja , lista todas as informaçoes que foram pedidas anteriormente para criar a tarefa
    for (int i = 0; i < lt.qtd; i++) {
        printf("Tarefa %d:\n", i + 1);
        printf("Nome: %s\n", lt.tarefas[i].tarefa);
        printf("Descricao: %s\n", lt.tarefas[i].descricao);
        printf("Prioridade: %d\n", lt.tarefas[i].prioridade);
        printf("Estado: %d\n", lt.tarefas[i].estado);
        printf("Categoria: %s\n", lt.tarefas[i].categoria);
        printf("\n");
    }

    return 0;
}
//Funçao que ira aparecer para o usuario para que ele escolha qual funçao ele quer realizar
void printMenu() {
    printf("----Lista de tarefas----\n");
    printf("1 - Criar Tarefa\n");
    printf("2 - Deletar Tarefa\n");
    printf("3 - Listar Tarefas\n");
    printf("4 - Alterar Tarefa\n");
    printf("5 - Filtrar por Prioridade\n");
    printf("6 - Filtrar por Estado\n");
    printf("7 - Filtrar por Categoria\n");
    printf("8 - Filtrar por Prioridade e Categoria\n");
    printf("9 - Exportar por Prioridade\n");
    printf("10 - Exportar por Categoria\n");
    printf("11 - Exportar por Prioridade e Categoria\n");
    printf("12 - Salvar Lista\n");
    printf("13 - Carregar Lista\n");
    printf("14 - Sair\n");
    printf("Digite a opcao que voce quer executar: ");
}

void alterarTarefa(ListaDeTarefas *lt) {
    int tarefai, modificaçao;

    printf("Digite o numero da tarefa que deseja modificar: ");
    scanf("%d", &tarefai);
  
    if (tarefai < 1 || tarefai > lt->qtd) {
        printf("Numero invalido.\n");
        return;
    }
    //Pergunta para o usuario qual das informaçoes da tarefa ele desja alterar
    printf("O que deseja modificar : (1 - Tarefa, 2 - Descricao, 3 - Prioridade, 4 - Estado, 5 - Categoria): ");
    scanf("%d", &modificaçao);
    //Altera a informaçao
    Tarefas *tarefa = &lt->tarefas[tarefai - 1];
    
    switch (modificaçao) {
        case 1:
            printf("Nova tarefa: ");
            scanf("%s", tarefa->tarefa);
            break;
        case 2:
            printf("Nova descrição: ");
            scanf("%s", tarefa->descricao);
            break;
        case 3:
            printf("Nova prioridade: ");
            scanf("%d", &tarefa->prioridade);
            break;
        case 4:
            printf("Novo estado (0 - Nao Iniciado, 1 - Em Andamento, 2 - Completo): ");
            scanf("%d", &tarefa->estado);
            break;
        case 5:
            printf("Nova categoria: ");
            scanf("%s", tarefa->categoria);
            break;
        default:
            printf("Opcao invalida.\n");
            break;
    }
}

//Essa funçao filtra a tarefa atraves de sua prioridade 
void filtrar_prioridade(ListaDeTarefas lt, int prioridade) {
    for (int i = 0; i < lt.qtd; i++) {
      //Realiza a filtragem caso a prioridade digitado pelo usuario seja igual a ja cadastrada anteriormente
        if (lt.tarefas[i].prioridade == prioridade) {
          printf("------------------- \n");
          printf("Tarefa %d:\n", i + 1);
          printf("Nome: %s\n", lt.tarefas[i].tarefa);
          printf("Descricao: %s\n", lt.tarefas[i].descricao);
          printf("Prioridade: %d\n", lt.tarefas[i].prioridade);
          printf("Estado: %d\n", lt.tarefas[i].estado);
          printf("Categoria: %s\n", lt.tarefas[i].categoria);
          printf("------------------- \n");
          printf("\n");
        }
    }
}
//filtra por estado
void filtrar_estado(ListaDeTarefas lt, int estado) {
    for (int i = 0; i < lt.qtd; i++) {
      //analisa se o estado digitado pelo usuario é igual ao digitado anteriormente
        if (lt.tarefas[i].estado == estado) {
          printf("------------------- \n");
            printf("Tarefa %d:\n", i + 1);
            printf("Nome: %s\n", lt.tarefas[i].tarefa);
            printf("Descricao: %s\n", lt.tarefas[i].descricao);
            printf("Prioridade: %d\n", lt.tarefas[i].prioridade);
            printf("Estado: %d\n", lt.tarefas[i].estado);
            printf("Categoria: %s\n", lt.tarefas[i].categoria);
            printf("------------------- \n");
        }
    }
}
//essa funçao filtra por categoria
void filtrar_categoria(ListaDeTarefas lt, char categoria[]) {
    for (int i = 0; i < lt.qtd; i++) {
        //ve se a categoria é a mesma digitada anteriormente 
        if (strcmp(lt.tarefas[i].categoria, categoria) == 0) {
          printf("------------------- \n");
            printf("Tarefa %d:\n", i + 1);
            printf("Nome: %s\n", lt.tarefas[i].tarefa);
            printf("Descricao: %s\n", lt.tarefas[i].descricao);
            printf("Prioridade: %d\n", lt.tarefas[i].prioridade);
            printf("Estado: %d\n", lt.tarefas[i].estado);
            printf("Categoria: %s\n", lt.tarefas[i].categoria);
          printf("------------------- \n");
          
        }
    }
}
//filtra prioridade e categoria
void filtrar_prioridade_e_categoria(ListaDeTarefas lt, int prioridade, char categoria[]) {
    for (int i = 0; i < lt.qtd; i++) {
      //analisa para ver se a prioridade e a categoria sao iguais as anteriormente escritas
        if (lt.tarefas[i].prioridade == prioridade && strcmp(lt.tarefas[i].categoria, categoria) == 0) {
            printf("Tarefa %d:\n", i + 1);
            printf("Nome: %s\n", lt.tarefas[i].tarefa);
            printf("Descricao: %s\n", lt.tarefas[i].descricao);
            printf("Prioridade: %d\n", lt.tarefas[i].prioridade);
            printf("Estado: %d\n", lt.tarefas[i].estado);
            printf("Categoria: %s\n", lt.tarefas[i].categoria);
            printf("\n");
        }
    }
}

//essa funçao exporta por prioridade
void exportar_prioridade(ListaDeTarefas lt, int prioridade, char nomeArquivo[]) {
    FILE *arquivo = fopen(nomeArquivo, "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    for (int i = 0; i < lt.qtd; i++) {
      //verifica se a prioridade ja escrita é igual a nova prioridade escrita
        if (lt.tarefas[i].prioridade == prioridade) {
            fprintf(arquivo,"------------------------------\n");
            fprintf(arquivo, "Prioridade :%d\n", lt.tarefas[i].prioridade);
            fprintf(arquivo,"Descriçao: %s \n",lt.tarefas[i].descricao);
            fprintf(arquivo,"Estado: %d \n",lt.tarefas[i].estado);
            fprintf(arquivo,"Nome da tarefa: %s \n",lt.tarefas[i].tarefa);
            fprintf(arquivo,"Categoria: %s \n",lt.tarefas[i].categoria);
            fprintf(arquivo,"------------------------------\n");        }
    }

    fclose(arquivo);
}

//essa funçao exporta por categoria
void exportar_categoria(ListaDeTarefas lt, char categoria[], char nomeArquivo[]) {
    FILE *arquivo = fopen(nomeArquivo, "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    for (int i = 0; i < lt.qtd; i++) {
      //verifica se a categoria ja escrita é igual a nova categoria escrita
        if (strcmp(lt.tarefas[i].categoria, categoria) == 0) {
            fprintf(arquivo,"------------------------------\n");
            fprintf(arquivo, "Prioridade :%d\n", lt.tarefas[i].prioridade);
            fprintf(arquivo,"Descriçao: %s \n",lt.tarefas[i].descricao);
            fprintf(arquivo,"Estado: %d \n",lt.tarefas[i].estado);
            fprintf(arquivo,"Nome da tarefa: %s \n",lt.tarefas[i].tarefa);
            fprintf(arquivo,"Categoria: %s \n",lt.tarefas[i].categoria);
            fprintf(arquivo,"------------------------------\n");        }
    }

    fclose(arquivo);
}

//essa funçao exporta por categoria e prioridade 
void exportar_prioridade_e_categoria(ListaDeTarefas lt, int prioridade, char categoria[], char nomeArquivo[]) {
    FILE *arquivo = fopen(nomeArquivo, "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    for (int i = 0; i < lt.qtd; i++) {
        //verifica se a prioridade e a categoria ja escrita sao iguais as novas 
        if (lt.tarefas[i].prioridade == prioridade && strcmp(lt.tarefas[i].categoria, categoria) == 0) {
            fprintf(arquivo,"------------------------------\n");
            fprintf(arquivo, "Prioridade :%d\n", lt.tarefas[i].prioridade);
            fprintf(arquivo,"Descriçao: %s \n",lt.tarefas[i].descricao);
            fprintf(arquivo,"Estado: %d \n",lt.tarefas[i].estado);
            fprintf(arquivo,"Nome da tarefa: %s \n",lt.tarefas[i].tarefa);
            fprintf(arquivo,"Categoria: %s \n",lt.tarefas[i].categoria);
            fprintf(arquivo,"------------------------------\n");
        }
    }

    fclose(arquivo);
}

//Essa funçao escreve um arquivo binario e salva as informaçoes ja escritas anteriormente nele
int salvarLista(ListaDeTarefas lt, char nome[]) {
    FILE *arquivo = fopen(nome, "wb");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    fwrite(&lt, sizeof(ListaDeTarefas), 1, arquivo);
    fclose(arquivo);
    return 0;
}
//Essa funçao carrega a lista
int carregarLista(ListaDeTarefas *lt, char nome[]) {
    FILE *arquivo = fopen(nome, "rb");

    if (arquivo == NULL) {
        return 1;
    }

    fread(lt, sizeof(ListaDeTarefas), 1, arquivo);
    fclose(arquivo);
    return 0;
}