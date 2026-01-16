// ============================================================================
// Week 2 Live Coding: Library Management System
//
// Follow along with the instructor!
// We'll build this step by step, uncommenting sections as we go.
// ============================================================================
#include <iostream>
#include <cstring>
using namespace std;
// ============================================================================
// STEP 1: Define our struct
// ============================================================================
struct Book {
int id;
char title[50];
char genre[20];
int pages;
bool isCheckedOut;
};
// ============================================================================
// STEP 2: Basic struct usage (uncomment in class)
// ============================================================================

void step2_basic_usage() {
cout << "=== STEP 2: Basic Struct Usage ===" << endl;
// Create a book using brace initialization
Book book1 = {101, "The Hobbit", "Fantasy", 310, false};
// Access members with dot operator
cout << "Title: " << book1.title << endl;
cout << "Pages: " << book1.pages << endl;
cout << "Checked out? " << (book1.isCheckedOut ? "Yes" : "No") << endl;
// Modify a member
book1.isCheckedOut = true;
cout << "After checkout: " << (book1.isCheckedOut ? "Yes" : "No") << endl;
cout << endl;
}

// ============================================================================
// STEP 3: Arrays of structs (uncomment in class)
// ============================================================================

void step3_arrays() {
cout << "=== STEP 3: Arrays of Structs ===" << endl;
// Create an array of books
Book library[4] = {
{101, "The Hobbit", "Fantasy", 310, false},
{102, "Dune", "SciFi", 412, true},
{103, "1984", "Fiction", 328, false},
{104, "The Martian", "SciFi", 369, true}
};
// Loop through and print
for (int i = 0; i < 4; i++) {
cout << library[i].id << ": " << library[i].title << endl;
}
cout << endl;
}

// ============================================================================
// STEP 4: Functions with structs - counting pattern (uncomment in class)
// ============================================================================

// Count how many books are checked out
int countCheckedOut(const Book books[], int size) {
int count = 0;
for (int i = 0; i < size; i++) {
if (books[i].isCheckedOut) {
count++;
}
}
return count;
}
void step4_counting() {
cout << "=== STEP 4: Counting Pattern ===" << endl;
Book library[4] = {
{101, "The Hobbit", "Fantasy", 310, false},
{102, "Dune", "SciFi", 412, true},
{103, "1984", "Fiction", 328, false},
{104, "The Martian", "SciFi", 369, true}
};
cout << "Checked out: " << countCheckedOut(library, 4) << endl;
// Expected: 2
cout << endl;
}

// ============================================================================
// STEP 5: Accumulator pattern - average (uncomment in class)
// ============================================================================

double averagePages(const Book books[], int size) {
double total = 0;
for (int i = 0; i < size; i++) {
total += books[i].pages;
}
return total / size;
}
void step5_average() {
cout << "=== STEP 5: Average Pattern ===" << endl;
Book library[4] = {
{101, "The Hobbit", "Fantasy", 310, false},
{102, "Dune", "SciFi", 412, true},
{103, "1984", "Fiction", 328, false},
{104, "The Martian", "SciFi", 369, true}
};
cout << "Average pages: " << averagePages(library, 4) << endl;
// Expected: (310 + 412 + 328 + 369) / 4 = 354.75
cout << endl;
}

// ============================================================================
// STEP 6: Find maximum pattern (uncomment in class)
// ============================================================================

Book findLongestBook(const Book books[], int size) {
Book longest = books[0]; // Start with first
for (int i = 1; i < size; i++) {
if (books[i].pages > longest.pages) {
longest = books[i];
}
}
return longest;
}
void step6_find_max() {
cout << "=== STEP 6: Find Maximum Pattern ===" << endl;
Book library[4] = {
{101, "The Hobbit", "Fantasy", 310, false},
{102, "Dune", "SciFi", 412, true},
{103, "1984", "Fiction", 328, false},
{104, "The Martian", "SciFi", 369, true}
};
Book longest = findLongestBook(library, 4);
cout << "Longest book: " << longest.title << " (" << longest.pages << " pages)"
<< endl;
// Expected: Dune (412 pages)
cout << endl;
}

// ============================================================================
// STEP 7: Comparing C-strings with strcmp (uncomment in class)
// ============================================================================

int countByGenre(const Book books[], int size, const char* genre) {
int count = 0;
for (int i = 0; i < size; i++) {
// strcmp returns 0 if strings are equal!
if (strcmp(books[i].genre, genre) == 0) {
count++;
}
}
return count;
}
void step7_strcmp() {
cout << "=== STEP 7: String Comparison ===" << endl;
Book library[4] = {
{101, "The Hobbit", "Fantasy", 310, false},
{102, "Dune", "SciFi", 412, true},
{103, "1984", "Fiction", 328, false},
{104, "The Martian", "SciFi", 369, true}
};
cout << "SciFi books: " << countByGenre(library, 4, "SciFi") << endl;
cout << "Fantasy books: " << countByGenre(library, 4, "Fantasy") << endl;
cout << "Romance books: " << countByGenre(library, 4, "Romance") << endl;
// Expected: 2, 1, 0
cout << endl;
}

// ============================================================================
// STEP 8: Pointers to structs - find and return (uncomment in class)
// ============================================================================

// Returns pointer to found book, or nullptr if not found
Book* findBookById(Book books[], int size, int searchId) {
for (int i = 0; i < size; i++) {
if (books[i].id == searchId) {
return &books[i]; // Return address of found book
}
}
return nullptr; // Not found
}
void step8_pointers() {
cout << "=== STEP 8: Pointers to Structs ===" << endl;
Book library[4] = {
{101, "The Hobbit", "Fantasy", 310, false},
{102, "Dune", "SciFi", 412, true},
{103, "1984", "Fiction", 328, false},
{104, "The Martian", "SciFi", 369, true}
};
// Search for existing book
Book* found = findBookById(library, 4, 102);
if (found != nullptr) {
cout << "Found: " << found->title << endl; // Arrow operator!
} else {
cout << "Not found!" << endl;
}
// Search for non-existent book
Book* notFound = findBookById(library, 4, 999);
if (notFound != nullptr) {
cout << "Found: " << notFound->title << endl;
} else {
cout << "Book 999 not found!" << endl;
}
cout << endl;
}

// ============================================================================
// STEP 9: Modify through pointer (uncomment in class)
// ============================================================================

// Forward declaration (findBookById defined in step 8)
Book* findBookById(Book books[], int size, int searchId);
bool checkOutBook(Book books[], int size, int bookId) {
Book* book = findBookById(books, size, bookId);
// Check if found
if (book == nullptr) {
return false;
}
// Check if already checked out
if (book->isCheckedOut) {
return false;
}
// Check it out!
book->isCheckedOut = true;
return true;
}
bool returnBook(Book books[], int size, int bookId) {
Book* book = findBookById(books, size, bookId);
if (book == nullptr) {
return false;
}
if (!book->isCheckedOut) {
return false; // Wasn't checked out
}
book->isCheckedOut = false;
return true;
}
void step9_modify() {
cout << "=== STEP 9: Modify Through Pointer ===" << endl;
Book library[4] = {
{101, "The Hobbit", "Fantasy", 310, false},
{102, "Dune", "SciFi", 412, true},
{103, "1984", "Fiction", 328, false},
{104, "The Martian", "SciFi", 369, true}
};
// Try to check out book 101 (available)
if (checkOutBook(library, 4, 101)) {
cout << "Checked out book 101!" << endl;
} else {
cout << "Could not check out book 101" << endl;
}
// Try to check out book 101 again (now unavailable)
if (checkOutBook(library, 4, 101)) {
cout << "Checked out book 101 again!" << endl;
} else {
cout << "Book 101 is already checked out" << endl;
}
// Try to check out non-existent book
if (checkOutBook(library, 4, 999)) {
cout << "Checked out book 999!" << endl;
} else {
cout << "Book 999 not found" << endl;
}
cout << endl;
}

// ============================================================================
// STEP 10: Filter pattern - copy matching items (uncomment in class)
// ============================================================================

int getAvailableBooks(const Book books[], int size, Book available[]) {
int count = 0;
for (int i = 0; i < size; i++) {
if (!books[i].isCheckedOut) {
available[count] = books[i]; // Copy the whole struct
count++;
}
}
return count;
}
void step10_filter() {
cout << "=== STEP 10: Filter Pattern ===" << endl;
Book library[4] = {
{101, "The Hobbit", "Fantasy", 310, false},
{102, "Dune", "SciFi", 412, true},
{103, "1984", "Fiction", 328, false},
{104, "The Martian", "SciFi", 369, true}
};
Book available[4]; // Array to hold results
int count = getAvailableBooks(library, 4, available);
cout << "Available books (" << count << "):" << endl;
for (int i = 0; i < count; i++) {
cout << " " << available[i].title << endl;
}
// Expected: The Hobbit, 1984
cout << endl;
}

// ============================================================================
// MAIN - Uncomment function calls as we progress through lecture
// ============================================================================
int main() {
cout << "Week 2: Introduction to Structs" << endl;
cout << "================================" << endl << endl;
// Uncomment these one at a time as we cover each section:
step2_basic_usage();
step3_arrays();
step4_counting();
step5_average();
step6_find_max();
step7_strcmp();
step8_pointers();
step9_modify();
step10_filter();
cout << "Lecture complete! Now try the hotel assignment." << endl;
return 0;
}