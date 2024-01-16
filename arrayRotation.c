// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");
#include <string.h>

struct Results solution(int A[], int N, int K) {
    struct Results result;
    // write your code in C99 (gcc 6.2.0)
    int Aresult[100], Aresultold[N];
 //   printf("N is %d\n", N);

 //   for (int i = 0; i < N; i++){
 //       Aresult[i] = A[i];
  //      Aresultold[i] = Aresult[i];
 //       printf("%d \n", Aresultold[i]);
  //  }



    memcpy(Aresult, A, sizeof Aresult);
    memcpy(Aresultold, Aresult, sizeof Aresultold);

    for (int i = 0; i < K; i++) {
        for (int j = 0; j < N; j++){
            if (j == 0){
                Aresult[j] = Aresultold[N-1]; 
            }
            else {
                Aresult[j] = Aresultold[j-1];
            }
        }
        memcpy(Aresultold, Aresult, sizeof Aresultold);
//        for (int k = 0; k < N; k++){
 //       printf("Aresult trans is on %i iteration %d\n",i, Aresult[k]);
 //       Aresultold[k] = Aresult[k];
 //       A[k] = Aresult[k];
 //   }
    }



 //   memcpy(A, Aresult, sizeof A);

     for (int k = 0; k < N; k++){
         A[k] = Aresult[k]; 
     }

 //   memcpy(*result.A, Aresult, sizeof *result.A);
 //   result.A = Aresult;
    result.A = A;
    result.N = N;
    return result;
}
