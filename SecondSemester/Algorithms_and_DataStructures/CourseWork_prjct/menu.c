#include <stdio.h>
#include <stdio.h>
#include "common.h"
#include "measurement.h"
#include "vector_filling.h"
#include "print_vector.h"
#include "3D_filling.h"
#include "print_3D.h"

void clrscr();//очищення екрану та встановлення курсору на [1;1] 
void getch_one();//очікування вводу '1' для продовження дій в меню

void menu()
{
	char flagch = '3';// прапорець рівня циклів while() для вибору режиму 
	int sel1;
	int sel2;
	int sel3;
	float time;
	float Ordered, Random, Back_Ordered;

	while(flagch == '3'){
		clrscr();
		printf("--------------|\tMain Menu\n");
		printf("1.Select2   \t(Alg1)");
		printf("\n2.Select7   \t(Alg2)");
		printf("\n3.Exchange2 \t(Alg3)");
		printf("\n4.Full table\t(Package mode)");
		printf("\n5.Exit");
		printf("\n----------------------");
		printf("\nChoose 1, 2, 3 or 4 ---> ");
		scanf("%d", &sel1);
		flagch = '2';
		switch(sel1){
			case 1:
				while(flagch == '2')// вибір типу масива для метода "Select2"
				{
					clrscr();
					printf("--------------|\t1.Select2   \t(Alg1)"); 
					printf ("\n  1.3D Array");
				    printf ("\n  2.Vector");
					printf ("\n  3.Exit");
					printf("\n----------------------");	
				    printf ("\n  Choose 1, 2 or 3 ---> ");
					scanf ("%d", &sel2);
					
	
					switch(sel2)
					{
						case 1:
							flagch = '1';				
							while(flagch == '1')// вибір заповнення 3D масива для метода "Select2"
							{
								clrscr();
								printf("--------------|\t1.Select2   \t(Alg1)"); 
								printf ("\n  1.Ordered 3D array");
	                            printf ("\n  2.Random 3D array");
	                            printf ("\n  3.Back-ordered 3D array");
								printf ("\n  4.Exit");
								printf("\n----------------------");	
	                            printf ("\n  Choose 1, 2, 3 or 4 ---> ");
	                            scanf("%d", &sel3);
	
								switch(sel3)
								{
									case 1: 
    							    ordered3DFill();
									printf("\n");
 									printf("Before:\n");
									print3D();
 
									Select2_measurement('o');
									time = MeasurementProcessing();
   									
									printf("\n");
									printf("After:\n");
									print3D();
   									printf ("\nP = %d, M = %d, N = %d; Time =%7.2f\n", P,M,N, time);
									getch_one();
										break;
									case 2:
									random3DFill();
									printf("\n");
 									printf("Before:\n");
									print3D();
 
									Select2_measurement('r');
									time = MeasurementProcessing();

									printf("\n");
									printf("After:\n");
									print3D();
   									printf ("\nP = %d, M = %d, N = %d; Time =%7.2f\n", P,M,N, time);
									getch_one();
										break;
									case 3:
    							    backOrdered3DFill();
									printf("\n");
 									printf("Before:\n");
									print3D();
        
									Select2_measurement('b');
									time = MeasurementProcessing();
		
									printf("\n");
									printf("After:\n");
									print3D();
   									printf ("\nP = %d, M = %d, N = %d; Time =%7.2f\n", P,M,N, time);
									getch_one();	
										break;
									case 4:
									flagch = '2';// Вихід до меню з вибором типу масива
										break;	
								}
							}
							break;// case 1 - switch (sel2)
						case 2:
							flagch = '1';
							while(flagch == '1')// вибір заповнення вектора для метода "Select2"
							{
								clrscr();
								printf("--------------|\t1.Select2   \t(Alg1)"); 
	                            printf ("\n  1.Ordered vector");
	                            printf ("\n  2.Random vector");
	                            printf ("\n  3.Back-ordered vector");
								printf ("\n  4.Exit");
								printf("\n----------------------");	
	                            printf ("\n  Choose 1, 2, 3 or 4 ---> ");
	                            scanf("%d", &sel3);
	
								switch(sel3)
								{
									case 1:  
    							    orderedVecFill();
									printf("\n");
 									printf("Before:\n");
									printV();
        
									select2_measurement('o');
									time = MeasurementProcessing();

									printf("\n");
									printf("After:\n");
									printV();
   									printf ("\nVec_Length = %d; Time =%7.2f\n", Vec_Length, time);
									getch_one();
											break;// case 1 - switch (sel3)
									case 2:  
    							    randomVecFill();
									printf("\n");
 									printf("Before:\n");
									printV();
        
									select2_measurement('r');
									time = MeasurementProcessing();
   									
	
									printf("\n");
									printf("After:\n");
									printV();
   									printf ("\nVec_Length = %d; Time =%7.2f\n", Vec_Length, time);
									getch_one();
											break;// case 2 - switch (sel3)
									case 3:  
    							    backOrderedVecFill();
									printf("\n");
 									printf("Before:\n");
									printV();
        
									select2_measurement('b');
									time = MeasurementProcessing();
   									
	
									printf("\n");
									printf("After:\n");
									printV();
   									printf ("\nVec_Length = %d; Time =%7.2f\n", Vec_Length, time);
									getch_one();
											break;// case 3 - switch (sel3)
									case 4:
										flagch = '2';// Вихід до меню з вибором типу масива
											break;// case 4 - switch (sel3)
								}
							}
							break;// case 2 - switch (sel2)
						case 3:
							flagch = '3';
								break;// case 3 - switch (sel1)
					}
	 			
				}
				break;// case 1 - switch (sel1)
			case 2:
				while(flagch == '2')// вибір типу масива для метода "Select7"
				{
					clrscr();
					printf("--------------|\t2.Select7   \t(Alg2)"); 
					printf ("\n  1.3D Array");
				    printf ("\n  2.Vector");
					printf ("\n  3.Exit");
					printf("\n----------------------");	
				    printf ("\n  Choose 1, 2 or 3 ---> ");
					scanf ("%d", &sel2);
	
					switch(sel2)
					{
						case 1:
							flagch = '1';				
							while(flagch == '1')// вибір заповнення 3D масива для метода "Select7"
							{
								clrscr();
								printf("--------------|\t2.Select7   \t(Alg2)"); 
	                            printf ("\n  1.Ordered 3D array");
	                            printf ("\n  2.Random 3D array");
	                            printf ("\n  3.Back-ordered 3D array");
								printf ("\n  4.Exit");
								printf("\n----------------------");	
	                            printf ("\n  Choose 1, 2, 3 or 4 ---> ");
	                            scanf("%d", &sel3);
	
								switch(sel3)
								{
									case 1: 
    							    ordered3DFill();
									printf("\n");
 									printf("Before:\n");
									print3D();
        
									Select7_measurement('o');
									time = MeasurementProcessing();
		
									printf("\n");
									printf("After:\n");
									print3D();							
   									printf ("\nP = %d, M = %d, N = %d; Time =%7.2f\n", P,M,N, time);
									getch_one();
										break;
									case 2:
    							    random3DFill();
									printf("\n");
 									printf("Before:\n");
									print3D();
		
 									Select7_measurement('r');
									time = MeasurementProcessing();
		
									printf("\n");
									printf("After:\n");
									print3D();									
   									printf ("\nP = %d, M = %d, N = %d; Time =%7.2f\n", P,M,N, time);
									getch_one();
										break;
									case 3:
    							    backOrdered3DFill();
									printf("\n");
 									printf("Before:\n");
									print3D();
        
 									Select7_measurement('b');
									time = MeasurementProcessing();
		
									printf("\n");
									printf("After:\n");
									print3D();							
   									printf ("\nP = %d, M = %d, N = %d; Time =%7.2f\n", P,M,N, time);
									getch_one();
										break;
									case 4:
									flagch = '2';// Вихід до меню з вибором типу масива
										break;	
								}
							}
							break;// case 1 - switch (sel2)
						case 2:
							flagch = '1';
							while(flagch == '1')// вибір заповнення вектора для метода "Select7"
							{
								clrscr();
								printf("--------------|\t2.Select7   \t(Alg2)"); 	
	                            printf ("\n  1.Ordered vector");
	                            printf ("\n  2.Random vector");
	                            printf ("\n  3.Back-ordered vector");
								printf ("\n  4.Exit");
								printf("\n----------------------");
	                            printf ("\n  Choose 1, 2, 3 or 4 ---> ");
	                            scanf("%d", &sel3);
	
								switch(sel3)
								{
									case 1:   
    							    orderedVecFill();
									printf("\n");
 									printf("Before:\n");
									printV();
        
									select7_measurement('o');
									time = MeasurementProcessing();
   									
	
									printf("\n");
									printf("After:\n");
									printV();
   									printf ("\nVec_Length = %d; Time =%7.2f\n", Vec_Length, time);
									getch_one();
									break;// case 1 - switch (sel3)
									case 2:   
    							    randomVecFill();
									printf("\n");
 									printf("Before:\n");
									printV();
        
									select7_measurement('r');
									time = MeasurementProcessing();
   									
	
									printf("\n");
									printf("After:\n");
									printV();
   									printf ("\nVec_Length = %d; Time =%7.2f\n", Vec_Length, time);
									getch_one();	
									break;// case 2 - switch (sel3)
									case 3:   
    							    backOrderedVecFill();
									printf("\n");
 									printf("Before:\n");
									printV();
        
									select7_measurement('b');
									time = MeasurementProcessing();
   									
	
									printf("\n");
									printf("After:\n");
									printV();
   									printf ("\nVec_Length = %d; Time =%7.2f\n", Vec_Length, time);
									getch_one();	
									break;// case 3 - switch (sel3)
									case 4:
										flagch = '2';// Вихід до меню з вибором типу масива
											break;// case 4 - switch (sel3)
								}
							}
							break;// case 2 - switch (sel2)
						case 3:
							flagch = '3';
								break;// case 3 - switch (sel2)
					}
	 			
				}
				break;// case 2 - switch (sel1)
			case 3:
				while(flagch == '2')// вибір типу масива для метода "Exchange2"
				{
					clrscr();
					printf("--------------|\t3.Exchange2   \t(Alg3)"); 
					printf ("\n  1.3D Array");
				    printf ("\n  2.Vector");
					printf ("\n  3.Exit");
					printf("\n----------------------");	
				    printf ("\n  Choose 1, 2 or 3 ---> ");
					scanf ("%d", &sel2);
					
	
					switch(sel2)
					{
						case 1:
							flagch = '1';				
							while(flagch == '1')// вибір заповнення 3D масива для метода "Exchange2"
							{
								clrscr();
								printf("--------------|\t3.Exchange2   \t(Alg3)"); 
	                            printf ("\n  1.Ordered 3D array");
	                            printf ("\n  2.Random 3D array");
	                            printf ("\n  3.Back-ordered 3D array");
								printf ("\n  4.Exit");
								printf("\n----------------------");	
	                            printf ("\n  Choose 1, 2, 3 or 4 ---> ");
	                            scanf("%d", &sel3);
	
								switch(sel3)
								{
									case 1: 
    							    ordered3DFill();
									printf("\n");
 									printf("Before:\n");
									print3D();
        
									Exchange2_measurement('o');
									time = MeasurementProcessing();
		
									printf("\n");
									printf("After:\n");
									print3D();							
   									printf ("\nP = %d, M = %d, N = %d; Time =%7.2f\n", P,M,N, time);
									getch_one();
										break;
									case 2: 
    							    random3DFill();
									printf("\n");
 									printf("Before:\n");
									print3D();
        
									Exchange2_measurement('r');
									time = MeasurementProcessing();
		
									printf("\n");
									printf("After:\n");
									print3D();							
   									printf ("\nP = %d, M = %d, N = %d; Time =%7.2f\n", P,M,N, time);
									getch_one();
										break;
									case 3: 
    							    backOrdered3DFill();
									printf("\n");
 									printf("Before:\n");
									print3D();

									Exchange2_measurement('b');
									time = MeasurementProcessing();
		
									printf("\n");
									printf("After:\n");
									print3D();							
   									printf ("\nP = %d, M = %d, N = %d; Time =%7.2f\n", P,M,N, time);
									getch_one();
										break;
									case 4:
									flagch = '2';// Вихід до меню з вибором типу масива
										break;	
								}
							}
							break;// case 1 - switch (sel2)
						case 2:
							flagch = '1';
							while(flagch == '1')// вибір заповнення вектора для метода "Exchange2"
							{
								clrscr();
								printf("--------------|\t3.Exchange2   \t(Alg3)"); 	
	                            printf ("\n  1.Ordered vector");
	                            printf ("\n  2.Random vector");
	                            printf ("\n  3.Back-ordered vector");
								printf ("\n  4.Exit");
								printf("\n----------------------");
	                            printf ("\n  Choose 1, 2, 3 or 4 ---> ");
	                            scanf("%d", &sel3);
	
								switch(sel3)
								{
									case 1:   
    							    orderedVecFill();
									printf("\n");
 									printf("Before:\n");
									printV();
        
									exchange2_measurement('o');
									time = MeasurementProcessing();
	
									printf("\n");
									printf("After:\n");
									printV();
   									printf ("\nVec_Length = %d; Time =%7.2f\n", Vec_Length,time);
									getch_one();	
									break;// case 1 - switch (sel3)
									case 2:   
    							    randomVecFill();
									printf("\n");
 									printf("Before:\n");
									printV();
        
									exchange2_measurement('r');
									time = MeasurementProcessing();
   									
	
									printf("\n");
									printf("After:\n");
									printV();
   									printf ("\nVec_Length = %d; Time =%7.2f\n", Vec_Length, time);
									getch_one();	
									break;// case 2 - switch (sel3)
									case 3:  
    							    backOrderedVecFill();
									printf("\n");
 									printf("Before:\n");
									printV();
         
									exchange2_measurement('b');
									time = MeasurementProcessing();
	
									printf("\n");
									printf("After:\n");
									printV();
   									printf ("\nVec_Length = %d; Time =%7.2f\n", Vec_Length, time);
									getch_one();	
									break;// case 3 - switch (sel3)
									case 4:
										flagch = '2';// Вихід до меню з вибором типу масива
											break;// case 4 - switch (sel3)
								}
							}
							break;// case 2 - switch (sel2)
						case 3:
							flagch = '3';
								break;// case 3 - switch (sel2)
					}
	 			
				}
				break;// case 3 - switch (sel1)
			case 4:
				//pacmode
				flagch = '3';
				clrscr();
				
				printf("\tTable for the array: P = %d, M = %d, N = %d; [Array walkthrough: 3]\n\n",P,M,N);

				printf("Method \t\tOrdered\t\t\tRandom Ordered\t\tBack Ordered\n\n");

				Select2_measurement('o');
				Ordered = MeasurementProcessing ();
			    Select2_measurement('r');
			    Random = MeasurementProcessing ();
			    Select2_measurement('b');
			    Back_Ordered = MeasurementProcessing ();
				printf("Select2\t\t%f\t\t%f\t\t%f\n\n", Ordered, Random, Back_Ordered);

				Select7_measurement ('o');
				Ordered = MeasurementProcessing ();
				Select7_measurement ('r');
				Random = MeasurementProcessing ();
				Select7_measurement ('b');
				Back_Ordered = MeasurementProcessing ();
				printf("Select7\t\t%f\t\t%f\t\t%f\n\n", Ordered, Random, Back_Ordered);

				Exchange2_measurement ('o');
				Ordered = MeasurementProcessing ();
				Exchange2_measurement ('r');
				Random = MeasurementProcessing ();
				Exchange2_measurement ('b');
				Back_Ordered = MeasurementProcessing ();
				printf("Exchange2\t%f\t\t%f\t\t%f\n\n", Ordered, Random, Back_Ordered);

				printf("\t  Table for the vector: N = %d; [Array walkthrough: 3]\n\n", Vec_Length);

				printf("Method \t\tOrdered\t\t\tRandom Ordered\t\tBack Ordered\n\n");

			    select2_measurement('o');
				Ordered = MeasurementProcessing ();
			    select2_measurement('r');
			    Random = MeasurementProcessing ();
			    select2_measurement('b');
			    Back_Ordered = MeasurementProcessing ();
				printf("Select2\t\t%f\t\t%f\t\t%f\n\n",  Ordered, Random, Back_Ordered);

			    select7_measurement ('o');
				Ordered = MeasurementProcessing ();
				select7_measurement ('r');
				Random = MeasurementProcessing ();
				select7_measurement ('b');
				Back_Ordered = MeasurementProcessing ();
				printf("Select7\t\t%f\t\t%f\t\t%f\n\n",  Ordered, Random, Back_Ordered);


			    exchange2_measurement ('o');
				Ordered = MeasurementProcessing ();
				exchange2_measurement ('r');
				Random = MeasurementProcessing ();
				exchange2_measurement ('b');
				Back_Ordered = MeasurementProcessing ();
				printf("Exchange2\t%f\t\t%f\t\t%f\n\n",  Ordered, Random, Back_Ordered);

				getch_one();
					break;
			case 5:
					flagch = '4';
					break;
			}// switch(sel1)
	}// while(flagch == 3)
}

void clrscr() 
{ 
	printf("\033[2J"); // очищення екрану 
	printf("\033[0;0f"); // встановлення курсору на [1;1]
}

void getch_one() {
	char ch = 'c';
    printf("\nInput 1 to continue...");
	while(ch != '1')
	{
	scanf("%c",&ch);
	}	
}
