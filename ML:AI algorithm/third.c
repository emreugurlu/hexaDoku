#include<stdio.h>
#include<stdlib.h>
int main(int argc, char** argv) {
if (argc!=3) {
printf("error\n");
exit(0);
}
FILE *fp = fopen(argv[1],"r");
if(fp == NULL) {
printf("error\n");
exit(0);
}
FILE *fp2 = fopen(argv[2],"r");

if(fp2 == NULL) {
printf("error\n");
exit(0);
}
double TESTER=0;
int COUNTER=0;
FILE *TEST = fopen(argv[2],"r");
while(fscanf(TEST,"%lf,",&TESTER)!=EOF) {
COUNTER++;

}
//fclose(TEST);
//COUNTER++;
COUNTER = COUNTER - 1;
//printf("%d\n",COUNTER);
int file2=0;
fscanf(fp2,"%d",&file2);
int file2COL = COUNTER/file2;
file2COL+=1;

double** file2matrix = malloc(file2*sizeof(double*));
for(int i = 0;i<file2;i++) {
file2matrix[i] = malloc(file2COL*sizeof(double));
}
double hi=0;
for(int i = 0; i<file2;i++) {
	for(int j = 0; j<file2COL;j++) {
if(j == 0) {
file2matrix[i][j] = 1;
}
else{
file2matrix[i][j] = 0;
}
}
}

for(int i = 0; i<file2;i++) {
	for(int j = 1; j<file2COL;j++){
fscanf(fp2,"%lf,",&hi);
file2matrix[i][j] = hi;
hi = 0;

}

}




int x=0;
int y=0;
fscanf(fp,"%d",&y);
fscanf(fp,"%d",&x);
y += 1;
//get x
//get y as well
double **matrixY;
double **matrixX;
matrixY = malloc(x*sizeof(double*));
matrixX= malloc(x*sizeof(double*));
//CREATING Y HERE
for (int i = 0; i<x; i++) {
matrixY[i] = malloc(1*sizeof(double));
}
for (int i = 0; i<x; i++) {
matrixX[i] = malloc(y*sizeof(double));
}
//int l = 0;
double s=0;
for (int i = 0; i<x; i++) {
	for (int j = 0; j<y; j++) {
if(j == 0) {

matrixX[i][j] = 1;

}
else{
matrixX[i][j] = 0;
}	//matrixX[i][j] = s;
}
}
int l = 0;
for(int i = 0; i<x; i++) {
	for(int j = 1; j<y; j++) {
fscanf(fp,"%lf,",&s);
matrixX[i][j] = s;
if (j == y-1) {
fscanf(fp,"%lf,",&s);
matrixY[l][0] = s;
l++;
}

}


}
/*
printf("THIS IS MATRIXX\n\n\n");
for(int i = 0; i<x; i++) {
for(int j = 0;j<y;j++) {
printf("%lf\t",matrixX[i][j]);
}
printf("\n");
}
printf("\n\n\n");
printf("THIS IS MATRIXY\n");
for(int i = 0;i<x;i++) {
printf("%lf\n",matrixY[i][0]);
}
printf("%d\n",y);
printf("%d\n",x);*/
//now transpose X.
s = 0;
double **matrixTranspose; 
matrixTranspose = malloc(y*sizeof(double*));
for(int i = 0; i<y; i++) {
matrixTranspose[i] = malloc(x*sizeof(double));
}
//now row length is column length and column length is row length.
for(int i = 0; i<y; i++) {
	for (int j = 0; j<x; j++) {
s = matrixX[j][i];
matrixTranspose[i][j] = s;
}
}
/*
printf("\n\n\n");
printf("THIS IS MATRIX TRANSPOSE\n");
for(int i = 0; i<y; i++) {
	for(int j = 0; j<x; j++) {
	printf("%lf\t",matrixTranspose[i][j]);
}
printf("\n");
}*/
//GOT THE TRANSPOSE, DONE
//NOW MULTIPLY X AND X TRANSPOSE WITH EACH OTHER.
double **matrixMultiply;
matrixMultiply = malloc(y*sizeof(double*));
for(int i = 0; i<y; i++) {
matrixMultiply[i] = malloc(y*sizeof(double));
}

//double f;
//double c;
// x= 10
// y = 4
s = 0;
for (int i = 0; i<y;i++) {
	for(int j = 0; j<y; j++) {
		s = 0;
		for (int p = 0; p<x; p++) {
		s += matrixTranspose[i][p] * matrixX[p][j];
		//matrixMultiply[i][j] = 0;
		matrixMultiply[i][j] = s;
}
//matrixMultiply[i][j] = s;
}
}
/*
printf("INCOMING X TIMES X TRANSPOSE\n");
for (int i = 0; i<y; i++) {
for(int j = 0; j<y; j++) {
printf("%lf\t",matrixMultiply[i][j]);
}
printf("\n");
}*/
//MULTIPLY X AND X TRANSPOSE DONE.
//FIND THE INVERSE NOW.

//double inverse=0;
double **identity;
identity = malloc(y*sizeof(double*));
for ( int i = 0; i<y; i++) {
identity[i] = malloc(y*sizeof(double));
}
for(int i = 0; i<y; i++) {
identity[i][i] = 1;
for(int j = 0; j<y; j++) {
if(identity[i][j]!=1) {
identity[i][j] = 0;
}
}
}
/*
for(int i = 0; i<y; i++) {
for(int j = 0; j<y; j++) {
printf("%lf\t",identity[i][j]);
}
printf("\n");
}*/
int carry5 = 0;
carry5 = 2*y;
double **augmented;
augmented = malloc(y*sizeof(double*));
for(int i = 0; i<y; i++) {
augmented[i] = malloc(carry5*sizeof(double));
}
for(int i = 0; i<y;i++) {
	for(int j = 0; j<y;j++) {
augmented[i][j] = matrixMultiply[i][j];
}
}
for (int i = 0;i<y;i++) {
for(int j=0;j<y;j++) {
if(i==j){
augmented[i][j+y] = 1;

}
else{
augmented[i][j+y] = 0;
}
}

}
/*
for(int i = 0; i<y;i++) {
for(int j = 0; j<2*y; j++) {
printf("%lf\t",augmented[i][j]);

}
printf("\n");
}*/

double xi = 0;
for(int i = 0; i<y; i++) {
for(int j=0;j<y;j++) {
if(i != j){
xi = augmented[j][i]/augmented[i][i];
for(int k = 0; k<2*y; k++) {
augmented[j][k] = augmented[j][k] - xi*augmented[i][k];

}
}
}

}
xi = 0;
double temp = 0;
for(int i = 0; i<y;i++) {
temp = augmented[i][i];
for(int j = 0;j<2*y; j++) {

augmented[i][j] = augmented[i][j]/temp;
} 

}
temp = 0;
/*

printf("\n\n\n");

for(int i = 0; i<y;i++) {
for(int j = 0; j<2*y; j++) {
printf("%lf\t",augmented[i][j]);

}
printf("\n");
}*/

int cat = 0;
for(int i = 0; i<y;i++) {
for(int j = y; j<y*2; j++) {
identity[i][cat] = augmented[i][j];
cat++;
}
cat = 0;
}/*
printf("\n\n\n");
printf("INCOMING INVERSE\n");
for(int i = 0; i<y; i++) {
for(int j = 0; j<y; j++) {
printf("%lf\t",identity[i][j]);
}
printf("\n");
}*/
//now multiply it with the transpose and then multiply with y.
/*for(int i = 0; i<y;i++) {
free(matrixMultiply[i]);
}
free(matrixMultiply);*/
double **matrixMultiply2;
matrixMultiply2 = malloc(y*sizeof(double*));
for(int i = 0; i<y; i++) {
matrixMultiply2[i] = malloc(x*sizeof(double));
}
s = 0;
for (int i = 0; i<y;i++) {
	for(int j = 0; j<x; j++) {
		s = 0;
		for (int p = 0; p<y; p++) {
		s += identity[i][p] * matrixTranspose[p][j];
		//matrixMultiply2[i][j] = 0;
		matrixMultiply2[i][j] = s;
}
//matrixMultiply[i][j] = s;
}
}
/*
printf("\n\n\n\n\n");
printf("INCOMING INVERSE TIMES TRANSPOSE");
printf("\n\n\n");
for(int i = 0; i<y;i++) {
	for(int j = 0; j<x;j++) {
printf("%lf\t",matrixMultiply[i][j]);
}
printf("\n");
}*/
s = 0;
double **W;
W=malloc(y*sizeof(double*));
for(int i = 0; i<y;i++) {
W[i] = malloc(1*sizeof(double));
}
s = 0;
for(int i = 0; i<y; i++) {
	for(int j = 0; j<1;j++) {
	s = 0;
		for(int p = 0; p<x; p++) {
s+= matrixMultiply2[i][p] * matrixY[p][j];
//W[i][j] = 0;
W[i][j] = s;
}
}

}
/*
printf("INCOMING W\n\n\n\n");
for(int i = 0; i<y; i++) {
printf("%lf\t",W[i][0]);
printf("\n");
}
printf("INCOMING X\n\n\n\n");
for(int i = 0; i<file2; i++) {
for(int j = 0; j<file2COL; j++) {
printf("%lf\t",file2matrix[i][j]);
}
printf("\n");
}*/
s = 0;
double **FINAL;
FINAL = malloc(file2*sizeof(double*));
for(int i = 0; i<file2;i++) {
FINAL[i] = malloc(1*sizeof(double));
}


for (int i = 0; i<file2;i++) {
	for(int j = 0; j<1; j++){
	s = 0;
		for(int k = 0; k<file2COL; k++) {
s+= file2matrix[i][k] * W[k][j];
//free(FINAL[i][j]);
FINAL[i][j] = s;
}
}
}
for(int i = 0; i<file2; i++) {
printf("%0.0lf\t",FINAL[i][0]);
printf("\n");

}

/*double **FINAL;
FINAL = malloc(file2*sizeof(double*));
for(int i = 0;i<file2; i++) {
FINAL[i] = malloc(1*sizeof(double));

}
//LETS = W[0][0];
//W[0][0] = 1;

for(int i = 0; i<file2;i++) {
printf("%0.0lf\t",FINAL[i][0]);
printf("\n");

}
*/
fclose(fp);
fclose(fp2);
fclose(TEST);

//A 3x3 TIMES A 3x1 gives A 3x1
//NOw i have a 4x10 * 10*1
//this should give me a 4x1
//now to get w we multiply with y

for(int i = 0; i<x; i++) {
for(int j = 0; j<y; j++) {
matrixX[i][j] = 0;


}
}




for(int i = 0;i<y; i++) {
for(int j = 0; j<y; j++) {
matrixMultiply[i][j] = 0;

}
}

COUNTER = 0;
file2COL = 0;


/*for(int i = 0; i<y; i++) {
for(int j = 0; j<x; j++) {
matrixTranspose[j][i] = 0;
}

}*/

for (int i = 0 ;i<x;i++) {
free(matrixX[i]);
free(matrixY[i]);
}
free(matrixY);
free(matrixX);
for(int i =0; i<file2;i++) {
free(file2matrix[i]);
free(FINAL[i]);
}
free(FINAL);
free(file2matrix);
for(int i = 0; i<y;i++) {
free(matrixTranspose[i]);
free(matrixMultiply[i]);
free(augmented[i]);
free(identity[i]);
free(matrixMultiply2[i]);
}
free(identity);
free(augmented);
free(matrixMultiply);
free(matrixTranspose);
free(matrixMultiply2);
//4x4 * a 4x10 it becomes a 4x10
// 4 ROWS 10 COLUMNS 



/*
for(int i = 0; i<y; i++) {
if(matrixMultiply[i][i]!=1) {
for(int h = 0; h<y; h++) {
matrixMultiply[i][h] = matrixMultiply[i][h]/matrixMultiply[i][i];
identity[i][h] = identity[i][h]/matrixMultiply[i][i]; 
}
if(matrixMultiply[i][i]==-1) {
for(int h = 0; h<y; h++) {
matrixMultiply[i][h] = -1 * matrixMultiply[i][h];
identity[i][h] = -1 * identity[i][h];
}
/	
}
for(int j = 0; j<y; j++) {
if(j != i) {
if(matrixMultiply[j][i]!= 0) {
inverse = matrixMultiply[j][i];
for(int n = 0; n<y; n++) {
xi = inverse*matrixMultiply[i][n];
yi = inverse*identity[i][n];
matrixMultiply[j][n] = matrixMultiply[j][n]- xi ;
identity[j][n] = identity[j][n] - yi;

}


}

}

}
}
*/



return 0;
}
