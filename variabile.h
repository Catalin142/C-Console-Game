#ifndef VARIABILE_H
#define VARIABILE_H

int dmg_sabie = 0, atac_normal = dmg_sabie, atac_strong = dmg_sabie + 15, hp, lvl, mana, skill_point, hpspan, goodending = 0, badending = 0, intre = 0;
float bani;
int x;
int y;
int Timer = 2;
bool playSoundinGame;
int x_mmv = 8;
int y_mmv = 8;
int x2;
int y2;
bool SystemCl;
char numele[16];
bool Side_Quest1;
///Map_I=1 Map_2=2 Map_Fin=3;
int curr_Location = 1;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


#endif // VARIABILE_H
