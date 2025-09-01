---

# Polynomial Coefficients from Roots (Hashira Placements Assignment)

This project solves the given assignment:

* Read input from JSON.
* Parse roots given in different bases.
* Build the polynomial using those roots.
* Output coefficients.
* Verify correctness by evaluating the polynomial at each root.

---

## 📂 Files

* **code.cpp** → Main program to compute coefficients.
* **verify.cpp** → Verifies correctness by checking `P(r) = 0` for each root.
* **testcase1.json** → Sample test case 1.
* **testcase2.json** → Sample test case 2.

---

## ⚙️ Requirements

* **C++17 or later**
* [nlohmann/json](https://github.com/nlohmann/json) (`json.hpp`)
* Boost multiprecision (already available in most g++ installs).

---

## 🚀 Compilation

```bash
g++ -std=c++17 code.cpp -o code
g++ -std=c++17 verify.cpp -o verify
```

---

## ▶️ Usage

Run with JSON input:

```bash
./code < testcase1.json
./verify < testcase1.json
```

---

## ✅ Example Output (Testcase 1)

```
Coefficients: [ -336, 160, -23, 1 ]

Verification:
P(r1) = 0
P(r2) = 0
P(r3) = 0
```

---

## 📌 Notes

* Coefficients are printed in **standard polynomial order**:
  `[ constant, x^1, x^2, …, leading term ]`.
* Only the first **k roots** are used (`k = degree + 1`).
* Works for arbitrarily large numbers thanks to `boost::multiprecision::cpp_int`.

---
