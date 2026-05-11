#include "../header/arquivo.h"

Arquivo::Arquivo(string ponto_final, string ponto_inical){
    this->ponto_final = ponto_final;
    this->ponto_inical = ponto_inical;
}

string Arquivo::get_ponto_final(){ return this->ponto_final; }
string Arquivo::get_ponto_inical(){ return this->ponto_inical; }


void Arquivo::set_ponto_final(string ponto_final){
    this->ponto_final = ponto_final;
}
void Arquivo::set_ponto_inical(string ponto_inical){
    this->ponto_inical = ponto_inical;
}

//Descrição: Lê um arquivo de texto para configurar um grafo, incluindo pontos inicial/final, orientação, arestas e heurísticas.
//Pré-condição: O caminho do arquivo é válido e o arquivo está formatado corretamente. As referências para os objetos são válidas.
//Pós-condição: O objeto 'grafo' é populado com os dados do arquivo. Retorna 'true' em caso de sucesso e 'false' se o arquivo não puder ser aberto.
bool Arquivo::ler_arquivo(string arquivo_entrada, Grafo &grafo, Arquivo &config, Aresta &aresta){
    string linha, sub_string;
    size_t pos_ini, pos_meio, pos_final;

    ifstream arq(arquivo_entrada);


    if (!arq.is_open()) {
        cerr << "Erro ao abrir arquivo de entrada: " << arquivo_entrada << endl;
        return false;
    }

    while(getline(arq, linha)){

        if(linha.empty() || linha.find("---") != string::npos || linha.find("Arquivo grande") != string::npos){
            continue;
        }

        if(linha.find("ponto_inicial(") != string::npos){
            pos_ini = linha.find("(") + 1;
            pos_final = linha.find(")");
            sub_string = linha.substr(pos_ini, pos_final - pos_ini);
            config.set_ponto_inical(sub_string); 
            cout << endl <<"Ponto inicial: " << config.get_ponto_inical();
        }

        else if(linha.find("ponto_final(") != string::npos){
            pos_ini = linha.find("(") + 1;
            pos_final = linha.find(")");
            sub_string = linha.substr(pos_ini, pos_final - pos_ini);
            config.set_ponto_final(sub_string);
            cout << " | Ponto final: " <<config.get_ponto_final();
        }

        else if (linha.find("orientado(") != string::npos) {
            grafo.set_orientado(linha.find("(s)") != string::npos);
            cout << " | Orientado: " << grafo.get_orientado() << endl;
        }

        else if(linha.find("aresta(") != string::npos){
            // Extrai o primeiro argumento
            pos_ini = linha.find("(") + 1;
            pos_meio = linha.find(",");
            sub_string = linha.substr(pos_ini, pos_meio - pos_ini);
            aresta.set_lig_inicio(sub_string);
            cout << endl << "Aresta: (" <<aresta.get_lig_inicio() << " , ";

            // Extrai o segundo argumento
            pos_ini = pos_meio + 1;
            pos_meio = linha.find(",", pos_ini);
            sub_string = linha.substr(pos_ini, pos_meio - pos_ini);
            aresta.set_lig_fim(sub_string);
            cout << aresta.get_lig_fim() << ")";

            // Extrai o terceiro argumento (custo)
            pos_ini = pos_meio + 1;
            pos_final = linha.find(")");
            sub_string = linha.substr(pos_ini, pos_final - pos_ini);
            aresta.set_custo(stoi(sub_string));
            cout << " | Custo: " << aresta.get_custo() << endl;

            grafo.add_aresta(aresta.get_lig_inicio(), aresta.get_lig_fim(), aresta.get_custo());
        }
    }
    arq.close();
    return true;
}