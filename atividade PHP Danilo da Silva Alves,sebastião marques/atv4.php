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

// Dados do funcionário a serem inseridos na tabela "funcionarios"
$id_funcionario = 1;
$nome = "Maria Santos";
$cargo = "Gerente";

// Construção da consulta SQL para inserir um novo registro na tabela "funcionarios"
$sql = "INSERT INTO funcionarios (id_funcionario, nome, cargo) VALUES ('$id_funcionario', '$nome', '$cargo')";

// Executa a consulta e exibe mensagem de sucesso ou erro
if ($conn->query($sql) === TRUE) {
    echo "Novo registro de funcionário criado com sucesso";
} else {
    echo "Erro: " . $sql . "<br>" . $conn->error;
}

// Dados do departamento a serem inseridos na tabela "departamentos"
$id_departamento = 1;
$nome_departamento = "Financeiro";

// Construção da consulta SQL para inserir um novo registro na tabela "departamentos"
$sql = "INSERT INTO departamentos (id_departamento, nome_departamento) VALUES ('$id_departamento', '$nome_departamento')";

// Executa a consulta e exibe mensagem de sucesso ou erro
if ($conn->query($sql) === TRUE) {
    echo "Novo registro de departamento criado com sucesso";
} else {
    echo "Erro: " . $sql . "<br>" . $conn->error;
}

// Fecha a conexão com o banco de dados
$conn->close();
?>
