// strings.c -- stringing the user along
// note: gets() was deprecated in C11

#include <stdio.h>
#include <string.h> // used to buffer '\n'

#define MSG "You must have many talents. Tell me some."
#define LIM 5
#define LINELEN 81

int main(void) {

	char name[LINELEN];
	char talents[LINELEN];
	int i;

	const char m1[40] = "Limit yourself to one line's worth.";
	const char m2[] = "If you can't think of anything, fake it.";
	const char *m3 = "\nEnough about me -- what's your name?";
	const char *mytal[LIM] = {
		"Adding numbers swiftly",
		"Multiplying accurately",
		"Stashing data",
		"Following instructions to the letter",
		"Understanding the C language"
	};

	printf("Hi! I'm Clyde the Computer. I have many talents.\n");
	printf("Let me tell you some of them.\n");
	puts("What were they? Ah, yes, here's a partial list.");

	for (i = 0; i < LIM; i++)
		puts(mytal[i]);
	puts(m3);

	fgets(name, 81, stdin); // replace gets() with fgets()
	name[strcspn(name, "\n")] = 0; // added to buffer '\n' 
	printf("Well, %s, %s\n", name, MSG);
	printf("%s\n%s\n", m1, m2);

	fgets(talents, 81, stdin); // replace gets() with fgets()
	puts("Let's see if I've got that list: ");
	talents[strcspn(talents, "\n")] = 0; // added to buffer '\n'
	puts(talents);
	printf("Thanks for the information, %s.\n", name);

	return 0;
}
