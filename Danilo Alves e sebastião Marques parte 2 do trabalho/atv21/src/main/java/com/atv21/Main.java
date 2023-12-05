package com.atv21;

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
            atualizarUsuariosCompras(conn);

            System.out.println("Operações concluídas com sucesso.");
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    private static void criarTabelasEInserirDados(Connection conn) throws SQLException {
        // Tabela usuarios
        String sqlUsuarios = "CREATE TABLE usuarios (" +
                "id_usuario INT PRIMARY KEY," +
                "nome VARCHAR(255)," +
                "email VARCHAR(255)" +
                ");" +
                "INSERT INTO usuarios (id_usuario, nome, email) VALUES (3, 'Eduardo', 'eduardo@example.com'), (4, 'Laura', 'laura@example.com');";

        // Tabela compras
        String sqlCompras = "CREATE TABLE compras (" +
                "id_compra INT PRIMARY KEY," +
                "id_usuario INT," +
                "produto_comprado VARCHAR(255)," +
                "quantidade INT," +
                "FOREIGN KEY (id_usuario) REFERENCES usuarios(id_usuario)" +
                ");" +
                "INSERT INTO compras (id_compra, id_usuario, produto_comprado, quantidade) VALUES (3, 3, 'Livro de Ficção', 3), (4, 4, 'Fones de Ouvido', 1);";

        try (PreparedStatement stmtUsuarios = conn.prepareStatement(sqlUsuarios);
             PreparedStatement stmtCompras = conn.prepareStatement(sqlCompras)) {
            stmtUsuarios.execute();
            stmtCompras.execute();
        }
    }

    private static void atualizarUsuariosCompras(Connection conn) throws SQLException {
        // Atualizar informações do usuário com id_usuario = 3
        atualizarUsuario(conn, 3, "Eduardo Silva", "eduardo.silva@example.com");

        // Adicionar um novo usuário e compra associada
        adicionarNovoUsuario(conn, "Camila", "camila@example.com", "Smartphone", 2);

        // Atualizar informações da compra com id_compra = 4
        atualizarCompra(conn, 4, "Fones de Ouvido - Versão Pro", 2);
    }

    private static void atualizarUsuario(Connection conn, int idUsuario, String novoNome, String novoEmail) throws SQLException {
        String sqlUpdateUsuario = "UPDATE usuarios SET nome = ?, email = ? WHERE id_usuario = ?";

        try (PreparedStatement stmtUpdateUsuario = conn.prepareStatement(sqlUpdateUsuario)) {
            stmtUpdateUsuario.setString(1, novoNome);
            stmtUpdateUsuario.setString(2, novoEmail);
            stmtUpdateUsuario.setInt(3, idUsuario);
            stmtUpdateUsuario.executeUpdate();
        }
    }

    private static void adicionarNovoUsuario(Connection conn, String nome, String email, String produtoComprado, int quantidade) throws SQLException {
        String sqlInsertUsuario = "INSERT INTO usuarios (nome, email) VALUES (?, ?)";
        String sqlInsertCompra = "INSERT INTO compras (id_usuario, produto_comprado, quantidade) VALUES (?, ?, ?)";

        try (PreparedStatement stmtInsertUsuario = conn.prepareStatement(sqlInsertUsuario, PreparedStatement.RETURN_GENERATED_KEYS);
             PreparedStatement stmtInsertCompra = conn.prepareStatement(sqlInsertCompra)) {

            // Adiciona o novo usuário
            stmtInsertUsuario.setString(1, nome);
            stmtInsertUsuario.setString(2, email);
            stmtInsertUsuario.executeUpdate();

            // Obtém o ID do novo usuário gerado
            int novoIdUsuario;
            try (var resultSet = stmtInsertUsuario.getGeneratedKeys()) {
                resultSet.next();
                novoIdUsuario = resultSet.getInt(1);
            }

            // Adiciona a nova compra associada ao usuário
            stmtInsertCompra.setInt(1, novoIdUsuario);
            stmtInsertCompra.setString(2, produtoComprado);
            stmtInsertCompra.setInt(3, quantidade);
            stmtInsertCompra.executeUpdate();
        }
    }

    private static void atualizarCompra(Connection conn, int idCompra, String novoProduto, int novaQuantidade) throws SQLException {
        String sqlUpdateCompra = "UPDATE compras SET produto_comprado = ?, quantidade = ? WHERE id_compra = ?";

        try (PreparedStatement stmtUpdateCompra = conn.prepareStatement(sqlUpdateCompra)) {
            stmtUpdateCompra.setString(1, novoProduto);
            stmtUpdateCompra.setInt(2, novaQuantidade);
            stmtUpdateCompra.setInt(3, idCompra);
            stmtUpdateCompra.executeUpdate();
        }
    }
}
