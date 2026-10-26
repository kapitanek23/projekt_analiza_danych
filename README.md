# Common Elements Across Matrix Rows

A small **C++ console experiment** that explores finding values shared by all rows of an integer matrix. It supports manual or random input, measures the counting phase with `std::chrono`, and appends timing results to a text file.

This repository contains an educational prototype in a single [main.cpp](main.cpp) file. The original repository name, `projekt_analiza_danych`, means “data analysis project” in Polish.

## What it demonstrates

- Dynamic allocation of a two-dimensional integer array.
- Manual entry or pseudorandom generation of matrix values.
- A fixed-size occurrence table used to track candidate values.
- Runtime measurement and appending results with `std::ofstream`.

## Build and run

Use a compiler with **C++11** support, such as GCC or Clang. No external libraries are required.

```bash
git clone https://github.com/kapitanek23/projekt_analiza_danych.git
cd projekt_analiza_danych
g++ -std=c++11 -O2 -Wall -Wextra -pedantic main.cpp -o matrix_rows
./matrix_rows
```

On Windows with a GCC toolchain, use `-o matrix_rows.exe` and run `.\matrix_rows.exe`.

The prompts are in Polish:

1. Enter the number of rows (`Podaj liczbe wierszy`) and columns (`Podaj liczbe kolumn`).
2. Choose **1** for manual entry or **2** for random values in the range 0–9.
3. For manual input, enter the matrix row by row.

### Example

For three rows and four columns, select manual input and enter:

```text
1 2 3 4
3 4 5 6
3 4 7 8
```

The program reports:

```text
Wspolne elementy we wszystkich wierszach: 3 4
```

The elapsed time varies by machine and input size.

## Timing output

Each run appends a line to `wyniki_operacji.txt` in the current working directory:

```text
rowsxcolumns,elapsed_milliseconds
```

For example, a short run may append `3x4,0`. The file has no header, and a zero value means the measurement rounded down to milliseconds. Allocation and input are outside the timed counting phase.

## Current constraints

Use positive dimensions and manually entered values from **1 to 99**, with no duplicates within a row, for the demonstrated case.

The current counting logic can give incorrect results when rows contain duplicates. Random mode may generate duplicates and zeros; zero is omitted from the printed results. Values outside 0–99 can index outside the occurrence array, and input is not validated. The result-printing loop also reaches index 100 of a 100-element array, which is an out-of-bounds read even for otherwise valid input.

The implementation also does not release its dynamically allocated matrix before exit. These constraints make it a learning prototype rather than a general-purpose matrix analysis library. No automated tests or CI workflow are included.

## Author and feedback

[Bartosz Kawalec](https://github.com/kapitanek23). Use [GitHub Issues](https://github.com/kapitanek23/projekt_analiza_danych/issues) to report a reproducer, including the complete matrix and expected common values.

## License

No license file is currently included in this repository.
