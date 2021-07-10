#include <iostream>
#define _WIN32_WINNT 0x0500
#include<windows.h>
#include <fstream>
#include <string.h>
#include <cstring>
#include <conio.h>
#include <stdlib.h>
#include <cstdlib>
#include <stdio.h>
#include <ctime>
#include <sstream>
#include "MMSystem.h"

using namespace std;

#include "variabile.h"
#include "Char.h"
#include "Voiduri.h"

int main()
{
    Setup(false);

    Logo();

    Start_Menu();

    system("cls");

    map[y][x] = char(215);

    char User_input;
    if (playSoundinGame == true)
        Music_player();

    while (1)
    {
        clearScreen();

        Start();

        if (curr_Location == 2)
            SetConsoleTextAttribute(hConsole, 8);

        if (map[11][81] == 'x' || map[15][93] == 'x')
            Side_Quest1 = true;

        //system("pause>null");

        User_input = _getch();

        if (GetAsyncKeyState(VK_DOWN))

        {
            int y2 = y + 1;
            if (map[y2][x] == ' ')
            {
                map[y][x] = ' ';
                y++;
                map[y][x] = char(215);
            }
            else
                Events(x, y2);
            SystemCl = true;
            SaveMM();
        }


        else if (GetAsyncKeyState(VK_UP))
        {
            int y2 = y - 1;
            if (map[y2][x] == ' ')
            {
                map[y][x] = ' ';
                y--;
                map[y][x] = char(215);
            }
            else
                Events(x, y2);
            SystemCl = true;
            SaveMM();
        }


        else if (GetAsyncKeyState(VK_RIGHT))
        {
            int x2 = x + 1;
            if (map[y][x2] == ' ')
            {
                map[y][x] = ' ';
                x++;
                map[y][x] = char(215);
            }
            else
                Events(x2, y);
            SystemCl = true;
            SaveMM();
        }


        else if (GetAsyncKeyState(VK_LEFT))
        {
            int x2 = x - 1;
            if (map[y][x2] == ' ')
            {
                map[y][x] = ' ';
                x--;
                map[y][x] = char(215);
            }
            else
                Events(x2, y);
            SystemCl = true;
            SaveMM();
        }


        else if (User_input == 27)
            Esc_Menu();
        else
            SystemCl = false;
    }
    return 0;
}
