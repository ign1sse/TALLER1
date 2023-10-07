# Software Manager

## Descripción

Este es un programa que permite gestionar una biblioteca personal de software. El usuario puede ver los detalles de los diferentes tipos de software que tiene, como su nombre, desarrollador, precio, edad minima, etc. También puede agregar o eliminar software de su biblioteca personal según sus necesidades. El programa tiene un sistema de login que verifica la identidad del usuario y le da acceso a diferentes funciones según su rol (administrador o usuario normal). El programa guarda los datos de los usuarios y del software en archivos de texto dentro de una subcarpeta llamada data (ir a "data/users.txt" para saber las credenciales de inicio de sesión).

## Instalación

Para ejecutar este programa se necesita tener instalado el compilador de C++ y el editor de código de su preferencia. Los pasos son los siguientes:

- Clonar o descargar el repositorio de GitHub donde se encuentra el código fuente del programa.
- Abrir la terminal y ejecutar el siguiente comando: g++ -o main.exe main.cpp
- Ejecutar el archivo 'main.exe' generado por el compilador.

## Uso

Al iniciar el programa, se le pedirá al usuario que ingrese su nombre y contraseña. Si el usuario no existe o los datos son incorrectos, se le dará la opción de volver a intentarlo o salir del programa. Si el usuario existe y los datos son correctos, se le mostrará un mensaje de bienvenida y el menú principal con las siguientes opciones:

- 1) My library: Esta opción muestra la lista de software que tiene el usuario en su biblioteca personal
- 2) List softwares: Esta opción muestra la lista de todos los software disponibles en el programa, permitiendo agregarlos a la biblioteca personal (sólo si se cumple con los requisito de edad o de privilegios) o eliminarlos de la maquina (sólo con el permiso de todos los usuarios que usen el programa). 
- 3) Logout: Esta opción cierra la sesión del usuario y pregunta si se desea volver al login o salir del programa definitivamente.
- 4) Add user: Esta opción solo está disponible para los usuarios administradores. Permite agregar un nuevo usuario al programa, solicitando su nombre, contraseña, edad, correo electrónico y permiso para acceder al registro (log).
- 5) Delete user: Esta opción solo está disponible para los usuarios administradores. Permite eliminar un usuario existente del programa, solicitando su nombre.
- 6) Edit user: Esta opción solo está disponible para los usuarios administradores. Permite editar los datos de un usuario existente del programa, solicitando su nombre y el dato que se quiere modificar.
- 7) Show log: Esta opción solo está disponible para los usuarios administradores. Muestra el registro de las acciones realizadas por los usuarios en el programa, como agregar o eliminar software.

Para seleccionar una opción, el usuario debe ingresar el número correspondiente y presionar enter. Luego, el usuario debe seguir las instrucciones que aparezcan por pantalla.

## Licencia

Este proyecto está bajo la licencia MIT.

## Contribuidores

Este proyecto fue creado por Ignacio Hernández.