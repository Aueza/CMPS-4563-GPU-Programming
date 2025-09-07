// C Basics, very similiar to C++.

#include <stdio.h>
#include <stdlib.h>

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
void printPoints(struct Point *p, int size){
    for(int i = 0; i < size; i++)
        printf("(%d, %d)\n", p[i].x, p[i].y);
}

void shiftPoints(struct Point *p, int size, int xShift, int yShift){
    for(int i = 0; i < size; i++){
        p[i].x += xShift;
        p[i].y += yShift;
    }
}

int main(){
    // Creating file pointer and opening file.
    FILE *fp;
    int num;
    fp = fopen("pointData.txt", "rb");

    // Error handling for file open.
    if (fp == NULL){
        puts ("Cannot open file");
        return 1;
    }

    int x,y,s;
    struct Point *p1;
    struct Point *p2;
    // Dynamically allocating memory for Point structs.
    fscanf(fp, "%d", &s);
    p1 = new struct Point[s];
    p2 = new struct Point[s];

    // Reading point data from file.
    for(int i = 0; i < s; i++){
        fscanf(fp, "%d", &x);
        fscanf(fp, "%d", &y);
        buildPoint(&p1[i], x, y);
        buildPoint(&p2[i], x, y);
    }

    printPoints(p1, s);
    shiftPoints(p2, s, rand()%10, rand()%10);
    printf("Shifted Points:\n");
    printPoints(p2, s);
    

    // Closing file.
    fclose(fp);
    return 0;
}