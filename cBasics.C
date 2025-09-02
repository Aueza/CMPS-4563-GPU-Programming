// C Basics, very similiar to C++.

#include <stdio.h>

// Example of a struct.
struct Student{
    int studentID;
    short year;
    float gpa;
};

int main(){
    char name[50];
    scanf("%c", &name);
    printf("Hello, %c", name);

    return 0;
}