package com.atv22;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class AtualizacaoClientesPedidos {

    public static void main(String[] args) {
        String jdbcUrl = "jdbc:sua_base_de_dados://seu_servidor:porta/seu_banco_de_dados";
        String usuario = "seu_usuario";
        String senha = "sua_senha";

        try (Connection conn = DriverManager.getConnection(jdbcUrl, usuario, senha)) {
            criarTabelasEInserirDados(conn);
            atualizarClientesPedidos(conn);

            System.out.println("Operações concluídas com sucesso.");
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    private static void criarTabelasEInserirDados(Connection conn) throws SQLException {
        // Tabela clientes
        String sqlClientes = "CREATE TABLE clientes (" +
                "id_cliente INT PRIMARY KEY," +
                "nome VARCHAR(255)," +
                "email VARCHAR(255)" +
                ");" +
                "INSERT INTO clientes (id_cliente, nome, email) VALUES (3, 'Rita', 'rita@example.com'), (4, 'Gabriel', 'gabriel@example.com');";

        // Tabela pedidos
        String sqlPedidos = "CREATE TABLE pedidos (" +
                "id_pedido INT PRIMARY KEY," +
                "id_cliente INT," +
                "produto VARCHAR(255)," +
                "quantidade INT," +
                "FOREIGN KEY (id_cliente) REFERENCES clientes(id_cliente)" +
                ");" +
                "INSERT INTO pedidos (id_pedido, id_cliente, produto, quantidade) VALUES (3, 3, 'Cadeira de Escritório', 2), (4, 4, 'Mochila', 1);";

        try (PreparedStatement stmtClientes = conn.prepareStatement(sqlClientes);
             PreparedStatement stmtPedidos = conn.prepareStatement(sqlPedidos)) {
            stmtClientes.execute();
            stmtPedidos.execute();
        }
    }

    private static void atualizarClientesPedidos(Connection conn) throws SQLException {
        // Atualizar informações do cliente com id_cliente = 3
        atualizarCliente(conn, 3, "Rita Silva", "rita.silva@example.com");

        // Adicionar um novo cliente e pedido associado
        adicionarNovoCliente(conn, "Lucas", "lucas@example.com", "Notebook", 1);

        // Atualizar informações do pedido com id_pedido = 4
        atualizarPedido(conn, 4, "Mochila - Edição Especial", 2);
    }

    private static void atualizarCliente(Connection conn, int idCliente, String novoNome, String novoEmail) throws SQLException {
        String sqlUpdateCliente = "UPDATE clientes SET nome = ?, email = ? WHERE id_cliente = ?";

        try (PreparedStatement stmtUpdateCliente = conn.prepareStatement(sqlUpdateCliente)) {
            stmtUpdateCliente.setString(1, novoNome);
            stmtUpdateCliente.setString(2, novoEmail);
            stmtUpdateCliente.setInt(3, idCliente);
            stmtUpdateCliente.executeUpdate();
        }
    }

    private static void adicionarNovoCliente(Connection conn, String nome, String email, String produtoPedido, int quantidade) throws SQLException {
        String sqlInsertCliente = "INSERT INTO clientes (nome, email) VALUES (?, ?)";
        String sqlInsertPedido = "INSERT INTO pedidos (id_cliente, produto, quantidade) VALUES (?, ?, ?)";

        try (PreparedStatement stmtInsertCliente = conn.prepareStatement(sqlInsertCliente, PreparedStatement.RETURN_GENERATED_KEYS);
             PreparedStatement stmtInsertPedido = conn.prepareStatement(sqlInsertPedido)) {

            // Adiciona o novo cliente
            stmtInsertCliente.setString(1, nome);
            stmtInsertCliente.setString(2, email);
            stmtInsertCliente.executeUpdate();

            // Obtém o ID do novo cliente gerado
            int novoIdCliente;
            try (var resultSet = stmtInsertCliente.getGeneratedKeys()) {
                resultSet.next();
                novoIdCliente = resultSet.getInt(1);
            }

            // Adiciona o novo pedido associado ao cliente
            stmtInsertPedido.setInt(1, novoIdCliente);
            stmtInsertPedido.setString(2, produtoPedido);
            stmtInsertPedido.setInt(3, quantidade);
            stmtInsertPedido.executeUpdate();
        }
    }

    private static void atualizarPedido(Connection conn, int idPedido, String novoProduto, int novaQuantidade) throws SQLException {
        String sqlUpdatePedido = "UPDATE pedidos SET produto = ?, quantidade = ? WHERE id_pedido = ?";

        try (PreparedStatement stmtUpdatePedido = conn.prepareStatement(sqlUpdatePedido)) {
            stmtUpdatePedido.setString(1, novoProduto);
            stmtUpdatePedido.setInt(2, novaQuantidade);
            stmtUpdatePedido.setInt(3, idPedido);
            stmtUpdatePedido.executeUpdate();
        }
    }
}
