///////////////////////////////////////////////////////////////////////////////
// You need to 
//    1. Read Problem 3 in homework assignmnet #3. 
//    2. Implement function GetStudentName.
//    3. Implement function SplitMessage.
//    4. Compile your code as explained in the PDF file.
//    5. Run the executable.
//    6. Test and debug your code.
//    7. Submit your code ("student_code_3.h") and results ("solution_3.dat") 
//       via Canvas.
//
///////////////////////////////////////////////////////////////////////////////

// Required libraries.
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// You can include standard C++ libraries here.


// This function should return your name.
// The name should match your name in Canvas.
void GetStudentName(std::string& your_name)
{
  
    your_name.assign("Lakshman Pavan Kumar Boddoju");
}

//This is the function you need to implement.
int SplitMessage(std::string message, int packet_size)
{

//If message in nil return 0
   if(message.empty())
   {
        return 0;
    }

    int i = 0, j = 0;
    int num_packets = 0;
    int substring_total = 0;
    int substring_length = 0;
    
    vector<int> pos_space;
    pos_space.clear();

    //This is using space as a delimiter and collecting the positions of all the spaces.
    for(i = 0; i < message.length(); i++)
    {
        if(message[i] == ' ')
        {
            pos_space.push_back(i);
        }
    }

    pos_space.push_back(message.length());


    //If the message is more than the packet size and there is only one word, then return 0.
    if (message.length() > packet_size && pos_space.size() == 1)
    {
        return 0;
    }

    //If the whole message is smaller than the packet size, then return amount of packets required as 1.
    if (message.length() <= packet_size)
    {
        return 1;
    }

	i = 0;
    while(i < pos_space.size()) 
    {
        if (i == 0)
		{
			substring_length = pos_space[i]; //first word.
		}
		else
		{
			substring_length = pos_space[i] - pos_space[i - 1]; //subsequent words.
			
			//if any word is longer than packet size, then return 0.
			if (substring_length > packet_size+1)
			{
				return 0;
			}
    	}
		substring_total = substring_total+substring_length; //This is combining words, to see whether multiple words can be sent in a same packet.
        
        if(substring_total > packet_size) //If multiple words are bigger than the packet size, then dont combine the words and send packet.
        {                       
            num_packets++;
            substring_total = pos_space[i] - pos_space[i - 1] - 1; //Current position becomes the first letter of next word
        }
        
        i++;
    }
    return num_packets + 1; //Returns packet number. Add one for last packet without space.
}
