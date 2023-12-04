<?php
// Parâmetros de conexão com o banco de dados
$servername = "localhost";
$username = "username";
$password = "password";
$dbname = "meu_banco_de_dados";

// Estabelece uma nova conexão com o banco de dados MySQL
$conn = new mysqli($servername, $username, $password, $dbname);

// Verifica se a conexão foi estabelecida com sucesso
if ($conn->connect_error) {
    // Encerra o script e exibe uma mensagem de erro em caso de falha na conexão
    die("Conexão falhou: " . $conn->connect_error);
}

// Dados do projeto a serem inseridos na tabela "projetos"
$id_projeto = 1;
$nome_projeto = "Projeto A";
$descricao = "Descrição do Projeto A";

// Construção da consulta SQL para inserir um novo registro na tabela "projetos"
$sql = "INSERT INTO projetos (id_projeto, nome_projeto, descricao) VALUES ('$id_projeto', '$nome_projeto', '$descricao')";

// Executa a consulta e exibe mensagem de sucesso ou erro
if ($conn->query($sql) === TRUE) {
    echo "Novo registro de projeto criado com sucesso";
} else {
    echo "Erro: " . $sql . "<br>" . $conn->error;
}

// Dados da atribuição a serem inseridos na tabela "atribuicoes"
$id_atribuicao = 1;
$id_projeto_associado = 1;
$id_funcionario_associado = 1;

// Construção da consulta SQL para inserir um novo registro na tabela "atribuicoes"
$sql = "INSERT INTO atribuicoes (id_atribuicao, id_projeto, id_funcionario) VALUES ('$id_atribuicao', '$id_projeto_associado', '$id_funcionario_associado')";

// Executa a consulta e exibe mensagem de sucesso ou erro
if ($conn->query($sql) === TRUE) {
    echo "Nova atribuição de projeto e funcionário criada com sucesso";
} else {
    echo "Erro: " . $sql . "<br>" . $conn->error;
}

// Fecha a conexão com o banco de dados
$conn->close();
?>
