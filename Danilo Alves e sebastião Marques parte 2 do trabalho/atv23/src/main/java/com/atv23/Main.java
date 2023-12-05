package com.atv23;

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
            atualizarFuncionariosProjetos(conn);

            System.out.println("Operações concluídas com sucesso.");
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    private static void criarTabelasEInserirDados(Connection conn) throws SQLException {
        // Tabela funcionarios
        String sqlFuncionarios = "CREATE TABLE funcionarios (" +
                "id_funcionario INT PRIMARY KEY," +
                "nome VARCHAR(255)," +
                "cargo VARCHAR(255)" +
                ");" +
                "INSERT INTO funcionarios (id_funcionario, nome, cargo) VALUES (3, 'Pedro', 'Desenvolvedor'), (4, 'Mariana', 'Analista de Dados');";

        // Tabela projetos
        String sqlProjetos = "CREATE TABLE projetos (" +
                "id_projeto INT PRIMARY KEY," +
                "nome_projeto VARCHAR(255)," +
                "descricao VARCHAR(255)" +
                ");" +
                "INSERT INTO projetos (id_projeto, nome_projeto, descricao) VALUES (3, 'Nova Plataforma Online', 'Desenvolvimento de uma nova plataforma web'), (4, 'Análise de Dados', 'Estudo e análise de grandes conjuntos de dados');";

        try (PreparedStatement stmtFuncionarios = conn.prepareStatement(sqlFuncionarios);
             PreparedStatement stmtProjetos = conn.prepareStatement(sqlProjetos)) {
            stmtFuncionarios.execute();
            stmtProjetos.execute();
        }
    }

    private static void atualizarFuncionariosProjetos(Connection conn) throws SQLException {
        // Atualizar informações do funcionário com id_funcionario = 3
        atualizarFuncionario(conn, 3, "Pedro Silva", "Arquiteto de Software");

        // Adicionar um novo funcionário e projeto associado
        adicionarNovoFuncionario(conn, "Lucia", "Engenheira de Dados", "Projeto Big Data");

        // Atualizar informações do projeto com id_projeto = 4
        atualizarProjeto(conn, 4, "Análise de Dados - Avançado", "Estudo e análise aprofundada de grandes conjuntos de dados");
    }

    private static void atualizarFuncionario(Connection conn, int idFuncionario, String novoNome, String novoCargo) throws SQLException {
        String sqlUpdateFuncionario = "UPDATE funcionarios SET nome = ?, cargo = ? WHERE id_funcionario = ?";

        try (PreparedStatement stmtUpdateFuncionario = conn.prepareStatement(sqlUpdateFuncionario)) {
            stmtUpdateFuncionario.setString(1, novoNome);
            stmtUpdateFuncionario.setString(2, novoCargo);
            stmtUpdateFuncionario.setInt(3, idFuncionario);
            stmtUpdateFuncionario.executeUpdate();
        }
    }

    private static void adicionarNovoFuncionario(Connection conn, String nome, String cargo, String projetoAssociado) throws SQLException {
        String sqlInsertFuncionario = "INSERT INTO funcionarios (nome, cargo) VALUES (?, ?)";
        String sqlInsertProjeto = "INSERT INTO projetos (nome_projeto, descricao) VALUES (?, ?)";
        String sqlInsertRelacao = "INSERT INTO funcionarios_projetos (id_funcionario, id_projeto) VALUES (?, ?)";

        try (PreparedStatement stmtInsertFuncionario = conn.prepareStatement(sqlInsertFuncionario, PreparedStatement.RETURN_GENERATED_KEYS);
             PreparedStatement stmtInsertProjeto = conn.prepareStatement(sqlInsertProjeto, PreparedStatement.RETURN_GENERATED_KEYS);
             PreparedStatement stmtInsertRelacao = conn.prepareStatement(sqlInsertRelacao)) {

            // Adiciona o novo funcionário
            stmtInsertFuncionario.setString(1, nome);
            stmtInsertFuncionario.setString(2, cargo);
            stmtInsertFuncionario.executeUpdate();

            // Obtém o ID do novo funcionário gerado
            int novoIdFuncionario;
            try (var resultSet = stmtInsertFuncionario.getGeneratedKeys()) {
                resultSet.next();
                novoIdFuncionario = resultSet.getInt(1);
            }

            // Adiciona o novo projeto associado ao funcionário
            stmtInsertProjeto.setString(1, projetoAssociado);
            stmtInsertProjeto.setString(2, "Descrição do novo projeto");
            stmtInsertProjeto.executeUpdate();

            // Obtém o ID do novo projeto gerado
            int novoIdProjeto;
            try (var resultSet = stmtInsertProjeto.getGeneratedKeys()) {
                resultSet.next();
                novoIdProjeto = resultSet.getInt(1);
            }

            // Adiciona a relação entre funcionário e projeto
            stmtInsertRelacao.setInt(1, novoIdFuncionario);
            stmtInsertRelacao.setInt(2, novoIdProjeto);
            stmtInsertRelacao.executeUpdate();
        }
    }

    private static void atualizarProjeto(Connection conn, int idProjeto, String novoNome, String novaDescricao) throws SQLException {
        String sqlUpdateProjeto = "UPDATE projetos SET nome_projeto = ?, descricao = ? WHERE id_projeto = ?";

        try (PreparedStatement stmtUpdateProjeto = conn.prepareStatement(sqlUpdateProjeto)) {
            stmtUpdateProjeto.setString(1, novoNome);
            stmtUpdateProjeto.setString(2, novaDescricao);
            stmtUpdateProjeto.setInt(3, idProjeto);
            stmtUpdateProjeto.executeUpdate();
        }
    }
}
