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

// cadastro_eventos.php
<?php
// Inclui o arquivo de conexão com o banco de dados
include 'connection.php';
?>

<!DOCTYPE html>
<html>
<body>

<form action="processa_eventos.php" method="post">
 Nome do Evento: <input type="text" name="nome_evento"><br>
 Data do Evento: <input type="date" name="data"><br>
 <input type="submit">
</form>

</body>
</html>

// processa_eventos.php
<?php
// Inclui o arquivo de conexão com o banco de dados
include 'connection.php';

// Obtém os dados do formulário
$nome_evento = $_POST['nome_evento'];
$data = $_POST['data'];

// Constrói a consulta SQL para inserir um novo evento
$sql = "INSERT INTO eventos (nome_evento, data) VALUES ('$nome_evento', '$data')";

// Executa a consulta e exibe mensagem de sucesso ou erro
if ($conn->query($sql) === TRUE) {
 echo "Novo evento adicionado com sucesso!";
} else {
 echo "Erro: " . $sql . "<br>" . $conn->error;
}

// Fecha a conexão com o banco de dados
$conn->close();
?>

// cadastro_participantes.php
<?php
// Inclui o arquivo de conexão com o banco de dados
include 'connection.php';
?>

<!DOCTYPE html>
<html>
<body>

<form action="processa_participantes.php" method="post">
 Nome do Participante: <input type="text" name="nome_participante"><br>
 Evento: <select name="id_evento">
    <?php
    // Consulta para obter os eventos disponíveis
    $sql = "SELECT id_evento, nome_evento FROM eventos";
    $result = $conn->query($sql);

    // Popula o dropdown com os eventos obtidos da consulta
    if ($result->num_rows > 0) {
      while ($row = $result->fetch_assoc()) {
        echo "<option value='" . $row["id_evento"] . "'>" . $row["nome_evento"] . "</option>";
      }
    } else {
      echo "0 results";
    }
    ?>
 </select><br>
 <input type="submit">
</form>

</body>
</html>

// processa_participantes.php
<?php
// Inclui o arquivo de conexão com o banco de dados
include 'connection.php';

// Obtém os dados do formulário
$nome_participante = $_POST['nome_participante'];
$id_evento = $_POST['id_evento'];

// Constrói a consulta SQL para inserir um novo participante
$sql = "INSERT INTO participantes (id_evento, nome_participante) VALUES ('$id_evento', '$nome_participante')";

// Executa a consulta e exibe mensagem de sucesso ou erro
if ($conn->query($sql) === TRUE) {
 echo "Novo participante adicionado com sucesso!";
} else {
 echo "Erro: " . $sql . "<br>" . $conn->error;
}

// Fecha a conexão com o banco de dados
$conn->close();
?>
