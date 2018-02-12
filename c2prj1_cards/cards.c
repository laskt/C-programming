#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  assert((c.value>=2 && c.value<=VALUE_ACE)&&(c.suit>=SPADES && c.suit<=CLUBS));
}

const char * ranking_to_string(hand_ranking_t r) {
  switch(r){
  case STRAIGHT_FLUSH : return "One\n";break;
  case FOUR_OF_A_KIND : return "Two\n";break;
  case FULL_HOUSE : return "Three\n";break;
  case FLUSH : return "Four\n";break;
  case STRAIGHT : return "Five\n";break;
  case THREE_OF_A_KIND : return "Six\n";break;
  case TWO_PAIR : return "Seven\n";break;
  case PAIR : return "Eight\n";break;
  case NOTHING : return "Nine\n";break;
  default: return EXIT_SUCCESS;break;
  }
}

char value_letter(card_t c) {
  switch(c.value){
  case 2 : return '2'; break;
  case 3 : return '3'; break;
  case 4 : return '4'; break;
  case 5 : return '5'; break;
  case 6 : return '6'; break;
  case 7 : return '7'; break;
  case 8 : return '8'; break;
  case 9 : return '9'; break;
  case 10 : return '0'; break;
  case VALUE_JACK : return 'J'; break;
  case VALUE_QUEEN : return 'Q'; break;
  case VALUE_KING : return 'K'; break;
  case VALUE_ACE : return 'A'; break;
  default: return EXIT_FAILURE; break;
  }
}

  char suit_letter(card_t c) {
  switch(c.suit){
  case SPADES : return 's'; break;
  case HEARTS : return 'h'; break;
  case DIAMONDS : return 'd'; break;
  case CLUBS : return 'c'; break;
  default: return EXIT_FAILURE; break;			     
  }
}

void print_card(card_t c) {
  printf("%c",value_letter(c));
  printf("%c",suit_letter(c));
}

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;
  switch(value_let){
  case '2' : temp.value=2; break;
  case '3' : temp.value=3; break;
  case '4' : temp.value=4; break;
  case '5' : temp.value=5; break;
  case '6' : temp.value=6; break;
  case '7' : temp.value=7; break;
  case '8' : temp.value=8; break;
  case '9' : temp.value=9; break;
  case '0' : temp.value=10; break;
  case 'J' : temp.value=VALUE_JACK; break;
  case 'Q' : temp.value=VALUE_QUEEN; break;
  case 'K' : temp.value=VALUE_KING; break;
  case 'A' : temp.value=VALUE_ACE; break;
  }
  
  switch(suit_let){
  case 's' : temp.suit=SPADES; break;
  case 'h': temp.suit=HEARTS; break;
  case 'd' : temp.suit=DIAMONDS; break;
  case 'c' : temp.suit=CLUBS; break;
  }

  assert_card_valid(temp);
  return temp;
}

card_t card_from_num(unsigned c) {
  card_t temp;
  int val = c/13;
  int rem = c%13;
  switch(val){
  case 0 : temp.suit=SPADES; break;
  case 1 : temp.suit=HEARTS; break;
  case 2 : temp.suit=DIAMONDS; break;    
  case 3 : temp.suit=CLUBS; break;
  }
  switch(rem){
  case 0 : temp.value=2; break;
  case 1 : temp.value=3; break;
  case 2 : temp.value=4; break;
  case 3 : temp.value=5; break;
  case 4 : temp.value=6; break;
  case 5 : temp.value=7; break;
  case 6 : temp.value=8; break;
  case 7 : temp.value=9; break;
  case 8 : temp.value=10; break;
  case 9 : temp.value=VALUE_JACK; break;
  case 10 : temp.value=VALUE_QUEEN; break;
  case 11 : temp.value=VALUE_KING; break;
  case 12 : temp.value=VALUE_ACE; break;
  }
  return temp;
}
