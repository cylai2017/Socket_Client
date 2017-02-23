
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>


int main(int argc, const char * argv[]) {
    // Instance socket
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    
    // Client sends the request to the server(designated IP and port)
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));  //Use 0 to fill every character
    server_address.sin_family = AF_INET;  //Use IPv4 address
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");  //Enter the IP address
    server_address.sin_port = htons(1234);  //port
    /* connect() function
     header file : #include <sys/socket.h>
     function definition : int connect(int sockfd, struct sockaddr * serv_addr, int addrlen);
     */
    connect(client_socket, (struct sockaddr*)&server_address, sizeof(server_address));
    
    //----------------------------------------------------------------------------------------
    
    //Read the data which were transferred by server
    char data[100];
    read(client_socket, data, sizeof(data)-1);
    
    printf("Message form server: %s\n", data);
    
    close(client_socket);
    return 0;
}
