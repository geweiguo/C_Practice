#define _CRT_SECURE_NO_WARNINGS 1 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>


#define ROWS 11
#define COLS 11
#define ROW 3
#define COL 3
#define MineCount 3



void Initboard(char arr[ROWS][COLS],int row,int col,char x);

void DispalyBoard(char arr[ROWS][COLS],int row,int col);

void Setmine(char arr[ROWS][COLS],int row,int col);

void Findmine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col);
