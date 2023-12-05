// Danilo alves, Sebastião marques

package com.atv25;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class Main {

    public static void main(String[] args) {
        String jdbcUrl = "jdbc:sua_base_de_dados://seu_servidor:porta/atv1";
        String usuario = "root";
        String senha = "";

        try (Connection conn = DriverManager.getConnection(jdbcUrl, usuario, senha)) {
            criarTabelasEInserirDados(conn);
            atualizarVendedoresVendas(conn);

            System.out.println("Operações concluídas com sucesso.");
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    private static void criarTabelasEInserirDados(Connection conn) throws SQLException {
        // Tabela vendedores
        String sqlVendedores = "CREATE TABLE vendedores (" +
                "id_vendedor INT PRIMARY KEY," +
                "nome VARCHAR(255)," +
                "area_atuacao VARCHAR(255)" +
                ");" +
                "INSERT INTO vendedores (id_vendedor, nome, area_atuacao) VALUES (3, 'Carlos', 'Eletrônicos'), (4, 'Sofia', 'Moda');";

        // Tabela vendas
        String sqlVendas = "CREATE TABLE vendas (" +
                "id_venda INT PRIMARY KEY," +
                "id_vendedor INT," +
                "produto_vendido VARCHAR(255)," +
                "valor DECIMAL(10, 2)," +
                "FOREIGN KEY (id_vendedor) REFERENCES vendedores(id_vendedor)" +
                ");" +
                "INSERT INTO vendas (id_venda, id_vendedor, produto_vendido, valor) VALUES (3, 3, 'Smartphone', 1500.00), (4, 4, 'Vestido', 120.00);";

        try (PreparedStatement stmtVendedores = conn.prepareStatement(sqlVendedores);
             PreparedStatement stmtVendas = conn.prepareStatement(sqlVendas)) {
            stmtVendedores.execute();
            stmtVendas.execute();
        }
    }

    private static void atualizarVendedoresVendas(Connection conn) throws SQLException {
        // Atualizar informações do vendedor com id_vendedor = 3
        atualizarVendedor(conn, 3, "Carlos Silva", "Eletrônicos e Eletrodomésticos");

        // Adicionar um novo vendedor e venda associada
        adicionarNovoVendedor(conn, "Mariana", "Decoração", "Cortinas", 80.00);

        // Atualizar informações da venda com id_venda = 4
        atualizarVenda(conn, 4, "Vestido - Edição Especial", 150.00);
    }

    private static void atualizarVendedor(Connection conn, int idVendedor, String novoNome, String novaAreaAtuacao) throws SQLException {
        String sqlUpdateVendedor = "UPDATE vendedores SET nome = ?, area_atuacao = ? WHERE id_vendedor = ?";

        try (PreparedStatement stmtUpdateVendedor = conn.prepareStatement(sqlUpdateVendedor)) {
            stmtUpdateVendedor.setString(1, novoNome);
            stmtUpdateVendedor.setString(2, novaAreaAtuacao);
            stmtUpdateVendedor.setInt(3, idVendedor);
            stmtUpdateVendedor.executeUpdate();
        }
    }

    private static void adicionarNovoVendedor(Connection conn, String nome, String areaAtuacao, String produtoVendido, double valor) throws SQLException {
        String sqlInsertVendedor = "INSERT INTO vendedores (nome, area_atuacao) VALUES (?, ?)";
        String sqlInsertVenda = "INSERT INTO vendas (id_vendedor, produto_vendido, valor) VALUES (?, ?, ?)";

        try (PreparedStatement stmtInsertVendedor = conn.prepareStatement(sqlInsertVendedor, PreparedStatement.RETURN_GENERATED_KEYS);
             PreparedStatement stmtInsertVenda = conn.prepareStatement(sqlInsertVenda)) {

            // Adiciona o novo vendedor
            stmtInsertVendedor.setString(1, nome);
            stmtInsertVendedor.setString(2, areaAtuacao);
            stmtInsertVendedor.executeUpdate();

            // Obtém o ID do novo vendedor gerado
            int novoIdVendedor;
            try (var resultSet = stmtInsertVendedor.getGeneratedKeys()) {
                resultSet.next();
                novoIdVendedor = resultSet.getInt(1);
            }

            // Adiciona a nova venda associada ao vendedor
            stmtInsertVenda.setInt(1, novoIdVendedor);
            stmtInsertVenda.setString(2, produtoVendido);
            stmtInsertVenda.setDouble(3, valor);
            stmtInsertVenda.executeUpdate();
        }
    }

    private static void atualizarVenda(Connection conn, int idVenda, String novoProduto, double novoValor) throws SQLException {
        String sqlUpdateVenda = "UPDATE vendas SET produto_vendido = ?, valor = ? WHERE id_venda = ?";

        try (PreparedStatement stmtUpdateVenda = conn.prepareStatement(sqlUpdateVenda)) {
            stmtUpdateVenda.setString(1, novoProduto);
            stmtUpdateVenda.setDouble(2, novoValor);
            stmtUpdateVenda.setInt(3, idVenda);
            stmtUpdateVenda.executeUpdate();
        }
    }
}
