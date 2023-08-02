#include <stdio.h>
#include <math.h>
#include <string.h>
#include <string.h>
#include <stdlib.h>

#define  MAX_TERMS  20
#define MAX_STR  200

void toEgyptian(int numerator, int den, char e[], char *terms[]);

void getIthElement(char e[], char *terms[], int i, char out[]);


int main() {
    int numerator = 876;
    int den = 998;
    char e[MAX_STR];
    e[0] = '\0';
    char *terms[MAX_TERMS];
    for (int i = 0; i < MAX_TERMS; i++) {
        terms[i] = NULL;
    }
    toEgyptian(numerator, den, e, terms);
    printf("%s \n", e);
    for (int i = 0; i < MAX_TERMS && terms[i] != NULL; ++i) {
        printf("%p\n", terms[i]);

    }
    char out[MAX_STR];
    out[0] = '\0';
    getIthElement(e, terms, 4, out);
    printf("%s \n", out);

    return 0;
}

// The method accepts  the numerator and denominator of a fraction.
// The method places in string 'e' the representation of the fraction as an Egyptian fraction.
// In addition, the method receives an array of pointers and in each cell in the array places the address
// of the beginning of one of the elements of the fraction.
void toEgyptian(int numerator, int den, char e[], char *terms[]) {
    int i;

    int yDx, yMODx;
    // Calculates the upper value of a fraction.
    if (den % numerator == 0) { yDx = den / numerator; }
    else { yDx = den / numerator + 1; }
    // do  modulo with a negative number.
    yMODx = ((-den) % numerator);
    if (yMODx != 0)
        yMODx = yMODx + numerator;
    strcat(e, "1/");
    char a[50] = {};
    sprintf(a, "%d", yDx);
    strcat(e, a);
// Stop condition, if the modulo is - 0 the function finishes.
// until then it adds the fractions to the char's array and calls itself in recursion.
    if (yMODx != 0) {
        strcat(e, "+");
        toEgyptian(yMODx, yDx * den, e, terms);
    }

    for(i=0;i<MAX_TERMS;i++)
        terms[i] = NULL;
//        save the pointers for '1' on the array in terms array.
    int count = 0;
    for (int i = 0; i < MAX_STR && e[i] != '\0'; i++) {
        if (e[i] == '1' && e[i + 1] == '/') {
            terms[count] = &e[i];
            count++;
        }
        if (e[i] == '\0')
            break;
    }


}

// The function returns the fraction number 'i' in the OUT array.
void getIthElement(char e[], char *terms[], int i, char out[]) {
    i--;
    out[0] = '\0';
    int count = 0;
    // If index 'i' indicates the beginning of the fragment,
    // the loop will copy the fragment into a temporary array (t) and at the end chain it to the OUT array.

if(i<MAX_TERMS&&terms[i]!=NULL){
        while (*(terms[i]) != '+') {

            out[count] = *terms[i];
            terms[i]++;
            count++;
            if (*terms[i] == '\0')
                break;
        }
        out[count] =0;
    }
}







