<?php
// Configurações do banco de dados (substitua os valores conforme necessário)
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "seu_banco_de_dados";

try {
    // Conexão usando PDO
    $conn = new PDO("mysql:host=$servername;dbname=$dbname", $username, $password);

    // Define o modo de erro do PDO para exceção
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

    // Criação da tabela usuarios
    $sqlUsuarios = "
    CREATE TABLE IF NOT EXISTS usuarios (
        id_usuario INT PRIMARY KEY AUTO_INCREMENT,
        nome VARCHAR(50) NOT NULL,
        email VARCHAR(100) NOT NULL
    )";

    $conn->exec($sqlUsuarios);
    echo "Tabela 'usuarios' criada com sucesso.\n";

    // Criação da tabela pedidos
    $sqlPedidos = "
    CREATE TABLE IF NOT EXISTS pedidos (
        id_pedido INT PRIMARY KEY AUTO_INCREMENT,
        id_usuario INT,
        produto VARCHAR(50) NOT NULL,
        quantidade INT NOT NULL,
        FOREIGN KEY (id_usuario) REFERENCES usuarios(id_usuario)
    )";

    $conn->exec($sqlPedidos);
    echo "Tabela 'pedidos' criada com sucesso.\n";

    // Inserção de dados de exemplo
    $sqlInserirUsuario = "INSERT INTO usuarios (nome, email) VALUES ('João', 'joao@email.com')";
    $conn->exec($sqlInserirUsuario);
    $idUsuarioInserido = $conn->lastInsertId();

    // Inserção de pedido relacionado ao usuário inserido
    $sqlInserirPedido = "INSERT INTO pedidos (id_usuario, produto, quantidade) VALUES ('$idUsuarioInserido', 'Produto A', 3)";
    $conn->exec($sqlInserirPedido);
    echo "Dados inseridos nas tabelas com sucesso!\n";

    // Inserção de mais dados de exemplo
    $sqlInserirUsuario2 = "INSERT INTO usuarios (nome, email) VALUES ('Maria', 'maria@email.com')";
    $conn->exec($sqlInserirUsuario2);
    $idUsuarioInserido2 = $conn->lastInsertId();

    // Inserção de pedido relacionado ao segundo usuário inserido
    $sqlInserirPedido2 = "INSERT INTO pedidos (id_usuario, produto, quantidade) VALUES ('$idUsuarioInserido2', 'Produto B', 2)";
    $conn->exec($sqlInserirPedido2);
    echo "Mais dados inseridos nas tabelas com sucesso!\n";
} catch (PDOException $e) {
    echo "Erro: " . $e->getMessage() . "\n";
}

// Fecha a conexão
$conn = null;
?>
