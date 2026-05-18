#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <filesystem>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <limits>
#include <algorithm>

using namespace std;

class Aresta{
    private:
        string lig_inicio;
        string lig_fim;
        int lig_custo;

    public:
        Aresta(string lig_inicio, string lig_fim, int lig_custo);

        string get_lig_inicio();
        string get_lig_fim();
        int get_custo();

        void set_lig_inicio(string lig_inicio);
        void set_lig_fim(string lig_fim);
        void set_custo(int lig_custo);
};

class Grafo{
    private:
        vector<Aresta> arestas; //arestas
        bool orientado;

    public:
        Grafo(bool orientado, vector<Aresta> aresta);

        // Getters
        bool get_orientado();
        vector<Aresta> get_aresta();

        // Setters
        void set_orientado(bool orientado);
        void set_aresta(vector<Aresta> aresta);

        // Adiciona uma aresta ao grafo
        // Adiciona uma aresta ao grafo
        // Descrição: Cria um objeto do tipo Aresta e o insere na lista de arestas do grafo.
        // Pré-condição: Os nomes dos vértices devem ser válidos (não vazios) e o custo deve ser um valor inteiro >= 0.
        // Pós-condição: A lista de arestas do grafo (`this->arestas`) conterá a nova aresta adicionada.
        void add_aresta(string inicio_aresta, string fim_aresta, int custo);

        void limpar_arestas();

        // Algoritmo de Dijkstra
        void dijkstra(string origem, string destino);

};

#endif