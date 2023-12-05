package com.atv20;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class Main{

    public static void main(String[] args) {
        String jdbcUrl = "jdbc:sua_base_de_dados://seu_servidor:porta/atv1";
        String usuario = "seu_usuario";
        String senha = "sua_senha";

        try (Connection conn = DriverManager.getConnection(jdbcUrl, usuario, senha)) {
            criarTabelasEInserirDados(conn);
            atualizarExamesPacientes(conn);

            System.out.println("Operações concluídas com sucesso.");
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    private static void criarTabelasEInserirDados(Connection conn) throws SQLException {
        // Tabela resultados_exames
        String sqlResultadosExames = "CREATE TABLE resultados_exames (" +
                "id_resultado INT PRIMARY KEY," +
                "tipo_exame VARCHAR(255)," +
                "resultado VARCHAR(255)" +
                ");" +
                "INSERT INTO resultados_exames (id_resultado, tipo_exame, resultado) VALUES (1, 'Exame de Sangue', 'Normal'), (2, 'Raio-X', 'Fratura identificada');";

        // Tabela pacientes
        String sqlPacientes = "CREATE TABLE pacientes (" +
                "id_paciente INT PRIMARY KEY," +
                "nome_paciente VARCHAR(255)," +
                "data_nascimento DATE" +
                ");" +
                "INSERT INTO pacientes (id_paciente, nome_paciente, data_nascimento) VALUES (1, 'Mariana', '1995-06-10'), (2, 'Rafael', '1987-09-25');";

        try (PreparedStatement stmtResultadosExames = conn.prepareStatement(sqlResultadosExames);
             PreparedStatement stmtPacientes = conn.prepareStatement(sqlPacientes)) {
            stmtResultadosExames.execute();
            stmtPacientes.execute();
        }
    }

    private static void atualizarExamesPacientes(Connection conn) throws SQLException {
        // Atualizar informações do exame com id_resultado = 1
        atualizarExame(conn, 1, "Exame de Sangue - Atualizado", "Resultado Alterado");

        // Adicionar um novo exame e paciente associado
        adicionarNovoExame(conn, "Tomografia", "Anomalia identificada", "Laura", "1990-03-15");

        // Atualizar informações do paciente com id_paciente = 2
        atualizarPaciente(conn, 2, "Rafael Silva", "1987-09-20");
    }

    private static void atualizarExame(Connection conn, int idResultado, String novoTipoExame, String novoResultado) throws SQLException {
        String sqlUpdateExame = "UPDATE resultados_exames SET tipo_exame = ?, resultado = ? WHERE id_resultado = ?";

        try (PreparedStatement stmtUpdateExame = conn.prepareStatement(sqlUpdateExame)) {
            stmtUpdateExame.setString(1, novoTipoExame);
            stmtUpdateExame.setString(2, novoResultado);
            stmtUpdateExame.setInt(3, idResultado);
            stmtUpdateExame.executeUpdate();
        }
    }

    private static void adicionarNovoExame(Connection conn, String tipoExame, String resultadoExame, String nomePaciente, String dataNascimento) throws SQLException {
        String sqlInsertExame = "INSERT INTO resultados_exames (tipo_exame, resultado) VALUES (?, ?)";
        String sqlInsertPaciente = "INSERT INTO pacientes (nome_paciente, data_nascimento) VALUES (?, ?)";
        String sqlInsertRelacao = "INSERT INTO pacientes_resultados_exames (id_paciente, id_resultado) VALUES (?, ?)";

        try (PreparedStatement stmtInsertExame = conn.prepareStatement(sqlInsertExame, PreparedStatement.RETURN_GENERATED_KEYS);
             PreparedStatement stmtInsertPaciente = conn.prepareStatement(sqlInsertPaciente, PreparedStatement.RETURN_GENERATED_KEYS);
             PreparedStatement stmtInsertRelacao = conn.prepareStatement(sqlInsertRelacao)) {

            // Adiciona o novo exame
            stmtInsertExame.setString(1, tipoExame);
            stmtInsertExame.setString(2, resultadoExame);
            stmtInsertExame.executeUpdate();

            // Obtém o ID do novo exame gerado
            int novoIdExame;
            try (var resultSet = stmtInsertExame.getGeneratedKeys()) {
                resultSet.next();
                novoIdExame = resultSet.getInt(1);
            }

            // Adiciona o novo paciente
            stmtInsertPaciente.setString(1, nomePaciente);
            stmtInsertPaciente.setString(2, dataNascimento);
            stmtInsertPaciente.executeUpdate();

            // Obtém o ID do novo paciente gerado
            int novoIdPaciente;
            try (var resultSet = stmtInsertPaciente.getGeneratedKeys()) {
                resultSet.next();
                novoIdPaciente = resultSet.getInt(1);
            }

            // Adiciona a relação entre paciente e exame
            stmtInsertRelacao.setInt(1, novoIdPaciente);
            stmtInsertRelacao.setInt(2, novoIdExame);
            stmtInsertRelacao.executeUpdate();
        }
    }

    private static void atualizarPaciente(Connection conn, int idPaciente, String novoNome, String novaData) throws SQLException {
        String sqlUpdatePaciente = "UPDATE pacientes SET nome_paciente = ?, data_nascimento = ? WHERE id_paciente = ?";

        try (PreparedStatement stmtUpdatePaciente = conn.prepareStatement(sqlUpdatePaciente)) {
            stmtUpdatePaciente.setString(1, novoNome);
            stmtUpdatePaciente.setString(2, novaData);
            stmtUpdatePaciente.setInt(3, idPaciente);
            stmtUpdatePaciente.executeUpdate();
        }
    }
}
