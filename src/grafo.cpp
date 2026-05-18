#include "../header/grafo.h"


Aresta::Aresta(string lig_inicio, string lig_fim, int lig_custo){
    this->lig_inicio = lig_inicio;
    this->lig_fim = lig_fim;
    this->lig_custo = lig_custo;
}

string Aresta::get_lig_inicio(){ return this->lig_inicio; }

string Aresta::get_lig_fim(){ return this->lig_fim; }

int Aresta::get_custo(){ return this->lig_custo; }

void Aresta::set_lig_inicio(string lig_inicio){ this->lig_inicio = lig_inicio; }

void Aresta::set_lig_fim(string lig_fim){ this->lig_fim = lig_fim; }

void Aresta::set_custo(int lig_custo){this->lig_custo = lig_custo; }

//GRAFO
Grafo::Grafo(bool orientado, vector<Aresta> aresta){
    this->orientado = orientado;
    this->arestas = aresta;
}

// Getters
bool Grafo::get_orientado(){ return this->orientado; }
vector<Aresta> Grafo::get_aresta(){ return this->arestas; }

// Setters
void Grafo::set_orientado(bool orientado){ this->orientado = orientado; }

void Grafo::set_aresta(vector<Aresta> aresta){ this->arestas = aresta; }


// Adiciona uma aresta ao grafo
// Descrição: Cria um objeto do tipo Aresta e o insere na lista de arestas do grafo.
// Pré-condição: Os nomes dos vértices devem ser válidos (não vazios) e o custo deve ser um valor inteiro >= 0.
// Pós-condição: A lista de arestas do grafo (`this->arestas`) conterá a nova aresta adicionada.
void Grafo::add_aresta(string inicio_aresta, string fim_aresta, int custo){
    Aresta aresta(inicio_aresta, fim_aresta, custo);
    this->arestas.push_back(aresta);
}

void Grafo::limpar_arestas(){
    this->arestas.clear();
}

void Grafo::dijkstra(string origem, string destino){
    const int INF = numeric_limits<int>::max();

    unordered_map<string, int> distancia;
    unordered_map<string, string> anterior;
    unordered_set<string> vertices;

    // Coleta todos os vértices existentes nas arestas
    for(Aresta aresta : this->arestas){
        vertices.insert(aresta.get_lig_inicio());
        vertices.insert(aresta.get_lig_fim());
    }

    // Verifica se origem e destino existem no grafo
    if(vertices.find(origem) == vertices.end()){
        cout << endl << "Erro: ponto inicial '" << origem << "' não existe no grafo." << endl;
        return;
    }

    if(vertices.find(destino) == vertices.end()){
        cout << endl << "Erro: ponto final '" << destino << "' não existe no grafo." << endl;
        return;
    }

    // Inicializa as distâncias
    for(string vertice : vertices){
        distancia[vertice] = INF;
    }

    distancia[origem] = 0;

    // Fila de prioridade: pair<custo_atual, vertice>
    priority_queue<
        pair<int, string>,
        vector<pair<int, string>>,
        greater<pair<int, string>>
    > fila;

    fila.push({0, origem});

    while(!fila.empty()){
        int custo_atual = fila.top().first;
        string vertice_atual = fila.top().second;
        fila.pop();

        // Se o custo retirado da fila não é mais o menor, ignora
        if(custo_atual > distancia[vertice_atual]){
            continue;
        }

        // Percorre as arestas do grafo
        for(Aresta aresta : this->arestas){
            string inicio = aresta.get_lig_inicio();
            string fim = aresta.get_lig_fim();
            int custo = aresta.get_custo();

            // Caso normal: grafo orientado ou direção original da aresta
            if(inicio == vertice_atual){
                int nova_distancia = distancia[vertice_atual] + custo;

                if(nova_distancia < distancia[fim]){
                    distancia[fim] = nova_distancia;
                    anterior[fim] = vertice_atual;
                    fila.push({nova_distancia, fim});
                }
            }

            // so permite o camnho inverso se o grafo nao for orientando
            if(!this->orientado && fim == vertice_atual){
                int nova_distancia = distancia[vertice_atual] + custo;

                if(nova_distancia < distancia[inicio]){
                    distancia[inicio] = nova_distancia;
                    anterior[inicio] = vertice_atual;
                    fila.push({nova_distancia, inicio});
                }
            }
        }
    }

    // Se não encontrou caminho
    if(distancia[destino] == INF){
        cout << endl << "Não existe caminho entre " << origem << " e " << destino << "." << endl;
        return;
    }

    // Reconstrói o caminho do destino até a origem
    vector<string> caminho;
    string atual = destino;

    while(atual != origem){
        caminho.push_back(atual);
        atual = anterior[atual];
    }

    caminho.push_back(origem);

    reverse(caminho.begin(), caminho.end());

    // Mostra o resultado
    cout << endl;
    cout << "Menor caminho de " << origem << " ate " << destino << ":" << endl;

    for(size_t i = 0; i < caminho.size(); i++){
        cout << caminho[i];

        if(i < caminho.size() - 1){
            cout << " -> ";
        }
    }

    cout << endl;
    cout << "Custo total: " << distancia[destino] << endl;
}
