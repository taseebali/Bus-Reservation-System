#include<stdio.h>
#include<string.h>
#include <stdlib.h>

char busname[5][100] = {"W11","W12","W13","W14","W15"};
int file = 0;
void buslist(); // shows the buslist
void booking(); //main booking system
void cancel();// cancels the booking done by booking() function
void status();// shows the seat status 
void status1(int choice);
void file_making(); //creates the file 


int main(){
	system("COLOR 70");
    int choice;
    do{

    system("cls");
    printf("\n-----------------------------------------\n");
    printf("\tWelcome to the Bus reservation system..!");
    printf("\n-----------------------------------------\n");
    printf("   [1] View Bus List\n\n");
    printf("   [2] Book Tickets\n\n");
    printf("   [3] Cancel Booking\n\n");
    printf("   [4] Bus Status Board\n\n");
    printf("   [5] Exit\n\n");
    printf("\n-----------------------------------------\n");
    printf("    \n\nEnter your Choice: ");
    scanf("%d", &choice);
    switch(choice){
    case 1:
        buslist();
        break;
    case 2:
        booking();
        break;
    case 3:
        cancel();
        break;
    case 4:
        status();
        break;
    }
    printf("\n\nPress any key to continue..");
    getch(); //holds the screen

    }
    while(choice != 5);
     system("cls");
   printf("\n-----------------------------------------\n");
   printf("\nThank you for using this Bus reservation system..!");
   printf("\n-----------------------------------------\n");
   return 1;
}

void buslist(){
     system("cls");
    printf("\n-----------------------------------------");
    printf("\n\t    BUS LIST");
    printf("\n -----------------------------------------");
    printf("\n1 --> %s\n\n", busname[0]);
    printf("2 --> %s\n\n", busname[1]);
    printf("3 --> %s\n\n", busname[2]);
    printf("4 --> %s\n\n", busname[3]);
    printf("5 --> %s\n\n", busname[4]);
}
void booking(){
    system("cls");
    buslist();
    //-----------------------------------------//

    int choice, no_s, seat_no, bill = 0, i,x=0;
    int t_sn = 32;
    char tempstr[50] = "seat", tempstr2[50];
    //----------------------------------------//

    FILE *fout_a; // file declaration 
    printf("\n\nEnter your choice: ");
    scanf("%d", &choice); // bus choice 
    if(choice <0 && choice>5){
        printf("Wrong Parameters..!");
        printf("\nGoing to main menu..!");
        main(); // returns to main 
    }
    
    printf("\n\n --------------------------------------------------------------\n\n");
    printf("How many seats you want to book?: ");
    scanf("%d", &no_s);// no of seats 
    file_making();// creates files 
	int t_s = no_s;//done for making sure that there is no garbage value while reading files as s_no is required ahead.
    //----------------------------------File Writing---------------------------------------------------------------------------------------------------------------------//

    if (choice == 1){
        fout_a = fopen("tsno1.txt", "r");// "r" means that we are going to write on this file and tsno  = total seat no on ref bus
        while(!feof(fout_a)){
            fscanf (fout_a, "%d", &x);
            if(x < 32){ 			// checks for total seat no.
                t_sn = x;
            }

        }
        fclose(fout_a);
        fout_a = fopen("tsno1.txt", "w");// "w" means that we are going to write on this file and tsno  = total seat no on ref bus
        fprintf(fout_a, "%d ", t_sn - no_s);
        fclose(fout_a);
    }
    else if (choice == 2){
        fout_a = fopen("tsno2.txt", "r");// "r" means that we are going to write on this file and tsno  = total seat no on ref bus
        while(!feof(fout_a)){
            fscanf (fout_a, "%d", &x);
            if(x < 32){
                t_sn = x;
            }
            else{
                t_sn = 32;
            }

        }
        fclose(fout_a);
        fout_a = fopen("tsno2.txt", "w");// "w" means that we are going to write on this file and tsno  = total seat no on ref bus
        fprintf(fout_a, "%d ", t_sn - no_s);
        fclose(fout_a);
    }
    else if (choice == 3){
       fout_a = fopen("tsno3.txt", "r");// "r" means that we are going to write on this file and tsno  = total seat no on ref bus
        while(!feof(fout_a)){
            fscanf (fout_a, "%d", &x);
            if(x < 32){
                t_sn = x;
            }
            else{
                t_sn = 32;
            }

        }
        fclose(fout_a);
        fout_a = fopen("tsno3.txt", "w");// "w" means that we are going to write on this file and tsno  = total seat no on ref bus
        fprintf(fout_a, "%d ", t_sn - no_s);
        fclose(fout_a);
    }
    else if (choice == 4){
        fout_a = fopen("tsno4.txt", "r");// "r" means that we are going to write on this file and tsno  = total seat no on ref bus
        while(!feof(fout_a)){
//            ch = fgetc(fout_a);
            fscanf (fout_a, "%d", &x);
            if(x < 32){
                t_sn = x;
            }
            else{
                t_sn = 32;
            }

        }
        fclose(fout_a);
        fout_a = fopen("tsno4.txt", "w");// "w" means that we are going to write on this file and tsno  = total seat no on ref bus
        fprintf(fout_a, "%d ", t_sn - no_s);
        fclose(fout_a);
    }
    else {
        fout_a = fopen("tsno5.txt", "r");// "r" means that we are going to write on this file and tsno  = total seat no on ref bus
        while(!feof(fout_a)){
            fscanf (fout_a, "%d", &x);
            if(x < 32){
                t_sn = x;
            }
            else{
                t_sn = 32;
            }

        }
        fclose(fout_a);
        fout_a = fopen("tsno5.txt", "w");// "w" means that we are going to write on this file and tsno  = total seat no on ref bus
        fprintf(fout_a, "%d ", t_sn - no_s);
        fclose(fout_a);
    }
    //-----------------------------------------------------------------------------------------------------------------------------------------------------------------//
    sprintf(tempstr2, "%s%d.txt", tempstr, choice);
    fout_a = fopen(tempstr2, "a+");// "w" means that we are going to write on this file and tsno  = total seat no on ref bus
    for(i = 0; i<t_s; i++){
        printf("Seat Number: ");
        scanf("%d", &seat_no);
        fprintf(fout_a, "%d ", seat_no);
        bill += 200;
    }
    fclose(fout_a);
    printf("Your total checks out to be %d", bill);

}
void cancel(){
	file_making();// creates files 
    int n, i ,x,y;
    int s_no = 0;
    int arr[32];// array for filing and seats 
    system("cls");
    buslist();
    printf("Enter your choice: ");
    scanf("%d", &n);
    status1(n);


}

void status(){
    int mn, i ,j,x,y = 0;
    system("cls");
    buslist();
    printf("Enter your choice: ");
    scanf("%d", &mn);

    //----------------------------------------------------------//
    file_making();
    checking(mn);
}

void status1(int choice){
    int i,j, y;
    int s = checking(choice);
    int seat_no;
    int count = 1;
    if(s == 32){
        printf("\n\nThe bus has all empty seats.");
    }
    else{
        FILE *a, *b;
        printf("Enter your Seat No.: ");
        scanf("%d", &seat_no);
        if(choice == 1){
                a = fopen("seat1.txt", "r");
                int size = 32-s;
                int gh[33] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
                int arr[size];
                int index;

                for(i = 0; i < size; i++){
                    fscanf(a, "%d", &y);
                    arr[i] = y;
                    gh[y] = 1;

                }
                fclose(a);
                for(i = 0; i < 33; i++){
                    if(gh[seat_no] == 1){
                        gh[seat_no] = 0;
                    }
                }
                for(i = 0; i <size; i++){
                	if(arr[i] == seat_no){
                		index = i;
                		break;
					}
				}

				if (index != -1){
					for(i = index; i < size - 1; i++)
            			arr[i] = arr[i+1];

    				freopen(NULL, "seat1.txt", b);
    				a = fopen("tsno1.txt", "w");
    				b = fopen("seat1.txt", "w");
    				fprintf(a, "%d", s+1);
    				fclose(a);
    				for(i = 0; i< size - 1; i++){
    					fprintf(b, "%d ", arr[i]);
					}
					fclose(b);
					
					for(i = 0; i<8; i++){
                        printf("    ");
                    	for(j = 0; j<4; j++){
                        	if(gh[count] == 1){
                            	printf("%d.Occupied\t\t", count);
                        	}
                        	else{
                            	printf("%d.Empty \t\t", count);
                        	}
                        count++;
                    	}
                    	printf("\n");
               	}
				}
				else{
					printf("Seat not found, Try again..!");
				}

            }else if(choice == 2){
            	a = fopen("seat2.txt", "r");
                int size = 32-s;
                int gh[33] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
                int arr[size];
                int index;

                for(i = 0; i < size; i++){
                    fscanf(a, "%d", &y);

                    arr[i] = y;
                    gh[y] = 1;

                }
                fclose(a);
                for(i = 0; i < 33; i++){
                    if(gh[seat_no] == 1){
                        gh[seat_no] = 0;
                    }
                }
                for(i = 0; i <size; i++){
                	if(arr[i] == seat_no){
                		index = i;
                		break;
					}
				}

				if (index != -1){
					for(i = index; i < size - 1; i++)
            			arr[i] = arr[i+1];

    				freopen(NULL, "seat2.txt", b);
    				a = fopen("tsno2.txt", "w");
    				b = fopen("seat2.txt", "w");
    				fprintf(a, "%d", s+1);
    				fclose(a);
    				for(i = 0; i< size - 1; i++){
    					fprintf(b, "%d ", arr[i]);
					}
					fclose(b);
					
					for(i = 0; i<8; i++){
                        printf("    ");
                    	for(j = 0; j<4; j++){
                        	if(gh[count] == 1){
                            	printf("%d.Occupied\t\t", count);
                        	}
                        	else{
                            	printf("%d.Empty \t\t", count);
                        	}
                        count++;
                    	}
                    	printf("\n");
               	}
				}
				else{
					printf("Seat not found, Try again..!");
				}

			}else if(choice == 3){
            	a = fopen("seat3.txt", "r");
                int size = 32-s;
                int gh[33] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
                int arr[size];
                int index;

                for(i = 0; i < size; i++){
                    fscanf(a, "%d", &y);
                    arr[i] = y;
                    gh[y] = 1;
                }
                fclose(a);
                for(i = 0; i < 33; i++){
                    if(gh[seat_no] == 1){
                        gh[seat_no] = 0;
                    }
                }
                for(i = 0; i <size; i++){
                	if(arr[i] == seat_no){
                		index = i;
                		break;
					}
				}
//				int x = 0;
				if (index != -1){
					for(i = index; i < size - 1; i++)
            			arr[i] = arr[i+1];

    				freopen(NULL, "seat3.txt", b);
    				a = fopen("tsno3.txt", "w");
    				b = fopen("seat3.txt", "w");
    				fprintf(a, "%d", s+1);
    				fclose(a);
    				for(i = 0; i< size - 1; i++){
    					fprintf(b, "%d ", arr[i]);
					}
					fclose(b);
					
					for(i = 0; i<8; i++){
                        printf("    ");
                    	for(j = 0; j<4; j++){
                        	if(gh[count] == 1){
                            	printf("%d.Occupied\t\t", count);
                        	}
                        	else{
                            	printf("%d.Empty \t\t", count);
                        	}
                        count++;
                    	}
                    	printf("\n");
               	}
				}
				else{
					printf("Seat not found, Try again..!");
				}

			}else if(choice == 4){
            	a = fopen("seat4.txt", "r");
                int size = 32-s;
                int gh[33] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
                int arr[size];
                int index;

                for(i = 0; i < size; i++){
                    fscanf(a, "%d", &y);

                    arr[i] = y;
                    gh[y] = 1;

                }
                fclose(a);
                for(i = 0; i < 33; i++){
                    if(gh[seat_no] == 1){
                        gh[seat_no] = 0;
                    }
                }
                for(i = 0; i <size; i++){
                	if(arr[i] == seat_no){
                		index = i;
                		break;
					}
				}

				if (index != -1){
					for(i = index; i < size - 1; i++)
            			arr[i] = arr[i+1];

    				freopen(NULL, "seat4.txt", b);
    				a = fopen("tsno4.txt", "w");
    				b = fopen("seat4.txt", "w");
    				fprintf(a, "%d", s+1);
    				fclose(a);
    				for(i = 0; i< size - 1; i++){
    					fprintf(b, "%d ", arr[i]);
					}
					fclose(b);
					
					for(i = 0; i<8; i++){
                        printf("    ");
                    	for(j = 0; j<4; j++){
                        	if(gh[count] == 1){
                            	printf("%d.Occupied\t\t", count);
                        	}
                        	else{
                            	printf("%d.Empty \t\t", count);
                        	}
                        count++;
                    	}
                    	printf("\n");
               	}
				}
				else{
					printf("Seat not found, Try again..!");
				}

			}else if(choice == 5){
            	a = fopen("seat5.txt", "r");
                int size = 32-s;
                int gh[33] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
                int arr[size];
                int index;

                for(i = 0; i < size; i++){
                    fscanf(a, "%d", &y);

                    arr[i] = y;
                    gh[y] = 1;
                }
                fclose(a);
                for(i = 0; i < 33; i++){
                    if(gh[seat_no] == 1){
                        gh[seat_no] = 0;
                    }
                }
                for(i = 0; i <size; i++){
                	if(arr[i] == seat_no){
                		index = i;
                		break;
					}
				}

				if (index != -1){
					for(i = index; i < size - 1; i++)
            			arr[i] = arr[i+1];

    				freopen(NULL, "seat5.txt", b);
    				a = fopen("tsno5.txt", "w");
    				b = fopen("seat5.txt", "w");
    				fprintf(a, "%d", s+1);
    				fclose(a);
    				for(i = 0; i< size - 1; i++){
    					fprintf(b, "%d ", arr[i]);
					}
					fclose(b);
					
					for(i = 0; i<8; i++){
                        printf("    ");
                    	for(j = 0; j<4; j++){
                        	if(gh[count] == 1){
                            	printf("%d.Occupied\t\t", count);
                        	}
                        	else{
                            	printf("%d.Empty \t\t", count);
                        	}
                        count++;
                    	}
                    	printf("\n");
               	}
				}
				else{
					printf("Seat not found, Try again..!");
				}

			}
			else{
				printf("wroong parameters..!");
			}

        }
    }

int checking(int n){
    int i ,j,x,y = 0;
    int count =1;
    FILE *fout_a;
    FILE *a;
    if(n == 1){
            a= fopen("tsno1.txt", "r");
            fout_a = fopen("seat1.txt", "r");
            while(!feof(a)){
                fscanf (a, "%d", &x);
            }
            if(a == NULL || x == 32){
                for(i = 0; i<8; i++){
                    printf("    ");
                for(j = 0; j<4; j++){
                        printf("%d.Empty \t\t", count);
                    count++;
                }
                printf("\n");
                }
                fclose(a);
            }
            else {
                int size = 33-x;
                int gh[33] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
                int arr[size];
                fclose(a);

                for(i = 0; i < size; i++){
                    fscanf(fout_a, "%d", &y);
                    arr[i] = y;// 5
                    gh[y] =1; //5th element == 1, the array works on binary value such as 1001101011101101011
                }

                for(i = 0; i<8; i++){
                        printf("    ");
                    for(j = 0; j<4; j++){
                        if(gh[count] == 1){
                            printf("%d.Occupied\t\t", count);
                        }
                        else{
                            printf("%d.Empty \t\t", count);
                        }
                        count++;
                    }
                    printf("\n");
                }
            fclose(fout_a);
            }
            return x;

    }
    else if(n == 2){
             a = fopen("tsno2.txt", "r");
            fout_a = fopen("seat2.txt", "r");
            while(!feof(a)){
                fscanf (a, "%d", &x);
            }
            if(a == NULL || x == 32){
                for(i = 0; i<8; i++){
                    printf("    ");
                for(j = 0; j<4; j++){
                        printf("%d.Empty \t\t", count);
                    count++;
                }
                printf("\n");
                }
                fclose(a);
            }
            else {
                int size = 33-x;
                int gh[33] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
                int arr[size];
                fclose(a);

                for(i = 0; i < size; i++){
                    fscanf(fout_a, "%d", &y);

                    arr[i] = y;
                    gh[y] =1;
                }

                for(i = 0; i<8; i++){
                        printf("    ");
                    for(j = 0; j<4; j++){
                        if(gh[count] == 1){
                            printf("%d.Occupied\t\t", count);
                        }
                        else{
                            printf("%d.Empty \t\t", count);
                        }
                        count++;
                    }
                    printf("\n");
                }
            fclose(fout_a);
            }


    }
    else if(n == 3){
             a = fopen("tsno3.txt", "r");
            fout_a = fopen("seat3.txt", "r");
            while(!feof(a)){
                fscanf (a, "%d", &x);
            }
            if(a == NULL || x == 32){
                for(i = 0; i<8; i++){
                    printf("    ");
                for(j = 0; j<4; j++){
                        printf("%d.Empty \t\t", count);
                    count++;
                }
                printf("\n");
                }
                fclose(a);
            }
            else {
                int size = 33-x;
                int gh[33] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
                int arr[size];
                fclose(a);

                for(i = 0; i < size; i++){
                    fscanf(fout_a, "%d", &y);
                    arr[i] = y;
                    gh[y] =1;
                }

                for(i = 0; i<8; i++){
                        printf("    ");
                    for(j = 0; j<4; j++){
                        if(gh[count] == 1){
                            printf("%d.Occupied\t\t", count);
                        }
                        else{
                            printf("%d.Empty \t\t", count);
                        }
                        count++;
                    }
                    printf("\n");
                }
            fclose(fout_a);
            }


    }
    else if(n == 4){
             a = fopen("tsno4.txt", "r");
            fout_a = fopen("seat4.txt", "r");
            while(!feof(a)){
                fscanf (a, "%d", &x);
            }
            if(a == NULL || x == 32){
                for(i = 0; i<8; i++){
                    printf("    ");
                for(j = 0; j<4; j++){
                        printf("%d.Empty \t\t", count);
                    count++;
                }
                printf("\n");
                }
                fclose(a);
            }
            else {
                int size = 33-x;
                int gh[33] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
                int arr[size];
                fclose(a);
                for(i = 0; i < size; i++){
                    fscanf(fout_a, "%d", &y);
                    arr[i] = y;
                    gh[y] =1;
                }

                for(i = 0; i<8; i++){
                        printf("    ");
                    for(j = 0; j<4; j++){
                        if(gh[count] == 1){
                            printf("%d.Occupied\t\t", count);
                        }
                        else{
                            printf("%d.Empty \t\t", count);
                        }
                        count++;
                    }
                    printf("\n");
                }
            fclose(fout_a);
            }


    }
    else if(n == 5){
             a = fopen("tsno5.txt", "r");
            fout_a = fopen("seat5.txt", "r");
            while(!feof(a)){
                fscanf (a, "%d", &x);
            }
            if(a == NULL || x == 32){
                for(i = 0; i<8; i++){
                    printf("    ");
                for(j = 0; j<4; j++){
                        printf("%d.Empty \t\t", count);
                    count++;
                }
                printf("\n");
                }
                fclose(a);
            }
            else {
                int size = 33-x;
                int gh[33] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
                int arr[size];
                fclose(a);
                for(i = 0; i < size; i++){
                    fscanf(fout_a, "%d", &y);
                    arr[i] = y;
                    gh[y] =1;
                }

                for(i = 0; i<8; i++){
                        printf("    ");
                    for(j = 0; j<4; j++){
                        if(gh[count] == 1){
                            printf("%d.Occupied\t\t", count);
                        }
                        else{
                            printf("%d.Empty \t\t", count);
                        }
                        count++;
                    }
                    printf("\n");
                }
            fclose(fout_a);
            }


    }
    else{
        printf("Wrongful Parameters, Returning to menu..!");
    }
}
void file_making(){

	if(file == 0){
		FILE *a;
	int t_sn = 32;
	a = fopen("tsno1.txt", "w");
	fprintf(a, "%d", t_sn);
	fclose(a);
	//------------------------------------------//
	a = fopen("tsno2.txt", "w");
	fprintf(a, "%d", t_sn);
	fclose(a);
	//------------------------------------------//
	a = fopen("tsno3.txt", "w");
	fprintf(a, "%d", t_sn);
	fclose(a);
	//------------------------------------------//
	a = fopen("tsno4.txt", "w");
	fprintf(a, "%d", t_sn);
	fclose(a);
	//------------------------------------------//
	a = fopen("tsno5.txt", "w");
	fprintf(a, "%d", t_sn);
	fclose(a);
	//------------------------------------------//
	file++;
	}
	
}

