#ifndef PRODUTO_H
#define PRODUTO_H

#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

class Produto {
private:
    int id;
    string nome;
    int quantidade;
    double preco;

public:
    // Construtor
    Produto(int id, const string& nome, int quantidade, double preco);

    // Métodos Getters
    int getId() const;
    string getNome() const;
    int getQuantidade() const;
    double getPreco() const;

    // Métodos Setters
    void setQuantidade(int novaQuantidade);
    void setPreco(double novoPreco);
    void setNome(const string& novoNome);

    // Exibir informações do produto
    void exibirProduto() const;
};

#endif