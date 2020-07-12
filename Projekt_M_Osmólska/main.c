#include "header.h"
int main()
{
    wydatki* lista=NULL;
	puts("Wybierz czynnosc:\n 1.Aktualizajca miesiecznych wydatkow\n 2.Zarzadzanie calym rokiem wydatkow\n 3.Historia\n 4.Historia caloroczna\n 5.Wyjscie z programu\n");
	int action;
	do {
		scanf("%d", &action);
		switch (action)
		{
			case 1:
			    addinfo(&lista);
			    show_list(lista);
			    break;
            case 2:
                add_year();
                break;
            case 3:
                show_history();
                break;
            case 4:
                show_year();
                break;
        }
	}while (action =!5);
}

