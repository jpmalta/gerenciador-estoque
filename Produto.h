#ifndef PRODUTO_H
#define PRODUTO_H

#include <string>
#include <iostream>

class Produto {
private:
    int id;
    std::string nome;
    int quantidade;
    double preco;

public:
    Produto(int id, const std::string& nome, int quantidade, double preco);

    int getId() const;
    std::string getNome() const;
    int getQuantidade() const;
    double getPreco() const;

    void setQuantidade(int novaQuantidade);
    void setPreco(double novoPreco);

    void exibirDetalhes() const;
};

#endif
