#include <stdio.h>
#include "proj.h"

int main() {
    ListaDeTarefas lt;
    lt.qtd = 0;

    int cod;
    int opcao;
    char nomeArquivo[100];

    cod = carregarLista(&lt, "arquivo");

    if (cod == 1){
        lt.qtd = 0;
    }

    do {
        printMenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                criarTarefa(&lt);
                break;
            case 2:
                deletarTarefa(&lt);
                break;
            case 3:
                listarTarefa(lt);
                break;
            case 4:
                alterarTarefa(&lt);
                break;
            case 5: {
                int prioridade;
                printf("Digite a prioridade desejada: ");
                scanf("%d", &prioridade);
                filtrar_prioridade(lt, prioridade);
                break;
            }
            case 6: {
                int estado;
                printf("Digite o estado desejado (0 - Nao Iniciado, 1 - Em Andamento, 2 - Completo): ");
                scanf("%d", &estado);
                filtrar_estado(lt, estado);
                break;
            }
            case 7: {
                char categoria[50];
                printf("Digite a categoria desejada: ");
                scanf("%s", categoria);
                filtrar_categoria(lt, categoria);
                break;
            }
            case 8: {
                int prioridade;
                char categoria[50];
                printf("Digite a prioridade desejada: ");
                scanf("%d", &prioridade);
                printf("Digite a categoria desejada: ");
                scanf("%s", categoria);
                filtrar_prioridade_e_categoria(lt, prioridade, categoria);
                break;
            }
            case 9: {
                int prioridade;
                printf("Digite a prioridade desejada: ");
                scanf("%d", &prioridade);
                printf("Digite o nome do arquivo para exportar: ");
                scanf("%s", nomeArquivo);
                exportar_prioridade(lt, prioridade, nomeArquivo);
                break;
            }
            case 10: {
                char categoria[50];
                printf("Digite a categoria desejada: ");
                scanf("%s", categoria);
                printf("Digite o nome do arquivo para exportar: ");
                scanf("%s", nomeArquivo);
                exportar_categoria(lt, categoria, nomeArquivo);
                break;
            }
            case 11: {
                int prioridade;
                char categoria[50];
                printf("Digite a prioridade desejada: ");
                scanf("%d", &prioridade);
                printf("Digite a categoria desejada: ");
                scanf("%s", categoria);
                printf("Digite o nome do arquivo para exportar: ");
                scanf("%s", nomeArquivo);
                exportar_prioridade_e_categoria(lt, prioridade, categoria, nomeArquivo);
                break;
            }
            case 12: {
                char nome[100];
                printf("Digite o nome do arquivo para salvar: ");
                scanf("%s", nome);
                salvarLista(lt, nome);
                break;
            }
            case 13: {
                char nome[100];
                printf("Digite o nome do arquivo para carregar: ");
                scanf("%s", nome);
                carregarLista(&lt, nome);
                break;
            }
            case 14:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
                break;
        }

    } while (opcao != 14);

    cod = salvarLista(lt, "arquivo");

    if (cod != 0){
        printf("Erro ao salvar lista\n");
    }


    return 0;
}