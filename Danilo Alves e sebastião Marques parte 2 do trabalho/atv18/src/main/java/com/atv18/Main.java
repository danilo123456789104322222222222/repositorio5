package com.atv18;
 
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
            atualizarLivrosAutores(conn);

            System.out.println("Operações concluídas com sucesso.");
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    private static void criarTabelasEInserirDados(Connection conn) throws SQLException {
        String sqlLivros = "CREATE TABLE livros (" +
                "id_livro INT PRIMARY KEY," +
                "titulo VARCHAR(255)," +
                "ano_publicacao INT" +
                ");" +
                "INSERT INTO livros (id_livro, titulo, ano_publicacao) VALUES (1, 'Aprendendo Python', 2020), (2, 'Introdução à Inteligência Artificial', 2019);";

        String sqlAutores = "CREATE TABLE autores (" +
                "id_autor INT PRIMARY KEY," +
                "nome_autor VARCHAR(255)" +
                ");" +
                "INSERT INTO autores (id_autor, nome_autor) VALUES (1, 'Carlos Silva'), (2, 'Ana Souza');";

        try (PreparedStatement stmtLivros = conn.prepareStatement(sqlLivros);
             PreparedStatement stmtAutores = conn.prepareStatement(sqlAutores)) {
            stmtLivros.execute();
            stmtAutores.execute();
        }
    }

    private static void atualizarLivrosAutores(Connection conn) throws SQLException {
        String sqlUpdateLivros = "UPDATE livros SET titulo = ?, ano_publicacao = ? WHERE id_livro = ?";

        try (PreparedStatement stmtUpdateLivros = conn.prepareStatement(sqlUpdateLivros)) {
            // Atualiza o livro com id_livro = 1
            stmtUpdateLivros.setString(1, "Aprendendo Python - Edição Atualizada");
            stmtUpdateLivros.setInt(2, 2022); // Novo ano de publicação
            stmtUpdateLivros.setInt(3, 1);
            stmtUpdateLivros.executeUpdate();

            // Adiciona um novo livro com autor associado
            stmtUpdateLivros.setString(1, "Novo Livro de Java");
            stmtUpdateLivros.setInt(2, 2021);
            stmtUpdateLivros.setInt(3, 3); // Novo id_livro
            stmtUpdateLivros.executeUpdate();

            // Atualiza o autor do livro com id_livro = 2
            atualizarAutores(conn, 2, "Introdução à IA - Edição Revisada", 2018, "Pedro Oliveira");
        }
    }

    private static void atualizarAutores(Connection conn, int idLivro, String novoTitulo, int novoAno, String novoAutor) throws SQLException {
        String sqlUpdateAutores = "INSERT INTO autores (id_autor, nome_autor) VALUES (?, ?) ON DUPLICATE KEY UPDATE nome_autor = ?";

        try (PreparedStatement stmtUpdateAutores = conn.prepareStatement(sqlUpdateAutores)) {
            // Adiciona ou atualiza o autor associado ao livro
            stmtUpdateAutores.setInt(1, idLivro);
            stmtUpdateAutores.setString(2, novoAutor);
            stmtUpdateAutores.setString(3, novoAutor);
            stmtUpdateAutores.executeUpdate();
        }

        // Atualiza o livro com os novos dados
        String sqlUpdateLivro = "UPDATE livros SET titulo = ?, ano_publicacao = ? WHERE id_livro = ?";

        try (PreparedStatement stmtUpdateLivro = conn.prepareStatement(sqlUpdateLivro)) {
            stmtUpdateLivro.setString(1, novoTitulo);
            stmtUpdateLivro.setInt(2, novoAno);
            stmtUpdateLivro.setInt(3, idLivro);
            stmtUpdateLivro.executeUpdate();
        }
    }
}
    
