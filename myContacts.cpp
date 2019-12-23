

	#include "ContactList.h"

	using namespace std;

	int main(int argc, char* argv[])
	{
		string dataFile, operationFile, input;
		char delimiter = ',';
		ifstream data, operation;
		vector<string> listOfTokens;
		unsigned flag=1;
		char *Quote	=	new char[2];  //character to print double quotes
		Quote[0]	=	34;  // ascii for quote
		Quote[1]	=	0;


		dataFile = argv[1];
		operationFile = argv[2];

		string contactF,contactL;
		unsigned contactM,contactD,contactY;

		ContactList CL;

		data.open(dataFile);

		if(data.is_open())
		{
			while(getline(data, input))
			{
				listOfTokens = split( input , delimiter );
	
				for(unsigned j=0;j<listOfTokens.size();j++)
				{
					if(flag==1)
					{
						contactF = listOfTokens[j];
						flag=2;
					} 
					else if(flag==2)
					{
						contactL = listOfTokens[j];
						flag=3;
					}
					else if(flag==3)
					{
						contactM = stoi(listOfTokens[j]);
						flag=4;
					}
					else if(flag==4)
					{
						contactD = stoi(listOfTokens[j]);
						flag=5;
					}
					else if(flag==5)
					{
						contactY = stoi(listOfTokens[j]);
						flag=1;
					}
				}
				Contact ct(contactF,contactL,contactM,contactD,contactY); //adding contact object to database
				CL.add(ct);
			}
	
			data.close();
		}
		else
		{
			//cout<<"Error opening File"<<endl;
		}

		cout<<"Loaded "<<CL.getSize()<< " records into contact list."<<endl;

		operation.open(operationFile);
		listOfTokens.clear();
		delimiter = ' ';


		if(operation.is_open())
		{
			while(getline(operation, input))
			{
				listOfTokens = split( input , delimiter );
					
				for(unsigned j=0;j<listOfTokens.size();j++)
				{
					int switchch;  //variable to store commands of all the operations
					if(removeSpecials(listOfTokens[0])=="S")
					{
						switchch = 1;
					}
					else if(removeSpecials(listOfTokens[0])=="F")
					{
						switchch = 2;
					}
					else if(removeSpecials(listOfTokens[0])=="A")
					{
						switchch = 3;
					}
					else if(removeSpecials(listOfTokens[0])=="D")
					{
						switchch = 4;
					}
					else if(removeSpecials(listOfTokens[0])=="R")
					{
						switchch = 5;
					}

					switch(switchch)  //switch cases to handle all the operations
					{
						case 1: CL.displayDatabase();
						break;
						case 2: {
							cout<<"Find ";
							cout<<Quote;
							cout<<listOfTokens[1];
							cout<<Quote;
							cout<<endl;
							if(CL.contains(removeSpecials(listOfTokens[1])) == false)  //To check if perticular object exists in the database
							{
								cout<<"  "<<"Not found."<<endl;
							}
							else
							{
								cout<<"  "<<"Found."<<endl;
								for(auto x=CL.getEntry(removeSpecials(listOfTokens[1])).begin(); x != CL.getEntry(removeSpecials(listOfTokens[1])).end(); ++x)
								{
									cout<<"  "<<(*x).getFirstName()<<" ";
									cout<<(*x).getLastName()<<", ";
									cout<<(*x).getBirthMonth()<<"/"<<(*x).getBirthDay()<<"/"<<(*x).getBirthYear()<<endl;
								}
							}
							break;
						}
						case 3:{
							cout<<"New contact added"<<endl;
							char delimiter1 = ',';
							string input1 = listOfTokens[1];
							vector<string> listOfToken;
				
							listOfToken = split(input1,delimiter1);
							contactF = removeSpecials(listOfToken[0]);
							contactL = removeSpecials(listOfToken[1]);
							contactM = stoi(removeSpecials(listOfToken[2]));
							contactD = stoi(removeSpecials(listOfToken[3]));
							contactY = stoi(removeSpecials(listOfToken[4]));

							Contact kt(contactF,contactL,contactM,contactD,contactY);
							CL.add(kt); //adding new contact object into database
							cout<<"  "<<kt.getFirstName()<<" ";
							cout<<kt.getLastName()<<", ";
							cout<<kt.getBirthMonth()<<"/"<<kt.getBirthDay()<<"/"<<kt.getBirthYear()<<endl;
							listOfToken.clear();
							break;
						}
						case 4:{
							cout<<"Delete \""<<listOfTokens[1]<<"\""<<endl;
							if(CL.contains(removeSpecials(listOfTokens[1])) == false)
							{
								cout<<"  "<<"Not found."<<endl;
							}
							else
							{
								set<Contact> temp = CL.getEntry(removeSpecials(listOfTokens[1]));
								if(temp.size()==1)
								{
									auto itu = temp.begin();
									cout<<"  "<<(*itu).getFirstName()<<" ";
									cout<<(*itu).getLastName()<<", ";
									cout<<(*itu).getBirthMonth()<<"/"<<(*itu).getBirthDay()<<"/"<<(*itu).getBirthYear()<<endl;
									CL.remove(removeSpecials(listOfTokens[1])); //removing single record with specified key
									cout<<"  "<<"Done."<<endl;
								}
								else
								{
									cout<<"  "<<"Multiple matches for \""<<listOfTokens[1]<<"\""<<endl;
									for(auto itv = temp.begin(); itv!=temp.end();itv++)
									{
										cout<<"  "<<(*itv).getFirstName()<<" ";
										cout<<(*itv).getLastName()<<", ";
										cout<<(*itv).getBirthMonth()<<"/"<<(*itv).getBirthDay()<<"/"<<(*itv).getBirthYear()<<endl;		
									}
									cout<<"  "<<"Not done."<<endl;
								}
							}
							break;
						}
						case 5:{
							cout<<"Remove \""<<listOfTokens[1]<<"\""<<endl;
							set<Contact> tempo = CL.getEntry(removeSpecials(listOfTokens[1]));
							for(auto itd = tempo.begin(); itd!=tempo.end();itd++)
							{
								cout<<"  "<<(*itd).getFirstName()<<" ";
								cout<<(*itd).getLastName()<<", ";
								cout<<(*itd).getBirthMonth()<<"/"<<(*itd).getBirthDay()<<"/"<<(*itd).getBirthYear()<<endl;		
							}
							CL.removeAll(removeSpecials(listOfTokens[1]));  //Removing all the records with similar key
							cout<<"  "<<"Done."<<endl;
							break;
						} 
					}
					break;
				}
			}
		}
		else
		{
			cout<<"Error opening File"<<endl;
		}

		cout<<"Wrote "<< CL.getSize() <<" records from contact list.";

		CL.getFinal("contacts.txt");  //writing the contents of final vector of contacts after perfoming all the operations
		
		cout<<endl;
		return 0;
			
	}