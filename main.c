#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    /* ============== VARIAVEIS GLOBAIS ============================ */
    int opcoesIniciais;
    int sairDoJogo = 0;
    /* variavel para verificar se o personagem ja foi criado
      se personagemCriado for 0: significa que ainda nao foi criado
      se personagemCriado for 1: significa que o personagem foi
      criado e pode iniciar o jogo*/
    int personagemCriado = 0;

    /*============== MENU DE ENTRADA (interface) =================*/

    printf("\n");
    printf("  ==============================================================\n");
    printf("\n");
    printf(
        "          Crônicas do Reino: A terra desconhecida                  \n");
    printf("\n");
    printf("\n");
    printf("     'Descubra seu destino em meio às Crônicas do Reino,'            "
           "\n");
    printf("            onde sua jornada épica de RPG começa.               \n");
    printf("\n");
    printf("\n");
    printf(
        "                                      ____                        \n");
    printf(
        "                                     /    \\                      \n");
    printf(
        "                                    /  /  /                       \n");
    printf(
        "                                   /  /  /                        \n");
    printf(
        "                                  /  /  /                         \n");
    printf(
        "                                 /  /  /                          \n");
    printf(
        "                                /  /  /                           \n");
    printf(
        "                               /  /  /                            \n");
    printf(
        "                              /  /  /                             \n");
    printf(
        "                             /  /  /                              \n");
    printf(
        "                    __      /  /  /                               \n");
    printf(
        "                   / /     /  /  /                                \n");
    printf(
        "                   \\ \\    /  /  /                               \n");
    printf(
        "                    \\ \\  /  /  /                                \n");
    printf("                     \\ \\      /    __                          \n");
    printf("                      \\ \\_________/ /                          \n");
    printf("                      /  __________/                             \n");
    printf("                     /  /                                        \n");
    printf("                    /  /                                         \n");
    printf("                 __/  /                                          \n");
    printf("                /     \\                                         \n");
    printf("                \\ ___ /                                         \n");
    printf("\n");
    printf("\n");
    printf("  ============================================================\n");
    printf("\n");

    printf("Pressione Enter para iniciar: ");
    int tecla = getchar();
    while (tecla != '\n')
    {
        while (getchar() != '\n')
            ;
        printf("Você precisa pressionar Enter, Tente novamente.\n");
        tecla = getchar();
    }
    printf("\n\n");
    printf(
        "Seja Bem-vindo às Crônicas do Reino.\n Comece agora sua jornada!!\n\n");

    /* while para fazer um loop infinito para o jogo rodar:
     enquanto a opcao inicial de menu for diferente de 3, execute
     o jogo.
     */
    while (sairDoJogo == 0)
    {

        /*======== MENU DE ENTRADA (opcoes usuario) =================*/
        printf("***********************************\n\n");
        printf("Escolha qual opção deseja executar:\n");
        printf("1 - Criar Personagem.\n");
        printf("2 - Entrar no jogo.\n");
        printf("3 - Sair.\n\n");
        printf("***********************************\n");
        printf("Digite a escolha abaixo:\n");

        /*opcoes do menu que o usuario pode escolher*/
        scanf("%d", &opcoesIniciais);
        switch (opcoesIniciais)
        {
        /*============== CRIAR PERSONAGEM =====================*/
        case 1:

            system("clear");
            personagemCriado = 1;

            /* variaveis dos personagens(inicializacao em 0 para caso o usuario queira
             * recriar o personagem)*/
            char nome[21];
            int raca = 0;
            int alinhamento = 0;
            int profissao = 0;
            int meta = 0;
            int meioEmQueVive = 0;
            char historiaPrevia[401];
            int porte = 0;
            int vida = 100;

        criacaoDePersonagem:
            printf("**************************************************\n\n");
            printf("   Muito Bem! Agora me diga mais sobre você\n   para ser  "
                   "escrito no livro das Crônicas\n\n");
            printf("**************************************************\n\n");

            /* NOME DO PERSONAGEM:
            nome do personagem que o usuário digitar, com restricao de
            no maximo 20 caracteres*/
            printf("* Obs: Digite um nome de no máximo 20 caracteres *\n");
            printf("Qual é o seu nome? ");
            scanf(" %[^\n]", nome);
            /* verificar se o nome inserido possui menos de 20 caracteres*/
            if (strlen(nome) > 20)
            {
                system("clear");
                printf("\n* Nome inválido! Você deve inserir até 20 caracteres! *\n\n");
                goto criacaoDePersonagem;
            }

            system("clear");
            /* RAÇA DO PERSONAGEM:*/
            while (raca != 1 && raca != 2 && raca != 3)
            {
                printf("\n Entendido %s, qual a sua raça?\n", nome);
                printf("1. Humano\n");
                printf("2. Anão\n");
                printf("3. Elfo\n");
                printf("-> ");
                scanf("%d", &raca);
                printf(": ");
                switch (raca)
                {
                case 1:
                    raca = 1;
                    printf("Certo, você é um Humano!\n");
                    break;
                case 2:
                    raca = 2;
                    printf("Certo, você é um Anão!\n");
                    break;
                case 3:
                    raca = 3;
                    printf("Certo, você é um Elfo!\n");
                    break;
                /* fazer usuario voltar caso insira alguma das opcoes diferentes*/
                default:
                    system("clear");
                    printf("\n* Opção Inválida! Tente Novamente *\n\n");
                    continue;
                }
            }

            /* ALINHAMENTO DO PERSONAGEM: */
            while (alinhamento != 1 && alinhamento != 2 && alinhamento != 3)
            {
                printf("\n  %s, agora escolha seu lado da força!\n", nome);
                printf("1. Mal\n");
                printf("2. Neutro\n");
                printf("3. Bom\n");
                printf("-> ");
                scanf("%d", &alinhamento);
                printf(": ");
                switch (alinhamento)
                {
                case 1:
                    alinhamento = 1;
                    printf(
                        "Uhhh então quer dizer que você é malvado... Escolha feita!\n");
                    break;
                case 2:
                    alinhamento = 2;
                    printf("Tranquilo, você é neutro!\n");
                    break;
                case 3:
                    alinhamento = 3;
                    printf("Gostei, você é do lado dos bonzinhos!\n");
                    break;
                /* fazer usuario voltar caso insira alguma das opcoes diferentes*/
                default:
                    printf("\n* Opção Inválida! Tente Novamente *\n");
                    continue;
                }
            }

            /* PROFISSAO DO PERSONAGEM:
             if e else para fazer a restricao se caso o alinhamento do personagem
            for Bom, ele nao podera escolher a classe Ladino. */
            if (alinhamento != 3)
            {
                while (profissao != 1 && profissao != 2 && profissao != 3)
                {
                    printf("\n  %s, qual sua profissão?\n", nome);
                    printf("1. Guerreiro\n");
                    printf("2. Mago\n");
                    printf("3. Ladino\n");
                    printf("-> ");
                    scanf("%d", &profissao);
                    printf(": ");
                    switch (profissao)
                    {
                    case 1:
                        profissao = 1;
                        printf("Você é um guerreiro? Excelente, vai ser um ótimo reforço "
                               "para as batalhas!\n");
                        break;
                    case 2:
                        profissao = 2;
                        printf("Surpreendente, você é mago? Não economize nos feitiços!\n");
                        break;
                    case 3:
                        profissao = 3;
                        printf("Ladino! Então você é malandro, né!\n");
                        break;
                    /* fazer usuario voltar caso insira alguma das opcoes diferentes*/
                    default:
                        printf("\n* Opção Inválida! Tente Novamente *\n");
                        continue;
                    }
                }
            }
            else
            {
                while (profissao != 1 && profissao != 2)
                {
                    printf("\n  %s, qual sua profissão?\n", nome);
                    printf("1. Guerreiro\n");
                    printf("2. Mago\n");
                    printf("-> ");
                    scanf("%d", &profissao);
                    printf(": ");
                    switch (profissao)
                    {
                    case 1:
                        profissao = 1;
                        printf("Você é um guerreiro? Excelente, vai ser um ótimo reforço "
                               "para as batalhas!\n");
                        break;
                    case 2:
                        profissao = 2;
                        printf("Surpreendente, você é mago? Não economize nos feitiços!\n");
                        break;
                    /* fazer usuario voltar caso insira alguma das opcoes diferentes*/
                    default:
                        printf("\n* Opção Inválida! Tente Novamente *\n");
                        continue;
                    }
                }
            }

            /* META DO PERSONAGEM:
             if e else para fazer a restricao se caso o alinhamento do personagem
            for Mal, ele nao podera escolher a opcao Destruir o Mal */
            if (alinhamento != 1)
            {
                while (meta != 1 && meta != 2 && meta != 3)
                {
                    printf("\n  %s, me fale a respeito das suas metas nessa jornada!\n",
                           nome);
                    printf("1. Governar o reino\n");
                    printf("2. Ficar rico\n");
                    printf("3. Destruir o mal\n");
                    printf("-> ");
                    scanf("%d", &meta);
                    printf(": ");
                    switch (meta)
                    {
                    case 1:
                        meta = 1;
                        printf("Quer se tornar imperador? Vai com calma novato haha! Boa "
                               "sorte!\n");
                        break;
                    case 2:
                        meta = 2;
                        printf("Quer ficar rico? Quem não quer, não é mesmo?\n");
                        break;
                    case 3:
                        meta = 3;
                        printf("Boa sorte heroi! Muitos tentaram, poucos conseguiram...\n");
                        break;
                    /* fazer usuario voltar caso insira alguma das opcoes diferentes*/
                    default:
                        printf("\n* Opção Inválida! Tente Novamente *\n");
                        continue;
                    }
                }
            }
            else
            {
                while (meta != 1 && meta != 2)
                {
                    printf("\n  %s, me fale a respeito das suas metas nessa jornada!\n",
                           nome);
                    printf("1. Governar o reino\n");
                    printf("2. Ficar rico\n");
                    printf("-> ");
                    scanf("%d", &meta);
                    printf(": ");
                    switch (meta)
                    {
                    case 1:
                        meta = 1;
                        printf("Quer se tornar imperador? Vai com calma novato haha! Boa "
                               "sorte!\n");
                        break;
                    case 2:
                        meta = 2;
                        printf("Quer ficar rico? Quem não quer, não é mesmo?\n");
                        break;
                    /* fazer usuario voltar caso insira alguma das opcoes diferentes*/
                    default:
                        printf("\n* Opção Inválida! Tente Novamente *\n");
                        continue;
                    }
                }
            }

            /* MEIO EM QUE VIVE DO PERSONAGEM:
             if e else para fazer a restricao caso a profissao do personagem
            for Ladino, o meio em que vive nao poderá ser Tribal*/
            if (profissao != 3)
            {
                while (meioEmQueVive != 1 && meioEmQueVive != 2 && meioEmQueVive != 3)
                {
                    printf("\n  %s, em qual meio você vai viver na sua jornada?\n", nome);
                    printf("1. Urbano\n");
                    printf("2. Rural\n");
                    printf("3. Tribal\n");
                    printf("-> ");
                    scanf("%d", &meioEmQueVive);
                    printf(": ");
                    switch (meioEmQueVive)
                    {
                    case 1:
                        meioEmQueVive = 1;
                        printf("Gosto desse meio, mais moderno ne?!\n");
                        break;
                    case 2:
                        meioEmQueVive = 2;
                        printf("Meio rural, perfeito para iniciar sua jornada!\n");
                        break;
                    case 3:
                        meioEmQueVive = 3;
                        printf("Quer dizer que você vive em uma tribo? Excelente caso "
                               "precise de ajuda!\n");
                        break;
                    /*fazer usuario voltar caso insira alguma das opcoes diferentes*/
                    default:
                        printf("\n* Opção Inválida! Tente Novamente *\n");
                        continue;
                    }
                }
            }
            else
            {
                while (meioEmQueVive != 1 && meioEmQueVive != 2)
                {
                    printf("\n  %s, em qual meio você vai viver na sua jornada?\n", nome);
                    printf("1. Urbano\n");
                    printf("2. Rural\n");
                    printf("-> ");
                    scanf("%d", &meioEmQueVive);
                    printf(": ");
                    switch (meioEmQueVive)
                    {
                    case 1:
                        meioEmQueVive = 1;
                        printf("Gosto desse meio, mais moderno ne?!\n");
                        break;
                    case 2:
                        meioEmQueVive = 2;
                        printf("Meio rural, perfeito para iniciar sua jornada!\n");
                        break;
                    /* fazer usuario voltar caso insira alguma das opcoes diferentes*/
                    default:
                        printf("\n* Opção Inválida! Tente Novamente *\n");
                        continue;
                    }
                }
            }

            /* PORTE DO PERSONAGEM:
             if e else para fazer a restricao caso a raca do personagem
            for Anao, ele nao podera escolher o porte Grande*/
            if (raca != 2)
            {
                while (porte != 1 && porte != 2 && porte != 3)
                {
                    printf("\n  %s, qual sua altura?\n", nome);
                    printf("1. Grande, de 2m \n");
                    printf("2. Médio, de 1.70m\n");
                    printf("3. Pequeno, de 1.50m\n");
                    printf("-> ");
                    scanf("%d", &porte);
                    printf(": ");
                    switch (porte)
                    {
                    case 1:
                        porte = 1;
                        printf("Grande para intimdar seus inimigos! Ótima escolha!\n");
                        break;
                    case 2:
                        porte = 2;
                        printf("Porte médio, sem exageros certo?\n");
                        break;
                    case 3:
                        porte = 3;
                        printf("Altura nem é tudo, da pra ser mais ágil e rápido sendo "
                               "pequeno...\n");
                        break;
                    /* fazer usuario voltar caso insira alguma das opcoes diferentes*/
                    default:
                        printf("\n* Opção Inválida! Tente Novamente *\n");
                        continue;
                    }
                }
            }
            else
            {
                while (porte != 2 && porte != 3)
                {
                    printf("\n  %s, qual sua altura?\n", nome);
                    printf("2. Médio, de 1.45m\n");
                    printf("3. Pequeno, de 1.20m\n");
                    printf("-> ");
                    scanf("%d", &porte);
                    printf(": ");
                    switch (porte)
                    {
                    case 2:
                        porte = 2;
                        printf("Porte médio, sem exageros certo?\n");
                        break;
                    case 3:
                        porte = 3;
                        printf("Altura nem é tudo, da pra ser mais ágil e rápido sendo "
                               "pequeno...\n");
                        break;
                    /* fazer usuario voltar caso insira alguma das opcoes */
                    default:
                        printf("\n* Opção Inválida! Tente Novamente *\n");
                        continue;
                    }
                }
            }

            /* HISTORIA PREVIA DO PERSONAGEM:
            historia em que o usuário digitar, com restricao de
            no maximo 400 caracteres*/
            printf("\nAgora para finalizar, conte-nos uma história prévia de como "
                   "seu personagem viveu até esse momento. [até 400 caracteres] : ");
            scanf(" %[^\n]", historiaPrevia);

            /* verificar se a historia possui menos que 400 caracteres*/
            if (strlen(historiaPrevia) > 400)
            {
                printf("* \n História inválida! Você deve inserir até 400 caracteres! "
                       "*\n\n");
            }
            system("clear");
            printf("\nPronto para inciar a jornada, personagem criado!\n");
            continue;
        case 2:
            /* verificar antes se o personagem foi criado*/
            if (personagemCriado == 1)
            {
                while (vida > 0)
                {

                    system("clear");

                    printf("\n\n");
                    printf("        ________________________        "
                           "_______________________       \n");
                    printf("        | ---------------------- \\____/ "
                           "______________________|      \n");
                    printf("        |     LIVRO DA VIDA      |    |                      "
                           " |       \n");
                    printf("        |    CRONICAS DO REINO   |    | 234.Avalon "
                           "Drakeheart |       \n");
                    printf("        | ---------------------- |    | 235.Ezekiel "
                           "Silvertom |       \n");
                    printf("        |   'Em um mundo de      |    | 236.Astrid Stormborn "
                           " |       \n");
                    printf("        |  mistérios, um livro   |    | 237.%-20s            "
                           " |       \n",
                           nome);
                    printf("        |  místico guarda os     |    |                      "
                           " |       \n");
                    printf("        |  destinos dos          |    |                      "
                           " |       \n");
                    printf("        |  escolhidos, onde são  |    |                      "
                           " |       \n");
                    printf("        |  eternamente gravados  |    |                      "
                           " |       \n");
                    printf("        |  nas páginas do Livro  |    |                      "
                           " |       \n");
                    printf("        |  da Vida'              |____|                  "
                           "2945 |       \n");
                    printf("        |_______________________ /    \\ "
                           "______________________|      \n");
                    printf("\n\n");

                    printf("    *Bem-vindo, viajante! Me chamo Thalamar, o ancião "
                           "Místico! Você adentrou as terras de um lugar lendário "
                           "conhecido como 'Crônicas do Reino'. Aqui, a magia permeia "
                           "cada centímetro e criaturas fantásticas habitam as "
                           "florestas, montanhas e cidades. Permita-me contar um pouco "
                           "sobre este mundo maravilhoso.*\n\n");
                    printf(
                        "\n    [Thalamar]: -O Reino é composto por várias regiões, cada "
                        "uma com sua própria história e peculiaridades. Temos a "
                        "majestosa Floresta Obscura, onde criaturas místicas, tenebrosas "
                        "e ancestrais coexistem em meio ao caos. Além disso, há a "
                        "imponente Montanha dos Dragões, lar de antigas feras aladas e "
                        "lendários tesouros escondidos. E, por fim, temos as cidades do "
                        "Reino, que são verdadeiras maravilhas! A capital, chamada "
                        "Lumina, é uma metrópole brilhante e cheia de vida, com feiras "
                        "encantadas, guildas de magos e castelos magníficos.\n\n");

                    if (meta == 1)
                    {
                        int escolha = 0;
                        printf("\n    [Thalamar]: -Como Ancião e seu condutor, irei "
                               "guiá-lo até a capital, onde você poderá buscar a ascensão "
                               "ao trono desta cidade magnífica. Sua escolha de governar o "
                               "reino será posta à prova!\n\n");

                        printf(
                            "\n\nFinalmente, chegamos ao seu destino! A partir de agora, "
                            "lembre-se de escolher com sabedoria suas próximas ações, pois "
                            "cada decisão terá suas próprias consequências!\n");
                        printf("\nMuito bem %s, qual rota você deseja percorrer para "
                               "alcançar a capital Lumina?\n\n",
                               nome);
                        printf("1. Ir a pé para a porta do pálacio. Opção demorada porém "
                               "segura!\n");
                        printf("2. Pegar carona com algum cidadão. Opcão imprevisível!\n");
                        printf(
                            "3. Comprar um cavalo para chegar ao portão. Opção Rápida!\n");
                        printf("-> ");
                        scanf("%d", &escolha);
                        system("clear");
                        switch (escolha)
                        {
                        case 1:
                            printf("\n\nA caminhada demorou porém você não teve "
                                   "contratempos!\n");
                            break;
                        case 2:
                            printf("\n\nVocê pegou carona com um cidadão gentil e chegou "
                                   "rapidamente e sem problemas!\n");
                            break;
                        case 3:
                            printf(
                                "\n\nNem tudo são flores! O vendedor lhe enganou e vendeu um "
                                "burrinho, que demorou muito mais para chegar ao destino!\n");
                            break;
                        }
                    }
                    else if (meta == 2)
                    {
                        int escolha = 0;
                        printf("    %s, como seu guia, vou levá-lo à Montanha dos Dragões, "
                               "onde se encontram os tesouros mais valiosos do reino. Se "
                               "seu objetivo é se tornar rico, este é o lugar perfeito "
                               "para buscar sua fortuna!\n\n",
                               nome);

                        printf("*Finalmente, chegamos ao seu destino! A partir de agora, "
                               "lembre-se de escolher com sabedoria suas próximas ações, "
                               "pois cada decisão terá suas próprias consequências!*\n");
                        printf("\nMuito bem %s, qual rota você deseja percorrer para "
                               "alcançar a Montanha dos Dragões?\n\n",
                               nome);
                        printf("1. Ir pelo caminho de lava onde o caminho é mais perigoso, "
                               "porém menor!\n");
                        printf("2. Escalar, caminho cansativo porém seguro!\n");
                        printf("3. Ir pelo caminho de pedra, caminho mais longo porém sem "
                               "obstáculos!\n");
                        printf("-> ");
                        scanf("%d", &escolha);
                        system("clear");
                        switch (escolha)
                        {
                        case 1:
                            printf("\n\nAo seguir pelo caminho de lava, infelizmente, você "
                                   "escorregou e acabou queimando o pé! Isso resultou em uma "
                                   "perda de 20 pontos de vida.\n");
                            break;
                        case 2:
                            printf("\n\nVocê optou por escalar a montanha, o que resultou em "
                                   "cansaço, mas sem nenhum ferimento\n");
                            break;
                        case 3:
                            printf("\n\nVocê decidiu seguir o caminho de pedra, embora tenha "
                                   "sido mais demorado, você não está cansado nem ferido.\n");
                            break;
                        }
                    }
                    else if (meta == 3)
                    {
                        int escolha = 0;
                        printf("    Desejo-lhe boa sorte, %s, pois irei conduzi-lo à "
                               "floresta mais perigosa e assombrosa que você já viu. "
                               "Juntos, vamos direto à raiz do problema para erradicar o "
                               "mal que assola essa região!\n\n",
                               nome);
                        printf("Finalmente, chegamos ao seu destino! A partir de agora, "
                               "lembre-se de escolher com sabedoria suas próximas ações, "
                               "pois cada decisão terá suas próprias consequências!\n");
                        printf("\nMuito bem %s, qual rota você deseja percorrer para "
                               "alcançar a Floresta?\n\n",
                               nome);
                        printf("1. Ir pelo lago tenebroso, caminho com obstáculos, porém, "
                               "menor!\n");
                        printf("2. Ir pela trilha sombria, caminho desconhecido!\n");
                        printf("3. Ir pela luz que adentra as árvores densas, caminho "
                               "demorado porém seguro!\n");
                        printf("-> ");
                        scanf("%d", &escolha);
                        system("clear");
                        switch (escolha)
                        {
                        case 1:
                            printf("\n\nVocê teve um desempenho excepcional! Conseguiu "
                                   "superar todos os obstáculos sem se machucar e economizou "
                                   "um tempo valioso!\n");
                            break;
                        case 2:
                            printf("\n\nVocê acabou se perdendo e demorou muito tempo pra "
                                   "chegar!\n");
                            break;
                        case 3:
                            printf("\n\nVocê escolheu um caminho extremamente seguro! Como "
                                   "prometido, apesar da demora, você chegou ao seu destino "
                                   "completamente ileso!\n");
                            break;
                        }
                    }
                    int evento2 = 0; /* inicio do evento 2 */
                    int evento3 = 0;
                    /* do{  botar quando terminar o evento 3, para ter uma opcao de voltar
                     * aqui. Deixar o evento 3 dentro dele.*/
                    if (meta == 1)
                    {
                        do
                        {
                            /* int evento2 = 0; acho que nn precisa disso */
                            printf("Você conseguiu chegar a porta do Palácio e lá se "
                                   "encontrava a velha guarda leal!\n");
                            printf("Ao chegar na porta do palácio uma bela donzela estava "
                                   "tentando entrar no reino para buscar seu filho que foi "
                                   "preso por engano. Porém os guardas não deixaram-na "
                                   "entrar e agrediram ela, fazendo com que ela se "
                                   "machucasse muito!\nOque deseja fazer?\n");
                            if (alinhamento != 3)
                            {
                                printf("1. Ajudar a moça e limpar suas feridas!\n");
                                printf("2. Ser corajoso e enfrentar os guardas para ajudar a "
                                       "moça a pegar seu filho!\n");
                                printf("3. Ignorá-la e zombar dela!\n");
                                printf("-> ");
                                scanf("%d", &evento2);
                                switch (evento2)
                                {
                                case 1:
                                    printf("Ótima atitude! Você conseguiu ajudá-la e ela ainda "
                                           "lhe deu uma poção que cura 20 pontos de vida!\n");

                                    break;
                                case 2:
                                    printf("As vezes ser corajoso não ajuda muito... Você acabou "
                                           "levando uma surra e perdeu 10 pontos de vida!\n");
                                    vida = vida - 10;

                                    break;
                                case 3:
                                    printf("Você passou reto e ainda zombou dela, debochado "
                                           "hein! Isso fez com que você economizasse tempo!\n");

                                    break;
                                }
                                /* break;*/
                            }
                            else if (alinhamento == 3)
                            {
                                printf("1. Ajudar a moça e limpar suas feridas!\n");
                                printf("2. Ser corajoso e enfrentar os guardas para ajudar a "
                                       "moça a pegar seu filho!\n");
                                printf("-> ");
                                scanf("%d", &evento2);
                                switch (evento2)
                                {
                                case 1:
                                    printf("Ótima atitude! Você conseguiu ajudá-la e ela ainda "
                                           "lhe deu uma poção que cura 20 pontos de vida!\n");

                                    break;
                                case 2:
                                    printf("As vezes ser corajoso não ajuda muito... Você acabou "
                                           "levando uma surra e perdeu 10 pontos de vida!\n");
                                    vida = vida - 10;

                                    break;
                                }
                                /* break; */
                            }

                            printf("\n\nApesar do contratempo com a donzela, você acabou "
                                   "entrando no palácio e agora precisa tomar uma decisão "
                                   "importante para chegar até o rei!\n");
                            if (profissao == 1)
                            {
                                printf("1. Passar despercebido pelos guardas!\n");
                                printf("2. Como um bom guerreiro, pegar a espada de um dos "
                                       "guardas e travar uma batalha!\n");
                                printf("3. Falar com os guardas tranquilamente!\n");
                                printf("->");
                                scanf("%d", &evento3);
                                switch (evento3)
                                {
                                case 1:
                                    printf("Você não obteve sucesso e foi pego pelos guardas! "
                                           "Isso te fez voltar para o lado de fora...\n\n\n");

                                    break;
                                case 2:
                                    printf("Você é o melhor guerreiro que eu ja vi... Quanta "
                                           "habilidade com a espada! Você conseguiu deter todos "
                                           "os guardas e entrou para o corredor real!\n");

                                    break;
                                case 3:
                                    printf("Os guardas, insatisfeitos com o modo de governo do "
                                           "rei, serviram de cúmplice e deixaram você entrar! "
                                           "Quanta sorte!\n");

                                    break;
                                }
                                /* break; */
                            }
                            else if (profissao == 2)
                            {
                                printf("1. Passar despercebido pelos guardas!\n");
                                printf("2. Como um bom mago, usar o feitiço Glaciem "
                                       "Circumdare!\n");
                                printf("3. Falar com os guardas tranquilamente!\n");
                                printf("->");
                                scanf("%d", &evento3);
                                switch (evento3)
                                {
                                case 1:
                                    printf("Você não obteve sucesso e foi pego pelos guardas! "
                                           "Isso te fez voltar para o lado de fora...\n\n\n");

                                    break;
                                case 2:
                                    printf(
                                        "Você é o melhor mago que eu ja vi... Você simplesmente "
                                        "congelou todos com esse feitiço! Irado!\n");

                                    break;
                                case 3:
                                    printf("Os guardas, insatisfeitos com o modo de governo do "
                                           "rei, serviram de cúmplice e deixaram você entrar! "
                                           "Quanta sorte!\n");

                                    break;
                                }
                                /* break; */
                            }
                            else if (profissao == 3)
                            {
                                printf("1. Lutar com todos guardas!\n");
                                printf("2. Passar despercebido por todos!\n");
                                printf("3. Falar com os guardas tranquilamente!\n");
                                printf("->");
                                scanf("%d", &evento3);
                                switch (evento3)
                                {
                                case 1:
                                    printf("Você não obteve sucesso e acabou apanhando! Eram "
                                           "muitos... Isso te fez voltar para o lado de "
                                           "fora...\n\n\n");

                                    break;
                                case 2:
                                    printf(
                                        "Você é o melhor ladino que eu ja vi... passou "
                                        "despercebido por todos e não fez um barulho sequer!\n");

                                    break;
                                case 3:
                                    printf("Os guardas, insatisfeitos com o modo de governo do "
                                           "rei, serviram de cúmplice e deixaram você entrar! "
                                           "Quanta sorte!\n");

                                    break;
                                }
                                /* break; */
                            }
                        } while (evento3 == 1); /* fecha chaves do "do" */
                    }
                    else if (meta == 2)
                    {
                        do
                        {
                            printf("\nEnfim você chegou ao topo da montanha!\n");
                            printf("Ao aproximar-se de um grande e perigoso mar de lava, "
                                   "onde você deve acertar seus saltos para passar, você se "
                                   "deparou com um pequeno goblin que estava precisando "
                                   "passar para pegar um pouco de dinheiro também, já que "
                                   "sua esposa estava doente! Oque deseja fazer?\n\n");
                            if (alinhamento != 3)
                            {
                                printf("1. Ajuda-lo a ultrapassar o rio de lava.\n");
                                printf("2. Emprestar um pouco de dinheiro\n");
                                printf("3. Ignorá-lo e dar-lhe um empurrão\n");
                                printf("-> ");
                                scanf("%d", &evento2);
                                switch (evento2)
                                {
                                case 1:
                                    printf(
                                        "Bela atitude! O goblin conseguiu pegar algumas moedas "
                                        "do outro lado da ponte e te deu uma poção de cura como "
                                        "agradecimento! Você recuperou 10 pontos de vida!\n");
                                    vida = vida + 10;
                                    break;
                                case 2:
                                    printf("Você ajudou o goblin com um pouco de dinheiro e ele "
                                           "saiu muito contente!\n");
                                    break;
                                case 3:
                                    printf("O goblin ficou com muita raiva e devolveu o empurrão "
                                           "que fez você tropessar e queimar a mão na lava! Isso "
                                           "te tirou 10 pontos de vida\n");
                                    vida = vida - 10;
                                    break;
                                }
                            }
                            else if (alinhamento == 3)
                            {
                                printf("1. Ajuda-lo a ultrapassar o rio de lava.\n");
                                printf("2. Emprestar um pouco de dinheiro\n");
                                printf("-> ");
                                scanf("%d", &evento2);
                                switch (evento2)
                                {
                                case 1:
                                    printf(
                                        "Bela atitude! O goblin conseguiu pegar algumas moedas "
                                        "do outro lado da ponte e te deu uma poção de cura como "
                                        "agradecimento! Você recuperou 10 pontos de vida!\n");
                                    vida = vida + 10;
                                    break;
                                case 2:
                                    printf("Você ajudou o goblin com um pouco de dinheiro e ele "
                                           "saiu muito contente!\n");
                                    break;
                                }
                            } /* inicio evento 3 da meta 2 */
                            printf("\n\nApesar do contratempo com o goblin, você acabou "
                                   "atravessando o rio de lava mas se deparou com um grande "
                                   "dragão adormecido! Oque você vai fazer?\n");
                            if (profissao == 1)
                            {
                                printf("1. Passar despercebido pelo dragão!\n");
                                printf("2. Como um bom guerreiro, pegar a espada e "
                                       "enfrentá-lo!\n");
                                printf("3. Mudar a rota para uma mais longa!\n");
                                printf("->");
                                scanf("%d", &evento3);
                                switch (evento3)
                                {
                                case 1:
                                    printf(
                                        "Você não obteve sucesso e foi pego pelo dragão! Isso te "
                                        "fez voltar para o outro lado do rio de lava...\n\n\n");

                                    break;
                                case 2:
                                    printf("Você é o melhor guerreiro que eu ja vi... Quanta "
                                           "habilidade com a espada! Você conseguiu deter a fera "
                                           "e se aproximar do tesouro!\n");

                                    break;
                                case 3:
                                    printf("Quanta demora! Achava que não ia chegar nunca! "
                                           "Apesar disso, estamos mais próximos do tesouro!\n");

                                    break;
                                }
                                /* break; */
                            }
                            else if (profissao == 2)
                            {
                                printf("1. Passar despercebido pelo dragão!\n");
                                printf(
                                    "2. Como um bom mago, usar o feitiço Visibilis Absens\n");
                                printf("3. Mudar a rota para uma mais longa!\n");
                                printf("->");
                                scanf("%d", &evento3);
                                switch (evento3)
                                {
                                case 1:
                                    printf(
                                        "Você não obteve sucesso e foi pego pelo dragão! Isso te "
                                        "fez voltar para o outro lado do rio de lava...\n\n\n");

                                    break;
                                case 2:
                                    printf("O dragão acordou mas nem te viu! Você simplesmente "
                                           "ficou invisível com esse feitiço! Que irado!\n");

                                    break;
                                case 3:
                                    printf("Quanta demora! Achava que não ia chegar nunca! "
                                           "Apesar disso, estamos mais próximos do tesouro!\n");

                                    break;
                                }
                                /*  break; */
                            }
                            else if (profissao == 3)
                            {
                                printf("1. Lutar com o dragão!\n");
                                printf("2. Passar despercebido pelo dragão!\n");
                                printf("3. Mudar a rota para uma mais longa!\n");
                                printf("->");
                                scanf("%d", &evento3);
                                switch (evento3)
                                {
                                case 1:
                                    printf(
                                        "Você não obteve sucesso e acabou apanhando! Isso te fez "
                                        "voltar para o outro lado do rio de lava...\n\n\n");

                                    break;
                                case 2:
                                    printf(
                                        "Você é o melhor ladino que eu ja vi... passou "
                                        "despercebido pela fera e não fez um barulho sequer!\n");

                                    break;
                                case 3:
                                    printf("Quanta demora! Achava que não ia chegar nunca! "
                                           "Apesar disso, estamos mais próximos do tesouro!\n");

                                    break;
                                }
                                /* break; */
                            }
                        } while (evento3 == 1); /* fecha chaves do "do" */
                    }
                    else if (meta == 3)
                    {
                        do
                        {
                            printf("Você finalmente chegou a parte mais sombria da floresta, "
                                   "é aqui que seu desafio começa!\n\n");
                            printf("Você terá que procurar por Dormagon, o ser mais sombrio "
                                   "e maligno dessas terras. Depois de vencê-lo, finalmente "
                                   "o mal não irá mais perturbar os cidadãos e será "
                                   "estabelecido a paz aqui!\n");
                            printf("Antes de iniciar sua procura, um pequeno garoto que "
                                   "estava perdido na floresta pede sua ajuda para sair de "
                                   "lá. Oque deseja fazer?\n");
                            if (alinhamento != 3)
                            {
                                printf("1. Ajuda-lo a sair da floresta. Você perderá tempo com "
                                       "isso!\n");
                                printf("2. Apenas falar como volta.\n");
                                printf("3. Ignorá-lo e seguir em busca de Dormagon, sem perder "
                                       "tempo!\n");
                                printf("-> ");
                                scanf("%d", &evento2);
                                switch (evento2)
                                {
                                case 1:
                                    printf("Bela atitude! Apesar de perder tempo, você ajudou o "
                                           "menino e ele lhe deu uma poção de cura! Com isso, "
                                           "você voltou ate onde estava e recuperou 10 pontos de "
                                           "sua vida!\n");
                                    vida = vida + 10;
                                    break;
                                case 2:
                                    printf("O menino obedeceu e foi com medo. Não se teve mais "
                                           "notícias dele...\n");
                                    break;
                                case 3:
                                    printf("O menino continuou perdido e sem rumo...\n");

                                    break;
                                }
                            }
                            else if (alinhamento == 3)
                            {
                                printf("1. Ajuda-lo a sair da floresta. Você perderá tempo com "
                                       "isso!\n");
                                printf("2. Apenas falar como volta.\n");
                                printf("-> ");
                                scanf("%d", &evento2);
                                switch (evento2)
                                {
                                case 1:
                                    printf("Bela atitude! Apesar de perder tempo, você ajudou o "
                                           "menino e ele lhe deu uma poção de cura! Com isso, "
                                           "você voltou ate onde estava e recuperou 10 pontos de "
                                           "sua vida!\n");
                                    vida = vida + 10;
                                    break;
                                case 2:
                                    printf("O menino obedeceu e foi com medo. Não se teve mais "
                                           "notícias dele...\n");
                                    break;
                                }
                            }
                            printf("\n\nApesar do contratempo com o menino, você acabou se "
                                   "deparando com Sukur, um dos servos de Dormagon. Ele está "
                                   "adormecido na frente do portal do reino de Dormagon, "
                                   "oque vai fazer?\n\n");
                            if (profissao == 1)
                            {
                                printf("1. Passar despercebido pelo Sukur!\n");
                                printf("2. Como um bom guerreiro, pegar a espada e "
                                       "enfrentá-lo!\n");
                                printf("3. Mudar a rota para uma mais longa!\n");
                                printf("->");
                                scanf("%d", &evento3);
                                switch (evento3)
                                {
                                case 1:
                                    printf("Você não obteve sucesso e foi pego pelo Sukur! Isso "
                                           "te fez voltar para muito longe...\n\n\n");

                                    break;
                                case 2:
                                    printf("Você é o melhor guerreiro que eu ja vi... Quanta "
                                           "habilidade com a espada! Você conseguiu deter Sukur "
                                           "e se atravessar o portal do Dormagon!\n");

                                    break;
                                case 3:
                                    printf("Quanta demora! Achava que não ia chegar nunca! "
                                           "Apesar disso, conseguimos entrar pelos fundos do "
                                           "reino de Dormagon!\n");

                                    break;
                                }
                                /* break; */
                            }
                            else if (profissao == 2)
                            {
                                printf("1. Passar despercebido pelo Sukur!\n");
                                printf("2. Como um bom mago, usar o feitiço Dissimulatio "
                                       "Mortis (Dissimulação da Morte)!\n");
                                printf("3. Mudar a rota para uma mais longa!\n");
                                printf("->");
                                scanf("%d", &evento3);
                                switch (evento3)
                                {
                                case 1:
                                    printf("Você não obteve sucesso e foi pego pelo Sukur! Isso "
                                           "te fez voltar para muito longe...\n\n\n");

                                    break;
                                case 2:
                                    printf("Que feitiço é esse?! Você conseguiu forjar a própria "
                                           "morte e enganar o Sukur! Desse modo, você passou por "
                                           "ele com facilidade! Irado!\n");

                                    break;
                                case 3:
                                    printf("Quanta demora! Achava que não ia chegar nunca! "
                                           "Apesar disso, conseguimos entrar pelos fundos do "
                                           "reino de Dormagon!\n");

                                    break;
                                }
                                /* break; */
                            }
                            else if (profissao == 3)
                            {
                                printf("1. Lutar com o Sukur!\n");
                                printf("2. Passar despercebido pelo Sukur!\n");
                                printf("3. Mudar a rota para uma mais longa!\n");
                                printf("->");
                                scanf("%d", &evento3);
                                switch (evento3)
                                {
                                case 1:
                                    printf("Você não obteve sucesso e acabou apanhando! Isso te "
                                           "fez voltar para muito longe...\n\n\n");

                                    break;
                                case 2:
                                    printf(
                                        "Você é o melhor ladino que eu ja vi... passou "
                                        "despercebido pelo Sukur e não fez um barulho sequer!\n");

                                    break;
                                case 3:
                                    printf("Quanta demora! Achava que não ia chegar nunca! "
                                           "Apesar disso, conseguimos entrar pelos fundos do "
                                           "reino de Dormagon!\n");

                                    break;
                                }
                                /* break; */
                            }
                        } while (evento3 == 1); /* fecha chaves do "do" */
                    }

                    if (meta == 1)
                    {
                        printf("\nAntes de entrar na sala do imperador, você terá que desafiar "
                               "Tiberius, o grande ancião do Rei!\n\n");
                        printf("[Tiberius] - Meu jovem, para passar por aqui você terá que "
                               "ganhar 2 vezes de mim no Jokempo. Tenho 112 anos e nunca "
                               "perdi uma sequer! Te desejo boa sorte...\n");

                        /* FAZER O JOKEMPO
                        desafio final será uma charada que o Rei fará para sair do trono */
                    }
                    if (meta == 2)
                    {
                        printf("Estamos chegando perto do nosso objetivo! O mar de ouro "
                               "nos espera!\n");
                        printf(
                            "Ao aproximar-se da última sala, onde todo ouro se encontra, "
                            "você se depara com Ignis, a guarda da sala! Ignis é uma "
                            "guerreira que viveu toda sua vida ao lado dos dragões, ela "
                            "consegue se comunicar e tem uma ótima relação com eles!\n\n");
                        printf("[Ignis] - Olá novato... fiquei sabendo que você está atrás "
                               "de ficar rico e quer entrar na sala, certo? Bom, lamento "
                               "te dizer mas isso não vai rolar... Eu te proponho um "
                               "desafio, que consiste em ganhar de mim 2 vezes no Jokempô! "
                               "Eu nunca perdi em toda minha vida e ninguém conseguiu "
                               "entrar na sala... te desejo boa sorte!\n\n");

                        /* fazer jokempo
                          desafio final será uma charada dita pelo Dragão Orion, o boss
                          final */
                    }
                    if (meta == 3)
                    {
                        printf("Esse reino é assustador! Quantas criaturas estranhas e "
                               "assustadoras! Enfim, vamos rápido para a sala de Dormagon "
                               "para acabar com isso!\n");
                        printf("Ao chegar no corredor que dá para o calabouço de Dormagon, "
                               "o pior acontece, Sukur aparece de forma misteriosa e trava "
                               "um diálogo com você\n\n");
                        printf("[Sukur] - Não é tão fácil passar por mim, sabia? Apesar da "
                               "minha fúria neste momento, irei lhe propor um desafio, já "
                               "que você deseja tanto ver Dormagon... O desafio consiste "
                               "em você vencer de mim 2 vezes no Jokempô! Eu te desejo boa "
                               "sorte, ja que ninguém nunca venceu de mim!\n\n");

                        /* fazer jokempo
                          desafio final será uma charada feita por Dormagon após uma dura
                          batalha */
                    }
                    int vitoria = 0;
                    while (vitoria != 2)
                    {
                        int jokenpoUsuario;

                        int jokenpoAdversario = rand() % 3;
                        jokenpoAdversario++;

                        printf("Escolha o que deseja jogar: \n");
                        printf("1. Pedra\n");
                        printf("2. Papel\n");
                        printf("3. Tesoura\n");
                        printf("-> ");
                        if (scanf("%d", &jokenpoUsuario) != 1)
                        {
                            printf("Entrada inválida. Tente novamente.\n");
                            continue;
                        }

                        printf("Ele jogou: %d \n", jokenpoAdversario);
                        if ((jokenpoUsuario == 1 && jokenpoAdversario == 1) ||
                            (jokenpoUsuario == 2 && jokenpoAdversario == 2) ||
                            (jokenpoUsuario == 3 && jokenpoAdversario == 3))
                        {
                            printf("* Vocês empataram! Joguem Novamente. *\n\n");
                            continue;
                        }
                        else if ((jokenpoUsuario == 1 && jokenpoAdversario == 2) ||
                                 (jokenpoUsuario == 2 && jokenpoAdversario == 3) ||
                                 (jokenpoUsuario == 3 && jokenpoAdversario == 1))
                        {
                            printf("Não foi dessa vez... Você perdeu!\n");
                            vida -= 10;
                            printf("Você está com %d pontos de vida\n\n", vida);
                            if (vida <= 0)
                            {
                                printf("Game Over");
                                sairDoJogo = 1;
                                break;
                            }
                        }
                        else if (jokenpoUsuario != 1 && jokenpoUsuario != 2 && jokenpoUsuario != 3)
                        {
                            printf("\n* Opção Inválida! Tente Novamente *\n");
                            continue;
                        }
                        else
                        {
                            printf("Você ganhou!\n");
                            vitoria++;
                            continue;
                        }
                        continue;
                    }
                    if (meta == 1)
                    {
                        printf("\n[Tiberius] - Eu... eu não acredito que perdi. Depois de todos esses anos, me parece que você é um bom canditado a herdar o trono. Siga em frente para sala do Rei!\n\n");
                        printf("Enquanto a porta se abre lentamente, revelando uma sala majestosa e imponente, você entra com cautela. Seus olhos são imediatamente atraídos pela grandiosidade do trono no centro da sala, onde o Rei Jeremias está sentado, vestido em trajes reais que brilham com a luz suave das velas...\n\n");
                        printf("[Jere] - Pobre aventureiro, chegou até aqui para morrer em vão?! Eu não vou desistir tão fácil do meu reinado, para passar por cima de mim você terá que adivinhar 3 das mais difíceis charadas que este mundo já viu!\n\n");
                    }
                    else if (meta == 2)
                    {
                        printf("\n[Ignis] - Eu... eu não acredito que perdi. Depois de todos esses anos, acho que finalmente achei alguém digno de entrar nessa sala de riquezas!\n\n");
                        printf("Com um passo hesitante, você atravessa o portal que o leva à sala final, onde lendários tesouros estão expostos. O brilho dourado das moedas e gemas cintilantes ilumina a sala vasta e repleta de riquezas inimagináveis. Mas à medida que seus olhos vagam pelo tesouro, você percebe algo assombroso.\n\n");
                        printf("[Orion] - Olá pequeno aventureiro. Não esperava que eu estivesse lhe aguardando né? Bom, eu poderia te engolir tranquilamente, mas irei lhe fazer uma proposta e, se você conseguir, poderá pegar quanto ouro quiser desta sala!\n");
                        printf("* Orion te desafiou a acertar 3 charadas! Boa sorte nessa luta final! *\n\n");
                    }
                    else if (meta == 3)
                    {
                        printf("\n[Sukur] - Eu... eu não acredito que perdi. Depois de todos esses anos, acho que você poderá tentar sua sorte com o ser mais maligno daqui! Boa sorte pois vai precisar.\n\n");
                        printf("Com passos cuidadosos e tensos, você adentra a sala final, onde as sombras dançam em meio a uma aura de trevas. Um silêncio sinistro envolve o ambiente, enquanto as paredes estão adornadas com símbolos antigos e ameaçadores. No centro da sala, sobre um pedestal sombrio, repousa o temível chefe conhecido como Dormagon. Seu aspecto é verdadeiramente aterrorizante: uma figura colossal, envolta em uma armadura negra que exala uma presença ameaçadora. Olhos ardentes e sinistros brilham em meio às sombras, e suas garras afiadas parecem prontas para desferir golpes devastadores.\n\n");
                        printf("[Dormagon] - Você ousa entrar em meu domínio, tolo mortal? Poderia causar as maiores dores que você poderia sentir, mas vou lhe propor um desafio, uma chance. Caso não vença, você será todo meu!\n\n");
                        printf("* Dormagon te desafiou a acertar 3 charadas! Boa sorte nessa luta final! *\n\n");
                    }

                    int i = 0;
                    srand(time(NULL));
                    int acerto = 0;
                    int respostaCharada = 0;
                    int charadaRespondida[10] = {0}; /* Inicializa o array charadaRespondida com 0 */

                    while (acerto != 3)
                    {
                        int charadaSorteada;
                        charadaSorteada = rand() % 11;
                        charadaSorteada++;

                        /* Verifica se a charadaSorteada já foi respondida */
                        int repetido = 0;
                        int j;
                        for (j = 0; j < i; j++)
                        {
                            if (charadaRespondida[j] == charadaSorteada)
                            {
                                repetido = 1;
                                break;
                            }
                        }

                        if (repetido == 1)
                        {
                            continue; /* Sorteia novamente se o número já tiver sido respondido */
                        }

                        charadaRespondida[i] = charadaSorteada;
                        i++;

                        if (charadaSorteada == 1)
                        {

                            printf("O que é, o que é? Quem faz, não usa. Quem usa, não vê. Quem vê, não quer usar.\n");
                            printf("1. Bengala\n");
                            printf("2. Óculos de Sol\n");
                            printf("3. Caixão\n");
                            printf("-> ");
                            scanf("%d", &respostaCharada);
                            if (respostaCharada == 3)
                            {
                                printf("Parabéns! Você Acertou.\n\n");
                                acerto++;
                            }
                            else
                            {
                                printf("Hmm que pena, você errou! Isso te causou menos 50 pontos de vida.");
                                vida -= 50;
                                printf("Você está com %d pontos de vida\n\n", vida);
                                if (vida <= 0)
                                {
                                    printf("Game Over\n");
                                    sairDoJogo = 1;
                                    exit(0);
                                }
                            }
                        }
                        if (charadaSorteada == 2)
                        {
                            printf("O que é que todos têm, alguns perdem, mas ninguém pode dar?\n");
                            printf("1. Passado\n");
                            printf("2. Sombra\n");
                            printf("3. A vida\n");
                            printf("-> ");
                            scanf("%d", &respostaCharada);
                            if (respostaCharada == 1)
                            {
                                printf("Parabéns! Você Acertou.\n\n");
                                acerto++;
                            }
                            else
                            {
                                printf("Hmm que pena, você errou! Isso te causou menos 50 pontos de vida.");
                                vida -= 50;
                                printf("Você está com %d pontos de vida\n\n", vida);
                                if (vida <= 0)
                                {
                                    printf("Game Over\n");
                                    sairDoJogo = 1;
                                    exit(0);
                                }
                            }
                        }
                        if (charadaSorteada == 3)
                        {
                            printf("O que é que sobe e desce sem se mover?\n");
                            printf("1. O Sol\n");
                            printf("2. Temperatura\n");
                            printf("3. Elevador\n");
                            printf("-> ");
                            scanf("%d", &respostaCharada);
                            if (respostaCharada == 2)
                            {
                                printf("Parabéns! Você Acertou.\n\n");
                                acerto++;
                            }
                            else
                            {
                                printf("Hmm que pena, você errou! Isso te causou menos 50 pontos de vida.");
                                vida -= 50;
                                printf("Você está com %d pontos de vida\n\n", vida);
                                if (vida <= 0)
                                {
                                    printf("Game Over\n");
                                    sairDoJogo = 1;
                                    exit(0);
                                }
                            }
                        }
                        if (charadaSorteada == 4)
                        {
                            printf("O que é que todos usam, mas ninguém vê?\n");
                            printf("1. Óculos\n");
                            printf("2. O nome\n");
                            printf("3. O cérebro\n");
                            printf("-> ");
                            scanf("%d", &respostaCharada);
                            if (respostaCharada == 3)
                            {
                                printf("Parabéns! Você Acertou.\n\n");
                                acerto++;
                            }
                            else
                            {
                                printf("Hmm que pena, você errou! Isso te causou menos 50 pontos de vida.");
                                vida -= 50;
                                printf("Você está com %d pontos de vida\n\n", vida);
                                if (vida <= 0)
                                {
                                    printf("Game Over\n");
                                    sairDoJogo = 1;
                                    exit(0);
                                }
                            }
                        }
                        if (charadaSorteada == 5)
                        {
                            printf("Diga o que sou e eu desapareço. O que sou eu?\n");
                            printf("1. Segredo\n");
                            printf("2. Silêncio\n");
                            printf("3. Eco\n");
                            printf("-> ");
                            scanf("%d", &respostaCharada);
                            if (respostaCharada == 2)
                            {
                                printf("Parabéns! Você Acertou.\n\n");
                                acerto++;
                            }
                            else
                            {
                                printf("Hmm que pena, você errou! Isso te causou menos 50 pontos de vida.");
                                vida -= 50;
                                printf("Você está com %d pontos de vida\n\n", vida);
                                if (vida <= 0)
                                {
                                    printf("Game Over\n");
                                    sairDoJogo = 1;
                                    exit(0);
                                }
                            }
                        }
                        if (charadaSorteada == 6)
                        {
                            printf("O que é, o que é? Fica cheio durante o dia e vazio durante a noite.\n");
                            printf("1. O sapato\n");
                            printf("2. A rua\n");
                            printf("3. A escola\n");
                            printf("-> ");
                            scanf("%d", &respostaCharada);
                            if (respostaCharada == 1)
                            {
                                printf("Parabéns! Você Acertou.\n\n");
                                acerto++;
                            }
                            else
                            {
                                printf("Hmm que pena, você errou! Isso te causou menos 50 pontos de vida.");
                                vida -= 50;
                                printf("Você está com %d pontos de vida\n\n", vida);
                                if (vida <= 0)
                                {
                                    printf("Game Over\n");
                                    sairDoJogo = 1;
                                    exit(0);
                                }
                            }
                        }
                        if (charadaSorteada == 7)
                        {
                            printf(" O que é, o que é? Vários pontinhos amarelos na parede.\n");
                            printf("1. Reflexo\n");
                            printf("2. Fandangos Alpinistas\n");
                            printf("3. Sujeira\n");
                            printf("-> ");
                            scanf("%d", &respostaCharada);
                            if (respostaCharada == 2)
                            {
                                printf("Parabéns! Você Acertou.\n\n");
                                acerto++;
                            }
                            else
                            {
                                printf("Hmm que pena, você errou! Isso te causou menos 50 pontos de vida.");
                                vida -= 50;
                                printf("Você está com %d pontos de vida\n\n", vida);
                                if (vida <= 0)
                                {
                                    printf("Game Over\n");
                                    sairDoJogo = 1;
                                    exit(0);
                                }
                            }
                        }
                        if (charadaSorteada == 8)
                        {
                            printf("O que é, o que é? Tem no meio do ovo.\n");
                            printf("1. Gema\n");
                            printf("2. Clara\n");
                            printf("3. A letra 'V'\n");
                            printf("-> ");
                            scanf("%d", &respostaCharada);
                            if (respostaCharada == 3)
                            {
                                printf("Parabéns! Você Acertou.\n\n");
                                acerto++;
                            }
                            else
                            {
                                printf("Hmm que pena, você errou! Isso te causou menos 50 pontos de vida.");
                                vida -= 50;
                                printf("Você está com %d pontos de vida\n\n", vida);
                                if (vida <= 0)
                                {
                                    printf("Game Over\n");
                                    sairDoJogo = 1;
                                    exit(0);
                                }
                            }
                        }
                        if (charadaSorteada == 9)
                        {
                            printf("Eu nunca fui, mas sempre serei. Ninguém nunca me viu, e nunca verão. Ainda assim, sou a esperança de todos. Quem sou eu?\n");
                            printf("1. Sonhos\n");
                            printf("2. Futuro\n");
                            printf("3. Eternidade\n");
                            printf("-> ");
                            scanf("%d", &respostaCharada);
                            if (respostaCharada == 2)
                            {
                                printf("Parabéns! Você Acertou.\n\n");
                                acerto++;
                            }
                            else
                            {
                                printf("Hmm que pena, você errou! Isso te causou menos 50 pontos de vida.");
                                vida -= 50;
                                printf("Você está com %d pontos de vida\n\n", vida);
                                if (vida <= 0)
                                {
                                    printf("Game Over\n");
                                    sairDoJogo = 1;
                                    exit(0);
                                }
                            }
                        }
                        if (charadaSorteada == 10)
                        {
                            printf("O que é o que é? Voa sem ter asas e chora sem ter olhos.\n");
                            printf("1. O vento\n");
                            printf("2. O pensamento\n");
                            printf("3. A Nuvem\n");
                            printf("-> ");
                            scanf("%d", &respostaCharada);
                            if (respostaCharada == 3)
                            {
                                printf("Parabéns! Você Acertou.\n\n");
                                acerto++;
                            }
                            else
                            {
                                printf("Hmm que pena, você errou! Isso te causou menos 50 pontos de vida.");
                                vida -= 50;
                                printf("Você está com %d pontos de vida\n\n", vida);
                                if (vida <= 0)
                                {
                                    printf("Game Over\n");
                                    sairDoJogo = 1;
                                    exit(0);
                                }
                            }
                        }

                    } /* fecha chaves do while que faz o loop para as charadas */
                    system("clear");
                    if (meta == 1)
                    {
                        printf("\n\n[Jere] - Bom, eu herdei esse trono por mais de 60 anos... Acho que essa linda capital merece um novo Rei! Parabéns %s!\n\n", nome);
                        printf("\n\n* %s retorna à sua cidade natal *", nome);
                        printf("\n[Thalamar] - Parabéns iniciante, ou devo dizer, parabéns novo Rei! Agora a responsábilidade está toda em suas mãos e você tem o poder máximo aqui! Aproveite com sabedoria! Estou orgulhoso %s.\n\n", nome);
                        printf("Após inúmeras batalhas, desafios e sacrifícios, %s finalmente conclui sua jornada épica. Agora com o olhar cansado, mas repleto de orgulho e satisfação, reflete sobre todas as adversidades que enfrentou para chegar até aqui. Desde os primeiros passos, até os combates, você nunca se permitiu desistir. Cada luta travada foi uma prova de sua coragem e habilidade, e cada obstáculo superado fortaleceu sua determinação.\n\n", nome);
                    }
                    else if (meta == 2)
                    {
                        printf("\n\n[Orion] - Você... acertou todas! Surpreendente! Pode pegar toda riqueza que quiser %s!\n\n", nome);
                        printf("\n\n* %s retorna à sua cidade natal *", nome);
                        printf("\n[Thalamar] - Parabéns iniciante, ou devo dizer, parabéns novo milionário! Novas aventuras te esperam e eu estarei aqui para ser seu guia! Estou orgulhoso %s.\n\n", nome);
                        printf("Após inúmeras batalhas, desafios e sacrifícios, %s finalmente conclui sua jornada épica. Agora com o olhar cansado, mas repleto de orgulho e satisfação, reflete sobre todas as adversidades que enfrentou para chegar até aqui. Desde os primeiros passos, até os combates, você nunca se permitiu desistir. Cada luta travada foi uma prova de sua coragem e habilidade, e cada obstáculo superado fortaleceu sua determinação.\n\n", nome);
                    }
                    else if (meta == 3)
                    {
                        printf("\n\n[Dormagon] - Não acredito! Como?!! Guardarei seu nome, %s!\n\n", nome);
                        printf("Dormagon, derrotado pela mente afiada do %s, desaba em um estrondo ensurdecedor. A escuridão que o envolvia se dissipa, revelando a figura majestosa do verdadeiro herói que emergiu dessa jornada.\n\n", nome);
                        printf("\n\n* %s retorna à sua cidade natal *", nome);
                        printf("\n[Thalamar] - Parabéns iniciante, ou devo dizer, parabéns Herói! Você conseguiu destruir todo mal que rodeava nossa cidade! Seremos eternamente gratos por isso! Estou orgulhoso %s.\n\n\n", nome);
                        printf("Após inúmeras batalhas, desafios e sacrifícios, %s finalmente conclui sua jornada épica. Agora com o olhar cansado, mas repleto de orgulho e satisfação, reflete sobre todas as adversidades que enfrentou para chegar até aqui. Desde os primeiros passos, até os combates, você nunca se permitiu desistir. Cada luta travada foi uma prova de sua coragem e habilidade, e cada obstáculo superado fortaleceu sua determinação.\n\n", nome);
                    }
                    printf("Fim do Jogo.\n");
                    exit(0);
                } /* fecha chaves do while(!sairDoJogo) que faz um loop do jogo inteiro
                   */
            }
            else
            {
                system("clear");
                printf("\n* Primeiro crie seu personagem *\n\n");
                continue;
            }
            break;
        case 3:
            printf("Voce saiu do jogo");
            sairDoJogo = 1;
            break;

        /*sistema de voltar quando usuario digita nenhuma
        das opcoes disponiveis*/
        default:
            system("clear");
            printf("\n* Opção Inválida! Tente Novamente *\n\n");
            continue;

        } /* fecha chaves do switch case principal */

    } /* fecha chaves do while principal do jogo */
} /* fecha chaves do main */