package com.atv19;

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
            atualizarEventosParticipantes(conn);

            System.out.println("Operações concluídas com sucesso.");
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    private static void criarTabelasEInserirDados(Connection conn) throws SQLException {
        // Tabela eventos
        String sqlEventos = "CREATE TABLE eventos (" +
                "id_evento INT PRIMARY KEY," +
                "nome_evento VARCHAR(255)," +
                "data DATE" +
                ");" +
                "INSERT INTO eventos (id_evento, nome_evento, data) VALUES (1, 'Conferência de Tecnologia', '2023-12-15'), (2, 'Workshop de Marketing Digital', '2023-11-20');";

        // Tabela participantes
        String sqlParticipantes = "CREATE TABLE participantes (" +
                "id_participante INT PRIMARY KEY," +
                "id_evento INT," +
                "nome_participante VARCHAR(255)," +
                "FOREIGN KEY (id_evento) REFERENCES eventos(id_evento)" +
                ");" +
                "INSERT INTO participantes (id_participante, id_evento, nome_participante) VALUES (1, 1, 'Gabriel'), (2, 2, 'Sofia');";

        try (PreparedStatement stmtEventos = conn.prepareStatement(sqlEventos);
             PreparedStatement stmtParticipantes = conn.prepareStatement(sqlParticipantes)) {
            stmtEventos.execute();
            stmtParticipantes.execute();
        }
    }

    private static void atualizarEventosParticipantes(Connection conn) throws SQLException {
        // Atualizar informações do evento com id_evento = 1
        atualizarEvento(conn, 1, "Conferência de Tecnologia 2.0", "2023-12-16");

        // Adicionar um novo evento e participante associado
        adicionarNovoEvento(conn, "Semana de Inovação", "2023-11-25", "Joana");

        // Atualizar informações do participante com id_participante = 2
        atualizarParticipante(conn, 2, "Sofia Silva");
    }

    private static void atualizarEvento(Connection conn, int idEvento, String novoNome, String novaData) throws SQLException {
        String sqlUpdateEvento = "UPDATE eventos SET nome_evento = ?, data = ? WHERE id_evento = ?";

        try (PreparedStatement stmtUpdateEvento = conn.prepareStatement(sqlUpdateEvento)) {
            stmtUpdateEvento.setString(1, novoNome);
            stmtUpdateEvento.setString(2, novaData);
            stmtUpdateEvento.setInt(3, idEvento);
            stmtUpdateEvento.executeUpdate();
        }
    }

    private static void adicionarNovoEvento(Connection conn, String nomeEvento, String dataEvento, String nomeParticipante) throws SQLException {
        String sqlInsertEvento = "INSERT INTO eventos (nome_evento, data) VALUES (?, ?)";
        String sqlInsertParticipante = "INSERT INTO participantes (id_evento, nome_participante) VALUES (?, ?)";

        try (PreparedStatement stmtInsertEvento = conn.prepareStatement(sqlInsertEvento, PreparedStatement.RETURN_GENERATED_KEYS);
             PreparedStatement stmtInsertParticipante = conn.prepareStatement(sqlInsertParticipante)) {

            // Adiciona o novo evento
            stmtInsertEvento.setString(1, nomeEvento);
            stmtInsertEvento.setString(2, dataEvento);
            stmtInsertEvento.executeUpdate();

            // Obtém o ID do novo evento gerado
            int novoIdEvento;
            try (var resultSet = stmtInsertEvento.getGeneratedKeys()) {
                resultSet.next();
                novoIdEvento = resultSet.getInt(1);
            }

            // Adiciona o novo participante associado ao evento
            stmtInsertParticipante.setInt(1, novoIdEvento);
            stmtInsertParticipante.setString(2, nomeParticipante);
            stmtInsertParticipante.executeUpdate();
        }
    }

    private static void atualizarParticipante(Connection conn, int idParticipante, String novoNome) throws SQLException {
        String sqlUpdateParticipante = "UPDATE participantes SET nome_participante = ? WHERE id_participante = ?";

        try (PreparedStatement stmtUpdateParticipante = conn.prepareStatement(sqlUpdateParticipante)) {
            stmtUpdateParticipante.setString(1, novoNome);
            stmtUpdateParticipante.setInt(2, idParticipante);
            stmtUpdateParticipante.executeUpdate();
        }
    }
}
