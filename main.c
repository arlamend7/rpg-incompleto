#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#define HEALTH 55
#define CRITICO 4
#define Raca 4
#define FISICO 3
#define Armadura 4
#define ArmasPrimarias 6
#define ArmasSecundarias 3
#define magias 5

void selecionarFisico(int opcaoFisico);
void selecionarArmadura(int opcaoArmadura);
void selecionarArmaPrimaria(int opcaoArmaMelee);
void selecionarArmaSecundaria(int opcaoArmaRanged);

char ModeloPersonagem[FISICO][100] = {{"Magro"}, {"Normal"}, {"Gordo"}};
char TipoRaca[Raca][100] = {{"Humano"},{"Meio-anjo"}, {"Meio-demonio"}, {"Cyborg"}};
char TipoArmadura[Armadura][100] = {{"Couro"}, {"pele de dragao"}, {"armadura leve"}, {"armadura pesada"}};
char TiposArmaPrimaria[ArmasPrimarias][100] = {{"Katana"}, {"Espada Longa"}, {"Machado Taurico"}, {"Alabarda"}, {"Tridente"}, {"Marreta"}};
char TiposArmaSecundaria[ArmasSecundarias][100] = {{"Adaga"}, {"Espada curta"}, {"Shuriken"}};
char TipoMagias[magias][100] = {{"Cura"}, {"+DEFESA"}, {"FATAL"}, {""}, {"Shuriken"}};
char opcaoChar;
int opcaoInt;
int opcaoVida;
int opcaoVelo;
int opcaoAtaque1;
int opcaoAtaque2;
int opcaoDefesa = 0;
int opcaoMult;
int RestoPlayer = 0;
int RestoIA = 0;
int statsPlayer[8];
/*
[0] = ModeloPersonagem;
[1] = Raça;
[2] = tipoArmaPrimaria;
[3] = tipoArmaSecundaria;
[4] = armadura;
[5] = vida;
[6] = Velocidade;
[7] = Mult;
*/
int statsIA[11];
/*
[0] = tipoPersonagem;
[1] = Fisico;
[2] = healthPersonagem;
[3] = tipoArmaMelee;
[4] = tipoArmaRanged;
[5] = extraHealthPersonagem;
[6] = chanceCritico;
[7] = chanceEsquiva;
*/
int sentinela;
int fimJogo = 0;
int fimMenu = 0;
int fimRodada = 0;
int rodadas;
int numChute;


int main()
{
        //Definição para acentos e cedilha
        setlocale(LC_ALL, "Portuguese");


        while(fimJogo == 0){


            // MENU DE SELEÇÃO

            do{

                    //Início do Jogo
                printf("Bem vindo ao Meu RPG.\n");
                printf("\n\n");
                system("pause");
                system("cls");

                //Fisico DE PERSONAGEN

                do{
                    int opcaoFisico;
                    printf("Escolha seu personagem:\n");
                    printf("[1] %s.\n", ModeloPersonagem[0]);
                    printf("[2] %s.\n", ModeloPersonagem[1]);
                    printf("[3] %s.\n", ModeloPersonagem[2]);
                    scanf("%i", &opcaoFisico);
                    opcaoFisico--;
                    statsPlayer[0] = opcaoFisico;
                    system("cls");
                    if(opcaoFisico < 0 || opcaoFisico >= FISICO){
                        printf("Opção de personagem inválida, tente novamente.\n\n");
                        system("pause");
                        system("cls");
                        sentinela = 0;
                    }
                    if (opcaoFisico == 0){
                        opcaoVida = rand() % (15 - 8 + 1) + 8;
                        opcaoVelo = rand() % (20 - 17 + 1) + 17;
                        opcaoMult = 5;
                        sentinela = 1;}
                    if (opcaoFisico == 1){
                        opcaoVida = rand() % (20 - 15 + 1) + 15;
                        opcaoVelo = rand() % (18 - 16 + 1) + 15;
                        opcaoMult = 6;}
                    if (opcaoFisico == 2){
                        opcaoVida = rand() % (30 - 20 + 1) + 20;
                        opcaoVelo = rand() % (17 - 14 + 1) + 14;
                        opcaoMult = 7;}
                    sentinela = 1;

                }while(sentinela == 0);




                // Classe do Personagem

                do{
                    int opcaoPersonagem;
                    printf("Escolha seu personagem:\n");
                    printf("[1] %s.\n", TipoRaca[0]);
                    printf("[2] %s.\n", TipoRaca[1]);
                    printf("[3] %s.\n", TipoRaca[2]);
                    printf("[4] %s.\n", TipoRaca[3]);
                    scanf("%i", &opcaoPersonagem);
                    opcaoPersonagem--;
                    statsPlayer[1] = opcaoPersonagem;
                    system("cls");
                    if(opcaoPersonagem < 0 || opcaoPersonagem >= Raca){
                        printf("Opção de personagem inválida, tente novamente.\n\n");
                        system("pause");
                        system("cls");
                        sentinela = 0;
                    }
                    else{
                        if (opcaoPersonagem == 0){
                            opcaoVelo -= rand() % (3 - 1 + 1) + 1;
                            opcaoMult += rand() % (3 - 1 + 1) + 1;}
                        if (opcaoPersonagem == 1){
                            opcaoVida += rand() % (15 - 10 + 1) + 10;
                            opcaoMult -= rand() % (2 - 1 + 1) + 1;}
                        if (opcaoPersonagem == 2){
                            opcaoVida -= rand() % (15 - 10 + 1) + 10;
                            opcaoVelo += rand() % (4 - 1 + 1) + 1;
                            opcaoMult += rand() % (4 - 1 + 1) + 1;
                            }
                        if (opcaoPersonagem == 3){
                            opcaoVida += rand() % (12 - 8 + 1) + 8;
                            opcaoDefesa += rand() % (7 - 4 + 1) + 4;}
                        sentinela = 1;
                    }
                }while(sentinela == 0);


                // Tipo de armadura
                do{
                    int opcaoArmadura;
                    printf("Escolha seu personagem:\n");
                    printf("[1] %s.\n", TipoArmadura[0]);
                    printf("[2] %s.\n", TipoArmadura[1]);
                    printf("[3] %s.\n", TipoArmadura[2]);
                    scanf("%i", &opcaoArmadura);
                    opcaoArmadura--;
                    statsPlayer[4] = opcaoArmadura;
                    system("cls");
                    if(opcaoArmadura < 0 || opcaoArmadura >= Armadura){
                        printf("Opção de personagem inválida, tente novamente.\n\n");
                        system("pause");
                        system("cls");
                        sentinela = 0;
                    }
                    else{
                        if (opcaoArmadura == 0){
                            opcaoDefesa += 3;}
                        if (opcaoArmadura == 1){
                            opcaoDefesa += 4;
                            opcaoVelo -= rand() % (2 - 1 + 1) + 1;}
                        if (opcaoArmadura == 2){
                            opcaoDefesa += 7;
                            opcaoVelo -= rand() % (3 - 1 + 1) + 1;}
                        if (opcaoArmadura == 3){
                            opcaoDefesa += 14;
                            opcaoVelo -= rand() % (6 - 2 + 1) + 1;}

                    }
                }while(sentinela == 0);



                //SELEÇÃO ARMAS PRIMARIAS

                do{
                    int opcaoArmaMelee;
                    printf("Escolha sua arma melee (de curto alcance):\n");
                    printf("[1] %s.\n", TiposArmaPrimaria[0]);
                    printf("[2] %s.\n", TiposArmaPrimaria[1]);
                    printf("[3] %s.\n", TiposArmaPrimaria[2]);
                    printf("[4] %s.\n", TiposArmaPrimaria[3]);
                    printf("[5] %s.\n", TiposArmaPrimaria[4]);
                    printf("[6] %s.\n", TiposArmaPrimaria[5]);
                    scanf("%i", &opcaoArmaMelee);
                    opcaoArmaMelee--;
                    statsPlayer[2] = opcaoArmaMelee;
                    system("cls");
                    if(opcaoArmaMelee < 0 || opcaoArmaMelee >= ArmasPrimarias){
                        printf("Opção de arma melee inválida, tente novamente.");
                        system("pause");
                        system("cls");
                        sentinela = 0;
                    }
                    else{
                        if (opcaoArmaMelee == 0){
                            opcaoAtaque1 = 2;
                            }
                        if (opcaoArmaMelee == 1){
                            opcaoAtaque1 = 3;
                            opcaoVelo -= rand() % (3 - 0 + 1) + 0;
                            }
                        if (opcaoArmaMelee == 2){
                            opcaoAtaque1 = 5;
                            opcaoVelo -= rand() % (5 - 2 + 1) + 1;
                            }
                        if (opcaoArmaMelee == 3){
                            opcaoAtaque1 = 4;
                            opcaoVelo -= rand() % (5 - 0 + 1) + 0;
                            }
                        if (opcaoArmaMelee == 4){
                            opcaoAtaque1 = 2;
                            opcaoVelo -= rand() % (2 - 0 + 1) + 0;
                            }
                        if (opcaoArmaMelee == 5){
                            opcaoAtaque1 = 4;
                            opcaoVelo -= rand() % (4 - 1 + 1) + 1;
                            }
                    }
                }while(sentinela == 0);

                //SELEÇÃO ARMAS SECUNDARIAS

                do{
                    int opcaoArmaSecundaria;
                    printf("Escolha sua arma de longo alcance:\n");
                    printf("[1] %s.\n", TiposArmaSecundaria[0]);
                    printf("[2] %s.\n", TiposArmaSecundaria[1]);
                    printf("[3] %s.\n", TiposArmaSecundaria[2]);
                    scanf("%i", &opcaoArmaSecundaria);
                    opcaoArmaSecundaria--;
                    statsPlayer[3] = opcaoArmaSecundaria;
                    system("cls");
                    if(opcaoArmaSecundaria < 0 || opcaoArmaSecundaria >= ArmasSecundarias){
                        printf("Opção de arma de longo alcance inválida, tente novamente.");
                        system("pause");
                        system("cls");
                        sentinela = 0;
                    }
                    else{
                        if (opcaoArmaSecundaria == 0){
                            opcaoAtaque2 = 1;}
                        if (opcaoArmaSecundaria == 1){
                            opcaoAtaque2 = 2;
                            opcaoVelo -= rand() % (2 - 0 + 1) + 0;}
                        if (opcaoArmaSecundaria == 2){
                            opcaoAtaque2 = 2;}
                    }
                }while(sentinela == 0);

                //VERIFICAÇÃO DA SELEÇÃO

                do{
                    printf("Verifique se estas são mesmo as suas escolhas:\n\n");
                    printf("%s\n\n", ModeloPersonagem[statsPlayer[0]]);
                    printf("%s\n\n", TipoRaca[statsPlayer[1]]);
                    printf("%s\n\n", TipoArmadura[statsPlayer[4]]);
                    printf("Arma primaria:%s.\n", TiposArmaPrimaria[statsPlayer[2]]);
                    printf("Arma secundaria:%s.\n", TiposArmaSecundaria[statsPlayer[3]]);
                    printf("\n[S] Sim.\n[N] Não.\n");
                    printf("Resposta: ");
                    scanf("\n%c", &opcaoChar);
                    switch(opcaoChar){
                        case 'N': case 'n':
                            sentinela = 0;
                            system("cls");
                            printf("VoltandoTiposArmaLonge ao início da seleção...\n");
                            system("pause");
                            system("cls");
                            break;
                        case 'S': case 's':
                            sentinela = 1;
                            system("cls");
                            printf("Você confirmou com sucesso suas escolhas. Preparando o início do RPG...\n");
                            system("pause");
                            system("cls");
                            fimMenu = 1;
                            break;
                        default:
                            sentinela = 2;
                            system("cls");
                            printf("Opção inválida, por favor selecione uma válida.\n");
                            system("pause");
                            system("cls");
                    }
                }while(sentinela == 2);
            }while(fimMenu == 0);    // FIM DO MENU DE SELEÇÃO

            // SELEÇÃO RANDOM VARIÁVEIS PLAYER

            statsPlayer[5] = HEALTH + opcaoVida;
            statsPlayer[6] = opcaoVelo;                                                 // Random Chance Esquiva

            // SELEÇÃO RANDOM VARIÁVEIS IA

            statsIA[0] = rand() % (FISICO);                                        // Random Fisico
            statsIA[1] = rand() % (Raca);                                              // Random Personagem
            statsIA[5] = HEALTH + rand() % (45 - 10 + 1) + 10;                         // Random Health
            statsIA[2] = rand() % (ArmasPrimarias);                                    // Random Arma 1
            statsIA[3] = rand() % (ArmasSecundarias);                                  // Random Arma 2
            statsIA[4] = rand() % (Armadura);                                          // Random Extra armadura
            statsIA[6] = rand() % ((opcaoVelo + 1) - 10 + 1) + 10;                                  // Random velocidade
            statsIA[7] = rand() % ((opcaoMult + 2) - 3 + 1) + 3;                                  // Random mult
            statsIA[8] = rand() % opcaoDefesa + 5;
            statsIA[9] = rand() % (5 - 2 + 1) + 2;
            statsIA[10] = rand() % (2 - 1 + 1) + 1;

            // AMOSTRAGEM DADOS PLAYER

            printf("Dados Player:\n\n");
            printf("Personagem: %s %s\n", ModeloPersonagem[statsPlayer[0]], TipoRaca[statsPlayer[1]]);
            printf("HP: %i\n", statsPlayer[5]);
            printf("VARIAVEL: %i\n", opcaoMult);
            printf("VELOCIDADE: %i\n", opcaoVelo);
            printf("DEFESA: %i\n", opcaoDefesa);
            printf("Ataque 1: %i\n", opcaoAtaque1);
            printf("Ataque 2: %i\n", opcaoAtaque2);
            printf("Armadura: %s\n", TipoArmadura[statsPlayer[4]]);
            printf("Arma primaria: %s\n", TiposArmaPrimaria[statsPlayer[2]]);
            printf("Arma secundaria: %s\n", TiposArmaSecundaria[statsPlayer[3]]);


            // AMOSTRAGEM DADOS IA

            printf("Dados Player:\n\n");
            printf("Personagem: %s %s\n", ModeloPersonagem[statsIA[0]], TipoRaca[statsIA[1]]);
            printf("HP: %i\n", statsIA[5]);
            printf("VARIAVEL: %i\n", statsIA[7]);
            printf("VELOCIDADE: %i\n", statsIA[6]);
            printf("DEFESA: %i\n", statsIA[8]);
            printf("Ataque 1: %i\n", statsIA[9]);
            printf("Ataque 2: %i\n", statsIA[10]);
            printf("Armadura: %s\n", TipoArmadura[statsIA[4]]);
            printf("Arma primaria: %s\n", TiposArmaPrimaria[statsIA[2]]);
            printf("Arma secundaria: %s\n", TiposArmaSecundaria[statsIA[3]]);
            system("pause");
            system("cls");

            // INÍCIO DA RODADA

            fimRodada = 0;
            do{
                do{
                    int opcao;
                    int escolhaIA;
                    int Ataque1;
                    int Ataque;
                    if(statsIA[6] > statsPlayer[6]){          //Ataque Player
                        escolhaIA = rand() % (3 - 1 + 1) + 1;
                        if(escolhaIA == 1){
                            Ataque = (rand() % (opcaoMult + 1)) * opcaoAtaque1;
                            printf("IA ataque causa: %i\n", Ataque);}
                        if(escolhaIA == 2){
                            Ataque = (rand() % (opcaoMult + 1)) * opcaoAtaque2;
                            printf("IA ataque causa: %i\n", Ataque);}
                        if(escolhaIA == 3){
                            Ataque = (rand() % (opcaoMult + 1)) * opcaoDefesa;
                            printf("IA defesa é de: %i\n", Ataque);}

                        printf("[1] Arma Primeira \n[2]- Arma secundaria\n[3]- Defender\n");
                        scanf("%i", &opcao);
                        if(opcao == 1){
                            Ataque1 = (rand() % (opcaoMult + 1)) * opcaoAtaque1;
                            printf("Seu ataque causa: %i", Ataque);}
                        if(opcao == 2){
                            Ataque1 = (rand() % (opcaoMult + 1)) * opcaoAtaque2;
                            printf("Seu ataque causa: %i", Ataque);}
                        if(opcao == 3){
                            Ataque1 = (rand() % (opcaoMult + 1)) * opcaoDefesa;
                            printf("sua defesa é de: %i", Ataque);}
                        system("pause");
                        system("cls");

                    }
                    else if(statsIA[6] < statsPlayer[6]){     //Ataque IA
                        printf("deu certo:\n");
                        printf("[1] Arma Primeira \n[2]- Arma secundaria\n[3]- Defender\n");
                        scanf("%i", &opcao);
                        if(opcao == 1){
                            Ataque1 = (rand() % (opcaoMult + 1)) * opcaoAtaque1;
                            printf("Seu ataque causa: %i\n", Ataque);}
                        if(opcao == 2){
                            Ataque1 = (rand() % (opcaoMult + 1)) * opcaoAtaque2;
                            printf("Seu ataque causa: %i\n", Ataque);}
                        if(opcao == 3){
                            Ataque1 = (rand() % (opcaoMult + 1)) * opcaoDefesa;
                            printf("sua defesa é de: %i\n", Ataque);}

                        escolhaIA = rand() % (3 - 1 + 1) + 1;
                        if(escolhaIA == 1){
                            Ataque = (rand() % (opcaoMult + 1)) * opcaoAtaque1;
                            printf("IA ataque causa: %i\n", Ataque);}
                        if(escolhaIA == 2){
                            Ataque = (rand() % (opcaoMult + 1)) * opcaoAtaque2;
                            printf("IA ataque causa: %i\n", Ataque);}
                        if(escolhaIA == 3){
                            Ataque = (rand() % (opcaoMult + 1)) * opcaoDefesa;
                            printf("IA defesa é de: %i\n", Ataque);}
                        system("pause");
                        system("cls");
                    }
                }while(statsIA[5] < 1 || statsPlayer[5] < 1);
                //Finalização da rodada
            }while(fimRodada == 0);
            fimJogo = 1;
        }   // FIM DO JOGO


    return 0;
}
