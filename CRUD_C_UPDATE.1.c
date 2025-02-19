#include <stdio.h>
#include <string.h>
#include <locale.h>

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
void excluirTipoCurso(struct TipoCurso tiposCurso[MAX_TIPOCURSO]);
void excluirDisciplinas(struct Disciplina disciplinas[MAX_DISCIPLINAS]);
void atualizarInscricao(struct InscricaoDisciplina inscricoes[MAX_INSCRICAO]);
void excluirInscricao(struct InscricaoDisciplina inscricoes[MAX_INSCRICAO]);
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
        printf("Escolha uma opcao: ");
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
                printf("Opcao invalida. Tente novamente.\n");
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
        printf("4. Excluir Tipo de Curso\n");
        printf("0. Voltar ao Menu Principal\n");
        printf("Escolha uma opcao: ");
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
            case 4:
                excluirTipoCurso(tiposCurso);
                break;
            case 0:
                return;
            default:
                printf("Opcao invalida. Tente novamente.\n");
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
        printf("Escolha uma opcao: ");
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
                printf("Opcao invalida. Tente novamente.\n");
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
        printf("4. Excluir Disciplinas\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
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
                excluirDisciplinas(disciplinas);
                break;
            case 0:
                printf("Saindo do programa.\n");
                return;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    }
}

void menuInscricao(struct InscricaoDisciplina inscricoes[MAX_INSCRICAO]) {
    int opcao;

    while (1) {
        printf("\nMENU INSCRICAO DE ALUNOS EM DISCIPLINA\n");
        printf("1. Criar Inscricao\n");
        printf("2. Listar Inscricoes\n");
        printf("3. Atualizar inscricoes\n");
        printf("4. Excluir inscricoes\n");
        printf("0. Voltar ao Menu Principal\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                criarInscricao(inscricoes);
                break;
            case 2:
                listarInscricoes(inscricoes);
                break;
            case 3:
                atualizarInscricao(inscricoes);
            case 4:
                excluirInscricao(inscricoes);
            case 0:
                return;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    }
}

void criarAluno(struct Aluno alunos[MAX_ALUNOS]) {
    struct Aluno novoAluno;
    printf("Insira as informacoes do aluno:\n");

    printf("Nome: ");
    scanf("%s", novoAluno.nome);

    printf("Matricula: ");
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
        printf("Matricula: %s\n", alunos[i].matricula);
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
            printf("Aluno encontrado. Insira as novas informacoes:\n");

            printf("Novo Nome: ");
            scanf("%s", alunos[i].nome);

            printf("Nova Matricula: ");
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
        printf("Aluno com ID %d nao encontrado.\n", idAlunoParaAtualizar);
    }
}

void excluirAluno(struct Aluno alunos[MAX_ALUNOS]) {
    int idAlunoParaExcluir;
    printf("Digite o ID do aluno que deseja excluir: ");
    scanf("%d", &idAlunoParaExcluir);

    int encontrado = 0;

    for (int i = 0; i < contadorDeAlunos; i++) {
        if (alunos[i].id == idAlunoParaExcluir) {
            printf("Aluno encontrado e excluido.\n");

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
    printf("Insira as informacoes da disciplina:\n");

    printf("Codigo da Disciplina: ");
    scanf("%s", novaDisciplina.codigoDisciplina);

    printf("Codigo do Tipo de Curso: ");
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
        printf("A capacidade maxima de disciplinas foi atingida.\n");
    }
}

void listarDisciplinas(struct Disciplina disciplinas[MAX_DISCIPLINAS]) {
    printf("Informacoes das disciplinas em formato de Array:\n");
    for (int i = 0; i < contadorDeDisciplinas; i++) {
        printf("Disciplina %d: [Codigo da Disciplina: %s, Codigo do Tipo de Curso: %s, Nome: %s, Nome do Professor: %s]\n",
               i + 1, disciplinas[i].codigoDisciplina, disciplinas[i].codigoTipoCurso,
               disciplinas[i].nomeDisciplina, disciplinas[i].nomeProfessor);
    }
}

void excluirDisciplinas(struct Disciplina disciplinas[MAX_DISCIPLINAS]){
    char codigoParaExcluir[20];
    printf("Digite o codigo da disciplina que deseja excluir: ");
    scanf("%s", codigoParaExcluir);

    int indiceParaExcluir = -1;

    // Isso aqui procura o índice da disciplina com base no código meu bom.
    for (int i = 0; i < contadorDeDisciplinas; i++) {
        if (strcmp(disciplinas[i].codigoDisciplina, codigoParaExcluir) == 0) {
            indiceParaExcluir = i;
            break;
        }
    }

    // Isso aqui remove a disciplina se ela for encontrada
    if (indiceParaExcluir != -1) {
        for (int i = indiceParaExcluir; i < contadorDeDisciplinas - 1; i++) {
            disciplinas[i] = disciplinas[i + 1];
        }

        contadorDeDisciplinas--;
        printf("Disciplina excluida com sucesso!\n");
    } else {
        printf("Disciplina nao encontrada.\n");
    }
    
}

void atualizarDisciplina(struct Disciplina disciplinas[MAX_DISCIPLINAS]) {
    char codigoParaAtualizar[100];
    printf("Digite o codigo da disciplina que deseja atualizar: ");
    scanf("%s", codigoParaAtualizar);

    int encontrada = 0;

    for (int i = 0; i < contadorDeDisciplinas; i++) {
        if (strcmp(disciplinas[i].codigoDisciplina, codigoParaAtualizar) == 0) {
            printf("Disciplina encontrada. Insira as novas informacoes:\n");

            printf("Novo Codigo da Disciplina: ");
            scanf("%s", disciplinas[i].codigoDisciplina);

            printf("Novo Codigo do Tipo de Curso: ");
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
        printf("Disciplina com codigo %s nao foi encontrada.\n", codigoParaAtualizar);
    }
}

void criarInscricao(struct InscricaoDisciplina inscricoes[MAX_INSCRICAO]) {
    struct InscricaoDisciplina novaInscricao;
    printf("Insira as informacoes da inscricao:\n");

    printf("Matricula do Aluno: ");
    scanf("%s", novaInscricao.matricula);

    printf("Codigo da Disciplina: ");
    scanf("%s", novaInscricao.codigoDisciplina);

    printf("Data de Inscricao: ");
    scanf("%s", novaInscricao.dataInscricao);

    if (contadorDeInscricoes < MAX_INSCRICAO) {
        inscricoes[contadorDeInscricoes] = novaInscricao;
        contadorDeInscricoes++;
        printf("Inscricao criada com sucesso!\n");
    } else {
        printf("A capacidade maxima de inscricoes foi atingida.\n");
    }
}

void listarInscricoes(struct InscricaoDisciplina inscricoes[MAX_INSCRICAO]) {
    printf("Lista de Inscricoes:\n");
    for (int i = 0; i < contadorDeInscricoes; i++) {
        printf("Matricula do Aluno: %s\n", inscricoes[i].matricula);
        printf("Codigo da Disciplina: %s\n", inscricoes[i].codigoDisciplina);
        printf("Data de Inscricao: %s\n", inscricoes[i].dataInscricao);
        printf("\n");
    }
}

void atualizarInscricao(struct InscricaoDisciplina inscricoes[MAX_INSCRICAO]) {
    char matriculaParaAtualizar[20];
    printf("Digite a matricula do aluno para atualizar a inscricao: ");
    scanf("%s", matriculaParaAtualizar);

    int indiceParaAtualizar = -1;

    // Procurar o índice da inscrição com base na matrícula do aluno
    for (int i = 0; i < contadorDeInscricoes; i++) {
        if (strcmp(inscricoes[i].matricula, matriculaParaAtualizar) == 0) {
            indiceParaAtualizar = i;
            break;
        }
    }

    // Esse Atualiza a inscrição se ela for encontrada
    if (indiceParaAtualizar != -1) {
        printf("Digite a nova data de inscricao: ");
        scanf("%s", inscricoes[indiceParaAtualizar].dataInscricao);

        printf("Inscricao atualizada com sucesso!\n");
    } else {
        printf("Inscricao nao encontrada.\n");
    }
}

void excluirInscricao(struct InscricaoDisciplina inscricoes[MAX_INSCRICAO]) {
    char matriculaParaExcluir[20];
    printf("Digite a matricula do aluno para excluir a inscricao: ");
    scanf("%s", matriculaParaExcluir);

    int indiceParaExcluir = -1;

    // Essa porra aqui procura o índice da inscrição com base na matrícula do aluno
    for (int i = 0; i < contadorDeInscricoes; i++) {
        if (strcmp(inscricoes[i].matricula, matriculaParaExcluir) == 0) {
            indiceParaExcluir = i;
            break;
        }
    }

    // Isso aqui só remove inscrição se ela for encontrada
    if (indiceParaExcluir != -1) {
        // Deslocar as inscrições à frente do índice para preencher o espaço
        for (int i = indiceParaExcluir; i < contadorDeInscricoes - 1; i++) {
            inscricoes[i] = inscricoes[i + 1];
        }

        contadorDeInscricoes--;
        printf("Inscricao excluida com sucesso!\n");
    } else {
        printf("Inscricao nao encontrada.\n");
    }
}

void criarTipoCurso(struct TipoCurso tiposCurso[MAX_TIPOCURSO]) {
    struct TipoCurso novoTipoCurso;
    printf("Insira as informacoes do tipo de curso:\n");

    printf("Codigo do Tipo de Curso: ");
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
        printf("A capacidade maxima de tipos de curso foi atingida.\n");
    }
}

void listarTiposCurso(struct TipoCurso tiposCurso[MAX_TIPOCURSO]) {
    printf("Lista de Tipos de Curso:\n");
    for (int i = 0; i < contadorDeTiposCurso; i++) {
        printf("Codigo do Tipo de Curso: %s\n", tiposCurso[i].codigoTipoCurso);
        printf("Nome: %s\n", tiposCurso[i].nome);
        printf("Turno: %s\n\n", tiposCurso[i].turno);
    }
}

void atualizarTipoCurso(struct TipoCurso tiposCurso[MAX_TIPOCURSO]) {
    char codigoParaAtualizar[100];
    printf("Digite o codigo do tipo de curso que deseja atualizar: ");
    scanf("%s", codigoParaAtualizar);

    int encontrado = 0;

    for (int i = 0; i < contadorDeTiposCurso; i++) {
        if (strcmp(tiposCurso[i].codigoTipoCurso, codigoParaAtualizar) == 0) {
            printf("Tipo de curso encontrado. Insira as novas informacoes:\n");

            printf("Novo Codigo do Tipo de Curso: ");
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
        printf("Tipo de curso com codigo %s nao foi encontrado.\n", codigoParaAtualizar);
    }
}

void excluirTipoCurso(struct TipoCurso tiposCurso[MAX_TIPOCURSO]) {
    char codigoParaExcluir[100];
    printf("Digite o codigo do tipo de curso que deseja excluir: ");
    scanf("%s", codigoParaExcluir);

    int indiceParaExcluir = -1;

    for (int i = 0; i < contadorDeTiposCurso; i++) {
        if (strcmp(tiposCurso[i].codigoTipoCurso, codigoParaExcluir) == 0) {
            indiceParaExcluir = i;
            break;
        }
    }

    if (indiceParaExcluir != -1) {
        for (int i = indiceParaExcluir; i < contadorDeTiposCurso - 1; i++) {
            tiposCurso[i] = tiposCurso[i + 1];
        }

        contadorDeTiposCurso--;
        printf("Tipo de curso excluido com sucesso!\n");
    } else {
        printf("Tipo de curso com codigo %s nao foi encontrado.\n", codigoParaExcluir);
    }
}
