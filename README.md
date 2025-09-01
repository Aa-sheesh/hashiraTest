Perfect 👍 Here’s your **README with expected outputs** for both test cases included:

---

# Hashira Placements Assignment

## 📌 Problem

Given `n` roots in JSON format (each root has a base and value), and a required `k = m + 1` roots (where `m` is the degree of the polynomial), construct the **monic polynomial** having those `k` roots and output its coefficients.

The polynomial is:

$$
P(x) = \prod_{i=1}^{k} (x - r_i)
$$

where each root `r_i` is first converted to decimal.

---

## 🛠️ Input Format

JSON file, e.g.:

```json
{
  "keys": {
    "n": 4,
    "k": 3
  },
  "1": { "base": "10", "value": "4" },
  "2": { "base": "2",  "value": "111" },
  "3": { "base": "10", "value": "12" },
  "6": { "base": "4",  "value": "213" }
}
```

---

## ✅ Output Format

Polynomial coefficients (from constant term to highest power).

Example:

```
Coefficients: [ -336, 160, -23, 1 ]
```

This corresponds to:

$$
P(x) = x^3 - 23x^2 + 160x - 336
$$

---

## 🚀 How to Run

1. Install [nlohmann/json](https://github.com/nlohmann/json):

   ```bash
   sudo apt update
   sudo apt install nlohmann-json3-dev
   ```
2. Compile the code:

   ```bash
   g++ -std=c++17 code.cpp -o poly
   ```
3. Run with a JSON test case:

   ```bash
   ./poly < testcase1.json
   ```

---

## 📂 Files

* `code.cpp` → C++ solution
* `testcase1.json` → Sample test
* `testcase2.json` → Second test

---

## 📝 Expected Outputs

### ▶ Testcase 1

Input (`testcase1.json`):

```json
{
  "keys": { "n": 4, "k": 3 },
  "1": { "base": "10", "value": "4" },
  "2": { "base": "2",  "value": "111" },
  "3": { "base": "10", "value": "12" },
  "6": { "base": "4",  "value": "213" }
}
```

Output:

```
Coefficients: [ -336, 160, -23, 1 ]
```

---

### ▶ Testcase 2

Input (`testcase2.json`): *(10 roots, k=7)*

Output (first 7 roots used):

```
Coefficients: [
-68251311922474227931291131263381395876233236117406283186409459444825993094514406289867143593522348021427278506790766073198900,
69242722857828950075440340313513423414802084042502172234667464543624790120201149174548909532528617931486933771,
-659422982387496339364177349268600659447242228929995566267403461578162207055624230394726655964,
1896953661197784192851619304941891141217656636090734451478146380932600517747,
-1750015510399802659018619826489058347218651671742010084868,
491196794452036188711731121904789704897,
-42744980544161216684,
1
]
```

---