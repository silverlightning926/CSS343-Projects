# Self-Evaluation

## Name(s): 

Out of 25 points. Use output.txt created using 
`./create-output.sh > output.txt 2>&1` for guidance.

Complete all questions with "Q:"

Q: Does the program compile and run to completion: Yes/No

Yes, the program compiles and runs to completion.

- If the program does not compile or gives a segmentation error when run, 
the maximum possible grade is 50%. No need to continue with the rest of self-evaluation

Q: All public functions have been implemented: 

100% implemented, 0% unimplemented

- -2 for each functionality not implemented

For each command, state Full, Partial or None to indicate 
if it has been fully, partially or not implemented at all.
Explain any partial implementations.

Inventory: Full / Complete
History: Full / Complete
Borrow: Full / Complete
Return: Full / Complete


Q: -1 for each compilation warning, min -3:

0 Warnings

- Check under *1. Compiles without warnings*
- If the warning message is addressed in README.md, including how the programmer tried to address it, no deductions

Q: -1 for each clang-tidy warning, min -3: 

0 Clang-Tidy Warnings

- Check under *3. clang-tidy warnings*
- If the warning message is addressed in README.md, including how the programmer tried to address it, no deductions

Q: -1 for each clang-format warning, min -3: 

0 Clang Format Issues

- Check under *4. clang-format does not find any formatting issues*


Q: -2 for any detected memory leak: 

No memory leaks

- Check under *5. No memory leaks using g++*
- Check under *6. No memory leaks using valgrind*

Q: Do the tests sufficiently test the code: 

- -1 for each large block of code not executed
- -2 for each function that is never called when testing
- Check under *7. Tests have full code coverage* paying attention to *The lines below were never executed*

Q: Are all functions in .h and .cpp file documents (min -3): 

100%, all code is in .h and .cpp files

- -1 for each function not documented

## Location of error message or functionality

State the file and function where the information can be found

invalid command code: InventoryManager.cpp - newCommand();

invalid movie type: InventoryManager.cpp - newCommand();

invalid customer ID: InventoryManager.cpp - newCustomer();
 
invalid movie: InventoryManager.cpp - newMovie();

factory classes: None

hashtable: InventoryManager.h - customers_ - using an stl unordered_map to store customers

container used for comedy movies: InventoryManager - comedyInventory - using a vector of comdies

function for sorting comedy movies: overloaded < operator in Comedy.cpp

function where comedy movies are sorted: std::sort in InventoryManager.cpp

functions called when retrieving a comedy movie based on title and year: newCommand() InventoryManager: It checks against all comedy movies for the one matching.

functions called for retrieving and printing customer history: history() found in Customer.cpp

container used for customer history: vector<std::pair<Movie, std::string>> customerHistory found in Customer.h

functions called when borrowing a movie: borrowMovie() found in Customer.cpp

explain borrowing a movie that does not exist: Within newCommand() InventoryManager, there is an if statement for each movie type that checks if it exists or not. It then returns a bool value (True for does not exist), later there is a check against that bool value and if the value is true then it returns a error message.

explain borrowing a movie that has 0 stock: Within newCommand() InventoryManager, there is a if statement when borrowing, if the stock of the relevant movie type is not greater than 0, then it returns an error message.

explain returning a movie that customer has not checked out: Explain to the user by printing our to the console that there has been an error and the user is unable to return the movie.

any static_cast or dynamic_cast used: No


Q: Total points: 25 (max 25)