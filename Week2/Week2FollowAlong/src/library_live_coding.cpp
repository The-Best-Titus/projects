// ============================================================================
// Week 2 Live Coding: Library Management System
// 
// Follow along with the instructor!
// Fill in the TODO sections as we work through each step together.
// ============================================================================

#include <iostream>
#include <cstring>
using namespace std;

// ============================================================================
// STEP 1: Define our struct
// ============================================================================

// TODO: Define a Book struct with the following members:
// - int id
// - char title[50]
// - char genre[20]
// - int pages
// - bool isCheckedOut



// ============================================================================
// STEP 2: Basic struct usage
// ============================================================================

void step2_basic_usage() {
    cout << "=== STEP 2: Basic Struct Usage ===" << endl;
    
    // TODO: Create a book using brace initialization
    // Book book1 = {...};
    
    // TODO: Print the title and pages using dot operator
    
    // TODO: Modify isCheckedOut to true
    
    // TODO: Print the updated checkout status
    
    cout << endl;
}

// ============================================================================
// STEP 3: Arrays of structs
// ============================================================================

void step3_arrays() {
    cout << "=== STEP 3: Arrays of Structs ===" << endl;
    
    // TODO: Create an array of 4 books with brace initialization
    // Book library[4] = { ... };
    
    // TODO: Loop through and print each book's id and title
    
    cout << endl;
}

// ============================================================================
// STEP 4: Functions with structs - counting pattern
// ============================================================================

// TODO: Implement countCheckedOut
// Count how many books are checked out
// Hint: Loop through, check isCheckedOut, increment counter
int countCheckedOut(const Book books[], int size) {
    // Your code here
    return 0;
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
// STEP 5: Accumulator pattern - average
// ============================================================================

// TODO: Implement averagePages
// Calculate the average page count across all books
// Hint: Sum all pages, divide by size
double averagePages(const Book books[], int size) {
    // Your code here
    return 0.0;
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
// STEP 6: Find maximum pattern
// ============================================================================

// TODO: Implement findLongestBook
// Find and return the book with the most pages
// Hint: Start with first book, compare with rest, keep track of longest
Book findLongestBook(const Book books[], int size) {
    // Your code here
    return books[0];  // Replace this
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
    cout << "Longest book: " << longest.title << " (" << longest.pages << " pages)" << endl;
    // Expected: Dune (412 pages)
    
    cout << endl;
}

// ============================================================================
// STEP 7: Comparing C-strings with strcmp
// ============================================================================

// TODO: Implement countByGenre
// Count how many books match the given genre
// Hint: Use strcmp(books[i].genre, genre) == 0 to compare strings
int countByGenre(const Book books[], int size, const char* genre) {
    // Your code here
    return 0;
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
// STEP 8: Pointers to structs - find and return
// ============================================================================

// TODO: Implement findBookById
// Search for a book by its id
// Return pointer to the book if found, nullptr if not found
// Hint: Loop through, when found return &books[i]
Book* findBookById(Book books[], int size, int searchId) {
    // Your code here
    return nullptr;
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
        cout << "Found: " << found->title << endl;  // Arrow operator!
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
// STEP 9: Modify through pointer
// ============================================================================

// TODO: Implement checkOutBook
// Find a book by id and mark it as checked out
// Return false if: book not found OR already checked out
// Return true if: successfully checked out
// Hint: Use findBookById, check conditions, set isCheckedOut = true
bool checkOutBook(Book books[], int size, int bookId) {
    // Your code here
    return false;
}

// TODO: Implement returnBook
// Find a book by id and mark it as returned (not checked out)
// Return false if: book not found OR wasn't checked out
// Return true if: successfully returned
bool returnBook(Book books[], int size, int bookId) {
    // Your code here
    return false;
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
// STEP 10: Filter pattern - copy matching items
// ============================================================================

// TODO: Implement getAvailableBooks
// Copy all available (not checked out) books to the available array
// Return the count of available books
// Hint: Loop through, if !isCheckedOut, copy to available[count], increment count
int getAvailableBooks(const Book books[], int size, Book available[]) {
    // Your code here
    return 0;
}

void step10_filter() {
    cout << "=== STEP 10: Filter Pattern ===" << endl;
    
    Book library[4] = {
        {101, "The Hobbit", "Fantasy", 310, false},
        {102, "Dune", "SciFi", 412, true},
        {103, "1984", "Fiction", 328, false},
        {104, "The Martian", "SciFi", 369, true}
    };
    
    Book available[4];  // Array to hold results
    int count = getAvailableBooks(library, 4, available);
    
    cout << "Available books (" << count << "):" << endl;
    for (int i = 0; i < count; i++) {
        cout << "  " << available[i].title << endl;
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
    
    // step2_basic_usage();
    // step3_arrays();
    // step4_counting();
    // step5_average();
    // step6_find_max();
    // step7_strcmp();
    // step8_pointers();
    // step9_modify();
    // step10_filter();
    
    cout << "Lecture complete! Now try the hotel assignment." << endl;
    
    return 0;
}
