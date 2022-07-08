#include <iostream>

using namespace std;
#include <time.h>
#include <windows.h>



int main()
{
    setlocale(LC_ALL,"portuguese");
    int dificuldade;
    cout<<endl<<"\n\t\t\t\t\t\tJOGO DA MEMÓRIA."<<endl<<endl<<endl;
    cout<<" Digite um número da dificuldade você gostaria de jogar: 1)Fácil , 2)Médio , 3)Difícil: ";
    cin>>dificuldade;
    system("cls");
    switch(dificuldade){
        case 1:
            {
                string p[4][4], g[4][4], m[4][4],a;
                int mode, i, j, ia, ja, jogadas=0, cont, chec, x, y;
                bool acerto = false;
                ///Subistituição da matriz.
                p[0][0]=char(003), p[0][1]=char(006), p[0][2]=char(014), p[0][3]=char(002);
                p[1][0]=char(004), p[1][1]=char(003), p[1][2]=char(120), p[1][3]=char(005);
                p[2][0]=char(005), p[2][1]=char(004), p[2][2]=char(014), p[2][3]=char(120);
                p[3][0]=char(207), p[3][1]=char(002), p[3][2]=char(006), p[3][3]=char(207);
                a=char(055);
                srand(time(NULL));
                mode= rand()%4+1;///Cálculo para manter o número entre 1 e 4.
                switch(mode){
                    case 1:
                        for(i=0; i<4; i++){
                            for(j=0; j<4; j++){
                                g[i][j]= p[i][j];///Matriz do jogo igual a matriz original.
                            }
                        }
                    break;

                    case 2:
                        for (i=0; i<4; i++){
                            for(j=0; j<4; j++){
                                g[i][j]=p[j][i];///Matriz é inversa da original.
                            }
                        }
                    break;

                    case 3:
                        for(i=0; i<4; i++){
                            for(j=0; j<4; j++){
                                g[i][j]=p[3-i][j];///Inverte as linhas da matriz.
                            }
                        }
                    break;

                    case 4:
                        for(i=0; i<4; i++){
                            for(j=0; j<4; j++){
                                g[i][j]=p[i][3-j];///Inverte as colunas da matriz.
                            }
                        }
                    break;
                }
                for(i=0; i<4; i++){
                    for(j=0; j<4; j++){
                        m[i][j]=a;
                    }
                }
                cout<<"\n\n\t\t\t\t\t\tJOGADA DA MEMÓRIA:FÁCIL."<<endl<<endl;
                system("pause");
                while(jogadas < 24 && acerto == false){///Mantém o jogo rodando até o jogador vencer ou perder todas as jogadas.
                    system("cls");
                    ia=4;
                    ja=4;
                    for(cont=0; cont<2; cont++){
                        cout<<"Jogadas Restantes: "<<24-jogadas<<endl;
                        cout<<"     C0 C1 C2 C3";
                            for(y=0; y<4; y++){
                                cout<<endl;
                                cout<<"L"<<y<<":  ";
                                for(x=0; x<4; x++){
                                    cout<<m[y][x]<<"  ";
                                }
                            }

                        cout<<"\n\nDigite a linha e a coluna a revelar: ";
                        cout<<"\nLinha: ";
                        cin>> i;
                        ///Verificardor de linha.
                        while(i<0 || i>3){
                            cout<<"Linha inexistente, digite novamente\nLinha: ";
                            cin>>i;
                        }
                        ///verificador de coluna.
                        cout<<"Coluna: ";
                        cin>> j;
                        while(j<0 || j>3){
                            cout<<"Coluna inexistente, digite novamente\nColuna: ";
                            cin>>j;
                        }
                        ///Averiguar se o local já foi selecionado.
                        if(i==ia && j==ja){
                            cout<<"\nMesmo local escolhido, favor escolher um diferente.\n";
                            cont--;
                        }else if(m[i][j] != a){///Averiguar se o local já foi aberto.
                            cout<<"\nLocal já descoberto, favor escolher um diferente."<<endl;
                            cont--;
                        }else{
                            m[i][j] = g[i][j];
                            for(y=0; y<4; y++){
                                cout<<endl;
                                for(x=0; x<4;x++){
                                    cout<<m[y][x]<<"  ";
                                }
                            }
                            ///Verificar se o jogador fez par ou não.
                            cout<<"\n";
                            if(cont == 1 && g[ia][ja] == g[i][j]){
                                cout<<"\nJogada OK.";
                            }else if (cont == 1){
                                cout<<"\nJogada NOK.";
                                m[i][j]=a;
                                m[ia][ja]=a;
                            }
                            ia=i, ja=j;
                            Sleep(1500);
                            system("cls");
                        }
                    }
                    chec=0;
                    for(i=0;i<4;i++){
                        for(j=0;j<4;j++){
                            if(m[i][j]==a){
                                chec++;
                            }
                        }
                    }
                    ///Verificações se o jogador ganho ou perdeu.
                    if(chec==0){
                        acerto = true;
                        cout<<"\n\n!!! VOCÊ GANHOU !!! PARABÉNS !!!\n"<<endl;
                        cout<<endl<<"Alunos:Agnês Rusche, Erick Wilde, Julia Amaral e Vinicius Jose.";
                    }else{
                        jogadas++;
                        if(jogadas == 24){
                            cout<<"\t\t\t\t\t\n\n!!! JOGADAS ENCERRADAS !!! VOCÊ PERDEU !!!\n"<<endl;
                            cout<<endl<<"Alunos:Agnês Rusche, Erick Wilde, Julia Amaral e Vinicius Jose.";
                        }
                    }
                }
                return 0;
            }
        break;
        case 2:
            {
                string p[4][6], g[4][6], m[4][6],a;
                int mode, i, j, ia, ja, jogadas=0, cont, chec, x, y;
                bool acerto = false;
                ///Subistituição da matriz.
                p[0][0]=char(003), p[0][1]=char(006), p[0][2]=char(120), p[0][3]=char(228), p[0][4]=char(240), p[0][5]=char(014);
                p[1][0]=char(004), p[1][1]=char(207), p[1][2]=char(021), p[1][3]=char(002), p[1][4]=char(005), p[1][5]=char(004);
                p[2][0]=char(005), p[2][1]=char(002), p[2][2]=char(240), p[2][3]=char(234), p[2][4]=char(120), p[2][5]=char(234);
                p[3][0]=char(207), p[3][1]=char(014), p[3][2]=char(228), p[3][3]=char(006), p[3][4]=char(003), p[3][5]=char(021);
                a=char(055);
                srand(time(NULL));
                mode= rand()%3;///Gerar numeros entre 0 a 3.
                switch(mode){
                    case 0:
                        for(i=0; i<4; i++){
                            for(j=0; j<6; j++){
                                g[i][j]= p[i][j];///Matriz do jogo igual a matriz original
                            }
                        }
                    break;

                    case 1:
                        for (i=0; i<4; i++){
                            for(j=0; j<6; j++){
                                g[i][j]=p[3-i][j];///Inverte as linhas da matriz.
                            }
                        }
                    break;

                    case 2:
                        for(i=0; i<4; i++){
                            for(j=0; j<6; j++){
                                g[i][j]=p[i][5-j];///Inverte as colunas da matriz.
                            }
                        }
                    break;
                }
                for(i=0; i<4; i++){
                    for(j=0; j<6; j++){
                        m[i][j]=a;
                    }
                }
                cout<<"\n\n\t\t\t\t\t\tJOGADA DA MEMÓRIA:MÉDIO."<<endl<<endl;
                system("pause");
                while(jogadas < 36 && acerto == false){///Mantém o jogo rodando até o jogador vencer ou perder todas as jogadas.
                    system("cls");
                    ia=5;
                    ja=7;
                    for(cont=0; cont<2; cont++){
                        cout<<"Jogadas Restantes: "<<36-jogadas<<endl;
                        cout<<"     C0 C1 C2 C3 C4 C5";
                            for(y=0; y<4; y++){
                                cout<<endl;
                                cout<<"L"<<y<<":  ";
                                    for(x=0; x<6; x++){
                                        cout<<m[y][x]<<"  ";
                                    }
                            }
                        cout<<"\n\nDigite a linha e a coluna a revelar: ";
                        cout<<"\nLinha: ";
                        cin>> i;
                        ///Verificardor de linha.
                        while(i<0 || i>3){
                            cout<<"Linha inexistente, digite novamente\nLinha: ";
                            cin>>i;
                        }
                        cout<<"Coluna: ";
                        cin>> j;
                        ///verificador de coluna.
                        while(j<0 || j>5){
                            cout<<"Coluna inexistente, digite novamente\nColuna: ";
                            cin>>j;
                        }
                        ///Averiguar se o local já foi selecionado.
                        if(i==ia && j==ja){
                            cout<<"\nMesmo local escolhido, favor escolher um diferente.\n";
                            cont--;
                        }else if(m[i][j] != a){///Averiguar se o local já foi aberto.
                            cout<<"\nLocal já descoberto, favor escolher um diferente."<<endl;
                            cont--;
                        }else{
                            m[i][j] = g[i][j];
                            for(y=0; y<4; y++){
                                cout<<endl;
                                for(x=0; x<6;x++){
                                    cout<<m[y][x]<<"  ";
                                }
                            }
                            ///Verificar se o jogador fez par ou não.
                            cout<<"\n";
                            if(cont == 1 && g[ia][ja] == g[i][j]){
                                cout<<"\nJogada OK.";
                            }else if (cont == 1){
                                cout<<"\nJogada NOK.";
                                m[i][j]=a;
                                m[ia][ja]=a;
                            }
                            ia=i, ja=j;
                            Sleep(1500);
                            system("cls");
                            }
                    }
                    chec=0;
                    for(i=0;i<4;i++){
                        for(j=0;j<6;j++){
                            if(m[i][j]==a){
                                chec++;
                            }
                        }
                    }
                    ///Verificações se o jogador ganho ou perdeu.
                    if(chec==0){
                        acerto = true;
                        cout<<"\n\n!!! VOCÊ GANHOU !!! PARABÉNS !!!\n"<<endl;
                        cout<<endl<<"Alunos:Agnês Rusche, Erick Wilde, Julia Amaral e Vinicius Jose.";
                    }else{
                        jogadas++;
                        if(jogadas == 36){
                            cout<<"\n\n!!! JOGADAS ENCERRADAS !!! VOCÊ PERDEU !!!\n"<<endl;
                            cout<<endl<<"Alunos:Agnês Rusche, Erick Wilde, Julia Amaral e Vinicius Jose.";
                        }
                    }
                }
                return 0;
            }
            break;
            case 3:
                {
                    string p[6][6], g[6][6], m[6][6],a;
                    int mode, i, j, ia, ja, jogadas=0, cont, chec, x, y;
                    bool acerto = false;
                    //Subistituição da matriz.
                    p[0][0]=char(003), p[0][1]=char(014), p[0][2]=char(002), p[0][3]=char(043), p[0][4]=char(171), p[0][5]=char(247);
                    p[1][0]=char(004), p[1][1]=char(003), p[1][2]=char(190), p[1][3]=char(247), p[1][4]=char(006), p[1][5]=char(240);
                    p[2][0]=char(005), p[2][1]=char(120), p[2][2]=char(225), p[2][3]=char(037), p[2][4]=char(014), p[2][5]=char(157);
                    p[3][0]=char(207), p[3][1]=char(037), p[3][2]=char(165), p[3][3]=char(165), p[3][4]=char(005), p[3][5]=char(120);
                    p[4][0]=char(006), p[4][1]=char(207), p[4][2]=char(171), p[4][3]=char(157), p[4][4]=char(004), p[4][5]=char(043);
                    p[5][0]=char(002), p[5][1]=char(240), p[5][2]=char(245), p[5][3]=char(190), p[5][4]=char(225), p[5][5]=char(245);
                    a=char(055);
                    srand(time(NULL));
                    mode= rand()%4+1;///Cálculo para manter o número entre 1 e 4.
                    switch(mode){
                        case 1:
                            for(i=0; i<6; i++){
                                for(j=0; j<6; j++){
                                    g[i][j]= p[i][j];///Matriz do jogo igual a matriz original.
                                }
                            }
                        break;

                        case 2:
                            for (i=0; i<6; i++){
                                for(j=0; j<6; j++){
                                    g[i][j]=p[j][i];///Matriz é inversa da original.
                                }
                            }
                        break;

                        case 3:
                            for(i=0; i<6; i++){
                                for(j=0; j<6; j++){
                                    g[i][j]=p[5-i][j];///Inverte as linhas da matriz.
                                }
                            }
                        break;

                        case 4:
                            for(i=0; i<6; i++){
                                for(j=0; j<6; j++){
                                    g[i][j]=p[i][5-j];///Inverte as colunas da matriz.
                                }
                            }
                        break;
                    }
                    for(i=0; i<6; i++){
                        for(j=0; j<6; j++){
                            m[i][j]=a;
                        }
                    }
                    cout<<"\n\n\t\t\t\t\t\tJOGO DA MEMÓRIA:DIFÍCIL."<<endl<<endl;
                    system("pause");
                    while(jogadas < 54 && acerto == false){///Mantém o jogo rodando até o jogador vencer ou perder todas as jogadas.
                        system("cls");
                        ia=6;
                        ja=6;
                        for(cont=0; cont<2; cont++){
                            cout<<"Jogadas Restantes: "<<54-jogadas<<endl;
                            cout<<"     C0 C1 C2 C3 C4 C5";
                            for(y=0; y<6; y++){
                                cout<<endl;
                                cout<<"L"<<y<<":  ";
                                for(x=0; x<6; x++){
                                    cout<<m[y][x]<<"  ";
                                }
                            }
                            cout<<"\n\nDigite a linha e a coluna a revelar: ";
                            cout<<"\nLinha: ";
                            cin>> i;
                            ///Verificardor de linha.
                            while(i<0 || i>5){
                                cout<<"Linha inexistente, digite novamente\nLinha: ";
                                cin>>i;
                            }
                            cout<<"Coluna: ";
                            cin>> j;
                            ///verificador de coluna.
                            while(j<0 || j>5){
                                cout<<"Coluna inexistente, digite novamente\nColuna: ";
                                cin>>j;
                            }
                            ///Averiguar se o local já foi selecionado.
                            if(i==ia && j==ja){
                                cout<<"\nMesmo local escolhido, favor escolher um diferente.\n";
                                cont--;
                            }else if(m[i][j] != a){///Averiguar se o local já foi aberto.
                                cout<<"\nLocal já descoberto, favor escolher um diferente."<<endl;
                                cont--;
                            }else{
                                m[i][j] = g[i][j];
                                for(y=0; y<6; y++){
                                    cout<<endl;
                                    for(x=0; x<6;x++){
                                        cout<<m[y][x]<<"  ";
                                    }
                                }
                                ///Verificar se o jogador fez par ou não.
                                cout<<"\n";
                                if(cont == 1 && g[ia][ja] == g[i][j]){
                                    cout<<"\nJogada OK.";
                                }else if (cont == 1){
                                    cout<<"\nJogada NOK.";
                                    m[i][j]=a;
                                    m[ia][ja]=a;
                                }
                                ia=i, ja=j;
                                Sleep(1500);
                                system("cls");
                            }
                        }
                        chec=0;
                        for(i=0;i<6;i++){
                            for(j=0;j<6;j++){
                                if(m[i][j]==a){
                                    chec++;
                                }
                            }
                        }
                        ///Verificações se o jogador ganho ou perdeu.
                        if(chec==0){
                            acerto = true;
                            cout<<"\n\n!!! VOCÊ GANHOU !!! PARABÉNS !!!\n"<<endl;
                            cout<<endl<<"Alunos:Agnês Rusche, Erick Wilde, Julia Amaral e Vinicius Jose.";
                        }else{
                            jogadas++;
                            if(jogadas == 54){
                                cout<<"\n\n!!! JOGADAS ENCERRADAS !!! VOCÊ PERDEU !!!\n"<<endl;
                                cout<<endl<<"Alunos:Agnês Rusche, Erick Wilde, Julia Amaral e Vinicius Jose.";
                            }
                        }
                    }
                    return 0;
                }
            break;

    }
    return 0;
}


