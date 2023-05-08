#include <stdio.h>
#include <stdlib.h>
#include "university.h"
//including string.h for strcmp
#include <string.h>
/*****************************************************************************
 * CS1050
 * FS2021
 * Lab 13 
 * By Ryan Milewski (rsmbby)
 * December 3, 2021
 *****************************************************************************/

// Stubs for functions you need to implement
Course GetCourseByDeptAndNumber(char * dept, int number)
{
    Course course={-1};
    //Create a pointer of type course (essentially an array) for each course.
    Course * fullcourselist;
    //load the course array with all of the courses using the API call
    fullcourselist = GetAllCourses();
    int counter = 0;
    //checking to see if we have reached the sentinel value course and if not then continue with the while loop.
    while(fullcourselist[counter].id != -1) {
        //if the courselist department matches with the given department using strcmp AND the number matches with the given number
        if((strcmp(fullcourselist[counter].dept,dept)==0) && (fullcourselist[counter].number==number)) {
            //copy that given course to our own course variable
            course = fullcourselist[counter];
        }
        counter++;
    }
    //return that given course variable.
    return course;
}

Course GetCourseByID(COURSE_ID id)
{
    Course course={-1};
    //following the same pattern as above, we will load the course array with all of the values.
    Course * fullcourselist;
    fullcourselist = GetAllCourses();
    int counter = 0;
    //following same pattern, looking until the id is equal to the sentinel value.
    while(fullcourselist[counter].id != -1) {
        //if the id equal to the given id passed into the function, then set that course equal to our created course as before.
        if(fullcourselist[counter].id == id) {
            course = fullcourselist[counter];
        }
        counter++;
    }
    //return the course variable to be printed.
    return course;
}

void PrintCourse(Course course)
{      
    //if the course value isn't the sentinel value, then print its values following JimR's formatting.
    if(course.id != -1) {
        printf("ID=%d,Name=%s,Dept=%s,Number=%d,Instructor=%s %s",course.id,course.name,course.dept,course.number,course.instructor_fname,course.instructor_lname);
    }
}


//////////////////////////////////////////////////////////////
// Stubs for bonus functions you may choose to implement
Student * GetStudentsByLastName(char * lname)
{   
    //same as above, we need a student array to hold all of the students.
    Student * fullstudentlist = GetAllStudents();
    int counter = 0;
    int studentcounter = 0;
    //going through each student until we hit the sentinel value.
    while(fullstudentlist[counter].number != -1) {
        //if the name in the array matches up with the given name passed in, add 1 to the counter so we can get how many names the pointer will hold
        if(strcmp(fullstudentlist[counter].lname,lname)==0) {
            studentcounter++;
        }
        counter++;
    }
    //create a pointer that will hold all of the names we are looking for and allocate memory for it. 
    //It will hold the number of students + 1 for the sentinel value of -1.
    Student * studentnames = malloc(sizeof(Student) * (studentcounter+1));
    //reset our counters to actually get names in our while loop.
    counter = 0;
    int arrcount = 0;
    //same syntax as above except, this time we will be actually storing the students in the pointer that was just created.
    while(fullstudentlist[counter].number != -1) {
    if(strcmp(fullstudentlist[counter].lname,lname)==0) {
        studentnames[arrcount] = fullstudentlist[counter];
        arrcount++;
    }
    counter++;
    }
    //add the sentinel value to the last value in the pointer.
    studentnames[arrcount].number = -1;
    //create a new pointer that is equal to the malloc'ed pointer so it's memory can be freed.
    Student * studentarrfinal = studentnames;
    free(studentnames);
    //return our pointer
    return studentarrfinal;
}

// For Honors students, you must also implement this function if you want bonus points
Student * GetStudentsByFirstAndLastName(char * fname, char * lname)
{
    //This function is the exact same as the above function except in two spots which I will specify.
    Student * fullstudentlist = GetAllStudents();
    int counter = 0;
    int studentcounter = 0;
    while(fullstudentlist[counter].number != -1) {
        //Here is one spot, where instead of just matching up the last name, we match up the first and last name.
        if((strcmp(fullstudentlist[counter].lname,lname)==0) && (strcmp(fullstudentlist[counter].fname,fname)==0)) {
            studentcounter++;
        }
        counter++;
    }
    Student * studentnames = malloc(sizeof(Student) * (studentcounter+1));
    counter = 0;
    int arrcount = 0;
    while(fullstudentlist[counter].number != -1) {
    //Here is the other difference, where we match up the first and last name again.
    if((strcmp(fullstudentlist[counter].lname,lname)==0) && (strcmp(fullstudentlist[counter].fname,fname)==0)) {
        studentnames[arrcount] = fullstudentlist[counter];
        arrcount++;
    }
    counter++;
    }
    studentnames[arrcount].number = -1;
    Student * studentarrfinal = studentnames;
    free(studentnames);
    return studentarrfinal;
}
/////////////////////////////////////////////////////////////////



// main() - Don't change this
int main(int argc, char * argv[])
{
    Course c;

    printf("Test #1:\n");
    c=GetCourseByID(5);
    PrintCourse(c);

    printf("\nTest #2:\n");
    c=GetCourseByID(11);
    PrintCourse(c);

    printf("\nTest #3:\n");
    c=GetCourseByID(999);
    PrintCourse(c);

    printf("\nTest #4:\n");
    c=GetCourseByDeptAndNumber("CS",1050);
    PrintCourse(c);

    printf("\nTest #5:\n");
    c=GetCourseByDeptAndNumber("STAT",4540);
    PrintCourse(c);

    printf("\nTest #6:\n");
    c=GetCourseByDeptAndNumber("ZZZZZZZZ",1050);
    PrintCourse(c);

    printf("\nTest #7:\n");
    c=GetCourseByDeptAndNumber("CS",999999);
    PrintCourse(c);

    /////////////////////////////
    // OPTIONAL BONUS TESTS
    /////////////////////////////
    Student * s;
    printf("\nTest #8:\n");
    s=GetStudentsByLastName("Ries");
    PrintStudents(s);

    printf("\nTest #9:\n");
    s=GetStudentsByLastName("Walkenhorst");
    PrintStudents(s);

    printf("\nTest #10:\n");
    s=GetStudentsByLastName("ZZZZZZZZZZZ");
    PrintStudents(s);

    printf("\nTest #11:\n");
    s=GetStudentsByFirstAndLastName("Charlotte","Ries");
    PrintStudents(s);
    /////////////////////////////
    /////////////////////////////

    return 0;
}
