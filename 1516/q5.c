#include <stdio.h>

void grade(double numberGrade) {
  char letterGrade;
  if (numberGrade >= 90) {
    letterGrade = 'A';
  } else if (numberGrade >= 80) {
    letterGrade = 'B';
  } else if (numberGrade >= 70) {
    letterGrade = 'C';
  } else if (numberGrade >= 60) {
    letterGrade = 'D';
  } else {
    letterGrade = 'F';
  }
  printf("Letter grade for %5.1f is %c\n", numberGrade, letterGrade);
}

int main(void) {
  grade(54.);
  grade(100.);
  return 0;
}
