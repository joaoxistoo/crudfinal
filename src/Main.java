import java.util.Scanner;

public class Main {

    static final int MAX_ALUNOS = 1000;
    static final int MAX_DISCIPLINAS = 1000;
    static final int MAX_CRIACAO = 1000;

    static int contadorCriacao = 0;
    static int contadorDeAlunos = 0;
    static int contadorDeDisciplinas = 0;
    static CriacaoDisciplina[] criacoes = new CriacaoDisciplina[MAX_CRIACAO];

    static Scanner scanner = new Scanner(System.in);

    static class Aluno {
        int id;
        String matricula;
        String nome;
        String cpf;
        String sexo;
        String email;
    }

    static class Disciplina {
        String codigoDisciplina;
        String codigoTipoCurso;
        String nomeDisciplina;
        String nomeProfessor;
    }

    static class CriacaoDisciplina {
        // matricula, codigoDisciplina, dataInscricao
        String matricula;
        String codigoDisciplina; // Adicionei ponto e vírgula aqui
        String dataInscricao;    // Adicionei ponto e vírgula aqui
    }

    public static void main(String[] args) {
        Aluno[] alunos = new Aluno[MAX_ALUNOS];
        Disciplina[] disciplinas = new Disciplina[MAX_DISCIPLINAS];
        CriacaoDisciplina[] criacoes = new CriacaoDisciplina[MAX_CRIACAO];
        int opcao;

        while (true) {
            System.out.println("\nMENU PRINCIPAL");
            System.out.println("1. Alunos");
            System.out.println("2. Disciplinas");
            System.out.println("0. Sair");
            System.out.print("Escolha uma opção: ");
            opcao = scanner.nextInt();

            switch (opcao) {
                case 1:
                    menuAlunos(alunos);
                    break;
                case 2:
                    menuDisciplinas(criacoes, alunos, disciplinas);
                    break;
                case 0:
                    System.out.println("Saindo do programa.");
                    return;
                default:
                    System.out.println("Opção inválida. Tente novamente.");
            }
        }
    }

    static void criarAluno(Aluno[] alunos) {
        Aluno novoAluno = new Aluno();
        System.out.println("Insira as informações do aluno:");

        System.out.print("Nome: ");
        novoAluno.nome = scanner.next();

        System.out.print("Matrícula: ");
        novoAluno.matricula = scanner.next();

        System.out.print("CPF: ");
        novoAluno.cpf = scanner.next();

        System.out.print("Email: ");
        novoAluno.email = scanner.next();

        System.out.print("Sexo: ");
        novoAluno.sexo = scanner.next();

        novoAluno.id = contadorDeAlunos++;
        alunos[contadorDeAlunos - 1] = novoAluno;
        System.out.println("Aluno criado com sucesso!");
    }

    static void listarAlunos(Aluno[] alunos) {
        System.out.println("Lista de Alunos:");
        for (int i = 0; i < contadorDeAlunos; i++) {
            System.out.println("ID: " + alunos[i].id);
            System.out.println("Nome: " + alunos[i].nome);
            System.out.println("Matrícula: " + alunos[i].matricula);
            System.out.println("CPF: " + alunos[i].cpf);
            System.out.println("Sexo: " + alunos[i].sexo);
            System.out.println("Email: " + alunos[i].email + "\n");
        }
    }

    static void atualizarAluno(Aluno[] alunos) {
        int idAlunoParaAtualizar;
        System.out.print("Digite o ID do aluno que deseja atualizar: ");
        idAlunoParaAtualizar = scanner.nextInt();

        boolean encontrado = false;
        for (int i = 0; i < contadorDeAlunos; i++) {
            if (alunos[i].id == idAlunoParaAtualizar) {
                System.out.println("Aluno encontrado. Insira as novas informações:");

                System.out.print("Novo Nome: ");
                alunos[i].nome = scanner.next();

                System.out.print("Nova Matrícula: ");
                alunos[i].matricula = scanner.next();

                System.out.print("Novo CPF: ");
                alunos[i].cpf = scanner.next();

                System.out.print("Novo Email: ");
                alunos[i].email = scanner.next();

                System.out.print("Novo Sexo: ");
                alunos[i].sexo = scanner.next();

                System.out.println("Aluno atualizado com sucesso!");
                encontrado = true;
                break;
            }
        }

        if (!encontrado) {
            System.out.println("Aluno com ID " + idAlunoParaAtualizar + " não encontrado.");
        }
    }

    static void excluirAluno(Aluno[] alunos) {
        int idAlunoParaExcluir;
        System.out.print("Digite o ID do aluno que deseja excluir: ");
        idAlunoParaExcluir = scanner.nextInt();

        boolean encontrado = false;

        for (int i = 0; i < contadorDeAlunos; i++) {
            if (alunos[i].id == idAlunoParaExcluir) {
                System.out.println("Aluno encontrado e excluído.");

                for (int j = i; j < contadorDeAlunos - 1; j++) {
                    alunos[j] = alunos[j + 1];
                }

                contadorDeAlunos--;
                encontrado = true;
                break;
            }
        }

        if (!encontrado) {
            System.out.println("Aluno com ID " + idAlunoParaExcluir + " não foi encontrado.");
        }
    }

    static void criarDisciplina(Disciplina[] disciplinas) {
        Disciplina novaDisciplina = new Disciplina();
        System.out.println("Insira as informações da disciplina:");

        System.out.print("Código da Disciplina: ");
        novaDisciplina.codigoDisciplina = scanner.next();

        System.out.print("Código do Tipo de Curso: ");
        novaDisciplina.codigoTipoCurso = scanner.next();

        System.out.print("Nome da Disciplina: ");
        novaDisciplina.nomeDisciplina = scanner.next();

        System.out.print("Nome do Professor: ");
        novaDisciplina.nomeProfessor = scanner.next();

        if (contadorDeDisciplinas < MAX_DISCIPLINAS) {
            disciplinas[contadorDeDisciplinas] = novaDisciplina;

            contadorDeDisciplinas++;
            System.out.println("Disciplina criada com sucesso!");
        } else {
            System.out.println("A capacidade máxima de disciplinas foi atingida.");
        }
    }

    static void listarDisciplinas(Disciplina[] disciplinas) {
        System.out.println("Informações das disciplinas em formato de Array:");
        for (int i = 0; i < contadorDeDisciplinas; i++) {
            System.out.println("Disciplina " + (i + 1) + ": [Código da Disciplina: " +
                    disciplinas[i].codigoDisciplina + ", Código do Tipo de Curso: " +
                    disciplinas[i].codigoTipoCurso + ", Nome: " +
                    disciplinas[i].nomeDisciplina + ", Nome do Professor: " +
                    disciplinas[i].nomeProfessor + "]");
        }
    }

    static void atualizarDisciplina(Disciplina[] disciplinas) {
        String codigoParaAtualizar;
        System.out.print("Digite o código da disciplina que deseja atualizar: ");
        codigoParaAtualizar = scanner.next();

        boolean encontrada = false;

        for (int i = 0; i < contadorDeDisciplinas; i++) {
            if (disciplinas[i].codigoDisciplina.equals(codigoParaAtualizar)) {
                System.out.println("Disciplina encontrada. Insira as novas informações:");

                System.out.print("Novo Código da Disciplina: ");
                disciplinas[i].codigoDisciplina = scanner.next();

                System.out.print("Novo Código do Tipo de Curso: ");
                disciplinas[i].codigoTipoCurso = scanner.next();

                System.out.print("Novo Nome da Disciplina: ");
                disciplinas[i].nomeDisciplina = scanner.next();

                System.out.print("Novo Nome do Professor: ");
                disciplinas[i].nomeProfessor = scanner.next();

                System.out.println("Disciplina atualizada com sucesso!");
                encontrada = true;
                break;
            }
        }

        if (!encontrada) {
            System.out.println("Disciplina com código " + codigoParaAtualizar + " não foi encontrada.");
        }
    }

    static void cadastrarInscricaoDisciplina(CriacaoDisciplina[] criacoes, Aluno[] alunos, Disciplina[] disciplinas) {
        CriacaoDisciplina novaInscricao = new CriacaoDisciplina();

        System.out.println("Insira as informações da inscrição:");

        System.out.print("Matrícula do Aluno: ");
        novaInscricao.matricula = scanner.next();

        System.out.print("Código da Disciplina: ");
        novaInscricao.codigoDisciplina = scanner.next();

        System.out.print("Data de Inscrição: ");
        novaInscricao.dataInscricao = scanner.next();

        if (contadorCriacao < MAX_CRIACAO) {
            criacoes[contadorCriacao] = novaInscricao;
            contadorCriacao++;
            System.out.println("Inscrição de disciplina criada com sucesso!");
        } else {
            System.out.println("A capacidade máxima de inscrições de disciplinas foi atingida.");
        }
    }



    static void menuAlunos(Aluno[] alunos) {
        int opcao;

        while (true) {
            System.out.println("\nMENU ALUNOS");
            System.out.println("1. Criar Aluno");
            System.out.println("2. Listar Alunos");
            System.out.println("3. Atualizar Aluno");
            System.out.println("4. Excluir Aluno");
            System.out.println("0. Voltar ao Menu Principal");
            System.out.print("Escolha uma opção: ");
            opcao = scanner.nextInt();

            switch (opcao) {
                case 1:
                    criarAluno(alunos);
                    break;
                case 2:
                    listarAlunos(alunos);
                    break;
                case 3:
                    atualizarAluno(alunos);
                    break;
                case 4:
                    excluirAluno(alunos);
                    break;
                case 0:
                    return;
                default:
                    System.out.println("Opção inválida. Tente novamente.");
            }
        }
    }

    static void menuDisciplinas(CriacaoDisciplina[] criacoes, Aluno[] alunos, Disciplina[] disciplinas) {
        int opcao;

        while (true) {
            System.out.println("\nMENU DE DISCIPLINAS");
            System.out.println("1. Criar Disciplinas");
            System.out.println("2. Listar Disciplinas");
            System.out.println("3. Atualizar Disciplinas");
            System.out.println("4. Cadastrar aluno em Disciplina");
            System.out.println("0. Sair");
            System.out.print("Escolha uma opção: ");
            opcao = scanner.nextInt();

            switch (opcao) {
                case 1:
                    criarDisciplina(disciplinas);
                    break;
                case 2:
                    listarDisciplinas(disciplinas);
                    break;
                case 3:
                    atualizarDisciplina(disciplinas);
                    break;
                case 4:
                    cadastrarInscricaoDisciplina(criacoes, alunos, disciplinas);
                case 0:
                    System.out.println("Saindo do programa.");
                    return;
                default:
                    System.out.println("Opção inválida. Tente novamente.");
            }
        }
    }
}
