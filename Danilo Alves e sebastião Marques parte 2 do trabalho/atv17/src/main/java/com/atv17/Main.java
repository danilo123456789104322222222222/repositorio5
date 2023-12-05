package com.atv17;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class Main {

    public static void main(String[] args) {
        String jdbcUrl = "jdbc:sua_base_de_dados://seu_servidor:porta/atv1";
        String usuario = "seu_usuario";
        String senha = "sua_senha";

        try (Connection conn = DriverManager.getConnection(jdbcUrl, usuario, senha)) {
            criarTabelasEInserirDados(conn);
            atualizarFornecedores(conn);
            atualizarCompras(conn);

            System.out.println("Operações concluídas com sucesso.");
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    private static void criarTabelasEInserirDados(Connection conn) throws SQLException {
        String sqlFornecedores = "CREATE TABLE fornecedores (" +
                "id_fornecedor INT PRIMARY KEY," +
                "nome VARCHAR(255)," +
                "contato VARCHAR(255)" +
                ");" +
                "INSERT INTO fornecedores (id_fornecedor, nome, contato) VALUES (1, 'Empresa A', 'contato@empresaA.com'), (2, 'Empresa B', 'contato@empresaB.com');";

        String sqlCompras = "CREATE TABLE compras (" +
                "id_compra INT PRIMARY KEY," +
                "id_fornecedor INT," +
                "produto_comprado VARCHAR(255)," +
                "quantidade INT," +
                "FOREIGN KEY (id_fornecedor) REFERENCES fornecedores(id_fornecedor)" +
                ");" +
                "INSERT INTO compras (id_compra, id_fornecedor, produto_comprado, quantidade) VALUES (1, 1, 'Peças de computador', 100), (2, 2, 'Material de escritório', 500);";

        try (PreparedStatement stmtFornecedores = conn.prepareStatement(sqlFornecedores);
             PreparedStatement stmtCompras = conn.prepareStatement(sqlCompras)) {
            stmtFornecedores.execute();
            stmtCompras.execute();
        }
    }

    private static void atualizarFornecedores(Connection conn) throws SQLException {
        String sql = "UPDATE fornecedores SET nome = ?, contato = ? WHERE id_fornecedor = ?";

        try (PreparedStatement stmt = conn.prepareStatement(sql)) {
            stmt.setString(1, "Empresa A Atualizada");
            stmt.setString(2, "novo_contato@empresaA.com");
            stmt.setInt(3, 1);
            stmt.executeUpdate();

            stmt.setString(1, "Empresa B Atualizada");
            stmt.setString(2, "novo_contato@empresaB.com");
            stmt.setInt(3, 2);
            stmt.executeUpdate();
        }
    }

    private static void atualizarCompras(Connection conn) throws SQLException {
        String sql = "UPDATE compras SET produto_comprado = ?, quantidade = ? WHERE id_compra = ? AND id_fornecedor = ?";

        try (PreparedStatement stmt = conn.prepareStatement(sql)) {
            stmt.setString(1, "Novas Peças de Computador");
            stmt.setInt(2, 150);
            stmt.setInt(3, 1);
            stmt.setInt(4, 1);
            stmt.executeUpdate();

            stmt.setString(1, "Novo Material de Escritório");
            stmt.setInt(2, 600);
            stmt.setInt(3, 2);
            stmt.setInt(4, 2);
            stmt.executeUpdate();
        }
    }
}
