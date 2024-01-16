// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

/* Function declarations */
int max(int num1, int num2);
int min(int num1, int num2);

int solution(int N) {
    // write your code in C99 (gcc 6.2.0)
        // array to store binary number
    int binaryNum[32];
    int binaryNumR[32];
    int indices[32];
    int oldN = N;
 
    // counter for binary array
    int i = 0;
    int dumi = 0;
    int dumind = 0;
    int maxgap = 0;
    int curgap;
    int gapInd = 0;
    int gapIndOld = 0;


    while (N > 0) {
 
        // storing remainder in binary array
        binaryNum[i] = N % 2;
        N = N / 2;
        i++;
    }

    for (int j = i - 1; j >= 0; j-- ) {

        binaryNumR[dumi] = binaryNum[j];
        //printf("%d",binaryNumR[dumi]);

        if (binaryNumR[dumi] == 1){
            gapIndOld = gapInd;
            gapInd = dumi;
        }

        curgap = gapInd - gapIndOld;

        maxgap = max(curgap,maxgap);

        dumi++;
    }

    if (maxgap <= 0){
        return 0;
    }
    else {
        return maxgap-1;
    }
}

int max(int num1, int num2)
{
    return (num1 > num2 ) ? num1 : num2;
}

/**
 * Find minimum between two numbers.
 */
int min(int num1, int num2) 
{
    return (num1 > num2 ) ? num2 : num1;
}

