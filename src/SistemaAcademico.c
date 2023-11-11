#include <stdio.h>
#include <string.h>

#define MAX_ALUNOS 1000
#define MAX_DISCIPLINAS 1000
#define MAX_INSCRICAO 1000
#define MAX_TIPOCURSO 1000

struct Aluno {
    int id;
    char matricula[100];
    char nome[100];
    char cpf[15];
    char sexo[10];
    char email[100];
};

struct Disciplina {
    char codigoDisciplina[100];
    char codigoTipoCurso[100];
    char nomeDisciplina[100];
    char nomeProfessor[100];
};

struct InscricaoDisciplina {
    char matricula[100];
    char codigoDisciplina[100];
    char dataInscricao[100];
};

struct TipoCurso {
    char codigoTipoCurso[100];
    char nome[100];
    char turno[20];
};

int contadorDeTiposCurso = 0;
int contadorDeAlunos = 0;
int contadorDeDisciplinas = 0;
int contadorDeInscricoes = 0;

// Protótipos das funções
void criarAluno(struct Aluno alunos[MAX_ALUNOS]);
void listarAlunos(struct Aluno alunos[MAX_ALUNOS]);
void atualizarAluno(struct Aluno alunos[MAX_ALUNOS]);
void excluirAluno(struct Aluno alunos[MAX_ALUNOS]);
void criarDisciplina(struct Disciplina disciplinas[MAX_DISCIPLINAS]);
void listarDisciplinas(struct Disciplina disciplinas[MAX_DISCIPLINAS]);
void atualizarDisciplina(struct Disciplina disciplinas[MAX_DISCIPLINAS]);
void criarInscricao(struct InscricaoDisciplina inscricoes[MAX_INSCRICAO]);
void listarInscricoes(struct InscricaoDisciplina inscricoes[MAX_INSCRICAO]);
void menuAlunos(struct Aluno alunos[MAX_ALUNOS]);
void menuDisciplinas(struct Disciplina disciplinas[MAX_DISCIPLINAS]);
void menuInscricao(struct InscricaoDisciplina inscricoes[MAX_INSCRICAO]);
void menuTiposCurso(struct TipoCurso tiposCurso[MAX_TIPOCURSO]);
void criarTipoCurso(struct TipoCurso tiposCurso[MAX_TIPOCURSO]);
void listarTiposCurso(struct TipoCurso tiposCurso[MAX_TIPOCURSO]);
void atualizarTipoCurso(struct TipoCurso tiposCurso[MAX_TIPOCURSO]);

int main() {
    struct Aluno alunos[MAX_ALUNOS];
    struct Disciplina disciplinas[MAX_DISCIPLINAS];
    struct InscricaoDisciplina inscricoes[MAX_INSCRICAO];
    struct TipoCurso tiposCurso[MAX_TIPOCURSO];
    int opcao;

    while (1) {
        printf("\nMENU PRINCIPAL\n");
        printf("1. Alunos\n");
        printf("2. Disciplinas\n");
        printf("3. Inscricao de Disciplinas\n");
        printf("4. Tipo Curso\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                menuAlunos(alunos);
                break;
            case 2:
                menuDisciplinas(disciplinas);
                break;
            case 3:
                menuInscricao(inscricoes);
                break;
            case 4:
                menuTiposCurso(tiposCurso);
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



void menuTiposCurso(struct TipoCurso tiposCurso[MAX_TIPOCURSO]) {
    int opcao;

    while (1) {
        printf("\nMENU TIPO DE CURSO\n");
        printf("1. Criar Tipo de Curso\n");
        printf("2. Listar Tipos de Curso\n");
        printf("3. Atualizar Tipo de Curso\n");
        printf("0. Voltar ao Menu Principal\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                criarTipoCurso(tiposCurso);
                break;
            case 2:
                listarTiposCurso(tiposCurso);
                break;
            case 3:
                atualizarTipoCurso(tiposCurso);
                break;
            case 0:
                return;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }
}



void menuAlunos(struct Aluno alunos[MAX_ALUNOS]) {
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

void menuDisciplinas(struct Disciplina disciplinas[MAX_DISCIPLINAS]) {
    int opcao;

    while (1) {
        printf("\nMENU DE DISCIPLINAS\n");
        printf("1. Criar Disciplinas\n");
        printf("2. Listar Disciplinas\n");
        printf("3. Atualizar Disciplinas\n");
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
            case 0:
                printf("Saindo do programa.\n");
                return;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }
}

void menuInscricao(struct InscricaoDisciplina inscricoes[MAX_INSCRICAO]) {
    int opcao;

    while (1) {
        printf("\nMENU INSCRICAO DE ALUNOS EM DISCIPLINA\n");
        printf("1. Criar Inscricao\n");
        printf("2. Listar Inscricoes\n");
        printf("0. Voltar ao Menu Principal\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                criarInscricao(inscricoes);
                break;
            case 2:
                listarInscricoes(inscricoes);
                break;
            case 0:
                return;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }
}

void criarAluno(struct Aluno alunos[MAX_ALUNOS]) {
    struct Aluno novoAluno;
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

void listarAlunos(struct Aluno alunos[MAX_ALUNOS]) {
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

void atualizarAluno(struct Aluno alunos[MAX_ALUNOS]) {
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

void excluirAluno(struct Aluno alunos[MAX_ALUNOS]) {
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

void criarDisciplina(struct Disciplina disciplinas[MAX_DISCIPLINAS]) {
    struct Disciplina novaDisciplina;
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
        strcpy(disciplinas[contadorDeDisciplinas].codigoDisciplina, novaDisciplina.codigoDisciplina);
        strcpy(disciplinas[contadorDeDisciplinas].codigoTipoCurso, novaDisciplina.codigoTipoCurso);
        strcpy(disciplinas[contadorDeDisciplinas].nomeDisciplina, novaDisciplina.nomeDisciplina);
        strcpy(disciplinas[contadorDeDisciplinas].nomeProfessor, novaDisciplina.nomeProfessor);

        contadorDeDisciplinas++;
        printf("Disciplina criada com sucesso!\n");
    } else {
        printf("A capacidade máxima de disciplinas foi atingida.\n");
    }
}

void listarDisciplinas(struct Disciplina disciplinas[MAX_DISCIPLINAS]) {
    printf("Informações das disciplinas em formato de Array:\n");
    for (int i = 0; i < contadorDeDisciplinas; i++) {
        printf("Disciplina %d: [Código da Disciplina: %s, Código do Tipo de Curso: %s, Nome: %s, Nome do Professor: %s]\n",
               i + 1, disciplinas[i].codigoDisciplina, disciplinas[i].codigoTipoCurso,
               disciplinas[i].nomeDisciplina, disciplinas[i].nomeProfessor);
    }
}

void atualizarDisciplina(struct Disciplina disciplinas[MAX_DISCIPLINAS]) {
    char codigoParaAtualizar[100];
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

void criarInscricao(struct InscricaoDisciplina inscricoes[MAX_INSCRICAO]) {
    struct InscricaoDisciplina novaInscricao;
    printf("Insira as informações da inscrição:\n");

    printf("Matrícula do Aluno: ");
    scanf("%s", novaInscricao.matricula);

    printf("Código da Disciplina: ");
    scanf("%s", novaInscricao.codigoDisciplina);

    printf("Data de Inscrição: ");
    scanf("%s", novaInscricao.dataInscricao);

    if (contadorDeInscricoes < MAX_INSCRICAO) {
        inscricoes[contadorDeInscricoes] = novaInscricao;
        contadorDeInscricoes++;
        printf("Inscrição criada com sucesso!\n");
    } else {
        printf("A capacidade máxima de inscrições foi atingida.\n");
    }
}

void listarInscricoes(struct InscricaoDisciplina inscricoes[MAX_INSCRICAO]) {
    printf("Lista de Inscricoes:\n");
    for (int i = 0; i < contadorDeInscricoes; i++) {
        printf("Matrícula do Aluno: %s\n", inscricoes[i].matricula);
        printf("Código da Disciplina: %s\n", inscricoes[i].codigoDisciplina);
        printf("Data de Inscrição: %s\n", inscricoes[i].dataInscricao);
        printf("\n");
    }
}

void criarTipoCurso(struct TipoCurso tiposCurso[MAX_TIPOCURSO]) {
    struct TipoCurso novoTipoCurso;
    printf("Insira as informações do tipo de curso:\n");

    printf("Código do Tipo de Curso: ");
    scanf("%s", novoTipoCurso.codigoTipoCurso);

    printf("Nome: ");
    scanf("%s", novoTipoCurso.nome);

    printf("Turno: ");
    scanf("%s", novoTipoCurso.turno);

    if (contadorDeTiposCurso < MAX_TIPOCURSO) {
        tiposCurso[contadorDeTiposCurso] = novoTipoCurso;
        contadorDeTiposCurso++;
        printf("Tipo de curso criado com sucesso!\n");
    } else {
        printf("A capacidade máxima de tipos de curso foi atingida.\n");
    }
}

void listarTiposCurso(struct TipoCurso tiposCurso[MAX_TIPOCURSO]) {
    printf("Lista de Tipos de Curso:\n");
    for (int i = 0; i < contadorDeTiposCurso; i++) {
        printf("Código do Tipo de Curso: %s\n", tiposCurso[i].codigoTipoCurso);
        printf("Nome: %s\n", tiposCurso[i].nome);
        printf("Turno: %s\n\n", tiposCurso[i].turno);
    }
}

void atualizarTipoCurso(struct TipoCurso tiposCurso[MAX_TIPOCURSO]) {
    char codigoParaAtualizar[100];
    printf("Digite o código do tipo de curso que deseja atualizar: ");
    scanf("%s", codigoParaAtualizar);

    int encontrado = 0;

    for (int i = 0; i < contadorDeTiposCurso; i++) {
        if (strcmp(tiposCurso[i].codigoTipoCurso, codigoParaAtualizar) == 0) {
            printf("Tipo de curso encontrado. Insira as novas informações:\n");

            printf("Novo Código do Tipo de Curso: ");
            scanf("%s", tiposCurso[i].codigoTipoCurso);

            printf("Novo Nome: ");
            scanf("%s", tiposCurso[i].nome);

            printf("Novo Turno: ");
            scanf("%s", tiposCurso[i].turno);

            printf("Tipo de curso atualizado com sucesso!\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Tipo de curso com código %s não foi encontrado.\n", codigoParaAtualizar);
    }
}
