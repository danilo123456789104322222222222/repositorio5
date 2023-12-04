<?php
// Função para adicionar um produto ao banco de dados
function adicionarProduto($conexao, $nome_produto, $preco, $nome_categoria) {
    // Preparar e executar a primeira consulta para inserir o produto
    $query = "INSERT INTO produtos (nome_produto, preco) VALUES (?, ?)";
    $stmt = $conexao->prepare($query);
    $stmt->bind_param("sd", $nome_produto, $preco);
    $stmt->execute();

    // Obter o ID do produto recém-inserido
    $id_produto = $stmt->insert_id;

    // Preparar e executar a segunda consulta para inserir a categoria
    $query = "INSERT INTO categorias (nome_categoria) VALUES (?)";
    $stmt = $conexao->prepare($query);
    $stmt->bind_param("s", $nome_categoria);
    $stmt->execute();

    // Obter o ID da categoria recém-inserida
    $id_categoria = $stmt->insert_id;

    // Preparar e executar a terceira consulta para associar o produto à categoria
    $query = "INSERT INTO produtos_categorias (id_produto, id_categoria) VALUES (?, ?)";
    $stmt = $conexao->prepare($query);
    $stmt->bind_param("ii", $id_produto, $id_categoria);
    $stmt->execute();
}

// Criar uma conexão com o banco de dados
$conexao = new mysqli("localhost", "usuario", "senha", "meu_banco_de_dados");

// Verificar se houve algum erro na conexão
if ($conexao->connect_error) {
    die("Erro de conexão: " . $conexao->connect_error);
}

// Chamar a função adicionarProduto para inserir um exemplo de produto
adicionarProduto($conexao, "Produto Exemplo", 100.0, "Categoria Exemplo");

// Fechar a conexão com o banco de dados
$conexao->close();
?>
