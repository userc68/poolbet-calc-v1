#include <iostream>
#include <iomanip>

// Armwrestling bets

using std::string;

int main() {

  std::cout << std::fixed << std::setprecision(2);

  float competitor1_bets, competitor2_bets, pool, commission, bet, multiplier;

  string competitor1, competitor2, yourpick, winner, loser;

  std::cout << "MATCH: ";
  std::cin >> competitor1 >> competitor2;

  if (competitor1 == competitor2) {
    std::cerr << "COMPETITORS CANNOT EQUAL EACHOTHER, EXITING PROGRAM";
    return 1;
  }

  std::cout << competitor1 << " TOTAL BETS($): ";
  std::cin >> competitor1_bets;

  std::cout << competitor2 << " TOTAL BETS($): ";
  std::cin >> competitor2_bets;

  if (competitor1_bets < 0 || competitor2_bets < 0) {
    std::cerr << "BETS CANNOT BE NEGATIVE. EXITING PROGRAM.\n";
    return 1;
  }

  std::cout << "COMMISSION(%): ";
  std::cin >> commission;

  if (commission >= 100) {
    std::cerr << "COMMISSION CANNOT BE OVER 100%, EXITING PROGRAM";
    return 1;
  }

  pool = (competitor1_bets + competitor2_bets) * (1 - commission / 100);

  std::cout << "YOU PICKED: ";
  std::cin >> yourpick;

  std::cout << "BET($): ";
  std::cin >> bet;

  if ((yourpick != competitor1) && (yourpick != competitor2)) {
    std::cerr << "YOUR PICK DOES NOT MATCH ANY COMPETITOR, EXITING PROGRAM";
    return 1;
  }

  if (bet > (yourpick == competitor1 ? competitor1_bets : competitor2_bets)) {
    std::cerr << "BET CANNOT BE HIGHER THAN TOTAL BETS ON YOUR PICKED COMPETITOR. EXITING PROGRAM.\n";
    return 1;
  }

  std::cout << "WINNER: ";
  std::cin >> winner;

  if ((winner != competitor1) && (winner != competitor2)) {
    std::cerr << "WINNER DOES NOT MATCH ANY COMPETITOR, EXITING PROGRAM";
    return 1;
  }

  if (yourpick == winner) {
    multiplier = pool / (yourpick == competitor1 ? competitor1_bets : competitor2_bets);
  } else {
    multiplier = 0;
  }

  std::cout << "YOU GET $" << bet * multiplier;

  return 0;
}