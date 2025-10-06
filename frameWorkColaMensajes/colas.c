#include "memoria.h"
#include "clave.h"
#include "sys/ipc.h"
#include "sys/shm.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
#include "colas.h"
#include "global.h"




int creoIdColaMensajes(int clave)
{
    int idColaMensajes = msgget(creoClave(), 0600 | IPC_CREAT);

    if(idColaMensajes == -1)
    {
        printf("Error al obtener identificador para cola de mensajes\n");
        exit(-1);
    }

    return idColaMensajes;

}

int enviarMensaje(int id_cola_mensajes, long rLongDest, int rIntRte, int rIntEvento, char* rpCharMsg)
{
    Mensaje msg;
    
    msg.long_dest = rLongDest;
    msg.int_rte = rIntRte;
    msg.int_evento = rIntEvento;

    strcpy(msg.char_mensaje, rpCharMsg);

    return msgsnd(id_cola_mensajes, (struct msgbuf *)&msg, sizeof(msg.int_rte) + sizeof(msg.int_evento) + sizeof(msg.char_mensaje), IPC_NOWAIT);


}

int recibirMensaje(int id_cola_mensajes, long rLongDest, Mensaje* rMsg)
{
    Mensaje msg;
    int res;

    res = msgrcv (id_cola_mensajes, (struct msgbuf *)&msg, sizeof(msg.int_rte) + sizeof(msg.int_evento) + sizeof(msg.char_mensaje), rLongDest, 0);

    rMsg->long_dest = msg.long_dest;
    rMsg->int_rte = msg.int_rte;
    rMsg->int_evento = msg.int_evento;
    strcpy(rMsg->char_mensaje, msg.char_mensaje);
    return res;


}


