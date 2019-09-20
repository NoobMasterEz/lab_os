

#include "all_lab.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

 
int main()
{
char choice;
char x;
bool gameOn = true;
while (gameOn != false){
cout << "\n *******************************\n";
cout << " 1 -Non_preemptive.\n";
cout << " 2 - preemptive.\n";
cout << " 3 - Round_Robin.\n";
cout << " 4 - priority.\n";
cout << " Enter your choice and press return: ";

cin >> choice;

switch (choice)
{
	case '1':
		
		
	 	main_Non_preemptive();
   


		
		
		break;
	case '2':
		main_preemptive();
		break;
	case '3':
		main_Round_Robin();
		break;
	case '4':
	 main_priority();
		break;
	case '5':
		blanker();
		break;
	case 'q':
		gameOn=false;
		break;
	default:
		cout << "Not a Valid Choice. \n";
		cout << "Choose again.\n";
		cin >> choice;
		system ("clear");
		break;
}

}
return 0;
}