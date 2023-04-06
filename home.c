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
} normalMenu;

typedef struct veganMenu {
    char date[20];
    char soup[20];
    char mainDish[20];
    char sideDish[20];
    char extra[20];
    int saleCount[3];
} veganMenu;

typedef struct vegetarianMenu {
    char date[20];
    char soup[20];
    char mainDish[20];
    char sideDish[20];
    char extra[20];
    int saleCount[3];
} vegetarianMenu;

typedef struct Cafeteria {
    char* month;
    normalMenu* normalmenu;
    veganMenu* veganMenu;
    vegetarianMenu* vegetarianMenu;
} Cafeteria;

void initialize_menus(Cafeteria* cafeteria, char* csv_file_name);
int main() {
    Cafeteria* cafeteria = (Cafeteria*) malloc(sizeof(Cafeteria));
    char* theFile = "cafeteria_march_menu.csv";
    initialize_menus(cafeteria, theFile);
    printf("%s",cafeteria->normalmenu[0].mainDish); 
    printf("The month is %s",cafeteria->month);

    free(cafeteria->normalmenu);
    free(cafeteria->veganMenu);
    free(cafeteria->vegetarianMenu);
    free(cafeteria->month);
    free(cafeteria);
}


void initialize_menus(Cafeteria* cafeteria, char* theFile)
{
  FILE* fp;
  char ch;
  char* token; 
  char* Split = ",";
  char** arr = (char**) malloc(6 * sizeof(char*));
  int i, normalIndex = 0, veganIndex = 0, vegetarianIndex = 0,j,n;
  char buffer[255];
  
  int hold[2];
  int charcount = 0;
  //Initializing
  cafeteria->normalmenu = (normalMenu*) malloc(sizeof(normalMenu) * 31);
  cafeteria->veganMenu = (veganMenu*)malloc(sizeof(veganMenu) * 31);
  cafeteria->vegetarianMenu = (vegetarianMenu*)malloc(sizeof(vegetarianMenu) * 31);
  cafeteria->month = NULL;

  // Month name
  for (int i = 0; theFile[i] != '\0'; i++) 
  { 
    if(theFile[i] == '_')
    {
      hold[charcount] = i;
      charcount++;
      if (charcount == 2)
      {
        int range = hold[1] - hold[0];
        cafeteria->month = (char*) malloc((range) * sizeof(char));
        strncpy(cafeteria->month, theFile + hold[0] + 1, range - 1);
        cafeteria->month[range - 1] = '\0'; 
        break;
      }
    }
  }

  // Reading the file and storing the information
  fp = fopen(theFile, "r");
  while(fgets(buffer, 255, fp) != NULL) {
      token = strtok(buffer, Split);
      i = 0, j = 0;
      while(token != NULL) {
        arr[i++] = token;
        token = strtok(NULL, Split);
      }
 			// Removing the double quoates in the .csv file
      for(n=0; n<5; n++) {
        for(j=0; j<strlen(arr[n]); j++) {
            if(arr[n][j] == '\"') {
                strcpy(&arr[n][j], &arr[n][j+1]);
                j--;
            }
        }
    }
      if(strcmp(arr[0],  "Normal" ) == 0)
      {
        strcpy((cafeteria->normalmenu[normalIndex]).date, arr[1]);
        strcpy((cafeteria->normalmenu[normalIndex]).soup, arr[2]);
        strcpy((cafeteria->normalmenu[normalIndex]).mainDish, arr[3]);
        printf("Flag:1 This string is %s \n", cafeteria -> normalmenu[normalIndex].mainDish);
        strcpy((cafeteria->normalmenu[normalIndex]).sideDish, arr[4]);
        strcpy((cafeteria->normalmenu[normalIndex]).extra, arr[5]);
        memset(cafeteria->normalmenu[normalIndex].saleCount, 0, 3);
        normalIndex++;

      }
      else if (strcmp(arr[0], "Vegan") == 0 )
      { 
        printf("You are in else if 1 \n");
        strcpy((cafeteria->vegetarianMenu[vegetarianIndex]).date, arr[1]);
        strcpy((cafeteria->vegetarianMenu[vegetarianIndex]).soup, arr[2]);
        strcpy((cafeteria->vegetarianMenu[vegetarianIndex]).mainDish, arr[3]);
        strcpy((cafeteria->vegetarianMenu[vegetarianIndex]).sideDish, arr[4]);
        strcpy((cafeteria->vegetarianMenu[vegetarianIndex]).extra, arr[5]);
        vegetarianIndex++;
      }
      else if (strcmp(arr[0], "Vegetarian") == 0)
      {
        printf("You are in else if 2 \n");
        strcpy((cafeteria->veganMenu[veganIndex]).date, arr[1]);
        strcpy((cafeteria->veganMenu[veganIndex]).soup, arr[2]);
        strcpy((cafeteria->veganMenu[veganIndex]).mainDish, arr[3]);
        strcpy((cafeteria->veganMenu[veganIndex]).sideDish, arr[4]);
        strcpy((cafeteria->veganMenu[veganIndex]).extra, arr[5]);
        veganIndex++;
      }
  }
  free(arr);
  fclose(fp);
}
