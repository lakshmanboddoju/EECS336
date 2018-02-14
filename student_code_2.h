///////////////////////////////////////////////////////////////////////////////
// You need to 
//    1. Read Problem 3 in homework assignmnet #2. 
//    2. Implement function GetStudentName.
//    3. Implement function CountNUOccurrences.
//    4. Compile your code as explained in the PDF file.
//    5. Run the executable.
//    6. Test and debug your code.
//    7. Submit your code ("student_code_2.h") and results ("solution_2.dat") 
//       via Canvas.
//
///////////////////////////////////////////////////////////////////////////////

//required libraries
#include <string>

//you can include standard C++ libraries here



// This function should return your name.
// The name should match your name in Canvas

void GetStudentName(std::string& your_name)
{
   //replace the placeholders "Firstname" and "Lastname"
   //with you first name and last name 
   your_name.assign("Lakshman Pavan Kumar Boddoju");
}

//This is the function you need to implement.
int CountNUOccurrences(std::string message)
{
    int occurence = 0;
    int length = message.length();
    for (int i=0; i<length; i++)
    {
        if(message[i]=='N' && message[i+1]=='U')
            occurence++;
    }

   /* return your result */;
   return occurence;
}
