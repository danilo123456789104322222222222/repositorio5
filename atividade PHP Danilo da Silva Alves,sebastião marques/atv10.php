// connection.php
<?php
// Configuração da conexão com o banco de dados
$servername = "localhost";
$username = "username";
$password = "password";
$dbname = "myDB";

// Criação de uma nova instância de conexão com o banco de dados
$conn = new mysqli($servername, $username, $password, $dbname);

// Verifica se a conexão foi estabelecida com sucesso
if ($conn->connect_error) {
 die("Connection failed: " . $conn->connect_error);
}
?>

// cadastro_pacientes.php
<?php
// Inclui o arquivo de conexão com o banco de dados
include 'connection.php';
?>

<!DOCTYPE html>
<html>
<body>

<form action="processa_pacientes.php" method="post">
 Nome do Paciente: <input type="text" name="nome_paciente"><br>
 Data de Nascimento: <input type="date" name="data_nascimento"><br>
 <input type="submit">
</form>

</body>
</html>

// processa_pacientes.php
<?php
// Inclui o arquivo de conexão com o banco de dados
include 'connection.php';

// Obtém os dados do formulário
$nome_paciente = $_POST['nome_paciente'];
$data_nascimento = $_POST['data_nascimento'];

// Constrói a consulta SQL para inserir um novo paciente
$sql = "INSERT INTO pacientes (nome_paciente, data_nascimento) VALUES ('$nome_paciente', '$data_nascimento')";

// Executa a consulta e exibe mensagem de sucesso ou erro
if ($conn->query($sql) === TRUE) {
 echo "Novo paciente adicionado com sucesso!";
} else {
 echo "Erro: " . $sql . "<br>" . $conn->error;
}

// Fecha a conexão com o banco de dados
$conn->close();
?>

// cadastro_resultados.php
<?php
// Inclui o arquivo de conexão com o banco de dados
include 'connection.php';
?>

<!DOCTYPE html>
<html>
<body>

<form action="processa_resultados.php" method="post">
 Paciente: <select name="id_paciente">
    <?php
    // Consulta para obter os pacientes disponíveis
    $sql = "SELECT id_paciente, nome_paciente FROM pacientes";
    $result = $conn->query($sql);

    // Popula o dropdown com os pacientes obtidos da consulta
    if ($result->num_rows > 0) {
      while ($row = $result->fetch_assoc()) {
        echo "<option value='" . $row["id_paciente"] . "'>" . $row["nome_paciente"] . "</option>";
      }
    } else {
      echo "0 results";
    }
    ?>
 </select><br>
 Tipo de Exame: <input type="text" name="tipo_exame"><br>
 Resultado: <input type="text" name="resultado"><br>
 <input type="submit">
</form>

</body>
</html>

// processa_resultados.php
<?php
// Inclui o arquivo de conexão com o banco de dados
include 'connection.php';

// Obtém os dados do formulário
$id_paciente = $_POST['id_paciente'];
$tipo_exame = $_POST['tipo_exame'];
$resultado = $_POST['resultado'];

// Constrói a consulta SQL para inserir um novo resultado de exame
$sql = "INSERT INTO resultados_exames (id_paciente, tipo_exame, resultado) VALUES ('$id_paciente', '$tipo_exame', '$resultado')";

// Executa a consulta e exibe mensagem de sucesso ou erro
if ($conn->query($sql) === TRUE) {
 echo "Resultado adicionado com sucesso!";
} else {
 echo "Erro: " . $sql . "<br>" . $conn->error;
}

// Fecha a conexão com o banco de dados
$conn->close();
?>
