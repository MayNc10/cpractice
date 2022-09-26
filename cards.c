#include <stdio.h>
#include <stdlib.h>

typedef struct Card {
    char* face;
    char* suit;
    int num;
} Card;

const int NUM_FACES = 13;
const int NUM_SUITS = 4;    

void fillDeck(Card deck[], char* faces[], char* suits[]);
void shuffle(Card deck[]);
void deal(Card deck[]);

int main(void) {
    Card deck[NUM_FACES * NUM_SUITS];
    char* faces[] = {"Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"};
    char* suits[] = {"Diamonds", "Clubs", "Hearts", "Spades"};
    srand(42);
    fillDeck(deck, faces, suits);
    shuffle(deck);
    deal(deck);
    return 0;
}

void fillDeck(Card deck[], char* faces[], char* suits[]) {
    for (size_t face = 0; face < NUM_FACES; face++) {
        for (size_t suit = 0; suit < NUM_SUITS; suit++) {
            deck[face * NUM_SUITS + suit].face = faces[face];
            deck[face * NUM_SUITS + suit].suit = suits[suit];
            deck[face * NUM_SUITS + suit].num = face + 2;
        }
    }
}
void shuffle(Card deck[]) {
    Card temp;
    int idx;

    for (int i = 0; i < NUM_FACES * NUM_SUITS - 1; i++) {
        idx = rand() % NUM_FACES * NUM_SUITS;
        temp = deck[idx];
        deck[idx] = deck[i];
        deck[i] = temp;
    }
}
void deal(Card deck[]) {
    for (int i = 0; i < NUM_FACES * NUM_SUITS; i++) printf("%s of %s\n", deck[i].face, deck[i].suit);
}

