#include <stdio.h>
#include <stdlib.h>

#if defined (WIN32)
#include <winsock2.h>
typedef int socklen_t;
#elif defined (linux)
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define closesocket(s) close(s)
typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;
#endif

#define PORT 3080




int main(void)
{


    int tentative = 1 ;
    int erreur ;
    int compteur;
    char mon_nom[64];
    int Reconnect = 0 ;
    HOSTENT* ip_resolue;
    SOCKADDR_IN valip;
    SOCKET id_sock;
    SOCKADDR_IN sin;
    char buffer[65535]; // Tampon contenant les données reçues ou envoyées
    int nombre_de_caractere;
    do
    {
#if defined (WIN32)
        WSADATA WSAData;
        erreur = WSAStartup(MAKEWORD(2,2), &WSAData);
#else
        erreur = 0;
#endif

        if(!erreur)
        {

            /* Création de la socket */
            id_sock = socket(AF_INET, SOCK_STREAM, 0);

            /* Configuration de la connexion */
            sin.sin_addr.s_addr = inet_addr("127.0.0.1");
            sin.sin_family = AF_INET;
            sin.sin_port = htons(PORT);

            /* Si le client arrive à se connecter */
            if(connect(id_sock, (SOCKADDR*)&sin, sizeof(sin)) != SOCKET_ERROR)
            {
#if defined (WIN32)
                system("cls");
#elif defined (linux)
                system("clear");
#endif
                printf("Reussite -> Serveur IP : %s:%d", inet_ntoa(sin.sin_addr), htons(sin.sin_port));
                Reconnect = 1 ;
                gethostname(mon_nom, sizeof(mon_nom));
                ip_resolue = gethostbyname(mon_nom);


                if(ip_resolue->h_addr_list[0] != NULL) //affichage ip
                {
                    for (compteur = 0; ip_resolue->h_addr_list[compteur+1] != NULL; compteur++) {}
                    memcpy(&valip.sin_addr.s_addr, ip_resolue->h_addr_list[compteur], ip_resolue->h_length);
                    printf("\nClient IP : %s",inet_ntoa(valip.sin_addr));
                }

                strcpy(buffer,"Salut je suis un client connecté"); //Envois donnée tcp
                nombre_de_caractere=send(id_sock,buffer,strlen(buffer),TCP_NODELAY);
                printf("\nid_sock   : %d",id_sock);
                if (nombre_de_caractere==SOCKET_ERROR)
                    printf("\nDesole, je n'ai pas envoyer les donnees du a l'erreur : %d",WSAGetLastError());
                else
                    printf("\nsend      : OK");


            }
            else
            {
                printf("%d/Echec -> Serveur IP : %s:%d\n",tentative, inet_ntoa(sin.sin_addr), htons(sin.sin_port));
                /* On ferme la socket précédemment ouverte */
#if defined (WIN32)
                WSACleanup();
#elif defined (linux)
                closesocket(sock);
#endif
                tentative ++ ;


            }

        }
    }

    while(Reconnect!=1);
    getchar();

    return EXIT_SUCCESS;
}
