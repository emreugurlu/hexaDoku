#include<stdio.h>
#include<stdlib.h>
int main(int argc, char** argv) {
if (argc!=2) {
printf("No file found\n");
exit(0);
}
FILE *fp = fopen(argv[1],"r");
if (fp == NULL) {
printf("file does not exist\n");
exit(0);
}
char **matrix;
matrix = malloc(16*sizeof(int*));
for(int i = 0; i<16; i++){
matrix[i] = malloc(16* sizeof(int));
}
char s;
for (int i = 0; i<16; i++) {
	for(int j = 0; j<16; j++) {
	fscanf(fp,"%c\t",&s);
	matrix[i][j] = s;

	}
}
//char **matrix2;
//int *matrix3;
//int **matrixFINAL;
//char *matrixmiss;
char hexa[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

//matrixmiss = malloc(16*sizeof(int*));
/*matrixFINAL = malloc(16*sizeof(int*));
for(int i = 0; i<16; i++) {
matrixFINAL[i] = malloc(16* sizeof(int));
}*/


//matrix3 = malloc(256*sizeof(int*));

/*matrix2 = malloc(4*sizeof(int*));
for (int i = 0; i<4; i++) {
matrix2[i] = malloc(4* sizeof(int));
}*/



int n = 0;
int m = 0;
int h = 1;
int d = 0;
int u = 1;
int v = 0;
//int x = 0;
int o = 0;
int c = 0;
int go = 0;
char *matrixmiss;
char **matrix2;
while (n < 16) {

matrixmiss = malloc(16*sizeof(int*));
matrix2 = malloc(4*sizeof(int*));
for (int i = 0; i<4; i++) {
matrix2[i] = malloc(4* sizeof(int));
}

if (n%4 == 0 && n!=0 ) {
d = d+4;
u++;
h = 1;
m = 0;
v = v+4;
o = 0;//signifies row translation for matrix2 to the main matrix 16x16 NOW FIGURE OUT COLUMN TRANSFORMATION
c = c+4;//signifies COLUMN TRASNLATION
}
for (int i = d, a = 0; i<4*u;i++, a++) {
	for(int j = m, b = 0; j<4*h; j++,b++) {
matrix2[a][b]=matrix[i][j];
	}
}
go = 0;
int count = 0;
for (int i = 0; i<4; i++) {
	for (int j = 0; j<4; j++) {
	if (matrix2[i][j] == '-') {
	count++;
}	
	matrixmiss[go] = matrix2[i][j]; 
	go++;
	}	

}
if (count>0) {
char *missing;
int missingcounter = 0;
int evet = 0;
missing=malloc(count* sizeof(int*));
for(int i = 0; i<16; i++ ) {
evet = 0;
	for (int j = 0;j<16;j++) {
		if (hexa[i] == matrixmiss[j]) {
			evet=1;
			break;
		}
	}
if (evet == 0) {
missing[missingcounter] = hexa[i];
//		printf("%c\n",missing[missingcounter]);
		missingcounter++;
}
}
//free(matrixmiss);
//HERE FIND MISSING NUMBERS OF THE MATRIX2 IF THERE ARE ANY. DO IF STATEMENT BELOW IF THERE ARE ANY and depending on how many there are make a matrix of that size and then figure out the missing ones.
//
for(int i = 0; i<4; i++) {
	for (int j = 0; j<4; j++) {
	if (matrix2[i][j] == '-') {

		for(int q = 0; q<count; q++) {
	 int truther = 0;
			for(int x = 0; x<16; x++) {
				if (matrix[x][j+o] == missing[q]) {
					truther = 1;
					continue;
}
}
			if (truther == 0) {
			for (int x =0 ;x<16;x++) {
				if(matrix[i+c][x] ==missing[q]) {
				truther = 1;
				continue;
}
}
}
	if (truther == 0) {
	matrix[i+c][j+o] = missing[q];
	//matrix2[i][j] = missing[q];
}

}
//translate, add o to i and add c to j for matrix then compare all of the missing matrix to those in the big matrix and if 
//whatever position may be do for loop of main matrix checking each row and the constant column its at then do for loop checking each column and constant row and compare it all with matrix[i+o][j+c]
//VERY FIRST START FOR LOOP OF THE MISSING NUMBERS if theres no duplicate of it in the row checker the truth=1 continue to column checker if truth =1, if theres none at column checker then truth stays as 1, place it there if truth =1, else if truth doesnt equal 1 then go on to next missing number. in the end we will modify the main matrix.

}
}
}
for(int i = 0; i<4; i++){
free(matrix2[i]);
}
free(missing);
}

h++;

m = m + 4;
//EDIT MATRIX 2 HERE AND FIND THE - VALUES.
/*for(int k = 0; k<4; k++) {
	for(int l = 0; l<4; l++) {
	matrix3[x] = matrix2[k][l];
	//printf("%c\t",matrix2[k][l]);
	x++;
}

//printf("\n");
}*/
o = o+4;
n++;
}


//ANSWER IS COMPLETE JUST FIGURE OUT SOLVING 4x4 MATRIX!
/*n = 0;
x = 0;
h = 1;
u =1;
m = 0;
d = 0;*/
/*while (n<16) {
if (n%4==0 && n!=0) {
h = 1;
u++;
m = 0;
d = d+4;
}
for (int i = d; i<4*u; i++) {
	for(int j = m; j<4*h; j++) {
matrixFINAL[i][j] = matrix3[x];
x++;
}

}
h++;
m = m+4;
n++;
}*/
/*for (int i = 0; i<16; i++) {
	for(int j = 0; j<16; j++) {

printf("%c\t", matrixFINAL[i][j]);
}
printf("\n");
}*/
//printf("\n\n\n\n");
free(matrix2);
free(matrixmiss);
//int li = 0;
//check row then check column.
int yes = 0;
//check rows
for(int i = 0; i<16; i++) {
for(int j = 0; j<16; j++) {
for(int k = 0; k<16; k++) {
if(matrix[i][j] == matrix[i][k]){
yes++;
}

}
if(yes>1) {
for(int x = 0; x<16; x++) {
free(matrix[x]);
}
free(matrix);
printf("no-solution\n");
exit(0);


}
else {
yes = 0;
}
}
}

for(int i = 0; i<16; i++) {
for(int j = 0; j<16; j++) {
for(int k = 0; k<16; k++) {
if(matrix[j][i] == matrix[k][i]){
yes++;
}

}
if(yes>1) {
for(int x = 0; x<16; x++) {
free(matrix[x]);
}
free(matrix);
printf("no-solution\n");
exit(0);
}
else {
yes = 0;
}
}


}



for(int i = 0; i<16; i++) {
for (int j = 0; j<16; j++) {
if(matrix[i][j] == '-') {
for(int x = 0;x<16; x++) {
free(matrix[x]);
}
free(matrix);
printf("no-solution\n");
//return 0;
exit(0);
}
}
}
for(int i = 0; i<16; i++) {
	for(int j = 0; j<16; j++) {
		printf("%c\t",matrix[i][j]);

}
printf("\n");
}
for(int i = 0; i<16; i++) {
free(matrix[i]);
}
free(matrix);
return 0;
}
