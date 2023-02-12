//Nahom Kiros
//CS201
//Assignment 1
/*this progrma is designed to measure typing speed. It will propmt the user to input a single word of  a sentence
at a time, and when finsihed, it displays the elpsed time to complete. */
#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define ARSIZE 9

void shuffle(char* text[ARSIZE]); //this function shuffles the array
void play(char* text[ARSIZE]); //thus function runs the game 
int main() {
  char * text[ARSIZE]; //array of words
  text[0] = "the";
  text[1] = "quick";
  text[2] = "brown";
  text[3] = "fox";
  text[4] = "jumps";
  text[5] = "over";
  text[6] = "the";
  text[7] = "lazy";
  text[8] = "dog";
  char read[35]; //used of input
  printf("!!!WELCOME TO THE TYPING GAME!!!\n");
  printf("ENTER start  WHEN READY\n");
  scanf("%s", read);
  if (strncmp(read, "start", strlen(read)) == 0) {//if input is start call shuffle
    shuffle(text);
  }

}
void shuffle(char * text[ARSIZE]) {
  struct timeval time; 
  gettimeofday( & time, NULL);
  srand((time.tv_sec * 10000) + (time.tv_sec / 10000));// seeding in to the rand func

  int index = 0; //index for swap
  char * hold; 
  for (int i = 0; i < ARSIZE; i++) {//swaps random element to the counting one
    index = rand() % ARSIZE;
    hold = text[i];
    text[i] = text[index];
    text[index] = hold;
  }
 play(text); 
}
void play(char * text[ARSIZE]) {
  char read[25];
  char check;//checks for space and end of file
  struct timeval start;
  struct timeval end;
  gettimeofday( & start, NULL);
  printf("ENTER THE WORDS ONE BY ONE\n");
  for (int i = 0; i < ARSIZE; i++) {
    while (strncmp(read, text[i], ARSIZE) != 0) {//pass, only if given the right input
      printf("WORD %d) : %s :", (i + 1), text[i]);
      scanf("%s", read);
      while ((check = getchar()) != '\n' && check != EOF); //checks for end of file and spacing
    }
  }
  gettimeofday( & end, NULL);
  struct timeval taken;
  timersub( & end, & start, & taken); //subtracts end from start and store on taken
  printf("CONGRATS!!! TIME TAKEN: %d seconds\n", taken);
}
