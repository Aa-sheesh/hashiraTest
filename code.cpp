#include <bits/stdc++.h>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

// Convert string in base 'b' to decimal (using long long)
long long toDecimal(const string &val, int base) {
    long long res = 0;
    for (char c : val) {
        int digit;
        if (isdigit(c)) digit = c - '0';
        else if (isalpha(c)) digit = 10 + (tolower(c) - 'a');
        else continue;
        res = res * base + digit;
    }
    return res;
}

// Multiply polynomial by (x - root)
void multiplyPoly(vector<long long> &poly, long long root) {
    vector<long long> newPoly(poly.size() + 1, 0);
    for (size_t i = 0; i < poly.size(); i++) {
        newPoly[i] += -root * poly[i];
        newPoly[i + 1] += poly[i];
    }
    poly = newPoly;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Read full JSON input from stdin
    string input((istreambuf_iterator<char>(cin)), istreambuf_iterator<char>());
    json j = json::parse(input);

    int n = j["keys"]["n"];
    int k = j["keys"]["k"];

    vector<long long> roots;
    for (auto& [key, value] : j.items()) {
        if (key == "keys") continue;
        int base = stoi(value["base"].get<string>());
        string val = value["value"].get<string>();
        roots.push_back(toDecimal(val, base));
    }

    // Pick first k roots
    sort(roots.begin(), roots.end()); // optional (to keep deterministic order)
    roots.resize(k);

    // Build polynomial
    vector<long long> poly = {1};
    for (long long r : roots) {
        multiplyPoly(poly, r);
    }

    // Output coefficients
    cout << "Coefficients: [ ";
    for (size_t i = 0; i < poly.size(); i++) {
        cout << poly[i];
        if (i + 1 < poly.size()) cout << ", ";
    }
    cout << " ]\n";

    return 0;
}
