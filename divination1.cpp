#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (){

    int segundos = time(0);
    srand (segundos);
    int secret = rand() % 100;

	int num = 0, attempts = 1;
	double score = 1000;

	int attempts_avaiable;
	int difficulty;

	printf("************************************ \n");
	printf("***Welcome to the divination game*** \n");
	printf("************************************ \n\n");

	printf("What level of difficulty \n");
	printf("(1)Easy  (2)Medium  (3)Hard \n\n");
	printf("Select: ");
	scanf("%d", &difficulty);

    switch (difficulty){
        case 1:
            printf("Attempts avaiable: 20 \n");
            attempts_avaiable = 20;
            break;
        case 2:
            attempts_avaiable = 15;
            printf("Attempts avaiable: 15 \n");
            break;
        case 3:
            attempts_avaiable = 6;
            printf("Attempts avaiable: 6 \n");
            break;
    }
    int print_attempts = attempts_avaiable; // usaremos a print_attempts para mostrar quantas tentativas ainda faltam

	for(int i=1; i <= attempts_avaiable; i++ )
	{
		printf("\nGuess the number: ");
		scanf("%d", &num);

        int missed = num != secret;
        int bigger = num < secret;          //Compressores usamos para diminuir código dentro dos laços e if's
        int negative = num < 0;

		if (negative){
			printf("Negative numbers are not permitted \n");
			i--;
			continue;
		}
		if (missed){
			if (bigger)
				printf("The number is bigger \n");
			else//smaller
				printf("The number is smaller \n");
		}
		else{
			printf("\nCongratulations, You won!! \n");
			break;
		}
		double scoring = score = score - (abs(num - secret)/2); // CALCULA PONTUAÇÃO.

        attempts++;
        printf("Attempts avaiable: %d \n", --print_attempts );
        if (score > 0)
            printf("Score: %.0f \n", scoring);
		else
            printf ("Score: 0 \n\n");
	}
	if (print_attempts == 0){
        printf("You lose \n");
	}
	printf("Number of attempts: %d \n", attempts);
	printf("Thank for playing \n");

}

