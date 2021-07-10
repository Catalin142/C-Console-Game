#ifndef VOIDURI_H
#define VOIDURI_H

char Boss1[100][100];

bool SwordStatus = false;

void center(const char* s)
{
    HANDLE hOut;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD NewSBSize;
    int l = strlen(s);
    int pos = (int)((195 - l) / 2);
    for (int i = 0; i < pos; i++)
        cout << " ";
    cout << s << endl;
}
void centerJumate(const char* s)
{
    HANDLE hOut;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD NewSBSize;
    int l = strlen(s);
    int pos = (int)((105 - l) / 2);
    for (int i = 0; i < pos; i++)
        cout << " ";
    cout << s;

    int poza = (int)((50 - l) / 2);
    for (int i = 0; i < poza; i++)
        cout << " ";
}

void centermini(const char* s, int x)
{
    HANDLE hOut;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD NewSBSize;
    int l = strlen(s);
    int pos = (int)((20 - l) / 2);
    for (int i = 0; i < pos; i++)
        cout << " ";
    cout << s << ":" << x;
}

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void Music_player()
{
    int Music = rand() % 6 + 1;
#if 0
    if (Music == 1)
    {
        PlaySound("muzica\\Soundtrack1.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
        Music = rand() % 6 + 1;
    }
    if (Music == 2)
    {
        PlaySound("muzica\\Soundtrack2.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
        Music = rand() % 6 + 1;
    }
    if (Music == 3)
    {
        PlaySound("muzica\\Soundtrack3.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
        Music = rand() % 6 + 1;
    }
    if (Music == 4)
    {
        PlaySound("muzica\\Soundtrack4.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
        Music = rand() % 6 + 1;
    }
    if (Music == 5)
    {
        PlaySound("muzica\\Soundtrack5.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
        Music = rand() % 6 + 1;
    }
    if (Music == 6)
    {
        PlaySound("muzica\\Soundtrack6.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
        Music = rand() % 6 + 1;
    }
#endif
}

//sa arate frumos
void Nice_Display(int x, const char* Nume, char Personaj[100][100])
{
    //PlaySound(NULL, NULL, 0);

    system("cls");


    cout << "\n\n";

    for (int i = 0; i < 5; i++)
        cout << " ";

    for (int i = 5; i <= 185; i++)
        cout << "=";

    center(Nume);

    for (int i = 0; i < 5; i++)
        cout << " ";

    for (int i = 5; i <= 185; i++)
        cout << "=";

    cout << "\n\n";

    for (int i = 0; i < x; i++)
    {
        HANDLE hOut;
        hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD NewSBSize;
        int l = strlen(Personaj[i]);
        int pos = (int)((191 - l) / 2);
        for (int i = 0; i < pos; i++)
            cout << " ";
        cout << Personaj[i] << endl;
    }

    for (int i = 0; i < 1; i++)
        cout << "\n" << endl;

    for (int i = 0; i < 5; i++)
        cout << " ";

    for (int i = 5; i <= 185; i++)
        cout << "=";

    cout << "\n\n";

}


void Setup(bool showFlag)
{
    //nume
    LPCWSTR title = L"Odiul: Ascensiunea";
    SetConsoleTitle(title);

    // sterge bara de scroll
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(handle, &info);
    COORD new_size =
    {
        info.srWindow.Right - info.srWindow.Left + 1,
        info.srWindow.Bottom - info.srWindow.Top + 1
    };
    SetConsoleScreenBufferSize(handle, new_size);

    //marime consola
    HWND console = GetConsoleWindow();
    RECT ConsoleRect;
    GetWindowRect(console, &ConsoleRect);
    MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 1550, 800, TRUE);

    //nu mai poti sa misti rezolutia
    HWND consoleWindow = GetConsoleWindow();
    SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);

    // sterge cursoru
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag;
    SetConsoleCursorInfo(out, &cursorInfo);

}




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void BossDisplay1(char x[100][100], char xBoss[100][100])
{
    Nice_Display(17, "   Castel:", Location1);

    cout << "\tAi ajuns la castelul ... poti alege in ce mod intri in castel. Poti alege modul stealth (1) sau nu (2):";
    int In;
    cin >> In;

    //Stealth
    if (In == 1)
    {

        cout << "\n\n";
        cout << "\tAi ales modul stealth.Daca faci o alegere gesita iesi din modul stealth\n\n\n";
        _getch();
        cout << "\tEsti in fata castelului, pe unde intri, pe singurul geam deschis care e la etaj (1) sau sari gardu si intri prin gradina (2)?:";
        int iN;
        cin >> iN;

        system("cls");

        for (int i = 0; i < 5; i++)
            cout << " ";

        for (int i = 5; i <= 185; i++)
            cout << "=";

        for (int i = 0; i < 2; i++)
            cout << "\n";

        //geam
        if (iN == 1);
        {
            cout << "\tAi ajuns langa geam. In fata lui e un gardian. Ce ii faci? Il tragi si il arunci pe geam(1) sau ii tai gatul cu sabia(2)?:";
            int guard;
            cin >> guard;

            //aruncare
            if (guard == 1)
            {
                cout << "\tL-ai prins de pelerina si l-ai tras. In timp ce cade il privesti in ochi timp de o secunda si sesisezi ca nu arata chiar ca un om normal.\n";
                cout << "\tOchii lui sunt rosii de asemenea si piele si are coarne, ca un demon.\n";
                cout << "\tLa impactul cu pamantul face un zgomot destul de puternic";
                //suntet cadere
                cout << " pe care e posibil sa il fi auzit si ceilalti gardieni.\n";
                _getch();
            }

            //gat
            if (guard == 2)
            {
                cout << "\tCu o miscare rapida scoti sabia ";
                //sunet sabie
                cout << "si ii tai gatul.\n";
                //sunet taiat
                cout << "\tDin el tasneste sange verde. Speriat, te duci la cadavrul lui si il intorci.\n";
                cout << "\tFata lui e rosie, parul negru si rar. Arata ca un demon mai ales ca are si niste coarne imense in cap.\n";
                _getch();
            }


        }

    }

    system("cls");
    if (playSoundinGame == true)
        Music_player();

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void clearScreen() ///<3
{
    HANDLE hOut;
    COORD Position;

    hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    Position.X = 0;
    Position.Y = 0;
    SetConsoleCursorPosition(hOut, Position);

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void save()
{
    ofstream f("savel.in");
    {
        f << numele << endl;
        f << dmg_sabie << endl;
        f << hp << endl;
        f << mana << endl;
        f << lvl << endl;
        f << bani << endl;
        f << x << endl;
        f << y << endl;
        f << curr_Location << endl;
        f << SwordStatus << endl;
        f << playSoundinGame << endl;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void harta_save()
{
    ofstream harta("harta.in");
    {
        {
            for (int display = 0; display < 22; display++)
            {
                harta << map[display] << endl;
                for (int X_Coord = 0; X_Coord < 100; X_Coord++)
                    for (int Y_Coord = 0; Y_Coord < 200; Y_Coord++)
                        if (map[X_Coord][Y_Coord] == ' ')
                            map[X_Coord][Y_Coord] = '.';
            }
        }
    }

}


void Logo()
{
    cout << "\n\n\n\n\n\n\n\n\n\n\n";
    for (int Foc = 0; Foc <= 8; Foc++)
    {
        if (Foc == 1)
            SetConsoleTextAttribute(hConsole, 6);
        if (Foc <= 4 && Foc != 1)
            SetConsoleTextAttribute(hConsole, 4);
        if (Foc > 4)
            SetConsoleTextAttribute(hConsole, 7);
        center(LOGO[Foc]);
    }

    SetConsoleTextAttribute(hConsole, 7);

    cout << "\n\n\n\n";
    center("Apasa orice ca sa continui.");
    _getch();

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void BOSS(char Personaj[100][100], char Boss[100][100], int HP)
{
    cout << "\n\n";
    for (int i = 0; i < 17; )
        for (int j = 0; j < 18; j++)
        {
            centerJumate(Personaj[i]);
            centerJumate(Boss[j]);
            i++;
            cout << endl;
        }
}


void urs()
{

    //PlaySound(NULL, NULL, 0);

    system("cls");

    _getch();

    cout << "Urs: Ah se pare ca Lica a trimis pe cineva sa ma rezolve uff... Tare imi placea berea lui!" << endl;
    cout << numele << ": Te cred ca iti place dar trebuie sa pleci!" << endl;
    cout << "Urs: Da eu n-am casa unde sa ma duc, ai putea sa ma ajuti sa imi caut un camin si eu calumea? Numele meu ii Martin" << endl;
    int usada;
    cout << "Il ajuti? 1.Da 2.Nu;" << endl;
    cin >> usada;
    if (usada == 1)
    {
        cout << numele << ": No hai ca te ajut";
        cout << "*Dupa ce l-ai ajutat sa-si faca un barlog in padure Martin te-a rasplatit cu 1 leu(ca atat avea sarmanu)*" << endl;
        goodending++;
        map[11][81] = ' ';
        map[15][93] = 'x';
        bani += 1;
        Side_Quest1 = true;
        cout << "Apasa orice ca sa iesi!";
        _getch();
    }

    if (usada != 1)
    {
        cout << numele << ": Nu pot sa te ajut Lica m-a rugat..." << endl;
        cout << "Martin: Bine, omoara-ma, macar lasa-ma sa mor cum imi place" << endl;
        cout << "*Ursu Martin s-a asezat si-a scos sticla de bere Ciucas si a baut si a tot baut pana s-a imbatat muci*" << endl;
        cout << "Martin: Ok sunt pregatit sa mor" << endl;
        map[11][81] = 'x';
        cout << "*Cu o miscare fulgeratoare scoti sabia din teaca si ii tai capul ursului*" << endl;
        cout << "*Mergi la Lica sa iti iei banii*" << endl;
        //PlaySound(TEXT("muzica\\PickupCoin.wav"), NULL, SND_SYNC);
        _getch();
        cout << "Lica:Asa da, ia uiti banii!" << endl;
        bani += 100;
        badending -= 1;
        Side_Quest1 = true;
        cout << "Apasa orice ca sa iesi!";
        _getch();

    }
    system("cls");
    if (playSoundinGame == true)
        Music_player();

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//span
int span_boss()
{
    Nice_Display(27, "     Span:", Span);

    cout << "\t1.Start" << endl << "\t2.Iesi";
    int principal;
    cin >> principal;
    if (principal == 2)
    {
        system("cls");
    }
    if (principal == 1)
    {
        cout << "Buna " << numele << "!" << endl;
        cout << "1=Atac normal; 2=Atac puternic" << endl;
        ///mergi la span spanu are ban spanu invarte banu te bati cu el ca e
        cout << "Acest inamic e Spanul ,el invarte banul si daca ghicesti pe ce fata pica(cap sau pajura), acestea sunt regulile: " << endl << "1=Cap" << endl << "2=Pajura" << endl;
        hpspan = 100;
        int ban = rand() % 2 + 1;
        int csaup;
        cout << "Ce alegi?(1 sau 2) (Daca alegi mai mult de 2 pierzi):";
        cin >> csaup;
        //PlaySound(TEXT("muzica\\span.wav"), NULL, SND_SYNC);
        if (ban == 1)
            cout << "E cap" << endl;
        else
            cout << "E pajura" << endl;

        if (csaup == ban)
        {
            cout << "Ai castigat, bravo " << numele << endl;

            map[11][12] = 'x';
            if (map[11][12] == 'x')
            {
                map[12][20] = 'P';
                map[7][15] = 'N';
            };

            lvl++;
            cout << "Ai castigat 100 de lei.\n";
            bani += 100;
            cout << "Ai ajuns la LVL " << lvl << endl;
            //PlaySound(TEXT("muzica\\Powerup5.wav"), NULL, SND_SYNC);
            _getch();

        }
        else
        {
            cout << "Ai pierdut!\n" << endl;
            _getch();

        }
    }

    fstream f("savel.in");
    {
        f << dmg_sabie << endl;
        f << hp << endl;
        f << mana << endl;
        f << lvl << endl;
        f << bani << endl;
        f << x << endl;
        f << y << endl;
    }
    fstream harta("harta.in");
    {
        for (int display = 0; display < 22; display++)
        {
            harta << map[display] << endl;
        }
    }

    system("cls");
    if (playSoundinGame == true)
        Music_player();

    return 0;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void shop()
{

    Nice_Display(19, "    Magazin:", ShopKeeper);

    Sleep(1000);

    int alegere;

    cout << "\tShopkeeper:Bine ai venit in magazin flacau,eu sunt Lica Samadaul, vrei sa cumperi ceva?" << endl;
    cout << "\tAi " << bani << " lei" << endl;
    if (Side_Quest1 == false)
    {
        cout << "\tLica:Inainte de asta, am o mica problema, acia langa tarc imi tot da un urs tarcoale la rezervele de bere.\n\tAi vrea sa te ocupi pentru mine de problema asta? Hai ca-ti dau 100 de lei de vrei." << endl;
        int danu = 0;
        cout << "\t1.Da varule manca-ti-as" << endl << "\t2.Nu fram" << endl;
        cout << "\t:";
        cin >> danu;
        if (danu != 2)
        {
            cout << "\tLica:No da mersi fain, acia chiar jos sub targ e ursu dar ai grije ca tare mare e si puternic pare!" << endl;
            cout << "\tApasa orice tasta ca sa continui ";
            _getch();
            map[11][81] = 'b';
        }
        Side_Quest1 = true;
    }
    {

        cout << "\t\n\t1.Sabie (+10 DMG)-LVL*60 lei" << endl << "\t2.Armura (+50 HP)-LVL*60" << endl << "\t3.Cristal de mana (+50 mana)-LVL*60" << endl << "\t4.Nimic" << endl << "\tCe vrei sa iei? (1,2,3 sau 4):";

        cin >> alegere;

        if (bani - (lvl * 60) <= 0 && alegere != 4)
        {
            cout << "\tFonduri insuficiente";
            _getch();
        }

        if (alegere != 0)
        {
            if (alegere == 1 && bani - (lvl * 60) >= 0)
            {
                if (SwordStatus == true)
                {
                    dmg_sabie = dmg_sabie + 10;
                    bani -= lvl * 60;
                    //PlaySound(TEXT("muzica\\shop.wav"), NULL, SND_SYNC);
                    SwordStatus = true;
                }

                else
                {
                    cout << "\tNu ai nicio sabie , costa 120 sa iti cumperi prima sabie(20 dmg).\n";
                    _getch();
                    dmg_sabie = 20;
                    bani -= 120;
                    //PlaySound(TEXT("muzica\\shop.wav"), NULL, SND_SYNC);
                    SwordStatus = true;
                }

            }
            else if (alegere == 2 && bani - (lvl * 60) >= 0)
            {
                hp += 50;
                bani -= lvl * 60;
               // PlaySound(TEXT("muzica\\shop.wav"), NULL, SND_SYNC);
            }
            else if (alegere == 3 && bani - (lvl * 60) >= 0)
            {
                mana += 50;
                bani -= lvl * 60;
                //PlaySound(TEXT("muzica\\shop.wav"), NULL, SND_SYNC);
            }

        }
    }
    system("cls");
    if (playSoundinGame == true)
        Music_player();

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void barbut_pe_viata()
{

    //PlaySound(NULL, NULL, 0);

    system("cls");

    _getch();

    int zar1;
    int zar2;
    int zarb1;
    int zarb2;

LOOP:
    zarb1 = rand() % 6 + 1;
    zarb2 = rand() % 4 + 1;
    zar1 = rand() % 6 + 1;
    zar2 = rand() % 6 + 1;

    cout << "\tApasa orice tasta ca sa invarti zaruruile" << endl;
    _getch();

    //PlaySound(TEXT("muzica\\zaruri.wav"), NULL, SND_ASYNC);

    cout << "\tAi nimerit:" << endl;
    cout << "\t -------     ------" << endl;
    cout << "\t|   " << zar1 << "   |   |   " << zar2 << "  |" << endl;
    cout << "\t|       |   |      |" << endl;
    cout << " \t-------     ------" << endl;

    cout << "\tApasa orice ca sa vezi ca e nimerit inamicul.\n";
    _getch();

    cout << "\tEl a nimenit:" << endl;

    //PlaySound(TEXT("muzica\\zaruri.wav"), NULL, SND_ASYNC);

    cout << "\t -------     ------" << endl;
    cout << "\t|   " << zarb1 << "   |   |   " << zarb2 << "  |" << endl;
    cout << "\t|       |   |      |" << endl;
    cout << "\t -------     ------" << endl;

    _getch();



    if (zar1 + zar2 == 2 && zarb1 + zarb2 != 2)
    {
        cout << "\tAi castigat!\n";
        map[12][20] = 'x';

        cout << "\tAi primit 120 lei.\n";
        bani += 120;

        _getch();

    }

    else if (zarb1 + zarb2 == 2 && zar1 + zar2 != 2)
    {
        cout << "\tAi pierdut.\n";

        _getch();

    }

    else if (zar1 + zar2 > zarb1 + zarb2)
    {
        cout << "\tAi castigat!\n";
        map[12][20] = 'x';

        cout << "\tAi primit 120 lei.\n";
        bani += 120;

        _getch();
    }

    else if (zar1 + zar2 < zarb1 + zarb2)
    {
        cout << "\tAi pierdut.\n";
        _getch();
    }

    else if (zarb1 + zarb2 == zar1 + zar2)
        goto LOOP;


    fstream f("savel.in");
    {
        f << dmg_sabie << endl;
        f << hp << endl;
        f << mana << endl;
        f << lvl << endl;
        f << bani << endl;
        f << x << endl;
        f << y << endl;
    }

    fstream harta("harta.in");
    {
        for (int display = 0; display < 22; display++)
        {
            harta << map[display] << endl;
        }

    }

    cout << "\tApasa orice tasta ca sa iesi";
    _getch();
    system("cls");


    if (playSoundinGame == true)
        Music_player();

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int Alba_Neagra()
{
    //PlaySound(NULL, NULL, 0);

    system("cls");

    cout << "\tSigur vrei sa joci? 1.Da 2.Nu ";
    char Sure;
    cin >> Sure;
    if (Sure == '2')
    {
        cout << "\tMai bine asa...\n";
        _getch();
    }

    if (Sure == '1')
    {
        int Choose;
        int Bet;
        cout << "\tDe cate ori vrei sa joci alba-neagra? ";
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
        LLL:
            cout << "\tCati bani pariezi? ";
            cin >> Bet;
            if (Bet > bani)
            {

                cout << "\tNu ai atatia bani... Ai doar" << bani << " lei";
                cout << "\tPariezi dinou? (1.Da 2.Nu) ";
                int YN;
                cin >> YN;
                if (YN == 2)
                    return 0;
                else
                    goto LLL;

            }
            int Pahar = rand() % 3 + 1;
            cout << "\tCe pahar alegi? (1,2 sau 3) ";
            cin >> Choose;
            if (Choose == Pahar)
            {
                cout << "\tAi castigat!!!\n";
                bani += Bet;
            }
            else
            {
                cout << "\tAi pierdut! :(\n";
                bani -= Bet;
            }
        }

        map[7][15] = 'N';
        map[18][16] = ' ';
        map[18][15] = ' ';
        _getch();
    }

    system("cls");

    if (playSoundinGame == true)
        Music_player();

}

void default_Boss(char Player[100][100], char Enemy[100][100], int hpBoss, const char* enemyName)
{

    system("cls");

    cout << endl;

    for (int i = 0; i < 5; i++)
        cout << " ";

    for (int i = 5; i <= 185; i++)
        cout << "=";

    cout << "\n\n";
    center(enemyName);

    for (int i = 0; i < 5; i++)
        cout << " ";

    for (int i = 5; i <= 185; i++)
        cout << "=";

    cout << "\n\n";

    BOSS(Player, Enemy, hpBoss);

    for (int i = 0; i < 5; i++)
        cout << " ";

    for (int i = 5; i <= 185; i++)
        cout << "=";

    cout << "\n\n";

    char Atac[100][100] =
    {
        "~=====================================================~",
        "|                                                     |",
        "|                                                     |",
        "|                                                     |",
        "|    1.Atac Normal                 2.Atac Puternic    |",
        "|                                                     |",
        "|                                                     |",
        "|                     3.Retragere                     |",
        "|                                                     |",
        "|                                                     |",
        "~=====================================================~",
    };

    int atacX = 3;
    int atacY = 4;

    int atac;

    Atac[atacY][atacX] = '>';

    for (int D = 0; D < 12; D++)
        center(Atac[D]);

    char User_Attack = 12;

    while (User_Attack != 13)
    {
        clearScreen();

        User_Attack = _getch();

        for (int i = 0; i < 28; i++)
            cout << "\n";

        for (int At = 0; At <= 10; At++)
        {
            center(Atac[At]);
        }

        if ((GetAsyncKeyState(VK_LEFT) && atacX - 30 == 3) || (GetAsyncKeyState(VK_LEFT) && atacX - 17 == 3 && atacY - 3 == 4))
        {
            if (atacX - 30 == 3)
            {
                Atac[atacY][atacX] = ' ';
                atacX -= 30;
                Atac[atacY][atacX] = '>';
            }
            if (atacX - 17 == 3 && atacY - 3 == 4)
            {
                Atac[atacY][atacX] = ' ';
                atacX -= 17;
                atacY -= 3;
                Atac[atacY][atacX] = '>';
            }

        }
        if ((GetAsyncKeyState(VK_RIGHT) && atacX + 30 == 33) || (GetAsyncKeyState(VK_RIGHT) && atacX + 13 == 33 && atacY - 3 == 4))
        {

            if (atacX + 30 == 33)
            {
                Atac[atacY][atacX] = ' ';
                atacX += 30;
                Atac[atacY][atacX] = '>';
            }

            if (atacX + 13 == 33 && atacY - 3 == 4)
            {
                Atac[atacY][atacX] = ' ';
                atacX += 13;
                atacY -= 3;
                Atac[atacY][atacX] = '>';
            }

        }
        if ((GetAsyncKeyState(VK_DOWN) && atacX == 3) || (GetAsyncKeyState(VK_DOWN) && atacX == 33))
        {
            if (atacX == 3) // 17 3
            {
                Atac[atacY][atacX] = ' ';
                atacX += 17;
                atacY += 3;
                Atac[atacY][atacX] = '>';
            }

            if (atacX == 33) // 13 3
            {
                Atac[atacY][atacX] = ' ';
                atacX -= 13;
                atacY += 3;
                Atac[atacY][atacX] = '>';
            }
        }

        if (GetAsyncKeyState(VK_UP) && atacX == 20 && atacY == 7)
        {
            Atac[atacY][atacX] = ' ';
            atacX -= 17;
            atacY -= 3;
            Atac[atacY][atacX] = '>';
        }



        if (User_Attack == 13)
        {
            if (Atac[atacY][atacX + 2] == '1')
                atac = 1;
            if (Atac[atacY][atacX + 2] == '2')
                atac = 2;
            if (Atac[atacY][atacX + 2] == '3')
                atac = 3;
        }
    }

    cout << atac;
    system("pause");
    system("cls");





}

void Events(int x2, int y)
{
    if (map[y][x2] == 'S')
        span_boss();
    if (map[y][x2] == 'l')
        shop();
    if (map[y][x2] == 'b')
        urs();
    if (map[y][x2] == 'B')
        BossDisplay1(Location1, Boss1);
    if (map[y][x2] == 'P')
        barbut_pe_viata();
    if (map[y][x2] == 'N')
        Alba_Neagra();
    if (map[y][x2] == 'D')
        default_Boss(Player, Span, 30, "Cata");
}

void SaveMM()
{
    save();
    harta_save();
}

void Start_Menu()
{
    int start;
    system("cls");

    cout << "\n\n";

    for (int i = 0; i < 5; i++)
        cout << " ";

    for (int i = 5; i <= 185; i++)
        cout << "=";

    cout << "\n\n";

    for (int nume = 0; nume <= 6; nume++)
        center(Nume_joc[nume]);

    cout << "\n\n\n\n\n";

    char meniu[100][100] =
    {
        "===============================================================",
        "||                                                           ||",
        "||                                                           ||",
        "||                        1.Continua                         ||",
        "||                        2.Joc nou                          ||",
        "||                                                           ||",
        "||                                                           ||",
        "||                                                           ||",
        "||                                                           ||",
        "===============================================================",
    };

    int SageataY = 3;
    int SageataX = 24;

    meniu[SageataY][SageataX] = '>';

    for (int Menu = 0; Menu <= 10; Menu++)
        center(meniu[Menu]);

    char User_Menu = 12;

    while (User_Menu != 13)
    {
        clearScreen();

        User_Menu = _getch();

        for (int i = 0; i < 16; i++)
            cout << "\n";

        for (int Menu = 0; Menu <= 10; Menu++)
        {
            center(meniu[Menu]);
        }

        if (GetAsyncKeyState(VK_UP) && SageataY - 1 == 3)
        {
            int yy2 = SageataY - 1;
            if (meniu[yy2][SageataX] == ' ')
            {
                meniu[SageataY][SageataX] = ' ';
                SageataY--;
                meniu[SageataY][SageataX] = '>';
            }

        }

        if (GetAsyncKeyState(VK_DOWN) && SageataY + 1 == 4)
        {
            int yy2 = SageataY + 1;
            if (meniu[yy2][SageataX] == ' ')
            {
                meniu[SageataY][SageataX] = ' ';
                SageataY++;
                meniu[SageataY][SageataX] = '>';
            }

        }

        if (User_Menu == 13)
        {
            if (meniu[SageataY][SageataX + 2] == '1')
                start = 1;
            if (meniu[SageataY][SageataX + 2] == '2')
                start = 2;
        }
    }


    system("cls");

    if (start == 1)
    {
        ifstream f("savel.in");
        {
            f >> numele;
            f >> dmg_sabie;
            f >> hp;
            f >> mana;
            f >> lvl;
            f >> bani;
            f >> x;
            f >> y;
            f >> curr_Location;
            f >> SwordStatus;
            f >> playSoundinGame;
        }

        ifstream harta("harta.in");
        for (int display = 0; display < 22; display++)
        {
            harta >> map[display];
        }
        SystemCl = true;

    }
    if (start == 2)
    {

        for (int i = 0; i < 5; i++)
            cout << " ";

        for (int i = 5; i <= 185; i++)
            cout << "=";

        center("~~Care ti-e numele?~~");
        cout << "\n\tDoar caractere (15)\n";
        cout << "\t\t:";
        cin >> numele;
        cout << "\n\tApasa orice ca sa corfirmi";
        _getch();
        system("cls");
        cout << "\tSalut " << numele << "." << endl;
        cout << "\tBine ai venit in RPG-ul lui Cata. Inainte sa incepi trebuie sa clarificam niste terburi:" << endl;
        cout << "\tTe misti cu sagetile din partea dreapta a tastaturii" << endl;
        _getch();
        cout << "\tBun. Caracterele mari sunt bossi,l e Lica(shopu), c e cazinoul, side missionurile sunt caractere mici" << endl;
        cout << "\tInainte sa iesi salveaza progresul" << endl;
        cout << "\tApasa orice tasta ca sa intri in meniu." << endl;
        _getch();
        dmg_sabie = 0;
        hp = 100;
        lvl = 1;
        mana = 100;
        bani = 20;
        x = 5;
        y = 3;
        SystemCl = true;
        playSoundinGame = true;
    }
    system("cls");

}

void Start()
{
    if (SystemCl == true)
    {

        for (int display = 0; display < 22; display++)
        {
            center(map[display]);
            for (int X_Coord = 0; X_Coord < 100; X_Coord++)
                for (int Y_Coord = 0; Y_Coord < 200; Y_Coord++)
                    if (map[X_Coord][Y_Coord] == '.')
                        map[X_Coord][Y_Coord] = ' ';
        }


        cout << "\n";
        center("~~~~~~~~~~RPG-ul lui Cata~~~~~~~~~~");
        cout << "\n\n";

        for (int i = 0; i < 5; i++)
            cout << " ";

        for (int i = 5; i <= 185; i++)
            cout << "=";

        cout << "\n\n\t";

        for (int i = 0; i < 25; i++)
            cout << "-";

        cout << "\n";
        cout << "\t|";
        SetConsoleTextAttribute(hConsole, 15);
        centermini("Lvl", lvl);
        SetConsoleTextAttribute(hConsole, 7);
        cout << "\t\t|\n";
        cout << "\t|";
        SetConsoleTextAttribute(hConsole, 4);
        centermini("HP", hp);
        SetConsoleTextAttribute(hConsole, 7);
        cout << "\t|\n";
        cout << "\t|";
        SetConsoleTextAttribute(hConsole, 9);
        centermini("Mana", mana);
        SetConsoleTextAttribute(hConsole, 7);
        cout << "\t|\n";
        cout << "\t|";
        SetConsoleTextAttribute(hConsole, 14);
        centermini("Bani", bani);
        SetConsoleTextAttribute(hConsole, 7);
        cout << "\t|\n";
        cout << "\t|";
        if (dmg_sabie != 0)
        {
            SetConsoleTextAttribute(hConsole, 8);
            centermini("Dmg", dmg_sabie);
            SetConsoleTextAttribute(hConsole, 7);
            cout << "\t\t|\n";
            cout << "\t|";
        }
        if (dmg_sabie == 0)
        {
            SetConsoleTextAttribute(hConsole, 8);
            centermini("N-ai sabie", dmg_sabie);
            SetConsoleTextAttribute(hConsole, 7);
            cout << "\t|\n";
            cout << "\t|";
        }

        for (int i = 0; i < 23; i++)
            cout << "-";
        cout << "|";


    }
    SetConsoleTextAttribute(hConsole, 7);
}

int Esc_Menu()
{
    system("cls");
    cout << "\n\n";

    for (int i = 0; i < 5; i++)
        cout << " ";

    for (int i = 5; i <= 185; i++)
        cout << "=";

    cout << "\n\n";

    for (int nume = 0; nume <= 6; nume++)
        center(Nume_joc[nume]);

    cout << "\n\n\n\n\n";

    char meniuEsc[100][100] =
    {
        "===============================================================",
        "||                                                           ||",
        "||                                                           ||",
        "||                        1.Continua                         ||",
        "||                        2.Credit                           ||",
        "||                        3.Salveaza jocul                   ||",
        "||                        4.Iesi din joc                     ||",
        "||                        5.Porneste/opreste muzica          ||",
        "||                                                           ||",
        "||                                                           ||",
        "||                                                           ||",
        "===============================================================",
    };


    int Choose;

    int ySageata = 3;
    int xSageata = 24;

    meniuEsc[ySageata][xSageata] = '>';

    for (int Menu = 0; Menu <= 16; Menu++)
        center(meniuEsc[Menu]);

    char User_MenuEsc = 12;

    while (User_MenuEsc != 13)
    {
        clearScreen();

        User_MenuEsc = _getch();

        for (int i = 0; i < 16; i++)
            cout << "\n";

        for (int Menu = 0; Menu <= 15; Menu++)
        {
            center(meniuEsc[Menu]);
        }

        if (GetAsyncKeyState(VK_UP) && ySageata > 3)
        {
            int y2 = ySageata - 1;
            if (meniuEsc[y2][xSageata] == ' ')
            {
                meniuEsc[ySageata][xSageata] = ' ';
                ySageata--;
                meniuEsc[ySageata][xSageata] = '>';
            }

        }

        if (GetAsyncKeyState(VK_DOWN) && ySageata < 7)
        {
            int y2 = ySageata + 1;
            if (meniuEsc[y2][xSageata] == ' ')
            {
                meniuEsc[ySageata][xSageata] = ' ';
                ySageata++;
                meniuEsc[ySageata][xSageata] = '>';
            }

        }

        if (User_MenuEsc == 13)
        {
            if (meniuEsc[ySageata][xSageata + 2] == '1')
                Choose = 1;
            if (meniuEsc[ySageata][xSageata + 2] == '2')
                Choose = 2;
            if (meniuEsc[ySageata][xSageata + 2] == '3')
                Choose = 3;
            if (meniuEsc[ySageata][xSageata + 2] == '4')
                Choose = 4;
            if (meniuEsc[ySageata][xSageata + 2] == '5')
                Choose = 5;
        }
    }

    if (Choose == 1)
        system("cls");
    if (Choose == 2)
    {
        system("cls");
        cout << "FlaCat Games++" << endl;
        cout << "Apasa orice tasta ca se reintri in joc...";
        _getch();
    }
    if (Choose == 3)
    {
        system("cls");
        save();
        harta_save();
    }
    if (Choose == 4)
    {
        save();
        harta_save();
        exit(0);
        return 0;
    }
    if (Choose == 5)
    {
        if (playSoundinGame == true)
        {
            playSoundinGame = false;
            //PlaySound(NULL, NULL, 0);
        }


        else
        {
            playSoundinGame = true;
            Music_player();
        }
        system("cls");
    }

}


#endif // VOIDURI_H
