#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <termios.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {

    int serial_port;
    struct termios oldtio;

    ////////////////////////////////////////////////////////
    // open port
    ////////////////////////////////////////////////////////
    //int serial_port = open("/dev/ttyACM0", O_RDWR | O_NOCTTY | O_NDELAY);
    serial_port = open("/dev/ttyS4", O_RDWR | O_NOCTTY );
    if (serial_port < 0) {
        printf("Error %i from open : %s\n", errno, strerror(errno));
        return -1;
    }

    ////////////////////////////////////////////////////////
    // is it a tty?
    ////////////////////////////////////////////////////////
    if (!isatty(serial_port)) {
        printf("Is not a tty\n");
        return -1;
    }

    ////////////////////////////////////////////////////////
    // get current port settings
    ////////////////////////////////////////////////////////
    if (tcgetattr(serial_port, &oldtio) != 0) {
        printf("Error %i from gett attr : %s\n", errno, strerror(errno));
        return -1;
    }

/*
    char buffer[1] = {0};

    while ( 1 ) {
        int num = read(serial_port, buffer, sizeof(buffer));
        if (num < 0) {
            perror("The error is:");
        } else if (num > 0) {
            printf("%c",buffer);
        } else {
            printf(".");
        }
    }    
*/



    return 0;
}
