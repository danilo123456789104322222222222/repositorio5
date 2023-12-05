package com.atv3;

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

            // Atualizar informações do cliente
            atualizarCliente(connection, 1, "Ana Silva", "ana.silva@example.com");
            atualizarCliente(connection, 2, "Pedro Oliveira", "pedro.oliveira@example.com");

            // Atualizar informações da venda associada ao cliente 1
            atualizarVenda(connection, 1, "Novo Celular", 1300.00);

            // Atualizar informações da venda associada ao cliente 2
            atualizarVenda(connection, 2, "Fones Pro", 180.00);

            System.out.println("Informações atualizadas com sucesso.");

        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    private static void criarTabelas(Connection connection) throws SQLException {
        String sqlClientes = "CREATE TABLE IF NOT EXISTS clientes (" +
                "id_cliente INT PRIMARY KEY," +
                "nome VARCHAR(255) NOT NULL," +
                "email VARCHAR(255) NOT NULL" +
                ")";

        String sqlVendas = "CREATE TABLE IF NOT EXISTS vendas (" +
                "id_venda INT PRIMARY KEY," +
                "id_cliente INT," +
                "produto_vendido VARCHAR(255) NOT NULL," +
                "valor DECIMAL(10, 2) NOT NULL," +
                "FOREIGN KEY (id_cliente) REFERENCES clientes(id_cliente)" +
                ")";

        try (Statement statement = connection.createStatement()) {
            statement.executeUpdate(sqlClientes);
            statement.executeUpdate(sqlVendas);
        }
    }

    private static void inserirDados(Connection connection) throws SQLException {
        // Inserir dados nas tabelas
        String sqlInsertClientes = "INSERT INTO clientes (id_cliente, nome, email) VALUES " +
                "(1, 'Ana', 'ana@example.com'), " +
                "(2, 'Pedro', 'pedro@example.com')";

        String sqlInsertVendas = "INSERT INTO vendas (id_venda, id_cliente, produto_vendido, valor) VALUES " +
                "(1, 1, 'Celular', 1200.00), " +
                "(2, 2, 'Fones', 150.00)";

        try (Statement statement = connection.createStatement()) {
            statement.executeUpdate(sqlInsertClientes);
            statement.executeUpdate(sqlInsertVendas);
        }
    }

    private static void atualizarCliente(Connection connection, int idCliente, String novoNome, String novoEmail)
            throws SQLException {
        String sql = "UPDATE clientes SET nome = ?, email = ? WHERE id_cliente = ?";

        try (PreparedStatement preparedStatement = connection.prepareStatement(sql)) {
            preparedStatement.setString(1, novoNome);
            preparedStatement.setString(2, novoEmail);
            preparedStatement.setInt(3, idCliente);

            preparedStatement.executeUpdate();
        }
    }

    private static void atualizarVenda(Connection connection, int idCliente, String novoProduto, double novoValor)
            throws SQLException {
        String sql = "UPDATE vendas SET produto_vendido = ?, valor = ? WHERE id_cliente = ?";

        try (PreparedStatement preparedStatement = connection.prepareStatement(sql)) {
            preparedStatement.setString(1, novoProduto);
            preparedStatement.setDouble(2, novoValor);
            preparedStatement.setInt(3, idCliente);

            preparedStatement.executeUpdate();
        }
    }
}

