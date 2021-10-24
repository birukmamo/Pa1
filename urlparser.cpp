#include <iostream>
#include <string>
//#include "version.h"


using namespace std;

int main()
{
    //dispalyVersion();
	string urlToParse;         		//hold the input url from the user input 
    string address, address2;        //hold the address of the domain and the file path
    bool isprotocol, isport, ishost, isfilepath; //boolean used to check the component
	
	//promt the user to input the url
	cout << "Enter Url to find the components: " << endl;
    cin >> urlToParse;		//enter the url
	cout << endl;
	
	//take the protocol from the url
	string protocol = urlToParse.substr(0, urlToParse.find("://")); 
	
	// Check if protocol name if it is valid
	if (protocol == "http" || protocol == "https" || protocol == "ftps" || protocol == "ftp")
	{
        isprotocol = true;
	}//endif

	// create new string with out the protocol
	string urlParse2 = urlToParse.substr(urlToParse.find("://") + 3);
	// find the domain
	string domain = urlParse2.substr(0, urlParse2.find("/"));

	int port = stoi(domain.substr(domain.find(":") + 1));

	if (port >= 1 && port <= 65535)
		isport = true;

	domain = domain.substr(0, domain.find(":"));
    int count = 0;
    for(int i=0; i < domain.length(); i++)
    {
        if(domain[i] == '.')
           {
            count = count + 1;
            if(count == 2)
            {
                address = domain.substr(i+1, domain.length());
                if(address == "com" || address == "edu" || address == "gov"
                   || address == "net" || address == "biz")
                    {
                      ishost = true;
                      break;
                    } 
               
            }//endif
        }//endif
    }//endfor
	
	//take the componet by droping the domain, port
	string urlParse3 = urlParse2.substr(urlParse2.find("/") + 1);
     
	string filePath = urlParse3.substr(0, urlParse3.find("?"));
    for(int i=0; i< filePath.length(); i++)
    {
    if(filePath[i] == '.')
     {  
        address2 = filePath.substr(i+1, filePath.length());	
        if (address2 == "html" || address2 == "htm")
        {
        isfilepath = true;
        break;
        }//endif
       }//endif
    }//endif
	
	//take the parameter only
	string parameters = urlParse3.substr(urlParse3.find("?") + 1);
	
	//print the output to dispaly to the terminal
    if(isprotocol == true && isport == true && ishost == true && isfilepath == true)
    {
		cout << endl;
		cout << "Protocol\t : " << protocol << endl;
		cout << "Domain\t\t : " << domain << endl;
		cout << "Port\t\t : " << port << endl;
		cout << "File Path\t : " << filePath << endl;
		cout << "Parameters\t : " << parameters << endl;
    }
    else
    {
        if(isprotocol == false)
            cout << "Protocol\t " << protocol <<" is not a valid protocol" << endl;
        if(isport == false)
            cout << "Port number must be between 1 and 65535" << endl;
        if(ishost == false)
            cout << "Domain \t" << address << " is an invalid domain name" << endl;
        if(isfilepath == false)
            cout << "File Path\t " << address2 << " is not valid" << endl;
}
return 0;
}





