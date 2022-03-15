#pragma once

struct GoToCard {
    int jumpTo;
    bool needJump;
};

void initChances(GoToCard (&cards)[16]) {
    cards[0].jumpTo = 15;
    cards[1].jumpTo = 23;
    cards[2].jumpTo = 0;
    cards[3].jumpTo = 40;
    cards[4].jumpTo = 39;
    cards[5].jumpTo = 11;
    cards[6].jumpTo = -3;
    for (size_t i = 0; i <= 6; ++i) {
        cards[i].needJump = true;
    }
    for (size_t i = 7; i < 16; ++i) {
        cards[i].needJump = false;
    }
}

void initTreasury(GoToCard (&cards)[16]) {
    cards[0].jumpTo = 1;
    cards[1].jumpTo = 0;
    cards[2].jumpTo = 40;
    for (size_t i = 0; i <= 2; ++i) {
        cards[i].needJump = true;
    }
    for (size_t i = 3; i < 16; ++i) {
        cards[i].needJump = false;
    }
}