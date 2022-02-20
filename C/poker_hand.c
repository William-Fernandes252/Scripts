/* Classifies a poker hand */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define HAND_SIZE 5
#define NUM_RANKS 13
#define NUM_SUITS 4
#define ACE 12
#define KING 11
#define QUEEN 10
#define JACK 9

//int num_in_ranks[NUM_RANKS];
//int num_in_suits[NUM_SUITS];
//bool straight, flush, four, three;
//int pairs; /* can be 0, 1, 2 or 3 */

void read_cards(short r, short s, int num_in_ranks[r], int num_in_suits[s]);
void analyze_hand(short r, short s, int num_in_ranks[r], int num_in_suits[s], bool * straight, bool * flush, bool * four, bool * three, int * pairs);
void print_result(bool straight, bool flush, bool four, bool three, int pairs);

int main(void) {
    int num_in_ranks[NUM_RANKS];
    int num_in_suits[NUM_SUITS];
    bool straight, flush, four, three;
    int pairs;
    
    for(;;) {
        read_cards(NUM_RANKS, NUM_SUITS, num_in_ranks, num_in_suits);
        analyze_hand(NUM_RANKS, NUM_SUITS, num_in_ranks, num_in_suits, &straight, &flush, &four, &three, &pairs);
        print_result(straight, flush, four, three, pairs);
    }
}

void read_cards(short r, short s, int num_in_ranks[r], int num_in_suits[s]) {
    bool card_exists[r][s];
    char ch, rank_ch, suit_ch;
    int rank, suit;
    bool bad_card;
    int cards_read = 0;

    for(rank = 0; rank < r; rank++) {
        num_in_ranks[rank] = 0;
        for(suit = 0; suit < s; suit++) {
            card_exists[rank][suit] = false;
        }
    }

    for(suit = 0; suit < s; suit++) {
        num_in_suits[suit] = 0;
    }

    while(cards_read < HAND_SIZE) {
        bad_card = false;

        printf("Enter a card (or 0 to exit the program): ");

        rank_ch = getchar();
        switch(rank_ch) {
            case '0': exit(EXIT_SUCCESS);
            case '2': rank = 0; break;
            case '3': rank = 1; break;
            case '4': rank = 2; break;
            case '5': rank = 3; break;
            case '6': rank = 4; break;
            case '7': rank = 5; break;
            case '8': rank = 6; break;
            case '9': rank = 7; break;
            case 't': case 'T': rank = 8; break;
            case 'j': case 'J': rank = JACK; break;
            case 'q': case 'Q': rank = QUEEN; break;
            case 'k': case 'K': rank = KING; break;
            case 'a': case 'A': rank = ACE; break;
            default: bad_card = true; break;
        }

        suit_ch = getchar();
        switch(suit_ch) {
            case 'c': case 'C': suit = 0; break;
            case 'd': case 'D': suit = 1; break;
            case 'h': case 'H': suit = 2; break;
            case 's': case 'S': suit = 3; break;
            default: bad_card = true; break;
        }

        while((ch = getchar()) != '\n') {
            if(ch != ' ') {
                bad_card = true;
            }
        }

        if(bad_card) {
            printf("Bad card entered. Will be ignored.\n");
        }
        else if(card_exists[rank][suit]) {
            printf("Last card was already entered. Will be ignored.\n");
        }
        else {
            num_in_suits[suit]++;
            num_in_ranks[rank]++;
            card_exists[rank][suit] = true;
            cards_read++;
        }
    }
}

void analyze_hand(short r, short s, int num_in_ranks[r], int num_in_suits[s], bool * straight, bool * flush, bool * four, bool * three, int * pairs) {
    int num_consec = 0;
    int rank, suit;
    *straight = false;
    *flush = false;
    *four = false;
    *three = false;
    *pairs = 0;

    for(suit = 0; suit < s; suit++) {
        if(num_in_suits[suit] == HAND_SIZE) {
            *flush = true;
        }
    }

    rank = 0;
    while(num_in_ranks[rank] == 0) {
        rank++;
    }
    for(; rank < r && num_in_ranks[rank] > 0; rank++) {
        num_consec++;
    }
    if(num_consec == HAND_SIZE) {
        *straight = true;
        return;
    }

    for(rank = 0; rank < r; rank++) {
        if(num_in_ranks[rank] == 4) {
            *four = true;
        }
        if(num_in_ranks[rank] == 3) {
            *three = true;
        }
        if(num_in_ranks[rank] == 2) {
            *pairs++;
        }
    }
}

void print_result(bool straight, bool flush, bool four, bool three, int pairs) {
    if(straight && flush) {
        printf("Straight flush.");
    }
    else if(four) {
        printf("Four of a kind.");
    }
    else if(three && pairs == 1) {
        printf("Full house.");
    }
    else if(three) {
        printf("Three of a kind.");
    }
    else if(flush) {
        printf("Flush.");
    }
    else if(straight) {
        printf("Straight.");
    }
    else if(pairs == 2) {
        printf("Two pairs.");
    }
    else if(pairs == 1) {
        printf("Pair.");
    }
    else {
        printf("High card.");
    }

    printf("\n\n");
}



