#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <random>
#include <numeric>

using namespace std;

static int diceThrowResult() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(1, 6);
    int random_number = distribution(gen);
    return random_number;
}

static int find_sequence(const vector<int>& src, const vector<int>& sequence, int index) {
    auto it = search(src.begin() + index, src.end(), sequence.begin(), sequence.end());
    
    if (it != src.end())
    {
        return 1 + find_sequence(src, sequence, distance(src.begin(), it) + sequence.size());
    }
    return 0;
}

static void reverse_sequence(vector<int>& src, const vector<int>& sequence, size_t index) {
    auto it = search(src.begin() + index, src.end(), sequence.begin(), sequence.end());

    if (it != src.end()) {
        reverse(it, it + sequence.size());
        reverse_sequence(src, sequence, distance(src.begin(), it) + sequence.size());
    }
}


class DiceRolls : public std::vector<int> {
private:
public:
    DiceRolls() {};
    DiceRolls(int throw_count) {
        generate_n(back_inserter(*this), throw_count, diceThrowResult);

        vector<int> seq1 = { 1,2,3 };
        vector<int> seq2 = { 4,5,6 };
        vector<int> seq3 = { 1,3,5 };
        vector<int> seq4 = { 2,4,6 };

        int c1 = find_sequence(*this, seq1, 0);
        int c2 = find_sequence(*this, seq2, 0);
        int c3 = find_sequence(*this, seq3, 0);
        int c4 = find_sequence(*this, seq4, 0);

        cout << "[1,2,3]: " << c1 << endl << "[4,5,6]: " << c2 << endl << "[1,3,5]: " << c3 << endl << "[2,4,6]: " << c4 << endl;

        reverse_sequence(*this, seq1, 0);
        reverse_sequence(*this, seq2, 0);
        reverse_sequence(*this, seq3, 0);
        reverse_sequence(*this, seq4, 0);

        cout << endl << "AFTER REVERSION" << endl;
        c1 = find_sequence(*this, seq1, 0);
        c2 = find_sequence(*this, seq2, 0);
        c3 = find_sequence(*this, seq3, 0);
        c4 = find_sequence(*this, seq4, 0);

        cout << "[1,2,3]: " << c1 << endl << "[4,5,6]: " << c2 << endl << "[1,3,5]: " << c3 << endl << "[2,4,6]: " << c4 << endl;
    }
};


int main() {
    DiceRolls d1(1000);
    return 0;
}