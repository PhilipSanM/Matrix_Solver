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
int i,j,k,w,R,l,vectorsNumber;
bool flag;
bool flagTGmain;
bool flagTG;
bool flagLI;

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
        flag=false;
        flagTGmain=false;
        flagTG=false;
        flagLI=false;
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
    float data[90];
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
    float data[90];
    Matrix matrixEqua;
    Matrix matrixConstant;
    float sum,sumA;
    int parameters=0,auxRows=0, unknown=0, cursorUnknon=0, auxUnknown=0;
    int aux=0,h=0,dataAux;
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
    k=R;
    //Init of the new Matrix
    for(i=0; i<=TAM-1; i++){
        for(j=0; j<=TAM; j++)
        {
            if(j==i){
                matrixEqua.matrix[i][j]=1;
            }else{
                matrixEqua.matrix[i][j]=0;
            }
        }
    }

    puts("**LET'S  START**");
    //The last Column  
    //Init of that
    for(i=0; i<R; i++){
        matrix->matrix[i][vectorsNumber]=1;
    }
    for(i=0;i<TAM;i++){

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


    if(R>vectorsNumber){
        puts("THAT'S NOT A SET GENERATOR");
        puts("(Because the matrix has not solutions)");
    }else if(R==vectorsNumber){
        OperacionGauss(matrix, R, &matrixEqua, vectorsNumber);
        MatrixSolutionTG(matrix,R,vectorsNumber, &matrixEqua);
        // MatrixPrinting(matrix, R, vectorsNumber);

        for(i=0;i<R;i++){
            sumA=0;
            sum=0;
            for(k=0; k<vectorsNumber;k++){
                sum=abs(sum)+matrix->matrix[i][k];
                sumA=sumA+matrix->matrix[i][k];
            }
            if(sum==0 && sumA==0){
                parameters++;
                // puts("SUma de parameters");
            }   
        }

        if(flagTGmain){
            puts("THAT'S NOT A SET GENERATOR");
            puts("Because the matrix hasnot solutions");
        
        }else{
            printf("\n\n");
            puts("THAT'S A SET GENERATOR");
            if(parameters==0){
                //Unic Solution
                // for(i=0;i<R;i++){ 
                // matrixConstant.matrix[0][0]=matrix->matrix[i][i];
                // matrix->matrix[i][i]=matrix->matrix[i][i]/matrixConstant.matrix[0][0];
                // matrix->matrix[i][R]=matrix->matrix[i][R]/matrixConstant.matrix[0][0];
                // }
                //Printing the solutions
                printf("(");
                for(i=0; i<R;i++){
                    printf("X%d",i+1);
                    if(i<R-1)
                        printf(",");
                }
                printf(")=");
                for(i=0; i<R;i++){
                    printf("+(");
                    for(w=0;w<R;w++){
                        matrixEqua.matrix[auxRows][w]=matrixEqua.matrix[auxRows][w]/matrix->matrix[i][i];
                        printf("+%fY%d",matrixEqua.matrix[auxRows][w],w+1);
                    }
                    printf(")");
                    auxRows++;
                    printf("(");
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
    
            }else{
            //Inf solutions
                // puts("It has infninity solutions So:");
            }



        }
    }else if(vectorsNumber>R){



        //Infinity solutions
        unknown=vectorsNumber-R;
        printf("XXXDDDD incognitas = %d",unknown);

        puts("It has infninity solutions So:");
        OperacionGauss(matrix, R, &matrixEqua, vectorsNumber);
        MatrixSolutionTG(matrix,R,vectorsNumber, &matrixEqua);
        MatrixPrinting(matrix, R, vectorsNumber);



        printf("\n(");
        for(i=0; i<R;i++){
            printf("X%d",i+1);
            if(i<R-1)
                printf(",");
        }

        printf(")=");
        for(i=0; i<R;i++){
            auxUnknown=vectorsNumber-1;


//AQUI VOY
            printf("+(");
            for(w=0;w<R;w++){
                matrixEqua.matrix[auxRows][w]=matrixEqua.matrix[auxRows][w]/matrix->matrix[i][i];
                printf("+%fY%d",matrixEqua.matrix[auxRows][w],w+1);
            }


            //PRINTING PARAMETERS
            
            // puts("IMPRESION PARAMETORS");
            // printf("++++%d++++",vectorsNumber);
            matrixConstant.matrix[0][0]=matrix->matrix[i][i];
            
            for(l=0;l<=vectorsNumber;l++){
                matrix->matrix[i][l]=matrix->matrix[i][l]/matrixConstant.matrix[0][0];
            } 

            // printf("\n\n\n");
            MatrixPrinting(matrix, R, vectorsNumber);



//PARAMS

            cursorUnknon=unknown-1;
            printf("+++valor del cursror: %d",cursorUnknon);
            for(w=0;w<unknown;w++){
                printf("+%fP%d",matrix->matrix[i][cursorUnknon],w+1);
                printf("Valor de w=%d\n",w);
                cursorUnknon++;
            }




            printf(")");
            auxRows++;
            printf("(");
            h=0;
            for(aux=0;aux<vectorsNumber;aux++){

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
    int aux=0,a;
    int rowEqu=0, columnEqu=0;
    int auxCount=0;
    w=0;
    for(j=0;j<n;j++){
        auxCount++;
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
                k=k-1;
                //For TermGenerator


                if(w==n){
                    w=0;
                }
                if(w==i-1){
                    w++;
                }

                for(a=0;a<=auxCount;a++){
                    matrixEqua->matrix[w][a]=matrixEqua->matrix[w][a]-constante.matrix[0][0]*matrixEqua->matrix[j][a];

                }

                //Switch Case to make the x,y,z values, that's manual and suck :(
                // switch(j){
                //     case 0:
                //         matrixEqua->matrix[w][0]=matrixEqua->matrix[w][0]-constante.matrix[0][0]*matrixEqua->matrix[j][0];

                //         break;
                //     case 1:
                //         matrixEqua->matrix[w][0]=matrixEqua->matrix[w][0]-constante.matrix[0][0]*matrixEqua->matrix[j][0];
                //         matrixEqua->matrix[w][1]=matrixEqua->matrix[w][1]-constante.matrix[0][0]*matrixEqua->matrix[j][1];

                //         break;
                //     case 2:
                //         matrixEqua->matrix[w][0]=matrixEqua->matrix[w][0]-constante.matrix[0][0]*matrixEqua->matrix[j][0];
                //         matrixEqua->matrix[w][1]=matrixEqua->matrix[w][1]-constante.matrix[0][0]*matrixEqua->matrix[j][1];
                //         matrixEqua->matrix[w][2]=matrixEqua->matrix[w][2]-constante.matrix[0][0]*matrixEqua->matrix[j][2];

                //         break;
                //     case 3:
                //         matrixEqua->matrix[w][0]=matrixEqua->matrix[w][0]-constante.matrix[0][0]*matrixEqua->matrix[j][0];
                //         matrixEqua->matrix[w][1]=matrixEqua->matrix[w][1]-constante.matrix[0][0]*matrixEqua->matrix[j][1];
                //         matrixEqua->matrix[w][2]=matrixEqua->matrix[w][2]-constante.matrix[0][0]*matrixEqua->matrix[j][2];
                //         matrixEqua->matrix[w][3]=matrixEqua->matrix[w][3]-constante.matrix[0][0]*matrixEqua->matrix[j][3];

                //         break;
                //     case 4:
                //         matrixEqua->matrix[w][0]=matrixEqua->matrix[w][0]-constante.matrix[0][0]*matrixEqua->matrix[j][0];
                //         matrixEqua->matrix[w][1]=matrixEqua->matrix[w][1]-constante.matrix[0][0]*matrixEqua->matrix[j][1];
                //         matrixEqua->matrix[w][2]=matrixEqua->matrix[w][2]-constante.matrix[0][0]*matrixEqua->matrix[j][2];
                //         matrixEqua->matrix[w][3]=matrixEqua->matrix[w][3]-constante.matrix[0][0]*matrixEqua->matrix[j][3];
                //         matrixEqua->matrix[w][4]=matrixEqua->matrix[w][4]-constante.matrix[0][0]*matrixEqua->matrix[j][4];

                //         break;
                //     case 5:
                //         matrixEqua->matrix[w][0]=matrixEqua->matrix[w][0]-constante.matrix[0][0]*matrixEqua->matrix[j][0];
                //         matrixEqua->matrix[w][1]=matrixEqua->matrix[w][1]-constante.matrix[0][0]*matrixEqua->matrix[j][1];
                //         matrixEqua->matrix[w][2]=matrixEqua->matrix[w][2]-constante.matrix[0][0]*matrixEqua->matrix[j][2];
                //         matrixEqua->matrix[w][3]=matrixEqua->matrix[w][3]-constante.matrix[0][0]*matrixEqua->matrix[j][3];
                //         matrixEqua->matrix[w][4]=matrixEqua->matrix[w][4]-constante.matrix[0][0]*matrixEqua->matrix[j][4];
                //         matrixEqua->matrix[w][5]=matrixEqua->matrix[w][5]-constante.matrix[0][0]*matrixEqua->matrix[j][5];

                //         break;
                //     case 6:
                //         matrixEqua->matrix[w][0]=matrixEqua->matrix[w][0]-constante.matrix[0][0]*matrixEqua->matrix[j][0];
                //         matrixEqua->matrix[w][1]=matrixEqua->matrix[w][1]-constante.matrix[0][0]*matrixEqua->matrix[j][1];
                //         matrixEqua->matrix[w][2]=matrixEqua->matrix[w][2]-constante.matrix[0][0]*matrixEqua->matrix[j][2];
                //         matrixEqua->matrix[w][3]=matrixEqua->matrix[w][3]-constante.matrix[0][0]*matrixEqua->matrix[j][3];
                //         matrixEqua->matrix[w][4]=matrixEqua->matrix[w][4]-constante.matrix[0][0]*matrixEqua->matrix[j][4];
                //         matrixEqua->matrix[w][5]=matrixEqua->matrix[w][5]-constante.matrix[0][0]*matrixEqua->matrix[j][5];
                //         matrixEqua->matrix[w][6]=matrixEqua->matrix[w][6]-constante.matrix[0][0]*matrixEqua->matrix[j][6];

                //         break;
                //     case 7:
                //         matrixEqua->matrix[w][0]=matrixEqua->matrix[w][0]-constante.matrix[0][0]*matrixEqua->matrix[j][0];
                //         matrixEqua->matrix[w][1]=matrixEqua->matrix[w][1]-constante.matrix[0][0]*matrixEqua->matrix[j][1];
                //         matrixEqua->matrix[w][2]=matrixEqua->matrix[w][2]-constante.matrix[0][0]*matrixEqua->matrix[j][2];
                //         matrixEqua->matrix[w][3]=matrixEqua->matrix[w][3]-constante.matrix[0][0]*matrixEqua->matrix[j][3];
                //         matrixEqua->matrix[w][4]=matrixEqua->matrix[w][4]-constante.matrix[0][0]*matrixEqua->matrix[j][4];
                //         matrixEqua->matrix[w][5]=matrixEqua->matrix[w][5]-constante.matrix[0][0]*matrixEqua->matrix[j][5];
                //         matrixEqua->matrix[w][6]=matrixEqua->matrix[w][6]-constante.matrix[0][0]*matrixEqua->matrix[j][6];
                //         matrixEqua->matrix[w][7]=matrixEqua->matrix[w][7]-constante.matrix[0][0]*matrixEqua->matrix[j][7];

                //         break;
                //     case 8:
                //         matrixEqua->matrix[w][0]=matrixEqua->matrix[w][0]-constante.matrix[0][0]*matrixEqua->matrix[j][0];
                //         matrixEqua->matrix[w][1]=matrixEqua->matrix[w][1]-constante.matrix[0][0]*matrixEqua->matrix[j][1];
                //         matrixEqua->matrix[w][2]=matrixEqua->matrix[w][2]-constante.matrix[0][0]*matrixEqua->matrix[j][2];
                //         matrixEqua->matrix[w][3]=matrixEqua->matrix[w][3]-constante.matrix[0][0]*matrixEqua->matrix[j][3];
                //         matrixEqua->matrix[w][4]=matrixEqua->matrix[w][4]-constante.matrix[0][0]*matrixEqua->matrix[j][4];
                //         matrixEqua->matrix[w][5]=matrixEqua->matrix[w][5]-constante.matrix[0][0]*matrixEqua->matrix[j][5];
                //         matrixEqua->matrix[w][6]=matrixEqua->matrix[w][6]-constante.matrix[0][0]*matrixEqua->matrix[j][6];
                //         matrixEqua->matrix[w][7]=matrixEqua->matrix[w][7]-constante.matrix[0][0]*matrixEqua->matrix[j][7];
                //         matrixEqua->matrix[w][8]=matrixEqua->matrix[w][8]-constante.matrix[0][0]*matrixEqua->matrix[j][8];

                //         break;
                //     case 9:
                //         matrixEqua->matrix[w][0]=matrixEqua->matrix[w][0]-constante.matrix[0][0]*matrixEqua->matrix[j][0];
                //         matrixEqua->matrix[w][1]=matrixEqua->matrix[w][1]-constante.matrix[0][0]*matrixEqua->matrix[j][1];
                //         matrixEqua->matrix[w][2]=matrixEqua->matrix[w][2]-constante.matrix[0][0]*matrixEqua->matrix[j][2];
                //         matrixEqua->matrix[w][3]=matrixEqua->matrix[w][3]-constante.matrix[0][0]*matrixEqua->matrix[j][3];
                //         matrixEqua->matrix[w][4]=matrixEqua->matrix[w][4]-constante.matrix[0][0]*matrixEqua->matrix[j][4];
                //         matrixEqua->matrix[w][5]=matrixEqua->matrix[w][5]-constante.matrix[0][0]*matrixEqua->matrix[j][5];
                //         matrixEqua->matrix[w][6]=matrixEqua->matrix[w][6]-constante.matrix[0][0]*matrixEqua->matrix[j][6];
                //         matrixEqua->matrix[w][7]=matrixEqua->matrix[w][7]-constante.matrix[0][0]*matrixEqua->matrix[j][7];
                //         matrixEqua->matrix[w][8]=matrixEqua->matrix[w][8]-constante.matrix[0][0]*matrixEqua->matrix[j][8];
                //         matrixEqua->matrix[w][9]=matrixEqua->matrix[w][9]-constante.matrix[0][0]*matrixEqua->matrix[j][9];
                        
                //         break;
                //     case 10:
                //         matrixEqua->matrix[w][0]=matrixEqua->matrix[w][0]-constante.matrix[0][0]*matrixEqua->matrix[j][0];
                //         matrixEqua->matrix[w][1]=matrixEqua->matrix[w][1]-constante.matrix[0][0]*matrixEqua->matrix[j][1];
                //         matrixEqua->matrix[w][2]=matrixEqua->matrix[w][2]-constante.matrix[0][0]*matrixEqua->matrix[j][2];
                //         matrixEqua->matrix[w][3]=matrixEqua->matrix[w][3]-constante.matrix[0][0]*matrixEqua->matrix[j][3];
                //         matrixEqua->matrix[w][4]=matrixEqua->matrix[w][4]-constante.matrix[0][0]*matrixEqua->matrix[j][4];
                //         matrixEqua->matrix[w][5]=matrixEqua->matrix[w][5]-constante.matrix[0][0]*matrixEqua->matrix[j][5];
                //         matrixEqua->matrix[w][6]=matrixEqua->matrix[w][6]-constante.matrix[0][0]*matrixEqua->matrix[j][6];
                //         matrixEqua->matrix[w][7]=matrixEqua->matrix[w][7]-constante.matrix[0][0]*matrixEqua->matrix[j][7];
                //         matrixEqua->matrix[w][8]=matrixEqua->matrix[w][8]-constante.matrix[0][0]*matrixEqua->matrix[j][8];
                //         matrixEqua->matrix[w][9]=matrixEqua->matrix[w][9]-constante.matrix[0][0]*matrixEqua->matrix[j][9];
                //         matrixEqua->matrix[w][10]=matrixEqua->matrix[w][10]-constante.matrix[0][0]*matrixEqua->matrix[j][10];
                //         break;
                //     default:
                //         puts("ERROR x,y,z");
                //         break;

                // }
                w++;


                // // printf("Valor en gauss  %f de la i %d y la k %d\n",matrix->matrix[i][k],i,k);
                // matrixEqua->matrix[w][]=matrix->matrix[i][k]*matrixEqua->matrix[][w];
                // // printf("Posicion0 %dtiene a  %f\n",w,matrixEqua->matrix[0][w]);
                // w++;

            }else{
                w++;
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
    float dataAux[90];
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
