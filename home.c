#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct normalMenu {
    char date[20];
    char soup[20];
    char mainDish[20];
    char sideDish[20];
    char extra[20];
    int saleCount[3];
}normalMenu;
typedef struct veganMenu {
    char date[20];
    char soup[20];
    char mainDish[20];
    char sideDish[20];
    char extra[20];
    int saleCount[3];
}veganMenu;
typedef struct vegetarianMenu {
    char date[20];
    char soup[20];
    char mainDish[20];
    char sideDish[20];
    char extra[20];
    int saleCount[3];
}vegetarianMenu;
typedef struct Cafeteria {
    char* month;
    normalMenu* normalmenu;
    veganMenu* veganMenu;
    vegetarianMenu* vegetarianMenu;
}Cafeteria; 
Cafeteria* cafeteria = NULL;
void read_menu();
int main() {
  cafeteria->normalmenu = malloc(sizeof(normalMenu) * 31);
  cafeteria->veganMenu = malloc(sizeof(veganMenu) * 31);
  cafeteria->vegetarianMenu = malloc(sizeof(vegetarianMenu) * 31);
  read_menu(cafeteria);
  printf("%s", cafeteria->normalmenu[0].mainDish);

  free(cafeteria->normalmenu);
  free(cafeteria->veganMenu);
  free(cafeteria->vegetarianMenu);
  free(cafeteria);
}

void read_menu()
{
  FILE* fp;
  char ch;
  char* token; 
  char Split = ',';
  char* arr[6];
  int i = 0, normalIndex = 0, veganIndex = 0, vegetarianIndex = 0,j = 0;
  char buffer[255];
  fp = fopen("cafeteria_march_menu.csv", "r");
  while(fgets(buffer, 255, fp) != NULL) {
      token = strtok(buffer, &Split);
      i = 0;
      while(token != NULL) {
        arr[i++] = token;
        token = strtok(NULL, &Split);
      }
      if(strcmp(arr[0], "Normal") == 0)
      {
        strcpy((cafeteria->normalmenu[normalIndex]).date, arr[1]);
        strcpy((cafeteria->normalmenu[normalIndex]).soup, arr[2]);
        strcpy((cafeteria->normalmenu[normalIndex]).mainDish, arr[3]);
        strcpy((cafeteria->normalmenu[normalIndex]).sideDish, arr[4]);
        strcpy((cafeteria->normalmenu[normalIndex]).extra, arr[5]);
      }
      else if (strcmp(arr[0], "Vegan") == 0)
      {
        strcpy((cafeteria->veganMenu[veganIndex]).date, arr[1]);
        strcpy((cafeteria->veganMenu[veganIndex]).soup, arr[2]);
        strcpy((cafeteria->veganMenu[veganIndex]).mainDish, arr[3]);
        strcpy((cafeteria->veganMenu[veganIndex]).sideDish, arr[4]);
        strcpy((cafeteria->veganMenu[veganIndex]).extra, arr[5]);
      }
      else if (strcmp(arr[0], "Vegetarian") == 0)
      { 
        strcpy(cafeteria->vegetarianMenu->date, arr[1]);
        strcpy(cafeteria->vegetarianMenu->soup, arr[2]);
        strcpy(cafeteria->vegetarianMenu->mainDish, arr[3]);
        strcpy(cafeteria->vegetarianMenu->sideDish, arr[4]);
        strcpy(cafeteria->vegetarianMenu->extra, arr[5]);
      }
  }
  
  fclose(fp);
}