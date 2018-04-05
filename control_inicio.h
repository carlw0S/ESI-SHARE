#include "viajes.h"
#include "incidencias.h"
#include "usuarios.h"
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void comprobacion_horas_viajes(T_Viajes *);

void comprobacion_incidencias(T_Incidencias *);

int login(T_Usuarios *, int );

/*Privada*/
void rm_fin_linea(char *, int );
