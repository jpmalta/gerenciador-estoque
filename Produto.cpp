#include <iostream>
#include <string>
#include <vector>

class Produto {
private:
    int id;
    std::string nome;
    int quantidade;
    double preco;

public:
    // Construtor
    Produto(int id, const std::string& nome, int quantidade, double preco)
        : id(id), nome(nome), quantidade(quantidade), preco(preco) {}

    // Métodos getters
    int getId() const { return id; }
    std::string getNome() const { return nome; }
    int getQuantidade() const { return quantidade; }
    double getPreco() const { return preco; }

    // Métodos setters
    void setQuantidade(int novaQuantidade) { quantidade = novaQuantidade; }
    void setPreco(double novoPreco) { preco = novoPreco; }

    // Exibe os detalhes do produto
    void exibirDetalhes() const {
        std::cout << "ID: " << id 
                  << ", Nome: " << nome
                  << ", Quantidade: " << quantidade
                  << ", Preco: R$ " << preco << "\n";
    }
};
