#include <iostream>
#include <string>
#include <cctype>
	using namespace std;

	int main()
	{
		// 1. 1
		// 2. *
		// 2. **
		// 2. 3,4,6
		// 3. 7
		// 4. 4
		// 5. 1
		// 6. 4
		// 7.
		// int score = 0;
		// cout << "Please enter the student's score:";
		// cin >> score;

		// int grade;
		// if (score >= 90 && score <= 100)
		// {
		// 	grade = 4;
		// }
		// else if (score >= 80)
		// {
		// 	grade = 3;
		// }
		// else if (score >= 70)
		// {
		// 	grade = 2;
		// }
		// else if (score >= 60)
		// {
		// 	grade = 1;
		// }
		// else 
		// {
		// 	grade = 0;
		// }
		// switch (grade)
		// {
		// 	case 4:
		// 		cout << "A" << endl;
		// 		break;
		// 	case 3:
		// 		cout << "B" << endl;
		// 		break;
		// 	case 2:
		// 		cout << "C" << endl;
		// 		break;
		// 	case 1:
		// 		cout << "D" << endl;
		// 		break;
		// 	case 0:
		// 		cout << "F" << endl;
		// 		break;
		// } 
		// 8. 
		int i;
		string str;
		cout << "enter: " << endl;
		cin >> str;

		i = 0;
		char lowercase = '*';
		do 
		{
			if(islower(str[i]))
			{
				break;
			}
			i++;
		}
		while(i < str.size());

		if (i == str.size())
		{
			cout << "No lowercase character." << endl;
		}
		else
		{
			cout << str[i] << endl;
		}
		return 0;
	}