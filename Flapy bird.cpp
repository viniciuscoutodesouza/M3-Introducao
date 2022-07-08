/*Versão beta desenvolvida por Thiago Felski Pereira para disciplina de Algoritmos*/
#include <iostream>
#include <windows.h>
#include <conio.h> ///para o getch()
#include <time.h>
///https://stackoverflow.com/questions/34474627/linux-equivalent-for-conio-h-getch

using namespace std;


/**
    F L A P B I R D (M2 Algoritmos)
    - Lembrando: não permitido o uso de funções e variáveis compostas como structs, vetores e matrizes
    - Corrigir os rastros (pássaro e obstáculos)
    - Implementar colisão
    - Implementar pontuação (mais um ponto para cada obstáculo superado)
    - Fazer 2 obstáculos simultâneos (obstaculo1 e obstaculo2)
    - Deixar a pontuação visível durante todo o jogo
    - Definir marcos para acelerar a velocidade
*/



int main()
{
    ///ALERTA: NÃO MODIFICAR O TRECHO DE CÓDIGO, A SEGUIR.
    //INICIO: COMANDOS PARA QUE O CURSOR NÃO FIQUE PISCANDO NA TELA
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO     cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = false; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
    //FIM: COMANDOS PARA QUE O CURSOR NÃO FIQUE PISCANDO NA TELA
    //INÍCIO: COMANDOS PARA REPOSICIONAR O CURSOR NO INÍCIO DA TELA
    COORD coord;
    //FIM: COMANDOS PARA REPOSICIONAR O CURSOR NO INÍCIO DA TELA
    ///ALERTA: NÃO MODIFICAR O TRECHO DE CÓDIGO, ACIMA.

    string repetir = "sim";
    int recorde = 0;

    while(repetir == "sim" || repetir == "Sim")
    {
        int bird_x=5, bird_y=10;
        int obstaculo_x = 53, obstaculo_y, obstaculo_x2 = 101, obstaculo_y2;
        int tecla, pontos = 0;
        int barreira = 5, barreira2 = 16;
        bool bird = true;

        while (bird == true) { //esse laço faz o jogo rodar para sempre

            ///DESENHO DO CENÁRIO
            cout<< pontos << " Pontos                                                                   " << "      Recorde : " << recorde << " pontos.\n";
            cout<<"-----------------------------------------------------------------------------------------------------";
            cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
            cout<<"-----------------------------------------------------------------------------------------------------";

            ///POSICIONA O PÁSSARO
            coord.X = bird_x;    coord.Y = bird_y;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            cout<<char(190);

            ///POSICIONA O OBSTÁCULO

            obstaculo_y=2;
            while(obstaculo_y<21){ ///REPETIÇÃO PARA DESENHAR A BARREIRA 1 ENTRE O ESPAÇO 2 E 20 DO EIXO Y
                coord.X = obstaculo_x;    coord.Y = obstaculo_y;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
                if(obstaculo_y<(barreira - 1) || obstaculo_y>(barreira + 1))
                {
                    cout<<char(219);
                }
                else if(obstaculo_y == bird_y && obstaculo_x == bird_x)
                {
                    cout<<char(190);///SERVE PARA DESENHAR O PÁSSARO QUANDO ESTA PASSANDO PELO OBSTACULO 1
                }
                else
                {
                    cout<<" ";
                }

                obstaculo_y++;
            }
            obstaculo_y2=2;
            while(obstaculo_y2<21){ ///REPETIÇÃO PARA DESENHAR A BARREIRA 2 ENTRE O ESPAÇO 2 E 20 DO EIXO Y
                coord.X = obstaculo_x2;    coord.Y = obstaculo_y2;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
                if(obstaculo_y2<(barreira2 - 1) || obstaculo_y2>(barreira2 + 1))
                {
                    cout<<char(219);
                }
                else if(obstaculo_y2 == bird_y && obstaculo_x2 == bird_x)
                {
                    cout<<char(190); ///SERVE PARA DESENHAR O PÁSSARO QUANDO ESTA PASSANDO PELO OBSTACULO 2
                }
                else
                {
                    cout<<" ";
                }

                obstaculo_y2++;
            }
            if(obstaculo_x <= 2) ///QUANDO A BARREIRA 1 CHEGAR NO FIM, GERA UMA NOVA BARREIRA E REPOSICIONA NO INICIO
            {
                srand(time(NULL));
                barreira = (rand()%17) + 3; /// RESTO DE 17 COM + 3 PARA O RESULTADO FICAR ENTRE 3 E 19 (BARREIRA DENTRO DO LIMITE)
                obstaculo_x = 101;
                pontos ++;
            }
            if(obstaculo_x2 <= 2) ///QUANDO A BARREIRA 2 CHEGAR NO FIM, GERA UMA NOVA BARREIRA E REPOSICIONA NO INICIO
            {
                srand(time(NULL));
                barreira2 = (rand()%17) + 3;
                obstaculo_x2 = 101;
                pontos ++;
            }
            if(pontos > recorde) ///COMANDO PARA MARCAR O RECORDE
            {
                recorde = pontos;
            }


            ///VERIFICA COLISÃO

            if(bird_x == obstaculo_x && (bird_y < (barreira - 1) || bird_y > (barreira + 1))) ///COLISÃO COM OBSTÁCULO 1
            {
                cout << "FIM DE JOGO\n";
                system("pause");
                system("cls");
                bird = false;
            }
            if(bird_x == obstaculo_x2 && (bird_y < (barreira2 - 1) || bird_y > (barreira2 + 1))) ///COLISÃO COM OBSTÁCULO 2
            {
                cout << "FIM DE JOGO\n";
                system("pause");
                system("cls");
                bird = false;
            }
            if(bird_y == 1 || bird_y == 21) ///COLISÃO COM TERRENO (TETO E CHÃO)
            {
                cout << "FIM DE JOGO\n";
                system("pause");
                system("cls");
                bird = false;
            }

            ///VERIFICA COMANDO DO JOGADOR
            if (kbhit()) { ///verifica se uma tecla foi pressionada
                tecla=getch(); //verifica comando do jogador
            }

            if ( tecla=='w' || tecla == 'W' ){
                bird_y--;
                tecla='0';
            } else { ///PÁSSARO CAI 1 POSIÇÃO SE NÃO FOI PRESSIONADO PARA SUBIR
                bird_y++;
            }



            ///OBSTÁCULO AVANÇA UMA POSIÇÃO PARA ESQUERDA 2 VEZES
            obstaculo_x--;
            obstaculo_x--;

            if (pontos >=10) ///QUANDO CHEGAR A 10 PONTOS AUMENTA AINDA MAIS A VELOCIDADE DO OBSTÁCULO 1
            {
                obstaculo_x--;
            }

            obstaculo_x2--;
            obstaculo_x2--;

            if (pontos >=10) ///QUANDO CHEGAR A 10 PONTOS AUMENTA AINDA MAIS A VELOCIDADE DO OBSTÁCULO 2
            {
                obstaculo_x2--;
            }

            ///TEMPO DE ESPERA
            if(pontos >=0 && pontos < 5)
            {
                Sleep(400);
            }
            else if(pontos >=5 && pontos < 10)
            {
                Sleep(350);
            }
            else if(pontos >=10 && pontos < 15)
            {
                Sleep(300);
            }
            else if(pontos >=15 && pontos < 20)
            {
                Sleep(250);
            }
            else
            {
                Sleep(200);
            }
            system ("cls");




        }

        cout << "Deseja jogar novamente? Sim ou Nao : "; ///OPÇÃO PARA RECOMEÇAR O JOGO
        cin >> repetir;
        system("cls");
    }

    cout << "\nObrigado por jogar nosso jogo, espero que tenha gostado.\n";



    return 0;
}
