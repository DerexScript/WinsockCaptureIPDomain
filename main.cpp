#include <winsock2.h>
#include <windows.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
    char      url[MAX_PATH];
    HOSTENT*  hostent;
    WSADATA   wsadata;
    IN_ADDR   addr;

    // intialize WSA Sockets
    if (WSAStartup(MAKEWORD(2,0),&wsadata)){
        cout << "WSA Startup Error" << endl;
        exit(1);
    }

    if (!argv[1]){
        cout << "Enter the URL to lookup : ";
        cin >> url;
        cout << endl;
    }else
      strcpy(url,argv[1]);

    // get HOSTENT data
    hostent = gethostbyname(url);
    if (hostent == NULL){
        cout << "Unresolvable host name" << endl;
        exit (1);
    }

    // extract main IP address
    addr.S_un.S_addr = *(ULONG*)hostent->h_addr_list[0];
    cout << "IP Address is : " << inet_ntoa(addr) << endl << endl;

    // release WSA
    WSACleanup();
    cout << "Press ENTER to continue...";
    cin.clear();
	cin.sync();
	cin.get();
    return 0;
}
