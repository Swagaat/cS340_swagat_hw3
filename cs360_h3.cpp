//Q.no.1

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

class Card {
public:
    int face;
    int suit;

    Card(int cardFace, int cardSuit) : face(cardFace), suit(cardSuit) {}

    static const std::string faces[];
    static const std::string suits[];

    std::string toString() const {
        return faces[face] + " of " + suits[suit];
    }

    static const int totalFaces = 13;
    static const int totalSuits = 4;
};

const std::string Card::faces[] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
const std::string Card::suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};

class DeckOfCards {
public:
    static const int totalCards = 52;
    std::vector<Card> deck;
    int currentCard;

    DeckOfCards() : currentCard(0) {
        for (int i = 0; i < Card::totalSuits; ++i) {
            for (int j = 0; j < Card::totalFaces; ++j) {
                deck.push_back(Card(j, i));
            }
        }
    }

    void shuffle() {
        for (int i = 0; i < totalCards; ++i) {
            int randIndex = rand() % totalCards;
            std::swap(deck[i], deck[randIndex]);
        }
    }

    Card dealCard() {
        return deck[currentCard++];
    }

    bool moreCards() const {
        return currentCard < totalCards;
    }
};

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    DeckOfCards myDeck;
    myDeck.shuffle();

    while (myDeck.moreCards()) {
        Card dealtCard = myDeck.dealCard();
        std::cout << dealtCard.toString() << std::endl;
    }

    return 0;
}








//Q.No.2
#include <iostream>
#include <vector>

class IntegerSet {
private:
    static const int setSize = 101;  // Range from 0 to 100
    std::vector<bool> set;

public:
    IntegerSet() : set(setSize, false) {}

    IntegerSet(const int arr[], int size) : set(setSize, false) {
        for (int i = 0; i < size; ++i) {
            if (arr[i] >= 0 && arr[i] <= 100) {
                set[arr[i]] = true;
            }
        }
    }

    void unionOfSets(const IntegerSet& set1, const IntegerSet& set2) {
        for (int i = 0; i < setSize; ++i) {
            set[i] = set1.set[i] || set2.set[i];
        }
    }

    void intersectionOfSets(const IntegerSet& set1, const IntegerSet& set2) {
        for (int i = 0; i < setSize; ++i) {
            set[i] = set1.set[i] && set2.set[i];
        }
    }

    void insertElement(int k) {
        if (k >= 0 && k <= 100) {
            set[k] = true;
        }
    }

    void deleteElement(int m) {
        if (m >= 0 && m <= 100) {
            set[m] = false;
        }
    }

    void printSet() const {
        bool isEmpty = true;
        for (int i = 0; i < setSize; ++i) {
            if (set[i]) {
                std::cout << i << " ";
                isEmpty = false;
            }
        }
        if (isEmpty) {
            std::cout << "---";
        }
        std::cout << std::endl;
    }

    bool isEqualTo(const IntegerSet& otherSet) const {
        for (int i = 0; i < setSize; ++i) {
            if (set[i] != otherSet.set[i]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    int arr1[] = {1, 3, 5, 7, 9};
    int arr2[] = {2, 4, 6, 8, 10};

    IntegerSet set1(arr1, 5);
    IntegerSet set2(arr2, 5);

    std::cout << "Set 1: ";
    set1.printSet();

    std::cout << "Set 2: ";
    set2.printSet();

    IntegerSet unionSet, intersectionSet;

    unionSet.unionOfSets(set1, set2);
    std::cout << "Union of Set 1 and Set 2: ";
    unionSet.printSet();

    intersectionSet.intersectionOfSets(set1, set2);
    std::cout << "Intersection of Set 1 and Set 2: ";
    intersectionSet.printSet();

    std::cout << "Is Set 1 equal to Set 2? " << (set1.isEqualTo(set2) ? "Yes" : "No") << std::endl;

    set1.insertElement(12);
    std::cout << "After inserting 12 into Set 1: ";
    set1.printSet();

    set2.deleteElement(6);
    std::cout << "After deleting 6 from Set 2: ";
    set2.printSet();

    return 0;
}

