#ifndef QUESTION_H
#define QUESTION_H

using namespace std;

class FindMaximumSubArrayRecursive {
    public:
        void Process();
    private:
        array<int, 3> FindMaximumSubarray(array<int, 16> A, int low, int high);
        array<int, 3> FindMaxCrossingSubarray(array<int, 16> A, int low, int mid, int high);
        void PrintProcessPartArray(array<int, 16> A, int low, int high, string markerL, string markerR);
};

class RotateMatrix90 {
    public:
        void Process();
    private:
        void Rotate90(int **input, size_t N);
        void PrintMatrix(int **input, size_t N);
};

class RotateMatrixN {
    public:
        void Process();
    private:
        void RotateN(int **input, size_t N, int k);
        void PrintMatrix(int **input, size_t N);
};

class BlackJack {
    public:
        void Process();
    private:
        enum CardSuit { SUIT_CLUB, SUIT_DIAMOND, SUIT_HEART, SUIT_SPADE, MAX_SUITS };

        enum CardRank {
        RANK_2,
        RANK_3,
        RANK_4,
        RANK_5,
        RANK_6,
        RANK_7,
        RANK_8,
        RANK_9,
        RANK_10,
        RANK_JACK,
        RANK_QUEEN,
        RANK_KING,
        RANK_ACE,
        MAX_RANKS
        };

        struct Card {
            CardRank rank;
            CardSuit suit;
        };

        void Swap(int &a, int &b);
        void PrintCard(const Card &card);
        void PrintDeck(const array<Card, 52> &deck);
        void SwapCard(Card &a, Card &b);
         int GetRandomNumber(int min, int max);
        void ShuffleDeck(array<Card, 52> &deck);
         int GetCardValue(const Card &card, int* ace_number);
        char GetPlayerChoice();
        bool PlayBlackJack(array<Card, 52> &deck);
        
};

#endif