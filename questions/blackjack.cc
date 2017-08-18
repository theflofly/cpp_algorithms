// courtesy of
// http://www.learncpp.com/cpp-tutorial/6-x-chapter-6-comprehensive-quiz/

#include <array>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "questions.h"

using namespace std;

void BlackJack::Swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

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

void BlackJack::PrintCard(const Card &card) {
  switch (card.rank) {
    case RANK_2:
      cout << '2';
      break;
    case RANK_3:
      cout << '3';
      break;
    case RANK_4:
      cout << '4';
      break;
    case RANK_5:
      cout << '5';
      break;
    case RANK_6:
      cout << '6';
      break;
    case RANK_7:
      cout << '7';
      break;
    case RANK_8:
      cout << '8';
      break;
    case RANK_9:
      cout << '9';
      break;
    case RANK_10:
      cout << 'T';
      break;
    case RANK_JACK:
      cout << 'J';
      break;
    case RANK_QUEEN:
      cout << 'Q';
      break;
    case RANK_KING:
      cout << 'K';
      break;
    case RANK_ACE:
      cout << 'A';
      break;
    case MAX_RANKS:
      cout << "Errror: MAX_SUITS should not be used in a card.";
      break;
  }

  switch (card.suit) {
    case SUIT_CLUB:
      cout << 'C';
      break;
    case SUIT_DIAMOND:
      cout << 'D';
      break;
    case SUIT_HEART:
      cout << 'H';
      break;
    case SUIT_SPADE:
      cout << 'S';
      break;
    case MAX_SUITS:
      cout << "Errror: MAX_SUITS should not be used in a card.";
      break;
  }

  cout << endl;
}

void BlackJack::PrintDeck(const array<Card, 52> &deck) {
  for (auto card : deck) {
    PrintCard(card);
  }
}

void BlackJack::SwapCard(Card &a, Card &b) {
  Card temp = a;
  a = b;
  b = temp;
}

int BlackJack::GetRandomNumber(int min, int max) {
  static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1);
  return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void BlackJack::ShuffleDeck(array<Card, 52> &deck) {
  for (int i = 0; i < 52; i++) {
    SwapCard(deck[i], deck[GetRandomNumber(0, 51)]);
  }
}

int BlackJack::GetCardValue(const Card &card, int* ace_number) {
  switch (card.rank) {
    case RANK_2:
      return 2;
    case RANK_3:
      return 3;
    case RANK_4:
      return 4;
    case RANK_5:
      return 5;
    case RANK_6:
      return 6;
    case RANK_7:
      return 7;
    case RANK_8:
      return 8;
    case RANK_9:
      return 9;
    case RANK_10:
      return 10;
    case RANK_JACK:
      return 10;
    case RANK_QUEEN:
      return 10;
    case RANK_KING:
      return 10;
    case RANK_ACE:
      cout << "Ace" << endl;
      (*ace_number)++;
      return 11;
  }

  return 0;
}

char BlackJack::GetPlayerChoice() {
  cout << "(h) to hit, (s) to stand: ";
  char choice;
  do {
    cin >> choice;
  } while (choice != 's' && choice != 'h');

  return choice;
}

bool BlackJack::PlayBlackJack(array<Card, 52> &deck) {
  Card *card_ptr = &deck[0];

  int player_score = 0;
  int dealer_score = 0;
  int player_aces = 0;
  int dealer_aces = 0;

  dealer_score += GetCardValue(*card_ptr++, &dealer_aces);
  cout << "The dealer is showing: " << dealer_score << endl;

  player_score += GetCardValue(*card_ptr++, &player_aces);
  player_score += GetCardValue(*card_ptr++, &player_aces);

  while (1) {
    cout << "You have " << player_score << endl;
    if (player_score > 21) return false;

    char choice = GetPlayerChoice();

    if (choice == 's') break;

    int value = GetCardValue(*card_ptr++, &player_aces);

    if ((value + player_score > 21) && player_aces > 0) {
        player_score -= 10;
        player_aces--;
        cout << "Ace becomes 1" << endl;
    }
    player_score += value;
  }

  while (dealer_score < 17) {
    int value = GetCardValue(*card_ptr++, &player_aces);

    if ((value + dealer_score > 21) && dealer_aces > 0) {
        dealer_score -= 10;
        dealer_aces--;
        cout << "Ace becomes 1" << endl;
    }
    dealer_score += value;
    cout << "The dealer now has: " << dealer_score << endl;
  }

  if (dealer_score > 21) {
    return true;
  }

  return (player_score > dealer_score);
}

void BlackJack::Process() {
  srand(static_cast<unsigned int>(time(0)));

  array<Card, 52> deck;

  int cardIndex = 0;

  for (int suit = 0; suit < MAX_SUITS; suit++) {
    for (int rank = 0; rank < MAX_RANKS; rank++) {
      deck[cardIndex].suit = static_cast<CardSuit>(suit);
      deck[cardIndex].rank = static_cast<CardRank>(rank);
      cardIndex++;
    }
  }

  ShuffleDeck(deck);

  if (PlayBlackJack(deck))
    cout << "You win!" << endl;
  else
    cout << "You lose!" << endl;

}