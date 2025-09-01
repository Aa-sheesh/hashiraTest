#include <bits/stdc++.h>
#include <nlohmann/json.hpp>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using json = nlohmann::json;
using boost::multiprecision::cpp_int;

cpp_int convertToDecimal(const string& value, int base) {
    cpp_int result = 0;
    for (char c : value) {
        int digit;
        if (isdigit(c)) digit = c - '0';
        else if (isalpha(c)) digit = tolower(c) - 'a' + 10;
        else throw invalid_argument("Invalid character in input");

        if (digit >= base) throw invalid_argument("Digit out of range for base");

        result = result * base + digit;
    }
    return result;
}

vector<cpp_int> buildPolynomial(const vector<cpp_int>& roots) {
    vector<cpp_int> coeffs = {1};
    for (const auto& r : roots) {
        vector<cpp_int> newCoeffs(coeffs.size() + 1, 0);
        for (size_t i = 0; i < coeffs.size(); i++) {
            newCoeffs[i]     += -r * coeffs[i];
            newCoeffs[i + 1] += coeffs[i];
        }
        coeffs.swap(newCoeffs);
    }
    return coeffs;
}

cpp_int evaluatePolynomial(const vector<cpp_int>& coeffs, cpp_int x) {
    cpp_int result = 0, power = 1;
    for (auto c : coeffs) {
        result += c * power;
        power *= x;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    json input;
    cin >> input;

    int k = input["keys"]["k"];

    vector<cpp_int> roots;
    for (auto& el : input.items()) {
        if (el.key() == "keys") continue;
        int base = stoi(el.value()["base"].get<string>());
        string value = el.value()["value"].get<string>();
        cpp_int decimalValue = convertToDecimal(value, base);
        roots.push_back(decimalValue);
    }

    if ((int)roots.size() > k) roots.resize(k);

    vector<cpp_int> coeffs = buildPolynomial(roots);

    cout << "Coefficients: [ ";
    for (size_t i = 0; i < coeffs.size(); i++) {
        cout << coeffs[i];
        if (i + 1 < coeffs.size()) cout << ", ";
    }
    cout << " ]\n";

    cout << "\nVerification:\n";
    for (size_t i = 0; i < roots.size(); i++) {
        cout << "P(r" << i + 1 << ") = " << evaluatePolynomial(coeffs, roots[i]) << "\n";
    }

    return 0;
}
