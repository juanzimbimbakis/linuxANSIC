#ifndef _colas_h
#define _colas_h


typedef struct
{
    long long_dest;
    int int_rte;
    int int_evento;
    char char_mensaje[100];
} Mensaje;

int creoIdColaMensajes(int clave);

int enviarMensaje(int id_cola_mensajes, long rLongDest, int rIntRte, int rIntEvento, char* rpCharMsg);

int recibirMensaje(int id_cola_mensajes, long rLongDest, Mensaje* rMsg);



#endif
