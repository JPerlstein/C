/********************
Program reads student's scores & outputs student's records.
Student records consist of 2 quizzes, 2 exam scores, student's-
average numeric score for the entire course & the final letter grade.
*********************/
#include <stdio.h>

// type descriptions.
struct StudentRecord
{
  int studentNumber;
  int quiz1;
  int quiz2;
  char finalGrade;
  int midExam;
  int finalExam;
  float numericAverage;
};
struct StudentRecord recStudent[5];

void input(struct StudentRecord *student);
void computeGrade(struct StudentRecord *student);
void output(const struct StudentRecord student);

int main()
{

  for (int i = 0; i < 5; i++)
  {
    input(&recStudent[i]);
    // computeGrade(& recStudent[i]);
    // output(recStudent[i]);
  }

  for (int i = 0; i < 5; i++)
  {
    computeGrade(&recStudent[i]);
  }

  for (int i = 0; i < 5; i++)
  {
    output(recStudent[i]);
  }
  return 0;
}
// prompts input for one student & set structure variable members.
void input(struct StudentRecord *student)
{
  printf("Please enter student number:\n");
  scanf("%d", &student->studentNumber);

  printf("Please enter two 10 point quizzes:\n");
  scanf("%d %d", &student->quiz1, &student->quiz2);

  printf("Please enter midterm and final exam grades. These are 100 point tests:\n");
  scanf("%d %d", &student->midExam, &student->finalExam);
}
// calculates numeric average & letter grade.
void computeGrade(struct StudentRecord *student)
{
  int sum = student->quiz1 + student->quiz2;

  // calculating numeric average score.
  student->numericAverage = ((float)sum * 25 / 20) + ((float)(student->midExam) * 25 / 100) + ((float)(student->finalExam) * 50 / 100);

  if (student->numericAverage > 90)
  {
    student->finalGrade = 'A';
  }
  else if ((student->numericAverage >= 80) && (student->numericAverage < 90))
  {
    student->finalGrade = 'B';
  }
  else if ((student->numericAverage >= 70) && (student->numericAverage < 80))
  {
    student->finalGrade = 'C';
  }
  else if ((student->numericAverage >= 60) && (student->numericAverage < 70))
  {
    student->finalGrade = 'D';
  }
  else if (student->numericAverage < 60)
  {
    student->finalGrade = 'F';
  }
}
// outputs student record.
void output(const struct StudentRecord student)
{
  printf("The record for student number: %d\n", student.studentNumber);

  printf("The quiz grades are: %d %d\n", student.quiz1, student.quiz2);

  printf("The midterm and exam grades are: %d %d\n", student.midExam, student.finalExam);

  printf("The numeric average is: %.2f\n", student.numericAverage);

  printf("and the letter grade assigned is %c\n", student.finalGrade);

  printf("\n");
}
