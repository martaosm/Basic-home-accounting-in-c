#include "header.h"

void add(wydatki** lista, wydatki* nowa)
{
     while (*lista != NULL) lista = &((*lista)->next);
     *lista = nowa;
     nowa->next = NULL;
}
void addinfo(wydatki** lista)
{
     wydatki* nowa = (wydatki*)malloc(sizeof(wydatki));
     printf("Podaj budzet: ");
     scanf("%d", &(nowa->budget));

     printf("Czynsz: ");
     scanf("%d", &(nowa->rent));

     printf("Kieszonkowe: " );
     scanf("%d", &(nowa->child));

     printf("Zakupy: " );
     scanf("%d",&(nowa->groceries));

     printf("Rachunki: " );
     scanf("%d",&(nowa->bills));

     printf("Edukacja: " );
     scanf("%d",&(nowa->education));

     add(lista, nowa);
}
void show_list(wydatki* lista)
{
    char str[100];
    int dwydatki;
    printf("Ile w tym miesiacu wydalo dziecko: ");
    scanf("%d",&dwydatki);
    printf("miesiac i rok(miesiac_rok): ");
    scanf("%s",&str);
    char buffer[32];
    snprintf(buffer,sizeof(char)*32,"%s.txt",str);
    FILE *pfile;
    pfile=fopen(buffer,"w+");
    wydatki* wsk = lista;
    int suma,suma1,suma2,suma3,suma4,suma5,budget;
    if(lista == NULL)
    printf("LISTA JEST PUSTA");
    else
        while( wsk != NULL)
     {
         fputs("Budzet: ",pfile);
         fprintf(pfile,"%d\n",wsk->budget);
         budget=wsk->budget;
         fputs("Czynsz: ",pfile);
         fprintf(pfile,"%d\n",wsk->rent);
         suma1=+wsk->rent;
         fputs("Kieszonkowe: ",pfile);
         fprintf(pfile,"%d\n",wsk->child);
         suma2=+wsk->child;
         fputs("Zakupy: ",pfile);
         fprintf(pfile,"%d\n",wsk->groceries);
         suma3=+wsk->groceries;
         fputs("Rachunki: ",pfile);
         fprintf(pfile,"%d\n",wsk->bills);
         suma4=+wsk->bills;
         fputs("Edukacja: ",pfile);
         fprintf(pfile,"%d\n",wsk->education);
         suma5=+wsk->education;
         wsk=wsk->next;
     }
     suma=suma1+suma2+suma3+suma4+suma5;
     int stan;
     if(suma>budget)
     {
         stan=budget-suma;
         fprintf(pfile,"Budzet zostal przekroczony. Twoj stan konta na miesiac %s to %d\n",str,stan);
     }
     else
     {
         stan=budget-suma;
         fprintf(pfile,"Budzet nie zostal przekroczony. Twoj stan konta na miesiac %s to %d\n",str,stan);
     }
     int info;
     if(dwydatki>suma2)
     {
         info=dwydatki-suma2;
         fprintf(pfile,"Limit dziecka zostal przekroczony o %d\n",info);
     }
     else
     {
         fprintf(pfile,"Limit nie zostal przekroczony\n");
     }
     fclose(pfile);
}

void show_history()
{
    char data[100];
    char buffer[32];
    char str[100];
    printf("miesiac i rok(miesiac_rok): ");
    scanf("%s",&str);
    snprintf(buffer,sizeof(char)*32,"%s.txt",str);
    FILE *pfile;
    pfile=fopen(buffer,"r");
    if(pfile==NULL)printf("Nie ma takiego pliku\n");
    for(int i=0;i<8;i++)
    {
        if(fgets(data,100,pfile)!=NULL)
            {
                printf(data);
            }
    }
    fclose(pfile);
}
void add_year()
{
    char buffer1[32];
    char str1[10];
    char str2[10];
    printf("rok: ");
    scanf("%s",&str2);
    snprintf(buffer1,sizeof(char)*32,"%s.txt",str2);
    FILE *pfile1;
    pfile1=fopen(buffer1,"a+");
    printf("Ktory plik chcesz dodac do historii wydatkow z roku %s?\n",str2);
    char data[100];
    char buffer2[32];
    char str[100];
    printf("miesiac i rok(miesiac_rok): ");
    scanf("%s",&str);
    fputs(str,pfile1);
    fputs("\n",pfile1);
    snprintf(buffer2,sizeof(char)*32,"%s.txt",str);
    FILE *pfile2;
    pfile2=fopen(buffer2,"r");
    for(int i=0;i<8;i++)
    {
        if(fgets(data,100,pfile2)!=NULL)
            {
                fprintf(pfile1,data);
            }
    }
    fclose(pfile1);
    fclose(pfile2);
}
void show_year()
{
    char data[1000000];
    char buffer[32];
    char str[100];
    printf("rok: ");
    scanf("%s",&str);
    snprintf(buffer,sizeof(char)*32,"%s.txt",str);
    FILE *pfile;
    pfile=fopen(buffer,"r");
    if(pfile==NULL)printf("Nie ma takiego pliku\n");
    for(int i=0;i<96;i++)
    {
        if(fgets(data,1000000,pfile)!=NULL)
            {
                printf(data);
            }
    }
    fclose(pfile);
}

