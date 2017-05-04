/* ultra-simple shell, first version */
#include "ush.h"
#define MAX_BUFFER 256
//#include "makeargv.c"

/* Bluetooth related library */
#include <bluetooth/bluetooth.h>
#include <bluetooth/rfcomm.h>
#include <bluetooth/sdp.h>
#include <bluetooth/sdp_lib.h>
#include <fcntl.h>

int main (int argc, char *argv[])
{
  // Creating the bluetooth socket
  /*
  int sock = socket(AF_BLUETOOTH, SOCK_STREAM, BTPROTO_RFCOMM);
  struct sockaddr_rc rem_addr = {0};
  char dest[18] = "60:57:18:7E:77:68";
  str2ba(dest, &rem_addr.rc_bdaddr);

  rem_addr.rc_family = AF_BLUETOOTH;
  rem_addr.rc_channel = 13;
  status = connect(s, (struct sockaddr*) & rem_addr, sizeof(rem_addr));
  */





  char inbuf[MAX_BUFFER];
  char **chargv;
  int i;

  for(;;) {
     gets(inbuf);
     if (strcmp(inbuf, QUIT_STRING) == 0)
        break;
     else {
        if (fork() == 0) {
           if (makeargv(inbuf, BLANK_STRING, &chargv) > 0)
     {
              execvp(chargv[0], chargv);
     }
        }
        wait(NULL);
     }
  }
  return 0;
}
