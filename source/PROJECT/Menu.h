#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

///Function declaration for menu selection
void SetColor(int ForgC);
void gotoxy(int x, int y);
void clearWindow();
void main_window();
void print_heading(const char st[]);
void SetColorAndBack(int ForC, int BackC);
void ClearConsole(int ForgC, int BackC);
void drawRectangle();
void window();

///Function definition for menu selection
void SetColor(int ForgC){
     WORD wColor;
     ///We will need this handle to get the current background attribute
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;

     ///We use csbi for the wAttributes word.
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
        ///Mask out all but the background attribute, and add in the foreground color
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}

void ClearConsole(int ForgC, int BackC)
{
     WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
     ///Get the handle to the current output buffer...
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     ///This is used to reset the carat/cursor to the top left.
     COORD coord = {0, 0};
     ///A return value... indicating how many chars were written
     ///   not used but we need to capture this since it will be
     ///   written anyway (passing NULL causes an access violation).
     DWORD count;
     ///This is a structure containing all of the console info
     /// it is used here to find the size of the console.
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     ///Here we will set the current color
     SetConsoleTextAttribute(hStdOut, wColor);
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          ///This fills the buffer with a given character (in this case 32=space).
          FillConsoleOutputCharacter(hStdOut, (TCHAR) 32, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
          FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &count );
          ///This will set our cursor position for the next print statement.
          SetConsoleCursorPosition(hStdOut, coord);
     }
     return;
}

void drawRectangle(){
    ///Top line
    gotoxy(0,0);
    printf("%c",201);
    for(int i = 1; i < 78; i++){gotoxy(i,0);
        printf("%c",205);
    }
    ///Bottom line
    gotoxy(78, 25);
    printf("%c",188);
    for(int i = 77; i > 0; i--){gotoxy(i,25);
        printf("%c",205);
    }
    ///Middle line
    for(int i = 1; i < 78; i++){gotoxy(i,8);
        printf("%c",205);
    }
    ///Right line
    gotoxy(78,0);
    printf("%c",187);
    for(int i = 1; i < 25; i++){gotoxy(78,i);
        if(i == 8){printf("%c",185);}
        else{printf("%c",186);}
    }
    ///Left line
    gotoxy(0,25);
    printf("%c",200);
    for(int i = 24; i > 0; i--){gotoxy(0,i);
        if(i == 8){printf("%c",204);}
        else{printf("%c",186);}
    }
}

void window(){
    char list1[] = "WELCOME STUDENT MANAGEMENT SYSTEM USING BINARY TREE DATA STRUCTURE";
    char list2[] = "BACH KHOA UNIVERSITY - 2020 - HO CHI MINH CITY";
    char list3[] = "PROGRAMMING AND MODIFYING BY";
    char list4[] = "Thoi Manh Cuong - ID: 1751012";

    drawRectangle();
    gotoxy(6,1);
    SetColor(5000);
    for(int n = 0; list1[n] != '\0'; n++){printf("%c",list1[n]);
        for(double m = 0; m < 888888; m++){}
    }
    gotoxy(15,3);
    for(int n = 0; list2[n] != '\0'; n++){printf("%c",list2[n]);
        for(double m = 0; m < 888888; m++){}
    }
    gotoxy(22,5);
    for(int n = 0; list3[n] != '\0'; n++){printf("%c",list3[n]);
        for(double m = 0; m < 888888; m++){}
    }
    gotoxy(18,7);
    for(int n = 0; list4[n] !='\0'; n++){printf("%c",list4[n]);
        for(double m = 0; m < 888888; m++){}
    }
}

void clearWindow(){
    //parameter "i" is X and "j" is Y on Cartesian Coordinate (Oxy)
    for(int i = 1; i < 100; i++){
        for(int j = 28; j < 50; j++){
            gotoxy(i,j);printf(" ");
        }
    }
    return;
}

void SetColorAndBack(int ForgC, int BackC){
     WORD wColor = ((BackC & 0x0F) << 10) + (ForgC & 0x0F);
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleTextAttribute(hStdOut, wColor);
     return;
}

void print_heading(const char st[]){
    SetColorAndBack(40,10);
    gotoxy(26,28);printf("--------- %s ---------",st);
    SetColorAndBack(20,30);
}

COORD coord = {0,0}; ///set the coordinate to 0, 0 (top-left corner of window);
void gotoxy(int x, int y){
    coord.X = x; coord.Y = y; /// X and Y coordinates
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hStdOut, coord);
}

void main_window(){

    char notice_2[] = "--- PLEASE ENTER THE CORRECT SELECTION AGAIN ---";
    char notice_1[] = "--- PLEASE PRESS THE CORRESPONDING NUMBER ON SCREEN TO PROCEED --- ";

    int choice, x = 1, i = 0, j = 0;
    SetColor(10);
	struct student *root = NULL;
	char name[20], cla[10], add[10], tel[10], id[10], sm[10], ch, ad;
	char *newname;
    do{
		gotoxy(x,10);printf("\t[1].ADD NEW STUDENT TO THE DATABASE.");
        gotoxy(x,12);printf("\t[2].DISPLAY INFORMATION OF A STUDENT IN THE DATABASE.");
        gotoxy(x,14);printf("\t[3].REMOVE STUDENT FROM THE DATABASE.");
        gotoxy(x,16);printf("\t[4].SAVE THE INFORMATION IN THE DATABASE TO THE FILE.");
        gotoxy(x,18);printf("\t[5].READ THE INFORMATION IN THE DATABASE FROM THE FILE.");
        gotoxy(x,20);printf("\t[6].EXIT FROM STUDENT MANAGEMENT PROGRAM.");
        do{
            gotoxy(x+6,22);
            SetColor(5000);
            ///Animating character notice_1
            for(int k = 0; notice_1[k] != '\0'; k++){
                printf("%c",notice_1[k]);
                for(double h = 0; h < 888888; h++){}
            }
            scanf("%d",&choice); fflush(stdin);
            if(choice < 1 || choice > 6){
                gotoxy(x+14,24);
                ///Animating character notice_2
                for(int l = 0; notice_2[l] != '\0' ; l++){
                    printf("%c",notice_2[l]);
                    for(double f = 0; f < 888888; f++){}
                }
            }
        }while(choice < 1 || choice > 6);

        switch(choice){
			case 1:
			    clearWindow();
			    gotoxy(x+25,26);
			    printf("--------------------------------------");
                print_heading("ADDING NEW STUDENT");
                gotoxy(x+25,30);
                printf("--------------------------------------");

                gotoxy(x,32);
                SetColor(1000);
                printf("******************************************************************************************************");

                SetColor(10);
                gotoxy(x+5,34);
                printf("[1] - Name Of Student -- ");gets(name); fflush(stdin);

                /*Three lines of code below converts the first character*
                 *in string of character from lower case to upper case*
                 *and also eliminates the redundant blank between two characters*/
                newname = convertStdName(name);
                strcpy(name,newname);
                free(newname);

                gotoxy(x+58,34);
                SetColor(20);
                printf("==> NAME --- ");puts(name);

                SetColor(10);
                gotoxy(x+5,36);
                printf("[2] - Class/Course -- ");gets(cla); fflush(stdin);

                gotoxy(x+58,36);
                SetColor(20);
                printf("==> CLASS --- ");
                while(cla[i]){ch = cla[i++];putchar(toupper(ch));}

                gotoxy(x+5,38);
                SetColor(10);
                printf("[3] - ID Number -- ");gets(id); fflush(stdin);

                gotoxy(x+58,38);
                SetColor(20);
                printf("==> ID NUMBER --- ");puts(id); fflush(stdin);

                gotoxy(x+5,40);
                SetColor(10);
                printf("[4] - Student's Address -- ");gets(add); fflush(stdin);

                gotoxy(x+58,40);
                SetColor(20);
                printf("==> ADDRESS --- ");
                while(add[j]){ad = add[j++];putchar(toupper(ad));}

                gotoxy(x+5,42);
                SetColor(10);
                printf("[5] - Telephone Number -- ");gets(tel); fflush(stdin);

                gotoxy(x+58,42);
                SetColor(20);
                printf("==> TELEPHONE NUMBER --- ");puts(tel);

                gotoxy(x+5,44);
                SetColor(10);
                printf("[6] - Semester -- ");gets(sm); fflush(stdin);

                gotoxy(x+58,44);
                SetColor(20);
                printf("==> SEMESTER --- ");puts(sm); 

                gotoxy(x+5,46);
                SetColor(1000);
                printf("**** The information of student %s is ADDED to the database successfully. ****",name);

			    AddStudent(name,id,add,tel,cla,sm);

			    gotoxy(x,48);
                SetColor(1000);
                printf("******************************************************************************************************");

			    gotoxy(x,50);
			    SetColor(1000);
			    system("pause");
			    break;

			case 2:
			    clearWindow();
			    gotoxy(x+25,26);
			    printf("-------------------------------------------------");
                print_heading("INFORMATION OF SINGLE STUDENT");
                gotoxy(x+25,30);
                printf("-------------------------------------------------");

                gotoxy(x,32);
                SetColor(1000);
                printf("****************************************************************************");

                gotoxy(x+4,34);
                SetColor(10);
                printf("Student's Name: -- ");gets(name); fflush(stdin);
                newname = convertStdName(name);
                strcpy(name,newname);
                free(newname);

                SetColor(20);
                PrintStudent(root,name);

                gotoxy(x,48);
                SetColor(1000);
                printf("****************************************************************************");

                gotoxy(x,50);
                SetColor(1000);
                system("pause");
				break;

            case 3:
                clearWindow();
			    gotoxy(x+25,26);
			    printf("---------------------------------------------");
                print_heading("REMOVING EXISTED STUDENT");
                gotoxy(x+25,30);
                printf("----------------------------------------------");

                gotoxy(x,32);
                SetColor(1000);
                printf("******************************************************************************************************");

                gotoxy(x,34);
                SetColor(10);
                printf("Enter Name -- ");gets(name); fflush(stdin);
                newname = convertStdName(name);
                strcpy(name,newname);
                free(newname);

                gotoxy(x+55,34);
                SetColor(20);
                printf("==> STUDENT'S NAME --- ");puts(name);

				int d = delete(root,name);
                SetColor(20);
                
				if (!d){
                	gotoxy(x,36);
                	SetColor(10);
                	printf("**** The information of the student %s is REMOVED from database successfully. ****",name);
				}
                else{
                	gotoxy(x,36);
                	SetColor(10);
					printf("**** The information of the student %s is NOT FOUND in the database. ****",name);		
				}
 				               
                
				balanceBinary(root);

                gotoxy(x,38);
                SetColor(1000);
                printf("******************************************************************************************************");

				gotoxy(x,40);
				SetColor(1000);
				system("pause");
				break;

			case 4:
                clearWindow();
                gotoxy(x,26);
                print_heading("SAVE RECORD TO A FILE");
                fflush(stdin);
                gotoxy(x,28);

                gotoxy(x,30);
                printf("****The information of student %s in the database is saved to a file successfully.****",name);
                WriteList(root);

                gotoxy(x,32);
                SetColor(1000);
                system("pause");
                break;

            case 5:
                clearWindow();
                gotoxy(x,26);
                print_heading("READ A FILE");
                fflush(stdin);
                gotoxy(x,28);

                gotoxy(x,30);
                ReadList();

                gotoxy(x,32);
                SetColor(1000);
                system("pause");
                break;

            case 6:
                clearWindow();
                char last_1[] = "DO YOU HAVE ANY QUESTIONS OR ANY IMPROVEMENTS, PLEASE FEEL FREE TO ASK ME.";
                char last_2[] = "VIA EMAIL (WORKING): 1450337@hcmut.edu.vn.";
                char last_3[] = "OR MY EMAIL: lephuochiep.1994.1911@gmail.com";
                gotoxy(x+25,26);
			    printf("--------------------------------------------------");
                print_heading("THANK YOU FOR USING MY PROGRAM");
                gotoxy(x+25,30);
                printf("--------------------------------------------------");
                fflush(stdin);

                gotoxy(x,32);
                SetColor(1000);

                printf("***********************************************************************************");

                gotoxy(x+18,34);
                SetColor(5555);
                for(int a = 0; last_1[a] != '\0'; a++){printf("%c",last_1[a]);
                        for(double q = 0; q < 8888888; q++){}
                }

                gotoxy(x+18,36);
                SetColor(5555);
                for(int b = 0; last_2[b] != '\0'; b++){printf("%c",last_2[b]);
                        for(double q = 0; q < 8888888; q++){}
                }

                gotoxy(x+18,38);
                SetColor(5555);
                for(int b = 0; last_3[b] != '\0'; b++){printf("%c",last_3[b]);
                        for(double q = 0; q < 8888888; q++){}
                }

                gotoxy(x,40);
                SetColor(1000);
                printf("***********************************************************************************");

                gotoxy(x,42);
                exit(1);
                break;
            }
        }
        while(1);
}
#endif // MENU_H_INCLUDED
