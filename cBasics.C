// C Basics, very similiar to C++.

#include <stdio.h>

// Example of a struct.
struct Point{
    int x;
    int y;
};

/// @brief Constructor-like function to initialize a Point struct.
/// @param p pointer to the Point struct to initialize.
void initPoint(struct Point *p){
    p->x = 0;
    p->y = 0;
}

/// @brief Parameterized constructor-like function to initialize a Point struct.
/// @param p pointer to the Point struct to initialize.
/// @param x x value/coordinate.
/// @param y y value/coordinate
void buildPoint(struct Point *p, int x, int y){
    p->x = x;
    p->y = y;
}

/// @brief Function to print the values of a Point struct.
/// @param p pointer to the Point struct to print.
void printPoint(struct Point *p){
    printf("Point(%d, %d)\n", p->x, p->y);
}


int main(){
    char name[50];
    scanf("%s", &name);
    printf("Hello, %s", name);

    return 0;
}