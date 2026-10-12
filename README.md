# Smart Delivery Planning – Fractional Knapsack

A menu-driven C program that solves the **Fractional Knapsack problem** using the **Greedy Method**. It is built for a delivery scenario: a vehicle has a fixed carrying capacity, each package has a value (profit) and a weight, and the goal is to load the vehicle so the total value carried is as large as possible. A complete package is taken whenever it fits, and a fraction of a package is taken only when a complete one no longer fits.

Course: Analysis of Algorithms (AOA), PBLE 1

---

## Features

- Menu-driven interface (7 options)
- Accepts up to 100 packages
- Calculates the Value/Weight ratio of every package
- Sorts packages in decreasing order of ratio
- Picks full packages first and a fraction only when required
- Displays the maximum profit and the fraction taken of each package

## How the Algorithm Works

1. Read the value `p[i]` and weight `w[i]` of each package, and the vehicle capacity `m`.
2. Compute the ratio `pw[i] = p[i] / w[i]` for each package.
3. Sort the packages in decreasing order of `pw[i]`. Profit, weight and ratio are swapped together so they stay aligned.
4. Go through the sorted packages with the remaining capacity:
   - If `w[i] <= remaining capacity`, take the whole package (`x[i] = 1`).
   - Otherwise take the fraction `x[i] = remaining / w[i]` and stop.
5. Total profit = sum of `p[i] * x[i]`.

**Why greedy works:** the item with the highest value per unit weight always gives the most value for the capacity it uses, so filling the vehicle in ratio order is optimal when fractions are allowed.

## Menu Options

| Option | Action |
|--------|--------|
| 1 | Enter package details (count, capacity, values, weights) |
| 2 | Display package details |
| 3 | Calculate and display Value/Weight ratios |
| 4 | Sort packages by ratio (decreasing) |
| 5 | Find the maximum value |
| 6 | Display selected packages and fraction taken |
| 7 | Exit |

> **Use the options in order: 1 → 3 → 4 → 5 → 6.** Ratios must be calculated before sorting, and sorting must be done before finding the maximum value.

## Compile and Run

Requires a C compiler such as GCC.

```bash
gcc fractional_knapsack.c -o fractional_knapsack
./fractional_knapsack
```

On Windows (MinGW):

```bash
gcc fractional_knapsack.c -o fractional_knapsack.exe
fractional_knapsack.exe
```

## Sample Run

**Input**

| Package | Value | Weight |
|---------|-------|--------|
| 1 | 40 | 5 |
| 2 | 30 | 10 |
| 3 | 50 | 5 |
| 4 | 20 | 4 |

Vehicle capacity = 15

**Ratios:** 8.00, 3.00, 10.00, 5.00

**Sorted order (decreasing ratio):** Package 3 (10.00), Package 1 (8.00), Package 4 (5.00), Package 2 (3.00)

**Selection**

| Package | Fraction Taken | Weight Used | Value Gained |
|---------|----------------|-------------|--------------|
| 3 | 1.00 | 5 | 50 |
| 1 | 1.00 | 5 | 40 |
| 4 | 1.00 | 4 | 20 |
| 2 | 0.10 | 1 | 3 |

**Total weight used = 15, Maximum Profit = 113.00**

## Time Complexity

| Step | Complexity |
|------|------------|
| Calculating ratios | O(n) |
| Sorting (bubble sort, two nested loops) | O(n²) |
| Greedy selection (single pass) | O(n) |
| **Overall** | **O(n²)** |

The sorting step dominates. Replacing bubble sort with merge sort or quicksort brings the overall complexity down to **O(n log n)**.

**Space complexity:** O(n) for the arrays.

## Concepts Covered

Greedy Method, Fractional Knapsack, ratio-based selection, sorting, time-complexity analysis.

## Limitations

- Maximum of 100 packages (fixed array size).
- Weights must be greater than zero (the ratio divides by weight).
- The program does not check that the menu options are used in the correct order.
- After sorting (option 4), the original package numbers are not kept; packages are shown by their sorted position.

## Repository


