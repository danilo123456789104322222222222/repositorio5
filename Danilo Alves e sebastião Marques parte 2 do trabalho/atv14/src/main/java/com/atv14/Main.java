package com.atv14;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.sql.Statement;

public class Main {

    public static void main(String[] args) {
        String jdbcUrl = "jdbc:mysql://localhost:3306/atv1";
        String username = "root";
        String password = "";

        try (Connection connection = DriverManager.getConnection(jdbcUrl, username, password)) {

            // Criar tabelas se não existirem
            criarTabelas(connection);

            // Inserir dados nas tabelas
            inserirDados(connection);

            // Atualizar informações do funcionário
            atualizarFuncionario(connection, 1, "Luiz Silva", "Desenvolvedor");
            atualizarFuncionario(connection, 2, "Carla Oliveira", "Diretor");

            // Atualizar informações do departamento associado ao funcionário 1
            atualizarDepartamento(connection, 1, "Desenvolvimento");

            // Atualizar informações do departamento associado ao funcionário 2
            atualizarDepartamento(connection, 2, "RH Estratégico");

            System.out.println("Informações atualizadas com sucesso.");

        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    private static void criarTabelas(Connection connection) throws SQLException {
        String sqlFuncionarios = "CREATE TABLE IF NOT EXISTS funcionarios (" +
                "id_funcionario INT PRIMARY KEY," +
                "nome VARCHAR(255) NOT NULL," +
                "cargo VARCHAR(255) NOT NULL" +
                ")";

        String sqlDepartamentos = "CREATE TABLE IF NOT EXISTS departamentos (" +
                "id_departamento INT PRIMARY KEY," +
                "nome_departamento VARCHAR(255) NOT NULL" +
                ")";

        try (Statement statement = connection.createStatement()) {
            statement.executeUpdate(sqlFuncionarios);
            statement.executeUpdate(sqlDepartamentos);
        }
    }

    private static void inserirDados(Connection connection) throws SQLException {
        // Inserir dados nas tabelas
        String sqlInsertFuncionarios = "INSERT INTO funcionarios (id_funcionario, nome, cargo) VALUES " +
                "(1, 'Luiz', 'Analista'), " +
                "(2, 'Carla', 'Gerente')";

        String sqlInsertDepartamentos = "INSERT INTO departamentos (id_departamento, nome_departamento) VALUES " +
                "(1, 'TI'), " +
                "(2, 'Recursos Humanos')";

        try (Statement statement = connection.createStatement()) {
            statement.executeUpdate(sqlInsertFuncionarios);
            statement.executeUpdate(sqlInsertDepartamentos);
        }
    }

    private static void atualizarFuncionario(Connection connection, int idFuncionario, String novoNome, String novoCargo)
            throws SQLException {
        String sql = "UPDATE funcionarios SET nome = ?, cargo = ? WHERE id_funcionario = ?";

        try (PreparedStatement preparedStatement = connection.prepareStatement(sql)) {
            preparedStatement.setString(1, novoNome);
            preparedStatement.setString(2, novoCargo);
            preparedStatement.setInt(3, idFuncionario);

            preparedStatement.executeUpdate();
        }
    }

    private static void atualizarDepartamento(Connection connection, int idDepartamento, String novoNome)
            throws SQLException {
        String sql = "UPDATE departamentos SET nome_departamento = ? WHERE id_departamento = ?";

        try (PreparedStatement preparedStatement = connection.prepareStatement(sql)) {
            preparedStatement.setString(1, novoNome);
            preparedStatement.setInt(2, idDepartamento);

            preparedStatement.executeUpdate();
        }
    }
}
