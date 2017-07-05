#include <stdio.h>
#include <omp.h>
int main ()
{
    int i, j, det, det5, det4, det3, det2, det1, det0;
    int m[4][4];
    //5 0 1 1 -2 3 4 1 0 2 -1 1 1 1 1 1

    printf("Digite os numeros da matriz: \n");

    for(i=0; i<4; i++){
             for(j=0; j<4; j++){

                      scanf("%d", &m[i][j]);

                      }
             }

    /* Imprimindo a Matriz Digitada*/

    printf("\nA matriz digitada foi:\n\n");

    for(i=0; i<4; i++){
             printf("\n");

             for(j=0; j<4; j++){

                      printf(" %d ", m[i][j]);

                      }
             }
     printf("\n\n");

    /*Fim da impressao da matriz*/

          /* Calculando o determinante de uma matriz 4x4 */
        #pragma omp parallel num_threads(6)

        #pragma omp sections
        {
            #pragma omp section
            {
                  det5 = (m[0][3] * m[1][2] * m[2][1] * m[3][0] - m[0][2] * m[1][3] * m[2][1] * m[3][0] -
                         m[0][3] * m[1][1] * m[2][2] * m[3][0] + m[0][1] * m[1][3] * m[2][2] * m[3][0]);
            }
            #pragma omp section
            {
                  det4 = (m[0][2] * m[1][1] * m[2][3] * m[3][0] - m[0][1] * m[1][2] * m[2][3] * m[3][0] -
                         m[0][3] * m[1][2] * m[2][0] * m[3][1] + m[0][2] * m[1][3] * m[2][0] * m[3][1]);
            }
            #pragma omp section
            {
                  det3 = (m[0][3] * m[1][0] * m[2][2] * m[3][1] - m[0][0] * m[1][3] * m[2][2] * m[3][1] -
                         m[0][2] * m[1][0] * m[2][3] * m[3][1] + m[0][0] * m[1][2] * m[2][3] * m[3][1]);
            }
            #pragma omp section
            {
                  det2 = (m[0][3] * m[1][1] * m[2][0] * m[3][2] - m[0][1] * m[1][3] * m[2][0] * m[3][2] -
                         m[0][3] * m[1][0] * m[2][1] * m[3][2] + m[0][0] * m[1][3] * m[2][1] * m[3][2]);
            }
            #pragma omp section
            {
                  det1 = (m[0][1] * m[1][0] * m[2][3] * m[3][2] - m[0][0] * m[1][1] * m[2][3] * m[3][2] -
                         m[0][2] * m[1][1] * m[2][0] * m[3][3] + m[0][1] * m[1][2] * m[2][0] * m[3][3]);
            }
            #pragma omp section
            {
                  det0 = (m[0][2] * m[1][0] * m[2][1] * m[3][3] - m[0][0] * m[1][2] * m[2][1] * m[3][3] -
                         m[0][1] * m[1][0] * m[2][2] * m[3][3] + m[0][0] * m[1][1] * m[2][2] * m[3][3]);
            }
        }

            #pragma omp barrier

          det = det4+det2+det5+det3+det1+det0;

          if(det == 0){
                      printf("Determinante = %d; Ela nao possui inversa.\n\n", det);
          }
          else
                      printf("Determinante = %d; Ela possui inversa.\n\n", det);

          //5 0 1 1 -2 3 4 1 0 2 -1 1 1 1 1 1


          /* Fim do calculo do det4 */
    return(0);

}
