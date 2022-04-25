#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>

using namespace std;


struct Course{
    char *course_num;
    char *instruct_id;
    char *sect_id;
    char *term_id;
    char *grade;
};

struct Student{
    char *empl_id;
    struct Course course[3];
};


int main() {
    

    Course Course1;
    Course1.course_num = "1115";
    Course1.instruct_id = "I12";
    Course1.sect_id = "s10";
    Course1.term_id = "T04";
    Course1.grade = "A+";

    Course Course2;
    Course2.course_num = "3130";
    Course2.instruct_id = "E45";
    Course2.sect_id = "M09";
    Course2.term_id = "LO6";
    Course2.grade = "C";


    Student Student1;

   
    Student1.empl_id = "23805450";

    Student1.course[0]=Course1;
    Student1.course[4]=Course2;


    cout << Student1.course[0].course_num << endl;
    cout << Student1.course[4].course_num << endl;




}



