#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <fstream>

#include"Contact.h"
#include"ContactList.h"
#include"string_tools.h"
#include"string_tools.cpp"

int main(int argc, char *argv[])
{
    ContactList object;
    string data;
    string data2;

    char delimiter = ',';
    char delimiter2 = ' ';
    ifstream inFile;
    ofstream outFile;
    //to check how arguments are there
    if ( argc == 3 ) 
    {
        //opening the first argv
        ifstream inFile ( argv[1] );
        if(inFile.is_open())
        while (getline(inFile,data))
        {

            vector<string> temp=split(data,delimiter);
            //making new data base and adding elements one by one
            Contact newContact( temp[0],  temp[1], stoul(temp[2]), stoul(temp[3]), stoul(temp[4]));
            object.add(newContact);
        }
        // object.add(newContact);
       //opening the second argv
        ifstream inFile2 ( argv[2] );
        if(inFile2.is_open())
        while (getline(inFile2,data2))
        {
            vector<string> temp=split(data,delimiter2);
            //checking if add is there calling the function add
            if(temp[0]=="A")
            {
                vector<string> temp1=split(temp[1],delimiter);   
                Contact newContact(temp1[1], (temp1[2]), stoul(temp1[3]), stoul(temp1[4]),stoul(temp1[5]));

                object.add(newContact);   
            }
            //checking if keyword find is there calling the function get entry after checking by contains
            else if(temp[0]=="F")
            {
                int x =object.contains(temp[1]);
                if(x==true)
                {
                    object.getEntry(temp[1]);
                }
                else
                cout<<"  Not found.";
            }
            //checking if keyword delete is there calling the function delete after checking by contains
            else if (temp[0]=="D")
            {
                int x =object.contains(temp[1]);
                if(x==true)
                    object.remove(temp[1]);
                else 
                    cout<<"  Not found.";       
            }
            //checking if keyword delete all is there calling the function delete all after checking by contains
            else if (temp[0]=="R")
            {
                  int x =object.contains(temp[1]);
                if(x==true)
                    object.removeAll(temp[1]);
                else 
                    cout<<"  Not found.";             
            }
            //Display all the the contents of the database
            else if (temp[0]=="S")
            {
                object.display();            
            }
            
        }
        
    }
  
    // ofstream writeFile("Contact.txt");
    // writeFile.is_open();
    // vector<Contact> data = object.write();
    // for (auto it = data.begin() ; it != data.end(); ++it)
    // {
    //     writeFile << it->getFname()<<","<<it->getLname()<<","<<" "<<it->getBmonth()<<","<<it->getBday()<<","<<it->getByear()<<std::endl;

    // }
    // writeFile.close();




}