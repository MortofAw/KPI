#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include<Windows.h>
#define BUFF 1000
#define StudCount 26 //Number of students in de group

void AverageScore(FILE* students, struct group* ses);
void WordInString(char c[BUFF], int pos, char* buff);
int error_open(FILE* students);
int error_close(FILE* students);
void copystr(char* source, char* destination);

struct group {
		char fname[10], lname[20], patr[15]; //прізвище,ім’я,по-батькові
		int prog, sda, matan, linal;
		double serbal; //marks
};

main() {
	setlocale(LC_CTYPE, "uk_UA.UTF-8"); //Ukr text at the console
	SetConsoleOutputCP(1251); //too

	struct group ses[StudCount+1];
	FILE* students = fopen("C:/KPI/FirstSmstr/OP/lab5/Students.txt", "r");//File at the path
	error_open(students);//checking opening

	AverageScore(students, ses);

	error_close(students);
}

void AverageScore(FILE* students,struct group* ses ) {
	char c[BUFF] = "";
	fgets(c, BUFF, students);  //Transposition '|' at the end of the first string
	char string[50];
	int index[StudCount];//Student's index with the worst av.sc
	double minbali[3], minbal = 0, serbal;

	for (int i = 0; i < StudCount; i++) {
		fgets(c, BUFF, students);//take a string

		WordInString(&c[0], 2, string);//take a last name
		copystr(string, ses[i].lname);//copy to stud's last name

		WordInString(&c[0], 5, string); //take marks from position
		ses[i].prog = atoi(string); //turn number symbol into num(char -> int) 

		WordInString(&c[0], 6, string);
		ses[i].sda = atoi(string);

		WordInString(&c[0], 7, string);
		ses[i].matan = atoi(string);

		WordInString(&c[0], 8, string);
		ses[i].linal = atoi(string);

		printf("%-20s\n  [%3d] [%3d] [%3d] [%3d]\n", ses[i].lname, ses[i].prog, ses[i].sda, ses[i].matan, ses[i].linal);//Show the students and marks
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < StudCount; j++) {
			ses[j].serbal = (ses[j].prog + ses[j].sda + ses[j].matan + ses[j].linal) / 4.0;// Average score of each student
			if (j == 0)minbal = ses[i].serbal; //if is the first el-t -> initialization of minbal
			else if (i == 1 && ses[j].serbal == minbali[i - 1]) continue; //If this av.sc. have been early 
			else if (i == 2 && (ses[j].serbal == minbali[i - 1] || ses[j].serbal == minbali[i - 2])) continue;//If this av.sc. have been early and early
			else if (minbal > ses[j].serbal) {
				minbal = ses[j].serbal;
			}
		}
		minbali[i] = minbal;
	}
	for (int i = 0,p=0; i < 3; i++) {
		for (int j = 0; j < StudCount; j++) {
			if (minbali[i] == ses[j].serbal) { index[p] = j; p++; }//Checking for the difference of de av.sc. and save index of them
		}
	}
	printf("\nStudents with the worst average score: \n\n");
	for (int i = 0; i < 3; i++)
		printf("%s's average score : \n[% 3.2f]\n", ses[index[i]].lname, ses[index[i]].serbal);
}
int error_open(FILE* students) {
	if (students == NULL) {
		printf("\nError while opening the file\n"); return 1;
	}
	printf("The file was successfully opened\n\n");
	return 0;
}

int error_close(FILE* students) {
	if (fclose(students)){ //Closed? Closed! _ If file close -> 0
		printf("Error while closing the file"); return 1;
	}
	printf("\nThe file was successfully closed\n\n");
	return 0;
}

void WordInString(char c[BUFF],int pos,char *buff) {//string,position,whereis to save the needed word
	int i = 1, nchar=0;
	for (; i <= pos;) { //Change position of needed word
		if (c[nchar] == ' ' || c[nchar] == '\t') { //Missed ' '
			nchar++;
			continue;
		}
		for (int j = 0; c[nchar] != ' ' && c[nchar] != '\t' && c[nchar] != '\n'; j++, nchar++) {//Copy even word to the buffer

				if (c[nchar + 1] == ' ' || c[nchar + 1] == '\t' || c[nchar + 1] == '\n') { //Writing a last symbol and unneeded end of string zeroing
					buff[j] = c[nchar];
					buff[++j] = '\0';
					nchar++;
					break;
				}
				else
					buff[j] = c[nchar]; //Writing an all character of word without the last one
		}
		i++;//Change position
	}
}

void copystr(char* from, char* to) {
	while (*from) {
		*to = *from;
		from++;
		to++;
	}
	*to= '\0'; //unneeded end of string zeroing
}