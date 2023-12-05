package com.atv15;

import java.sql.*;

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

            // Atualizar informações do projeto
            atualizarProjeto(connection, 1, "Sistema de Controle Atualizado", "Nova descrição do sistema");

            // Atualizar informações da atribuição associada ao projeto 2
            atualizarAtribuicao(connection, 2, 2, 3);

            System.out.println("Informações atualizadas com sucesso.");

        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    private static void criarTabelas(Connection connection) throws SQLException {
        String sqlProjetos = "CREATE TABLE IF NOT EXISTS projetos (" +
                "id_projeto INT PRIMARY KEY," +
                "nome_projeto VARCHAR(255) NOT NULL," +
                "descricao VARCHAR(255) NOT NULL" +
                ")";

        String sqlAtribuicoes = "CREATE TABLE IF NOT EXISTS atribuicoes (" +
                "id_atribuicao INT PRIMARY KEY," +
                "id_projeto INT," +
                "id_funcionario INT," +
                "FOREIGN KEY (id_projeto) REFERENCES projetos(id_projeto)," +
                "FOREIGN KEY (id_funcionario) REFERENCES funcionarios(id_funcionario)" +
                ")";

        try (Statement statement = connection.createStatement()) {
            statement.executeUpdate(sqlProjetos);
            statement.executeUpdate(sqlAtribuicoes);
        }
    }

    private static void inserirDados(Connection connection) throws SQLException {
        // Inserir dados nas tabelas
        String sqlInsertProjetos = "INSERT INTO projetos (id_projeto, nome_projeto, descricao) VALUES " +
                "(1, 'Sistema de Controle', 'Desenvolvimento de um sistema interno'), " +
                "(2, 'Portal Corporativo', 'Desenvolvimento de um portal para clientes')";

        String sqlInsertAtribuicoes = "INSERT INTO atribuicoes (id_atribuicao, id_projeto, id_funcionario) VALUES " +
                "(1, 1, 1), " +
                "(2, 2, 2)";

        try (Statement statement = connection.createStatement()) {
            statement.executeUpdate(sqlInsertProjetos);
            statement.executeUpdate(sqlInsertAtribuicoes);
        }
    }

    private static void atualizarProjeto(Connection connection, int idProjeto, String novoNome, String novaDescricao)
            throws SQLException {
        String sql = "UPDATE projetos SET nome_projeto = ?, descricao = ? WHERE id_projeto = ?";

        try (PreparedStatement preparedStatement = connection.prepareStatement(sql)) {
            preparedStatement.setString(1, novoNome);
            preparedStatement.setString(2, novaDescricao);
            preparedStatement.setInt(3, idProjeto);

            preparedStatement.executeUpdate();
        }
    }

    private static void atualizarAtribuicao(Connection connection, int idAtribuicao, int novoIdProjeto, int novoIdFuncionario)
            throws SQLException {
        String sql = "UPDATE atribuicoes SET id_projeto = ?, id_funcionario = ? WHERE id_atribuicao = ?";

        try (PreparedStatement preparedStatement = connection.prepareStatement(sql)) {
            preparedStatement.setInt(1, novoIdProjeto);
            preparedStatement.setInt(2, novoIdFuncionario);
            preparedStatement.setInt(3, idAtribuicao);

            preparedStatement.executeUpdate();
        }
    }

}
