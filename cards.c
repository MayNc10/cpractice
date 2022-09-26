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
            printf("%d %d\n", face, suit);
            Card card;
            card.face = faces[face];
            printf("%s ", card.face);
            card.suit = suits[suit];
            printf("%s\n", card.suit);
            card.num = face + 2;
            deck[face * NUM_FACES + suit] = card;
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
    for (int i = 0; i < NUM_FACES * NUM_SUITS; i++) printf("%s of %s", deck[i].face, deck[i].suit);
}

