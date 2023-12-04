<?php
// Definição dos parâmetros de conexão com o banco de dados
$servername = "localhost";
$username = "username";
$password = "password";
$dbname = "meu_banco_de_dados";

// Criação de uma nova instância de conexão com o banco de dados
$conn = new mysqli($servername, $username, $password, $dbname);

// Verifica se a conexão foi estabelecida com sucesso
if ($conn->connect_error) {
    // Encerra o script e exibe uma mensagem de erro em caso de falha na conexão
    die("Conexão falhou: " . $conn->connect_error);
}

// Dados do cliente a serem inseridos na tabela "clientes"
$id_cliente = 1;
$nome = "João Silva";
$email = "joao.silva@email.com";

// Construção da consulta SQL para inserir um novo registro na tabela "clientes"
$sql = "INSERT INTO clientes (id_cliente, nome, email) VALUES ('$id_cliente', '$nome', '$email')";

// Executa a consulta e exibe mensagem de sucesso ou erro
if ($conn->query($sql) === TRUE) {
    echo "Novo registro de cliente criado com sucesso";
} else {
    echo "Erro: " . $sql . "<br>" . $conn->error;
}

// Dados da venda a serem inseridos na tabela "vendas"
$id_venda = 1;
$produto_vendido = "Produto X";
$valor = 100.00;

// Construção da consulta SQL para inserir um novo registro na tabela "vendas"
$sql = "INSERT INTO vendas (id_venda, id_cliente, produto_vendido, valor) VALUES ('$id_venda', '$id_cliente', '$produto_vendido', '$valor')";

// Executa a consulta e exibe mensagem de sucesso ou erro
if ($conn->query($sql) === TRUE) {
    echo "Novo registro de venda criado com sucesso";
} else {
    echo "Erro: " . $sql . "<br>" . $conn->error;
}

// Fecha a conexão com o banco de dados
$conn->close();
?>
