<?php

require_once 'config.php';

$request_method = $_SERVER["REQUEST_METHOD"];

switch($request_method) {
    case 'POST':
        if (isset($_GET['alunos'])) {
            // Obter os dados do aluno da solicitação POST
            $aluno = json_decode(file_get_contents('php://input'), true);

            // Adicionar os dados do aluno à tabela `alunos`
            $stmt = $pdo->prepare('INSERT INTO alunos (id_aluno, nome, turma) VALUES (:id_aluno, :nome, :turma)');
            $stmt->execute($aluno);

            // Responder com o ID do aluno inserido
            echo json_encode(['id_aluno' => $pdo->lastInsertId()]);
        } elseif (isset($_GET['cursos'])) {
            // Obter os dados do curso da solicitação POST
            $curso = json_decode(file_get_contents('php://input'), true);

            // Adicionar os dados do curso à tabela `cursos`
            $stmt = $pdo->prepare('INSERT INTO cursos (id_curso, nome_curso, instrutor) VALUES (:id_curso, :nome_curso, :instrutor)');
            $stmt->execute($curso);

            // Responder com o ID do curso inserido
            echo json_encode(['id_curso' => $pdo->lastInsertId()]);
        } elseif (isset($_GET['matriculas'])) {
            // Obter os dados da matrícula da solicitação POST
            $matricula = json_decode(file_get_contents('php://input'), true);

            // Vincular o aluno ao curso na tabela `matriculas`
            $stmt = $pdo->prepare('INSERT INTO matriculas (id_aluno, id_curso) VALUES (:id_aluno, :id_curso)');
            $stmt->execute($matricula);

            // Responder com a confirmação de que a matrícula foi criada
            echo json_encode(['success' => true]);
        } else {
            // Caso contrário, responder com um erro
            http_response_code(400);
            echo json_encode(['error' => 'Bad request']);
        }
        break;
    default:
        // Caso contrário, responder com um erro
        http_response_code(405);
        echo json_encode(['error' => 'Method not allowed']);
}