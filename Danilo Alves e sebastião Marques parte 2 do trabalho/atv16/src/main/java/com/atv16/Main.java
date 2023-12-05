package com.atv16;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class Main {

    public static void main(String[] args) {
        // Configurações de conexão ao banco de dados
        String jdbcURL = "jdbc:mysql://localhost:3306/banco_de_dados";
        String username = "root";
        String password = "";

        try {
            // Carregar o driver JDBC
            Class.forName("com.mysql.cj.jdbc.Driver");

            // Estabelecer a conexão com o banco de dados
            Connection connection = DriverManager.getConnection(jdbcURL, username, password);

            // Inserir dados na tabela alunos
            inserirDadosAlunos(connection);

            // Inserir dados na tabela cursos
            inserirDadosCursos(connection);

            // Atualizar dados de alunos e cursos
            atualizarDados(connection, 1, "Lucas", "A", 1, "Matemática", "Professor Carlos");

            // Fechar a conexão
            connection.close();
        } catch (ClassNotFoundException | SQLException e) {
            e.printStackTrace();
        }
    }

    private static void inserirDadosAlunos(Connection connection) throws SQLException {
        String sql = "INSERT INTO alunos (id_aluno, nome, turma) VALUES (?, ?, ?)";

        try (PreparedStatement preparedStatement = connection.prepareStatement(sql)) {
            preparedStatement.setInt(1, 1);
            preparedStatement.setString(2, "Lucas");
            preparedStatement.setString(3, "A");
            preparedStatement.executeUpdate();

            preparedStatement.setInt(1, 2);
            preparedStatement.setString(2, "Julia");
            preparedStatement.setString(3, "B");
            preparedStatement.executeUpdate();
        }
    }

    private static void inserirDadosCursos(Connection connection) throws SQLException {
        String sql = "INSERT INTO cursos (id_curso, nome_curso, instrutor) VALUES (?, ?, ?)";

        try (PreparedStatement preparedStatement = connection.prepareStatement(sql)) {
            preparedStatement.setInt(1, 1);
            preparedStatement.setString(2, "Matemática");
            preparedStatement.setString(3, "Professor Carlos");
            preparedStatement.executeUpdate();

            preparedStatement.setInt(1, 2);
            preparedStatement.setString(2, "Ciências");
            preparedStatement.setString(3, "Professora Ana");
            preparedStatement.executeUpdate();
        }
    }

    private static void atualizarDados(Connection connection, int idAluno, String novoNome, String novaTurma,
                                       int idCurso, String novoNomeCurso, String novoInstrutor) throws SQLException {
        // Atualizar dados na tabela alunos
        String sqlUpdateAluno = "UPDATE alunos SET nome=?, turma=? WHERE id_aluno=?";
        try (PreparedStatement preparedStatement = connection.prepareStatement(sqlUpdateAluno)) {
            preparedStatement.setString(1, novoNome);
            preparedStatement.setString(2, novaTurma);
            preparedStatement.setInt(3, idAluno);
            preparedStatement.executeUpdate();
        }

        // Verificar se o curso já existe
        String sqlSelectCurso = "SELECT * FROM cursos WHERE id_curso=?";
        try (PreparedStatement preparedStatement = connection.prepareStatement(sqlSelectCurso)) {
            preparedStatement.setInt(1, idCurso);
            if (preparedStatement.executeQuery().next()) {
                // Se o curso existir, atualizar os dados
                String sqlUpdateCurso = "UPDATE cursos SET nome_curso=?, instrutor=? WHERE id_curso=?";
                try (PreparedStatement preparedStatementCurso = connection.prepareStatement(sqlUpdateCurso)) {
                    preparedStatementCurso.setString(1, novoNomeCurso);
                    preparedStatementCurso.setString(2, novoInstrutor);
                    preparedStatementCurso.setInt(3, idCurso);
                    preparedStatementCurso.executeUpdate();
                }
            } else {
                // Se o curso não existir, inserir um novo
                String sqlInsertCurso = "INSERT INTO cursos (id_curso, nome_curso, instrutor) VALUES (?, ?, ?)";
                try (PreparedStatement preparedStatementCurso = connection.prepareStatement(sqlInsertCurso)) {
                    preparedStatementCurso.setInt(1, idCurso);
                    preparedStatementCurso.setString(2, novoNomeCurso);
                    preparedStatementCurso.setString(3, novoInstrutor);
                    preparedStatementCurso.executeUpdate();
                }
            }
        }
    }
}
