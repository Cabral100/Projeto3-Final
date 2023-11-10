#ifndef PROJETO_PROJ_H
#define PROJETO_PROJ_H

typedef struct {
    int prioridade;
    char tarefa[300];
    char descricao[100];
    int estado;
    char categoria[50];
} Tarefas;

typedef struct {
    Tarefas tarefas[100];
    int qtd;
} ListaDeTarefas;

int criarTarefa(ListaDeTarefas *lt);
void deletarTarefa(ListaDeTarefas *lt);
int listarTarefa(ListaDeTarefas lt);
void printMenu();
void alterarTarefa(ListaDeTarefas *lt);
void filtrar_prioridade(ListaDeTarefas lt, int prioridade);
void filtrar_estado(ListaDeTarefas lt, int estado);
void filtrar_categoria(ListaDeTarefas lt, char categoria[]);
void filtrar_prioridade_e_categoria(ListaDeTarefas lt, int prioridade, char categoria[]);
void exportar_prioridade(ListaDeTarefas lt, int prioridade, char nomeArquivo[]);
void exportar_categoria(ListaDeTarefas lt, char categoria[], char nomeArquivo[]);
void exportar_prioridade_e_categoria(ListaDeTarefas lt, int prioridade, char categoria[], char nomeArquivo[]);
int salvarLista(ListaDeTarefas lt, char nome[]);
int carregarLista(ListaDeTarefas *lt, char nome[]);

#endif //PROJETO_PROJ_H