#include "../header/menu.h"

// Descrição: Exibe no terminal o menu de opções disponíveis para o usuário,
// Pré-condição: Nenhuma.
// Pós-condição: O menu é impresso na tela e o programa aguarda a entrada do usuário.
void imprimir_opcoes(){
    cout <<endl << endl <<  "Escolha uma opcao:" << endl << endl;
    cout << "0 - Sair do programa" << endl;
    cout << "1 - Ler Arquivo" << endl;
    cout << "2 - Menor caminho - Dijkstra" << endl;
    cout << endl << "Insira a opcao: ";
}

// Descrição: Altera a cor do console do Windows usando o comando.
// Pré-condição: Nenhuma
// Pós-condição: A cor do console é alterada para o esquema definido (1D).
void cor_sistema(){
    system("Color 0D");
}


//Descrição: Mostra as opções do menu e executa a opção que o usuário desejar
//Pré-condição: Nenhuma
//Pós-condição: Mostra as opções do menu
void menu(){
    Arquivo config_arquivo("", "");
    vector<Aresta> arestas_vazias;
    Grafo grafo(false, arestas_vazias);
    Aresta aresta_template("", "", 0);

    int op;
    string nome_arquivo;

    do{
        imprimir_opcoes();
        cin >> op;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl;

        switch (op){

            case 1:
                {    
                    cout << "Digite o nome do arquivo de leitura (inclua o .txt ao final): ";
                    cin >> nome_arquivo;

                    grafo.limpar_arestas();

                    cout << "Lendo arquivo de configuracao: " << nome_arquivo << "..." << endl;
                    if (!config_arquivo.ler_arquivo(nome_arquivo, grafo, config_arquivo, aresta_template)) {
                        cerr << "Erro fatal: Falha na leitura do arquivo de entrada." << endl;
                        exit(1); // Termina o programa se o arquivo não puder ser lido
                    }
                    cout << "Leitura concluida com sucesso." << endl << endl;
                }

                break;
            
            case 2:
                {

                    string ponto_inicial = config_arquivo.get_ponto_inical();
                    string ponto_final = config_arquivo.get_ponto_final();

                    cout << "Executando Dijkstra para encontrar o melhor caminho..." << endl;
                    grafo.dijkstra(config_arquivo.get_ponto_inical(), config_arquivo.get_ponto_final());
                }

                break;

            default:
                break;
            }

    } while(op != 0);

}