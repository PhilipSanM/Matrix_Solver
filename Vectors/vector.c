/*      =======================================================================
        ===================INSTITUTO POLITECNICO NACIONAL======================
        =======================================================================
                            =============================
                            =ESCUELA SUPERIOR DE COMPUTO=
                            =============================
>>Name: Sánchez Martánez Felipe
>>Gruop: 2BM1
>>Carrer: Ing en Inteligencia Artificial
>>date of last modification: 03/01/22
                   
Lienar Algebra
This program will play with the vectors and the Vector space
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include<time.h> 
#include <stdbool.h>
#define TAM 30

typedef struct{
    float matrix[TAM][TAM];
}Matrix;
//R is the number of rows   R=n
//VecorNumber will be the number of columns vectorsNumber=unknown
int i,j,k,R,vectorsNumber;
bool flag;
bool flagTGmain;
bool flagTG;
bool flagLI;
float data[90];
float dataInf[90];

void LinearCombination(Matrix* matrix);
void TermGenerato(Matrix* matrix);
void LinearIndependence(Matrix* matrix);
void Basis(Matrix* matrix);

//Fro GaussJordan Program
void MatrixStarting(Matrix* matrix, int Tam);
void OperacionGauss(Matrix* matrix, int n, Matrix* matrixEqua, int vectorsNumber);
void MatrixPrinting(Matrix* matrix, int rows, int columns);
void MatrixSolutionLC(Matrix* matrix, int n,int unknown);
void MatrixSolutionTG(Matrix* matrix, int n,int unknown, Matrix* matrixEqua);

void main(int argc, char const *argv[]){
    int option;
    Matrix matrix;
    /* code */
    puts("\n\n\n=============================================");
    puts("============ V E C T O R 'I N A T O R =======");
    puts("=============================================\n\n\n");
    do{
        MatrixStarting(&matrix,TAM);
        flag=FALSE;
        flagTGmain=FALSE;
        flagTG=FALSE;
        flagLI=FALSE;
        puts("What do U wanna do?");
        puts("1.- Play with Linear Combinations.");
        puts("2.- Play with the Term Generator.");
        puts("3.- Play with the Linear Independence.");
        puts("4.- Play with Basis.");
        puts("5.- Close the program.");
        fflush(stdin);
        scanf("%d",&option);
        switch(option){
            case 1:
                
                LinearCombination(&matrix);
                break;
            case 2:

                TermGenerato(&matrix);
                break;
            case 3:
                LinearIndependence(&matrix);
                break;
            case 4:
                Basis(&matrix);
                break;
            case 5:
                puts("Have a nice day :)");
                exit(0);
                break;
            default:
                puts("Pls select a correct option");
                printf("\n\n\n");
                break;

        }

    }while (true);
    
}

void LinearCombination(Matrix* matrix){
    Matrix matrixEqua;
    int aux,h=0,dataAux;
    puts("\n\n\n=============================================");
    puts("============ LINEAR COMBINATION =======");
    puts("=============================================\n\n\n");
    puts("Insert the dimension of R:");
    fflush(stdin);
    scanf("%d",&R);
    printf("\n\n");
    dataAux=R;
    puts("Insert the number of Vectors:");
    fflush(stdin);
    scanf("%d",&vectorsNumber);
    printf("\n\n");
    k=0;
    puts("**LET'S  START**");
    puts("-Insert the space of U");    
    for(i=0; i<R; i++){
        printf("Insert the data for the number #%d\n",i+1);
        fflush(stdin);
        scanf("%f",&matrix->matrix[i][vectorsNumber]);
        data[k]=matrix->matrix[i][vectorsNumber];
        k++;
    }
    puts("-Insert the Vectors");    
    for(i=0; i<vectorsNumber; i++){
        printf("\nFor the vector # %d: \n",i+1);
        for(j=0; j<R; j++){
            printf("Insert the data of the number #%d\n",j+1);
            fflush(stdin);
            scanf("%f",&matrix->matrix[j][i]);
            data[k]=matrix->matrix[j][i];
            k++;
        }
    }

    if(R==vectorsNumber){
        OperacionGauss(matrix, R, &matrixEqua, vectorsNumber);
        MatrixSolutionLC(matrix,R,vectorsNumber);

        if(flag){
            //GG
        }else{
            printf("(");
            for(i=0; i<R;i++){
                printf("%0.2f",data[i]);
                if(i<R-1)
                    printf(",");
            }
            printf(")=");
            for(i=0; i<R;i++){
                printf("+%f(",matrix->matrix[i][vectorsNumber]);
                h=0;
                for(aux=0;aux<R;aux++){
                    printf("%0.2f",data[dataAux]);
                    dataAux++;
                    h++;
                    if(h<R){
                        printf(",");
                    
                    }else{
                        break;
                    }

                }
                printf(")");

            }
            printf("\n\n");

        }
    }else{
        puts("THAT'S NOT A LINEAR COMBINATION OF U");
        puts("So, it doesn't belong to U");
    }
    // MatrixPrinting(matrix, R, vectorsNumber);
    // OperacionGauss(matrix, R);
    // MatrixPrinting(matrix, R, vectorsNumber);

}

void TermGenerato(Matrix* matrix){
    Matrix matrixEqua;
    int aux,h=0,dataAux;
    puts("\n\n\n=============================================");
    puts("============ TERM GENERATOR =======");
    puts("=============================================\n\n\n");
    puts("Insert the dimension of R:");
    fflush(stdin);
    scanf("%d",&R);
    printf("\n\n");
    dataAux=R;
    puts("Insert the number of Vectors:");
    fflush(stdin);
    scanf("%d",&vectorsNumber);
    printf("\n\n");
    k=0;
    //Init of the new Matrix
    for(i=0; i<=TAM-1; i++){
        for(j=0; j<=TAM; j++)
        {
            matrix.matrixEqua[i][j]=1;
        }
    }

    puts("**LET'S  START**");
    //The last Column  
    for(i=0; i<R; i++){
        matrix->matrix[i][vectorsNumber]=1;
    }
    puts("-Insert the Vectors");    
    for(i=0; i<vectorsNumber; i++){
        printf("\nFor the vector # %d: \n",i+1);
        for(j=0; j<R; j++){
            printf("Insert the data of the number #%d\n",j+1);
            fflush(stdin);
            scanf("%f",&matrix->matrix[j][i]);
            data[k]=matrix->matrix[j][i];
            k++;
        }
    }

    OperacionGauss(matrix, R, &matrixEqua);
    MatrixSolutionTG(matrix,R,vectorsNumber, &matrixEqua);
    if(R>vectorsNumber){
        puts("THAT'S NOT A SET GENERATOR");

        if(flagTGmain){
            //GG
        }else{
            printf("THAT'S A SET GENERATOR");

        }


    }else{
        
    }
    // MatrixPrinting(matrix, R, vectorsNumber);
    // OperacionGauss(matrix, R);
    // MatrixPrinting(matrix, R, vectorsNumber);

}
void LinearIndependence(Matrix* matrix){

}
void Basis(Matrix* matrix){

}



void OperacionGauss(Matrix* matrix, int n, Matrix* matrixEqua, int vectorsNumber){
    Matrix constante;
    for(j=0;j<n;j++){
        for(i=0; i<n; i++){
            if(i!=j)
            {
                // if(matrix->matrix[j][j]==0)
                //     constante.matrix[0][0]=0;
                // else
                    constante.matrix[0][0]=matrix->matrix[i][j]/matrix->matrix[j][j];
                for(k=0; k<=vectorsNumber; k++)
                {
                    matrix->matrix[i][k]=matrix->matrix[i][k]-constante.matrix[0][0]*matrix->matrix[j][k];

                }
                matrixEqua->matrix[i][]=matrix->matrix[i][k];

            }
        }
    }

}


void MatrixPrinting(Matrix* matrix, int rows, int columns){
    for(i=0;i<=rows-1;i++){
        printf("\n");
        for(j=0; j<columns;j++){
//            printf("Matriz[%d][%d]=\t%f\n",i,j,matrix->matrix[i][j]);
            printf("%fx%d\t",matrix->matrix[i][j],j+1);
            if(j==columns-1){
                printf("= %f",matrix->matrix[i][columns]);
            }
        }

    }
//     printf("\n\n\n\n");
//     for(i=0;i<=n-1;i++){
//         printf("\n");
//         for(j=0; j<n;j++){
// //            printf("Matriz[%d][%d]=\t%f\n",i,j,matrix->matrix[i][j]);
//             printf("%fx%d\t",matrix->matrix[i][j],j+1);
//         }
//         printf("= %f\t",matrix->matrix[i][n]);
//     }
}

    
void MatrixStarting(Matrix* matrix, int Tam){
    for(i=0; i<=Tam-1; i++)
    {
        for(j=0; j<=Tam; j++)
        {
            matrix->matrix[i][j]=0;
        }
    }
}

void MatrixSolutionLC(Matrix* matrix, int n, int unknown){
    float sum,sumA;
    Matrix matrixConstant;
    int parameters=0,values=0,r=0,l;
    //Por rows
    for(i=0;i<n;i++){
        sum=0;
        for(k=0; k<n;k++){
            sum=abs(sum)+matrix->matrix[i][k];
            sumA=sumA+matrix->matrix[i][k];

        }
        if(sum==0 && sumA==0){
            //There is no solution to the matrix
            flag=true;
        }
    }

    if(flag){
        puts("THAT'S NOT A LINEAR COMBINATION OF U");
        puts("So, it doesn't belong to U");
    }else{
        printf("\n\n");
        puts("THAT'S A LINEAR COMBINATION OF U");
        puts("So, it belong to U");
        printf("\n");
        for(i=0;i<n;i++){ 
   
            matrixConstant.matrix[0][0]=matrix->matrix[i][i];
            matrix->matrix[i][i]=matrix->matrix[i][i]/matrixConstant.matrix[0][0];
            matrix->matrix[i][n]=matrix->matrix[i][n]/matrixConstant.matrix[0][0];
        }
    }

}



void MatrixSolutionTG(Matrix* matrix, int n, int unknown, Matrix* matrixEqua){
    float sum,sumA;
    int parameters=0,values=0,r=0,l;

    //Por rows

    for(i=0;i<n;i++){
        sum=0;
        for(k=0; k<unknown;k++){
            sum=abs(sum)+matrix->matrix[i][k];
            sumA=sumA+matrix->matrix[i][k];
        }
        if(sum==0 && sumA==0 && matrix->matrix[i][unknown]!=0){
            //There is no solution to the matrix
            flagTGmain=true;
        }
    }

    for(i=0;i<n;i++){
            sum=0;
            for(k=0; k<=unknown;k++){
                sum=abs(sum)+matrix->matrix[i][k];
        }
        if(sum==0){
            parameters++;
                
        }
    }

    if(flag){
        puts("THAT'S NOT A SET GENERATOR");
        
    }else{
        printf("\n\n");
        puts("THAT'S A SET GENERATOR");
        if(parameters==0){
            //Unic Solution

        }else{
            //Inf solutions


        }


        printf("\n");
    }

}


//             mm    mm                      
//    *@@@@* *@@@    @@                      
//      @@     @@                            
//      @@     @@  *@@@  *@@@@@@@@m   mm@*@@ 
//      @@     !@    @@    @@   *@@  m@*   @@
//      @@     !@    !@    !@    @@  !@******
// @@!  @@     !@    !@    !@    !@  !@m    m
//      !!     !!    !!    !@!   !!  !!******
// !!!  !!     :!    !!    !@   !!!  :!!     
//  :!: :    : : : : : :   :!: : :    : : :: 
//                         ::                
//                       : : ::              
