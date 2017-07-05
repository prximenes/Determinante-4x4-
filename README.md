# Determinante-4x4-
Calculo de determinante para matrizes 4x4 usando OpenMP

caso teste: 5 0 1 1 -2 3 4 1 0 2 -1 1 1 1 1 1
saída: Determinante = -19; Ela possui inversa.


----------------------------------
Instalando OpenMP

http://tdm-gcc.tdragon.net/download


Na hora de instalar, selecionar a opção de baixar a biblioteca do openmp (é
um dos componentes do gcc). Apontar o Codeblocks pra usar ele, mudar em:

settings -> compiler -> toolchain executables
e em settings -> debugger -> default)

Acesse essas janelas e escreva:
(settings -> compiler -> other options): -fopenmp
(settings -> compiler -> linker settings -> other linker options): -fopenmp
----------------------------------
Para compilar no Linux
$ gcc [nome].c -fopenmp
$./a.out

Biblioteca
#include <omp.h>
