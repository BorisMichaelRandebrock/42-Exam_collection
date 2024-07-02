/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:20:26 by brandebr          #+#    #+#             */
/*   Updated: 2024/03/13 10:52:37 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return (i);
}
int ft_putstr_fd2(char *str)
{
    write(2, str, ft_strlen(str));
    return (1);
}
/****
 * La función ft_execute() recibe un fragmento de cadena de texto (que no es "cd" ni su palabra siguiente) desde argv.
 * Este fragmento se extiende hasta el final de la cadena o hasta que se encuentra un punto y coma (;), que no está incluido en la cadena.
 * Luego, la función intenta ejecutar el programa cuyo nombre se encuentra en el primer elemento de argv,
 * seguido por el fragmento de cadena mencionado. Si la ejecución tiene éxito, continúa normalmente.
 * Sin embargo, si la ejecución no tiene éxito, imprime un mensaje de error. En resumen, esta función se encarga
 * de ejecutar programas con argumentos específicos y manejar posibles errores de ejecución.
 * ****/
int ft_execute(char *argv[], int i, int tmp_fd, char *env[])
{
    argv[i] = NULL; // le ponemos un NULL donde termina para que no le pasemos nada mas. Si se lo pusieramos en el padre nos cargariamos el parseo
    dup2(tmp_fd, 0); // dup2(descriptor1, descriptor2) hace que el descriptor2 apunte al mismo recurso que descriptor1.La entrada estandar apunta a donde apuntaba tmp_fd. Redirige la entrada del proceso hijo al descriptor de archivo que contiene la entrada original (referencia al teclado original). donde se printa por defecto sera el temp_fd. En resumen, quizas el comando que ejecutamos con execv requiere que metamos datos por estandar input (teclado). Entonces, la línea dup2(tmp_fd, 0) se utiliza para que el programa que se está ejecutando en el proceso hijo piense que está recibiendo datos desde la entrada estándar (teclado), cuando en realidad está recibiendo los datos desde tmp_fd, lo que puede ser útil en situaciones en las que deseamos proporcionar datos predefinidos o automatizados al programa.
    close(tmp_fd);//Cerrramos en el hijo el duplicado
    execve(argv[0], argv, env);//Si tiene exito, el control pasa al nuevo programa y no continua. Solo continua leyendo el codigo si no tiene exito.
    ft_putstr_fd2("error: cannot execute ");//Solo llega aqui si no se ha ejecutado con exito execve.
    ft_putstr_fd2(argv[0]);
    ft_putstr_fd2("\n");
    return (1);
}
int main(int argc, char *argv[], char *env[])
{
    int i;
    int fd[2];
    int tmp_fd;
    int pid;
    (void)argc; // necesitamos que evite los warnings (no usamos argc) para poder compilar con -Wall -Wextra -Werror
    i = 0;
    tmp_fd = dup(0);//Hacemos una copia del fd del teclado. Vamos a enviar desde otro lugar, guardamos la posicion.
    while (argv[i] && argv[i + 1]) //Recorremos los argv.
    {
        argv = &argv[i + 1];    //Movemos el puntero de argv, que ira corriendo mientras haya argv[i+1]. Si no hubiera mas indicaciones, acabaria en el ultimo argv[i]
        i = 0;
        //count until we have all informations to execute the next child;
        while (argv[i] && strcmp(argv[i], ";") && strcmp(argv[i], "|")) // Pero la condicion para incrementar i es que NO sea ni ; ni |
            i++;
        if (strcmp(argv[0], "cd") == 0) //Si lo primero que hay en la linea de entrada es "cd"...
        {
            if (i != 2) // i no ha llegado mas alla de 2. a) No hay más texto después de "cd". b) Se ha detenido en ; o |
                ft_putstr_fd2("error: cd: bad arguments\n");
            else if (chdir(argv[1]) == -1)// debido a argv = &argv[i + 1], argv[1] siempre es la palabra en que se pare el incremento de i. En este caso, se habia parado en la palabra despues de encontrar "cd" (i == 2). Asi que intentamos cambiar al directorio argv[1]. Si no podemos, ejecutamos lo siguiente:
            {
                ft_putstr_fd2("error: cd: cannot change directory to ");
                ft_putstr_fd2(argv[1]);
                ft_putstr_fd2("\n");
            }
        }
        else if (i != 0 && (argv[i] == NULL || strcmp(argv[i], ";") == 0)) //Nos metemos aqui si i se ha incrementado, lo que significa que se ha encontrado algo que no es ni "cd", ni "|", ni ";". a) Si argv[i] es NULL, lo cual significa que no hay más argumentos después de lo que se ha encontrado, o b) Si argv[i] es igual a ";".
        {
            pid = fork();
            if (pid == -1)
                return 1;
            if (pid == 0)
            {
                if (ft_execute(argv, i, tmp_fd, env))// Retornaremos 1 Si, y solo si, hemos ejecutado ft_execute completamente. Si execve funciona, no se ejecuta completamente y no retornara 1.
                    return (1);
            }
            else// Para el proceso padre. Cerramos el tmp_fd que hemos dupilcado antes. Esperamos con waitpid a que acabe el hijo.
            {
                close(tmp_fd);
                waitpid(pid, NULL, WUNTRACED);
                tmp_fd = dup(0);//Restauramos el tmp_fd a la entrada estandar. Preparando el terreno para el futuro.
            }
        }
        else if(i != 0 && strcmp(argv[i], "|") == 0) //pipe
        {
            pipe(fd);// ejecutamos una funcion pipe. Nos dara un fd[0] que es el fd de lectua y un fd[1] que es el fd de escritura.
            pid = fork();// ejecutamos un fork.
            if (pid == 0)//El hijo.
            {
                dup2(fd[1], 1);//redirige la escritura estandar, ahora apunta a donde apunta el fd del pipe de escritura. Es decir, cualquier cosa que antes se imprimiria en pantalla, se enviara a traves del pipe. Es lo que hace un pipe: redirigiimos la salida del primer comando hacia la entrada del segundo comando.
                close(fd[0]);//Cerramos la lectura del pipe.
                if (ft_execute(argv, i, tmp_fd, env))
                    return (1);
            }
            else
            {
                close(fd[1]);
                close(tmp_fd);
                tmp_fd = fd[0];
            }
        }
    }
    close(tmp_fd);
	//Cerramos al final el tmp_fd.
    return (0);
}
