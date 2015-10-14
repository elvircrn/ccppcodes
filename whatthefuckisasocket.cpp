/*
protols -> specify interactions between the communication entities.

socket  -> a way to speak to other programs using standard unix file descriptors

SOCK_STREAM -> stream socket

* reliable 2 way communication stream
* use a protocol called Transmission Control Protocol
    * data arrives sequentially and error-free
* note: IP is not responsible for data integrity (deals with internet routing

SOCK_DGRAM  -> datagram socket (connectionless sockets)

* data may arrive out of order
* use IP for routing
* don't use TCP
* connectionless: don't have to maintain an open connection
* used when TCP stack is not available
* UDP (user datagram protocol) -> doesn't break down data into pieces
    *
* sample applications:
    * TFTP   (trivial file transfer protocol that uses UDP )
    * DHCPCD (DHCP client)
    * multiplayer games
    * streaming audio
    * video conferencing

* layers 1:
    * Application
    * Presentation
    * Session
    * Transport
    * Network
    * Data Link
    * Physical

* Layered Network Model:
    * Application Layer (telnet, ftp, etc.)
    * Host-to-Host Transport Layer (TCP, UDP)
    * Internet Layer (IP and routing)
    * Network Access Layer (Ethernet, wi-fi, or whatever)

* port number
    * 16-bit number
    * local address for the connection
    *

* fix Host Byte Order by using a function to convert to Network Byte Order
    * htons() -> host to network short
    * htonl() -> host to network long
    * ntohs() -> network to host short
    * ntohl() -> network to host long

* socket descriptor -> int
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <string>
#include <cstring>
#include <winsock2.h>
#include <ws2tcpip.h>

using namespace std;

#pragma comment(lib, "Ws2_32.lib")

/*struct sockaddr
{
    unsigned short sa_family;   // address family, AF_xxx
    char           sa_data[14]; // 14 bytes of protocl address
};*/

/*struct addrinfo
{
    int              ai_flags;
    int              ai_family;    // AF_INET (IPv4), AF_INET6 (IPv6), AF_UNSPEC (unspecified
    int              ai_socktype;  // SOCK_STREAM, SOCK_DGRAM
    int              ai_protocol;  // use 0 for "any"
    size_t           ai_addrlen;   // size of ai_addr in bytes
    struct sockaddr *ai_addr;
    char            *ai_canonname;

    struct addrinfo *ai_next;      // linked list, next node
};*/



/*struct sockaddr_in
{
    short int          sin_family;   // address family, AF_INET
    unsigned short int sin_port;     // port number
    struct in_addr     sin_addr;     // internet address
    unsigned char      sin_zero [8]; // same size as struct sockaddr
};*/

/*struct in_addr
{
    uint32_t s_addr;
};*/

/*struct in6_addr {
    unsigned char   s6_addr[16];   // IPv6 address
};*/

/*struct sockaddr_in6 {
    uint16_t        sin6_family;   // address family, AF_INET6
    uint16_t        sin6_port;     // port number, Network Byte Order
    uint32_t        sin6_flowinfo; // IPv6 flow information
    struct in6_addr sin6_addr;     // IPv6 address
    uint32_t       sin6_scope_id; // Scope ID
};*/

/*struct sockaddr_storage {
    sa_family_t  ss_family;     // address family

    // all this is padding, implementation specific, ignore it:
    char      __ss_pad1[_SS_PAD1SIZE];
    int64_t   __ss_align;
    char      __ss_pad2[_SS_PAD2SIZE];
};*/


int main()
{
    WSAData wsaData;

    if (WSAStartup (MAKEWORD(1, 0), &wsaData) != 0)
    {
        fprintf (stderr, "WSAStartup failed!\n");
        exit(1);
    }

    return 0;
}








































