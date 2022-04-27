#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <map>
#include <set>
#include <sstream>
#include <ctime>
#include <unordered_set>
#include <algorithm>



using namespace std;


struct Course{
    string  course_num;
    string  instruct_id;
    string  sect_id;
    string  term_id;
    string  grade;
};

struct Student{
    string  empl_id;
    Course course;
};

void readFile (vector <Student>& uAlbany,ofstream& out_stream, string line,set < string >& sInstructor,
  set < string >& sCourseNo, set < string >& sGrade);
bool didPass(string grade);
void passRateInstr(vector<Student> uAlbany,ofstream& out_stream, set <string> sets);


int main() {

string emplid,courseno,instructorid,termid,sectionid,grade;
ifstream in_stream;
ofstream out_stream;
out_stream.open("output.txt"); // opening output file
vector <string> files;
vector <Student> uAlbany;
set < string > sInstructor;
set < string > sCourseNo;
set < string > sGrade;

files.push_back("./data/d279545d975c1652689e8195e2426adf/1115.csv");
files.push_back("./data/d279545d975c1652689e8195e2426adf/3115.csv");
files.push_back("./data/d279545d975c1652689e8195e2426adf/3130.csv");

 for (int x =0; x < 3; x++){
   cout << "file opened " << files[x]<<endl;
   readFile(uAlbany,out_stream,files[x],sInstructor,sCourseNo, sGrade);
   
   
 }

 passRateInstr(uAlbany,out_stream,sInstructor);

 


 }



void readFile(vector<Student>& uAlbany,ofstream& out_stream,string file,set < string >& sInstructor,
  set < string >& sCourseNo, set < string >& sGrade){

   string emplid,courseno,instructorid,termid,sectionid,grade;
   ifstream file_reader;
   file_reader.open(file);
   Course course1;
   Student student;
   int count = 1;
   string lines;
   getline(file_reader,lines);
   while(file_reader.good()){

     getline(file_reader,emplid,',');
     student.empl_id = emplid;

     getline(file_reader,courseno,',');
     student.course.course_num = courseno;
     sCourseNo.insert(courseno);

     getline(file_reader,instructorid,',');
     student.course.instruct_id = instructorid;
     sInstructor.insert(instructorid);


     getline(file_reader,termid,',');
     student.course.term_id = termid;

     getline(file_reader,sectionid,',');
     student.course.sect_id = sectionid;

     getline(file_reader,grade,'\n');
     student.course.grade = grade;
     sGrade.insert(grade);

     uAlbany.push_back(student);
     count ++;
     
     
   }


   

  // cout << " *******************************"<<endl;
  // cout << "\n current size " << uAlbany.size() << endl;
   






 }

bool didPass(string grade){
     vector <string> psG;
     psG.push_back("A+");
     psG.push_back("A");
     psG.push_back("A-");
     psG.push_back("B+");
     psG.push_back("B");
     psG.push_back("B-");
     psG.push_back("C+");
     psG.push_back("C");
     psG.push_back("C-");
     psG.push_back("CR");
     psG.push_back("D+");
     psG.push_back("D");
     psG.push_back("D-");
     psG.push_back("P");
     

     if (find( psG.begin(), psG.end(), grade) != psG.end() ){
       return true;
     }
     return false;

   }

void passRateInstr(vector<Student> uAlbany,ofstream& out_stream, set <string> sets){
     
     set <string>::iterator itr;

     cout << "\n********** Pass Rates By Instructor ***********\n" << endl;



     for (itr = sets.begin(); itr != sets.end(); itr++){
       //grabs first instruster from set
       double ttl_students = 0;
       double passed =0; 

       for(int j =0; j < uAlbany.size(); j++){
         //itereates through ualbany database


         if (*itr == uAlbany[j].course.instruct_id){
           //compares ualbany database to find intrustur grabbed from set

           ttl_students++;


           if(didPass(uAlbany[j].course.grade)){
             passed++;
            // cout << uAlbany[j].course.grade <<endl;

           //end of 4th loop
           }

        //end of third loop
         }

      // end of second loop
       }
       double passRate =  passed/ttl_students;

       cout <<"Instructor # " << *itr << " pass rate is : " << passRate << endl;
       

    //end of first loop
     }


     

     


   }


