#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;
#include <locale>

// Classe Produto
class Produto {
private:
    int id;
    string nome;
    int quantidade;
    double preco;

public:
    // Construtor
    Produto(int id, const string& nome, int quantidade, double preco)
        : id(id), nome(nome), quantidade(quantidade), preco(preco) {}

    // Métodos Getters
    int getId() const { return id; }
    string getNome() const { return nome; }
    int getQuantidade() const { return quantidade; }
    double getPreco() const { return preco; }
  
    // Métodos Setters
    void setQuantidade(int novaQuantidade) { quantidade = novaQuantidade; }
    void setPreco(double novoPreco) { preco = novoPreco; }
    void setNome(const string& novoNome) { nome = novoNome; }

    // Exibir informações do produto
    void exibirProduto() const {
        cout << "ID: " << id
             << " | Nome: " << nome
             << " | Quantidade: " << quantidade
             << " | Preço: R$ " << fixed << setprecision(2) << preco << endl;
    }
};

// Funções principais
void exibirMenu();
void cadastrarProduto(vector<Produto>& produtos, int& proximoId);
void listarProdutos(const vector<Produto>& produtos);
void buscarProduto(const vector<Produto>& produtos);
void atualizarProduto(vector<Produto>& produtos);
void removerProduto(vector<Produto>& produtos);
void gerarRelatorio(const vector<Produto>& produtos);

int main() {
    std::setlocale(LC_ALL, "pt_BR.UTF-8");

    vector<Produto> produtos; // Armazena os produtos
    int proximoId = 1; // Gerador de IDs automáticos
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
    cout << "\n===== Gerenciador de Estoque =====\n";
    cout << "1. Cadastrar Produto\n";
    cout << "2. Listar Produtos\n";
    cout << "3. Buscar Produto\n";
    cout << "4. Atualizar Produto\n";
    cout << "5. Remover Produto\n";
    cout << "6. Gerar Relatório\n";
    cout << "7. Sair\n";
    cout << "=================================\n";
}

// Função para cadastrar um produto
void cadastrarProduto(vector<Produto>& produtos, int& proximoId) {
    string nome;
    int quantidade;
    double preco;

    cout << "\n--- Cadastro de Produto ---\n";
    cout << "Nome: ";
    cin.ignore(); // Limpa o buffer
    getline(cin, nome);
    cout << "Quantidade: ";
    cin >> quantidade;
    cout << "Preço: ";
    cin >> preco;

    produtos.emplace_back(proximoId++, nome, quantidade, preco);
    cout << "Produto cadastrado com sucesso!\n";
}

// Função para listar todos os produtos
void listarProdutos(const vector<Produto>& produtos) {
    cout << "\n--- Lista de Produtos ---\n";
    if (produtos.empty()) {
        cout << "Nenhum produto cadastrado.\n";
        return;
    }
    for (const auto& produto : produtos) {
        produto.exibirProduto();
    }
}

// Função para buscar um produto pelo ID
void buscarProduto(const vector<Produto>& produtos) {
    int idBusca;
    cout << "\n--- Buscar Produto ---\n";
    cout << "Digite o ID do produto: ";
    cin >> idBusca;

    for (const auto& produto : produtos) {
        if (produto.getId() == idBusca) {
            cout << "Produto encontrado:\n";
            produto.exibirProduto();
            return;
        }
    }
    cout << "Produto com ID " << idBusca << " não encontrado.\n";
}

// Função para atualizar um produto
void atualizarProduto(vector<Produto>& produtos) {
    int idAtualizar;
    cout << "\n--- Atualizar Produto ---\n";
    cout << "Digite o ID do produto: ";
    cin >> idAtualizar;

    for (auto& produto : produtos) {
        if (produto.getId() == idAtualizar) {
            cout << "Produto encontrado:\n";
            produto.exibirProduto();

            int novaQuantidade;
            double novoPreco;
            string novoNome;

            cout << "Novo nome (deixe vazio para manter): ";
            cin.ignore();
            getline(cin, novoNome);
            cout << "Nova quantidade: ";
            cin >> novaQuantidade;
            cout << "Novo preço: ";
            cin >> novoPreco;

            if (!novoNome.empty()) produto.setNome(novoNome);
            produto.setQuantidade(novaQuantidade);
            produto.setPreco(novoPreco);

            cout << "Produto atualizado com sucesso!\n";
            return;
        }
    }
    cout << "Produto com ID " << idAtualizar << " não encontrado.\n";
}

// Função para remover um produto
void removerProduto(vector<Produto>& produtos) {
    int idRemover;
    cout << "\n--- Remover Produto ---\n";
    cout << "Digite o ID do produto: ";
    cin >> idRemover;

    for (auto it = produtos.begin(); it != produtos.end(); ++it) {
        if (it->getId() == idRemover) {
            produtos.erase(it);
            cout << "Produto removido com sucesso!\n";
            return;
        }
    }
    cout << "Produto com ID " << idRemover << " não encontrado.\n";
}

// Função para gerar relatório
void gerarRelatorio(const vector<Produto>& produtos) {
    cout << "\n--- Relatório de Estoque ---\n";
    double valorTotal = 0.0;

    for (const auto& produto : produtos) {
        valorTotal += produto.getQuantidade() * produto.getPreco();
    }

    cout << "Valor total do estoque: R$ " << fixed << setprecision(2) << valorTotal << endl;
}
