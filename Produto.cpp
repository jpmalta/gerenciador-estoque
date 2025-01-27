#include "Produto.h"
#include <iostream>
#include <iomanip>
using namespace std;

// Construtor
Produto::Produto(int id, const string& nome, int quantidade, double preco)
    : id(id), nome(nome), quantidade(quantidade), preco(preco) {}

// Métodos Getters
int Produto::getId() const { return id; }
string Produto::getNome() const { return nome; }
int Produto::getQuantidade() const { return quantidade; }
double Produto::getPreco() const { return preco; }

// Métodos Setters
void Produto::setQuantidade(int novaQuantidade) { quantidade = novaQuantidade; }
void Produto::setPreco(double novoPreco) { preco = novoPreco; }
void Produto::setNome(const string& novoNome) { nome = novoNome; }

// Exibir informações do produto
void Produto::exibirProduto() const {
    cout << "ID: " << id
         << " | Nome: " << nome
         << " | Quantidade: " << quantidade
         << " | Preço: R$ " << fixed << setprecision(2) << preco << endl;
}
