#include <stdio.h>
#include <math.h>
#include <string.h>

#define SIZE 512

// first block
void FirstBlock(FILE *f){
	printf("[First block]\n");
	
	int n;
	printf("Enter the number of elements:");
	scanf("%d",&n);

	if(n == 0)
	{
		printf("\nNone of elements is in sum!\n");
		return;
	}
	else if(n == 1)
		{
			printf("\nOnly one element and this one is -2.0!\n");
			return;
		}
	else if(n == 2)
		{
			printf("\nOnly two elements and there are -2.0 and -0.5!\n");
			return;
		}

	if((f=fopen("exp.dat","wb"))==NULL){
		printf("Error while opening the file\n");
		return;
	}

	float t1,t2,t3;
	float fact = 1.0;
	float sum = 0.0;
	
	for(int i=1;i<=n;i++){
		fact*=i;
		sum += pow(-1,i)*(i+1)/fact;
		printf("%f; ", sum);
		fwrite(&sum,sizeof(float),1,f);
	}
	fclose(f);
	
	printf("\n");
	
	int count=0;
	float curr;
	
	if((f=fopen("exp.dat","rb"))==NULL){
		printf("Error while opening the file\n");
		return;
	}

	while(1){
	if(count > 3 && fread(&curr,sizeof(curr),1,f)){ // c>3 for dont read t1 to pointer
		t1 = t2;
		t2 = t3;
		t3 = curr;
	}else if(count <= 3){//1if
		fread(&t1,sizeof(t1),1,f);
		fread(&t2,sizeof(t2),1,f);
		fread(&t3,sizeof(t3),1,f);
		count = 4;//for add(4) component of the file
	}else 
		break;
	}
	
	printf("Your third pos from the end - %f\n",t1);
	
	fclose(f);
}
// second block
void SecondBlock(FILE *f){
	printf("[Second block]\n");
	
	int n;
	printf("Enter the number of elements:");
	scanf("%d",&n);

	if((f=fopen("exp.dat","wb"))==NULL){
		printf("Error while opening the file\n");
		return;
	}

	for(int i=0;i<n;i++){
		printf("%d ",i);
		fwrite(&i, sizeof(i), 1, f);
	}
	printf("\n");
	fclose(f);

	int sum = 0;
	int ai,an;

	if((f=fopen("exp.dat","rb"))==NULL){
		printf("Error while opening the file\n");
		return;
	}

	for(int i=0;i<n;i++){
		fseek(f,i*sizeof(int),SEEK_SET);
		fread(&ai,sizeof(ai),1,f);
		printf("%d ai%d\n", ai, i);
		fseek(f,(-(i)*sizeof(int)-sizeof(int)),SEEK_END);
		fread(&an,sizeof(an),1,f);
		printf("%d an%d\n", an, i);
		sum+=ai*an;
	}

	printf("Your sum - %d\n",sum);
	
	fclose(f);
}
// third block
void ThirdBlock(FILE *f, FILE *g, char *S){

	printf("[Third block]\n");

	if((f=fopen("f.txt","r"))==NULL){
		printf("Error while opening the file f.txt\n");
		return;
	}
	
	printf("		Your f.txt:\n");

	char ch;
	while((ch = fgetc(f)) != EOF)
		putchar(ch);//вивід текста файлу f

	printf("\n");
	fclose(f);

	if((f=fopen("f.txt","r"))==NULL){
		printf("Error while opening the file f.txt\n");
		return;
	}

	if((g=fopen("g.txt","w"))==NULL){
		printf("Error while opening the file g.txt\n");
		return;
	}

	char buff[SIZE];

	while(fgets(buff, SIZE, f) != NULL){// якщо отриманий рядок не пустий
		if(strstr(buff,S)!=NULL){// пошук рядка S у буфері з рядком файла f
			fputs(buff, g);// запис рядка з буфера у файл f
		}
	}

	fclose(f);
	fclose(g);

	if((f=fopen("g.txt","r"))==NULL){
		printf("Error while opening the file g.txt\n");
		return;
	}
	
	printf("		Your g.txt:\n");

	while((ch = fgetc(g)) != EOF)
		putchar(ch);//вивід текста файлу f

	printf("\n");
	fclose(g);
}

int main(void){
	FILE *f;
	FILE *g;
	char S[SIZE];

	printf("\n");
	FirstBlock(f);
	
	printf("\n");
	SecondBlock(f);

	printf("\nInput S string for third block(No more 512 chars) --> ");
	scanf("%s",S);

	printf("\n");
	ThirdBlock(f,g,S);
	
	return 0;
}
