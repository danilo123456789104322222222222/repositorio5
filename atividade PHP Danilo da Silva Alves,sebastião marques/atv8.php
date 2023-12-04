<?php

// Parâmetros de conexão com o banco de dados
$servername = "localhost";
$username = "username";
$password = "password";
$dbname = "meu_banco_de_dados";

// Criar uma nova conexão
$conn = new mysqli($servername, $username, $password, $dbname);

// Verificar se a conexão foi estabelecida com sucesso
if ($conn->connect_error) {
    die("Conexão falhou: " . $conn->connect_error);
}

// Adicionar Fornecedor
$sql = "INSERT INTO fornecedores (id_fornecedor, nome, contato) VALUES (?, ?, ?)";

// Preparar a consulta SQL
$stmt = $conn->prepare($sql);

// Vincular parâmetros da consulta
$stmt->bind_param("iss", $id_fornecedor, $nome, $contato);

// Definir valores dos parâmetros
$id_fornecedor = 1;
$nome = "Fornecedor A";
$contato = "Contato A";

// Executar a consulta
$stmt->execute();

// Adicionar Compra
$sql = "INSERT INTO compras (id_compra, id_fornecedor, produto, quantidade, preco) VALUES (?, ?, ?, ?, ?)";

// Preparar a consulta SQL
$stmt = $conn->prepare($sql);

// Vincular parâmetros da consulta
$stmt->bind_param("iisssd", $id_compra, $id_fornecedor, $produto, $quantidade, $preco);

// Definir valores dos parâmetros
$id_compra = 1;
$id_fornecedor = 1;
$produto = "Produto A";
$quantidade = 10;
$preco = 100.00;

// Executar a consulta
$stmt->execute();

// Fechar a conexão com o banco de dados
$conn->close();

?>
