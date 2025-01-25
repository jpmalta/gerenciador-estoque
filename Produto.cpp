#include "Produto.h"

Produto::Produto(int id, const std::string& nome, int quantidade, double preco)
    : id(id), nome(nome), quantidade(quantidade), preco(preco) {}

int Produto::getId() const {
    return id;
}

std::string Produto::getNome() const {
    return nome;
}

int Produto::getQuantidade() const {
    return quantidade;
}

double Produto::getPreco() const {
    return preco;
}

void Produto::setQuantidade(int novaQuantidade) {
    quantidade = novaQuantidade;
}

void Produto::setPreco(double novoPreco) {
    preco = novoPreco;
}

void Produto::exibirDetalhes() const {
    std::cout << "ID: " << id 
              << ", Nome: " << nome
              << ", Quantidade: " << quantidade
              << ", Preco: R$ " << preco << "\n";
}
