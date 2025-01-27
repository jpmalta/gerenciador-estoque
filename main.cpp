#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "Produto.h"
using namespace std;

// Prototipação de funções
void exibirMenu();
void cadastrarProduto(vector<Produto>& produtos, int& proximoId);
void listarProdutos(const vector<Produto>& produtos);
void buscarProduto(const vector<Produto>& produtos);
void atualizarProduto(vector<Produto>& produtos);
void removerProduto(vector<Produto>& produtos);
void gerarRelatorio(const vector<Produto>& produtos);

int main() {
    vector<Produto> produtos;
    int proximoId = 1;
    int opcao;

    do {
        exibirMenu();
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1: cadastrarProduto(produtos, proximoId); break;
            case 2: listarProdutos(produtos); break;
            case 3: buscarProduto(produtos); break;
            case 4: atualizarProduto(produtos); break;
            case 5: removerProduto(produtos); break;
            case 6: gerarRelatorio(produtos); break;
            case 7: cout << "Saindo do programa...\n"; break;
            default: cout << "Opção inválida. Tente novamente.\n";
        }
    } while (opcao != 7);

    return 0;
}

// Função para exibir o menu
void exibirMenu() {
    cout << "\n=== MENU ===\n";
    cout << "1. Cadastrar Produto\n";
    cout << "2. Listar Produtos\n";
    cout << "3. Buscar Produto\n";
    cout << "4. Atualizar Produto\n";
    cout << "5. Remover Produto\n";
    cout << "6. Gerar Relatório\n";
    cout << "7. Sair\n";
    cout << "=============\n";
}

// Função para cadastrar um novo produto
void cadastrarProduto(vector<Produto>& produtos, int& proximoId) {
    string nome;
    int quantidade;
    double preco;

    cout << "Digite o nome do produto: ";
    cin.ignore();
    getline(cin, nome);

    cout << "Digite a quantidade: ";
    cin >> quantidade;

    cout << "Digite o preço: ";
    cin >> preco;

    Produto novoProduto(proximoId, nome, quantidade, preco);
    produtos.push_back(novoProduto);
    proximoId++;

    cout << "Produto cadastrado com sucesso!\n";
}

// Função para listar todos os produtos
void listarProdutos(const vector<Produto>& produtos) {
    if (produtos.empty()) {
        cout << "Nenhum produto cadastrado.\n";
        return;
    }

    cout << "\n=== Lista de Produtos ===\n";
    for (const auto& produto : produtos) {
        produto.exibirProduto();
    }
}

// Função para buscar um produto pelo ID
void buscarProduto(const vector<Produto>& produtos) {
    int id;
    cout << "Digite o ID do produto: ";
    cin >> id;

    for (const auto& produto : produtos) {
        if (produto.getId() == id) {
            produto.exibirProduto();
            return;
        }
    }

    cout << "Produto com ID " << id << " não encontrado.\n";
}

// Função para atualizar um produto
void atualizarProduto(vector<Produto>& produtos) {
    int id;
    cout << "Digite o ID do produto a ser atualizado: ";
    cin >> id;

    for (auto& produto : produtos) {
        if (produto.getId() == id) {
            string novoNome;
            int novaQuantidade;
            double novoPreco;

            cout << "Digite o novo nome do produto: ";
            cin.ignore();
            getline(cin, novoNome);
            cout << "Digite a nova quantidade: ";
            cin >> novaQuantidade;
            cout << "Digite o novo preço: ";
            cin >> novoPreco;

            produto.setNome(novoNome);
            produto.setQuantidade(novaQuantidade);
            produto.setPreco(novoPreco);

            cout << "Produto atualizado com sucesso!\n";
            return;
        }
    }

    cout << "Produto com ID " << id << " não encontrado.\n";
}

// Função para remover um produto
void removerProduto(vector<Produto>& produtos) {
    int id;
    cout << "Digite o ID do produto a ser removido: ";
    cin >> id;

    for (auto it = produtos.begin(); it != produtos.end(); ++it) {
        if (it->getId() == id) {
            produtos.erase(it);
            cout << "Produto removido com sucesso!\n";
            return;
        }
    }

    cout << "Produto com ID " << id << " não encontrado.\n";
}

// Função para gerar um relatório
void gerarRelatorio(const vector<Produto>& produtos) {
    if (produtos.empty()) {
        cout << "Nenhum produto cadastrado.\n";
        return;
    }

    double valorTotal = 0.0;
    cout << "\n=== Relatório de Estoque ===\n";
    for (const auto& produto : produtos) {
        produto.exibirProduto();
        valorTotal += produto.getQuantidade() * produto.getPreco();
    }

    cout << "Valor total do estoque: R$ " << fixed << setprecision(2) << valorTotal << endl;
}
