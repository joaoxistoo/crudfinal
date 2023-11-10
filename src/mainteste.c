#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALUNOS 1000
#define MAX_DISCIPLINAS 1000
#define MAX_CRIACAO 1000

typedef struct {
    int id;
    char matricula[50];
    char nome[100];
    char cpf[15];
    char sexo[10];
    char email[100];
} Aluno;

typedef struct {
    char codigoDisciplina[50];
    char codigoTipoCurso[50];
    char nomeDisciplina[100];
    char nomeProfessor[100];
} Disciplina;

typedef struct {
    char matricula[50];
    char codigoDisciplina[50];
    char dataInscricao[20];
} CriacaoDisciplina;

int contadorCriacao = 0;
int contadorDeAlunos = 0;
int contadorDeDisciplinas = 0;
CriacaoDisciplina criacoes[MAX_CRIACAO];

void menuAlunos(Aluno alunos[]);
void criarAluno(Aluno alunos[]);
void listarAlunos(Aluno alunos[]);
void atualizarAluno(Aluno alunos[]);
void excluirAluno(Aluno alunos[]);

void menuDisciplinas(CriacaoDisciplina criacoes[], Aluno alunos[], Disciplina disciplinas[]);
void criarDisciplina(Disciplina disciplinas[]);
void listarDisciplinas(Disciplina disciplinas[]);
void atualizarDisciplina(Disciplina disciplinas[]);
void cadastrarInscricaoDisciplina(CriacaoDisciplina criacoes[], Aluno alunos[], Disciplina disciplinas[]);

int main() {
    Aluno alunos[MAX_ALUNOS];
    Disciplina disciplinas[MAX_DISCIPLINAS];
    CriacaoDisciplina criacoes[MAX_CRIACAO];
    int opcao;

    while (1) {
        printf("\nMENU PRINCIPAL\n");
        printf("1. Alunos\n");
        printf("2. Disciplinas\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                menuAlunos(alunos);
                break;
            case 2:
                menuDisciplinas(criacoes, alunos, disciplinas);
                break;
            case 0:
                printf("Saindo do programa.\n");
                return 0;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}

void criarAluno(Aluno alunos[]) {
    Aluno novoAluno;
    printf("Insira as informações do aluno:\n");

    printf("Nome: ");
    scanf("%s", novoAluno.nome);

    printf("Matrícula: ");
    scanf("%s", novoAluno.matricula);

    printf("CPF: ");
    scanf("%s", novoAluno.cpf);

    printf("Email: ");
    scanf("%s", novoAluno.email);

    printf("Sexo: ");
    scanf("%s", novoAluno.sexo);

    novoAluno.id = contadorDeAlunos++;
    alunos[contadorDeAlunos - 1] = novoAluno;
    printf("Aluno criado com sucesso!\n");
}

void listarAlunos(Aluno alunos[]) {
    printf("Lista de Alunos:\n");
    for (int i = 0; i < contadorDeAlunos; i++) {
        printf("ID: %d\n", alunos[i].id);
        printf("Nome: %s\n", alunos[i].nome);
        printf("Matrícula: %s\n", alunos[i].matricula);
        printf("CPF: %s\n", alunos[i].cpf);
        printf("Sexo: %s\n", alunos[i].sexo);
        printf("Email: %s\n\n", alunos[i].email);
    }
}

void atualizarAluno(Aluno alunos[]) {
    int idAlunoParaAtualizar;
    printf("Digite o ID do aluno que deseja atualizar: ");
    scanf("%d", &idAlunoParaAtualizar);

    int encontrado = 0;
    for (int i = 0; i < contadorDeAlunos; i++) {
        if (alunos[i].id == idAlunoParaAtualizar) {
            printf("Aluno encontrado. Insira as novas informações:\n");

            printf("Novo Nome: ");
            scanf("%s", alunos[i].nome);

            printf("Nova Matrícula: ");
            scanf("%s", alunos[i].matricula);

            printf("Novo CPF: ");
            scanf("%s", alunos[i].cpf);

            printf("Novo Email: ");
            scanf("%s", alunos[i].email);

            printf("Novo Sexo: ");
            scanf("%s", alunos[i].sexo);

            printf("Aluno atualizado com sucesso!\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Aluno com ID %d não encontrado.\n", idAlunoParaAtualizar);
    }
}

void excluirAluno(Aluno alunos[]) {
    int idAlunoParaExcluir;
    printf("Digite o ID do aluno que deseja excluir: ");
    scanf("%d", &idAlunoParaExcluir);

    int encontrado = 0;

    for (int i = 0; i < contadorDeAlunos; i++) {
        if (alunos[i].id == idAlunoParaExcluir) {
            printf("Aluno encontrado e excluído.\n");

            for (int j = i; j < contadorDeAlunos - 1; j++) {
                alunos[j] = alunos[j + 1];
            }

            contadorDeAlunos--;
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Aluno com ID %d não foi encontrado.\n", idAlunoParaExcluir);
    }
}

void criarDisciplina(Disciplina disciplinas[]) {
    Disciplina novaDisciplina;
    printf("Insira as informações da disciplina:\n");

    printf("Código da Disciplina: ");
    scanf("%s", novaDisciplina.codigoDisciplina);

    printf("Código do Tipo de Curso: ");
    scanf("%s", novaDisciplina.codigoTipoCurso);

    printf("Nome da Disciplina: ");
    scanf("%s", novaDisciplina.nomeDisciplina);

    printf("Nome do Professor: ");
    scanf("%s", novaDisciplina.nomeProfessor);

    if (contadorDeDisciplinas < MAX_DISCIPLINAS) {
        disciplinas[contadorDeDisciplinas] = novaDisciplina;

        contadorDeDisciplinas++;
        printf("Disciplina criada com sucesso!\n");
    } else {
        printf("A capacidade máxima de disciplinas foi atingida.\n");
    }
}

void listarDisciplinas(Disciplina disciplinas[]) {
    printf("Informações das disciplinas em formato de Array:\n");
    for (int i = 0; i < contadorDeDisciplinas; i++) {
        printf("Disciplina %d: [Código da Disciplina: %s, Código do Tipo de Curso: %s, Nome: %s, Nome do Professor: %s]\n",
               i + 1, disciplinas[i].codigoDisciplina, disciplinas[i].codigoTipoCurso,
               disciplinas[i].nomeDisciplina, disciplinas[i].nomeProfessor);
    }
}

void atualizarDisciplina(Disciplina disciplinas[]) {
    char codigoParaAtualizar[50];
    printf("Digite o código da disciplina que deseja atualizar: ");
    scanf("%s", codigoParaAtualizar);

    int encontrada = 0;

    for (int i = 0; i < contadorDeDisciplinas; i++) {
        if (strcmp(disciplinas[i].codigoDisciplina, codigoParaAtualizar) == 0) {
            printf("Disciplina encontrada. Insira as novas informações:\n");

            printf("Novo Código da Disciplina: ");
            scanf("%s", disciplinas[i].codigoDisciplina);

            printf("Novo Código do Tipo de Curso: ");
            scanf("%s", disciplinas[i].codigoTipoCurso);

            printf("Novo Nome da Disciplina: ");
            scanf("%s", disciplinas[i].nomeDisciplina);

            printf("Novo Nome do Professor: ");
            scanf("%s", disciplinas[i].nomeProfessor);

            printf("Disciplina atualizada com sucesso!\n");
            encontrada = 1;
            break;
        }
    }

    if (!encontrada) {
        printf("Disciplina com código %s não foi encontrada.\n", codigoParaAtualizar);
    }
}

void cadastrarInscricaoDisciplina(CriacaoDisciplina criacoes[], Aluno alunos[], Disciplina disciplinas[]) {
    CriacaoDisciplina novaInscricao;
    printf("Insira as informações da inscrição:\n");

    printf("Matrícula do Aluno: ");
    scanf("%s", novaInscricao.matricula);

    printf("Código da Disciplina: ");
    scanf("%s", novaInscricao.codigoDisciplina);

    printf("Data de Inscrição: ");
    scanf("%s", novaInscricao.dataInscricao);

    if (contadorCriacao < MAX_CRIACAO) {
        criacoes[contadorCriacao] = novaInscricao;
        contadorCriacao++;
        printf("Inscrição de disciplina criada com sucesso!\n");
    } else {
        printf("A capacidade máxima de inscrições de disciplinas foi atingida.\n");
    }
}

void menuAlunos(Aluno alunos[]) {
    int opcao;

    while (1) {
        printf("\nMENU ALUNOS\n");
        printf("1. Criar Aluno\n");
        printf("2. Listar Alunos\n");
        printf("3. Atualizar Aluno\n");
        printf("4. Excluir Aluno\n");
        printf("0. Voltar ao Menu Principal\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

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
                printf("Opção inválida. Tente novamente.\n");
        }
    }
}

void menuDisciplinas(CriacaoDisciplina criacoes[], Aluno alunos[], Disciplina disciplinas[]) {
    int opcao;

    while (1) {
        printf("\nMENU DE DISCIPLINAS\n");
        printf("1. Criar Disciplinas\n");
        printf("2. Listar Disciplinas\n");
        printf("3. Atualizar Disciplinas\n");
        printf("4. Cadastrar aluno em Disciplina\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

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
                printf("Saindo do programa.\n");
                return;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }
}
