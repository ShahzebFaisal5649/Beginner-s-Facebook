#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	string nm[10];

	cout << "================ Friends List ================" << endl;
	ifstream myfile("names.txt", ios::in);
	if (myfile.is_open())
	{
		while (!myfile.eof())
		{
			for(int i =0 ; i <  10 ;i++)
			{                             // names file se data le rha
				myfile >> nm[i];
			}
		}
	}
	else
	{
		cout << "Unable To Read File" << endl;
	}
	myfile.close();
	
	for(int i =0 ; i< 10 ; i++)
	{
		cout << nm[i] << endl;
	}

	cout << "================ Friend-ships ================ " << endl;
	// array initialize 
	int arr[100][100] = {
	{0, 1, 0, 1, 1, 0, 0, 1, 1, 0},
	{1, 0, 0, 1, 1, 1, 1, 0, 1, 1},
	{0, 0, 0, 0, 1, 1, 1, 1, 1, 1},
	{1, 1, 0, 0, 0, 0, 1, 1, 1, 1},
	{1, 1, 1, 0, 0, 1, 0, 1, 1, 1},                                              
	{0, 1, 1, 0, 1, 0, 0, 0, 1, 0},
	{0, 1, 1, 1, 0, 0, 0, 0, 0, 1},
	{1, 0, 1, 1, 1, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 0, 0, 0, 1},
	{0, 1, 1, 1, 1, 0, 1, 1, 1, 0},
	};

	for (int i = 0; i < 10; i++)
	{
	    cout<<"              ";
		for (int j = 0; j < 10; j++)
		{
			cout << arr[i][j] <<" ";
		}
		cout << endl;
	}

	char per1, per2;
	cout << "Enter ID of Person 1 :" << endl;
	cin >> per1;

	cout << "Enter ID of Person 2 :" << endl;
	cin >> per2;

	if((per1!=per2) && (per1>=48 &&  per1<58) && (per2>=48 && per2<58) )
	{                      
	    // check lgaya jo ke person1 or person2 ko check kre ga
		int person1; 
		person1 = ((int)per1); 
		person1 = person1 - 48;

        // again converting to int
		int person2 ; 
		person2 = ((int)per2);
		person2 = person2 - 48;

		for(int i= 0 ; i < 10 ;i++)
		{
			if(arr[person1][i] == 1 && arr[person2][i] == 1 )
			{
				ofstream file("mutualfriends.txt", ios::app);
				if (file.is_open())
				{
					file << endl << nm[i];                           //adding mutual friends to file
					cout << nm[i] << "\t" ;
					cout << "Friends Added Successfully! " << endl;
				}
				else
				{
					cout << "Unable To Read File" << endl;
				}
				file.close();
			}
		}
		cout << "Friends Suggestion To PERSON 1 "<<endl;
		for(int i =0 ; i < 10 ;i++)
		{
			if((arr[person2][i] == 1) &&  arr[person1][i] == 0  )
			{
				cout <<"Friends : " << i << " : " << nm[i] << endl;
				int temp;
				temp = i;
				for(int k =0 ; k< 10 ;k++)
				{
					if(arr[temp][k]==1 && arr[person1][k] == 0 )
					{
						cout<<  "Friends Of Friends :" <<  k << " : " << nm[k] << endl;
					}
				}
			}
		}
		int opt;
		cout << "If You Want To Make New Friends?" << endl;
		cout << "Press 1 For Yes! "<< endl;
		cout << "Press 2 For No! "<< endl;
		cin >> opt;
        cout<<"=========================================="<<endl;
		if(opt == 1)
		{
			int id;
			cout << "Enter The ID From Above : " <<endl;
			cin >> id;
			
			arr[person1][id] = 1;
			arr[id][person1] = 1;
			
			cout << "Friends Added Successfully! " << endl;
			string com = " , ";
			
			ofstream Myfile("friends.txt", ios::app);
			if (Myfile.is_open())
			{
				Myfile << person1 << com  << id << endl;
			}
			else
			{
				cout << "Unable To Read File" << endl;
			}
			for(int i =0 ;i<10;i++)
			{
			    cout<<"              ";
				for(int j =0 ;j < 10 ;j++)
				{
					cout << arr[i][j] << " ";
				}
				cout << endl;
			}
		}
		else
		{
			cout << "No Friends Made " << endl;
		}
		cout << "Friends Suggestion To PERSON 2 "<<endl;
		for(int i =0 ; i < 10 ;i++)
		{
			if((arr[person1][i] == 1) &&  arr[person2][i] == 0)
			{
			    cout <<"Friends : " << i << " : " << nm[i] << endl;
				int temp;
				temp = i;
				for(int k =0 ; k< 10 ;k++)
				{
					if(arr[temp][k]==1 && arr[person2][k] == 0 )
					{
						cout<<  "Friends Of Friends :" <<  k << " : " << nm[k] << endl;
					}
				}
			}
		}
		int option;
		cout << "Press 1 For Yes! "<< endl;
		cout << "Press 2 For No! "<< endl;
		cin >> option;
        cout<<"=========================================="<<endl;
		
		if(option == 1)
		{
			int id;
			cout << "Enter The Id From Above : " <<endl;
			cin >> id;
			
			arr[person2][id] = 1;
			arr[id][person2] = 1;
			cout << "Friends Added Successfully! " << endl;
			
			for(int i =0 ;i<10;i++)
			{
			    cout<<"              ";
				for(int j =0 ;j < 10 ;j++)
				{
					cout << arr[i][j] << " ";
				}
				cout << endl;
			}
		}
		else
		{
			cout << "No Friends Made " << endl;
		}
	}
	else 
	{
		cout << "Enter Valid Entries" << endl;
	}
	cout<<"=========================================="<<endl;
	system("pause");
	return 0;
}
