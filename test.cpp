#include <iostream>

void testThisMess() {
    sqlite3_open("ASCIIdatabase.db", &db);
    std::cout << "Database connection opened" << std::endl;
}

UPDATE (table name) SET (column name) = (value or ?) WHERE (conditions)