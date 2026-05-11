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

