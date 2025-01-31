/*
Rock, Paper, Scissors written in C.

Written by Jack Michell

January 30, 2025
*/

#include <complex.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WINNING_SCORE 3

int main() {
  unsigned int player_score = 0, computer_score = 0;
  char player_choice, computer_choice;

  printf("Welcome to Rock, Paper, Scissors!\n\n");

  // Loop through the game until a WINNING_SCORE is reached
  while (player_score < WINNING_SCORE && computer_score < WINNING_SCORE) {

    // Get choice from player
    printf("Pick (R)ock, (P)aper, (S)cissors: ");
    scanf(" %c", &player_choice);
    player_choice = tolower(player_choice);

    // Randomly generate the computer choice
    // from a range [min, max] or in this case [1, 3]
    // with each of the 3 numbers representing
    // rock, paper, or scissors
    srand(time(NULL));

    // n = rand() % (max - min + 1) + min
    int random_number = (rand() % (100 - 1 + 1) + 1);

    if (random_number <= 0) {
      return 0;
    } else if (random_number >= 1 && random_number <= 33) {
      computer_choice = 'r';
    } else if (random_number >= 34 && random_number <= 66) {
      computer_choice = 'p';
    } else {
      computer_choice = 's';
    }

    // If the player and computer play the same choice,
    // do not add to total score
    if (player_choice == computer_choice) {
      printf("Tie!\n\n");
      printf("Current score:\n Player: %d\n Computer: %d\n\n", player_score,
             computer_score);
    }

    // Add points where needed
    if (player_choice == 'r' && computer_choice == 'p') {
      printf("Computer picked %c, player picked %c.\n\n", computer_choice,
             player_choice);
      computer_score++;
      printf("Current score:\n Player: %d\n Computer: %d\n\n", player_score,
             computer_score);
    } else if (player_choice == 'p' && computer_choice == 'r') {
      printf("Computer picked %c, player picked %c.\n\n", computer_choice,
             player_choice);
      player_score++;
      printf("Current score:\n Player: %d\n Computer: %d\n\n", player_score,
             computer_score);
    }

    if (player_choice == 'p' && computer_choice == 's') {
      printf("Computer picked %c, player picked %c.\n\n", computer_choice,
             player_choice);
      computer_score++;
      printf("Current score:\n Player: %d\n Computer: %d\n\n", player_score,
             computer_score);
    } else if (player_choice == 's' && computer_choice == 'p') {
      printf("Computer picked %c, player picked %c.\n\n", computer_choice,
             player_choice);
      player_score++;
      printf("Current score:\n Player: %d\n Computer: %d\n\n", player_score,
             computer_score);
    }

    if (player_choice == 's' && computer_choice == 'r') {
      printf("Computer picked %c, player picked %c.\n\n", computer_choice,
             player_choice);
      computer_score++;
      printf("Current score:\n Player: %d\n Computer: %d\n\n", player_score,
             computer_score);
    } else if (player_choice == 'r' && computer_choice == 's') {
      printf("Computer picked %c, player picked %c.\n\n", computer_choice,
             player_choice);
      player_score++;
      printf("Current score:\n Player: %d\n Computer: %d\n\n", player_score,
             computer_score);
    }
  }

  // Check if winning score was reached
  if (computer_score == WINNING_SCORE) {
    printf("Computer wins!\n");
    return 0;
  } else if (player_score == WINNING_SCORE) {
    printf("Player wins!\n");
    return 0;
  } else {
    printf("An error occured determining winner.\n");
    return 0;
  }
}
