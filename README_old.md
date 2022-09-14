Laboratorio III  Sistemas Operativos 2 
### Ingeniería en Computación - FCEFyN - UNC
# Optimizaciones de código

## Introducción
El avance del hardare por sobre el sofware ha generado un gap que continúa en crecimiento. Esto ha generado que los desarrolladores de software en algunas situaciones pierdan de vista el hardware objetivo y generen sofware poco eficiente.

## Objetivo
El objetivo del presente laboratorio es que los Estudiantes aprendan algunas técnicas de optimización de código, con el objetivo de que los trabajos tengan mejor performance y consuman menores recorsos.

## Desarrollo
### Problema a resolver
Dado el archibo lab3.c en el presente repo, se pide que el estudiante lo analice, estudie y le realice toda tardea de optimización y refactorización que considere para que el software sea mas óptimo en consumo de recursos.

Se le debe medir y documentar las optimizaciones realizadas utilizando alguna herramienta de profiling y usando como base el software tal ocmo esta presentado.

Extra: Debe diseñar y desarrollar un unit test que valide el software (NO usando un framework, sólo un script).

### Restricciones
- Se puede utilizar tanto GCC u otro compilador
- La compilación debe realizarse sin [optimizaciones de compilación (-O0)](https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html)
- No se debe limitar a las técnicas presentadas en clase.

### Criterios de Corrección
- Se debe compilar el código con los flags de compilación: 
     -Wall -Pedantic -Werror -Wextra -Wconversion -std=gnu11
- La correcta gestion de memoria.
- Dividir el código en módulos de manera juiciosa.
- Estilo de código.
- Manejo de errores
- El código no debe contener errores, ni warnings.
- El código no debe contener errores de cppcheck.

## Entrega
La entrega se hace a travéz del repositorio de GitHub y se deberá demostrar la realizacion del mismo mediante un correcto uso. El repositorio deberá proveer los archivos fuente y cualquier otro archivo asociados a la compilación, archivos  de  proyecto  ”Makefile”  y  el  código correctamente documentado. No debe contener ningún archivo asociado a proyectos de un IDE y se debe asumir que el proyecto podrá ser compilado y corrido por una `tty` en una distribución de Linux con las herramientas típicas de desarrollo. También se deberá entregar un informe en formato _Markdown_ documentando cada cambio que se le realiza al código, que efecto produce sobre el mismo y porqué?
También se deberá investigar acerca de qué utilidades de profiling gratuitas existen y que brinda cada una (un capítulo del informe), optando por una para realizar las mediciones de tiempo de ejecución de la aplicación diseñada.

El informe debe contener gráficos y análisis de comparación entre la ejecución procedural y la distribuida. El informe además debe contener el diseño de la solución y la comparativa de profilers.

## Evaluación
El presente trabajo práctico es individual y deberá entregarse antes de las 23:50ART del día 21 de Abril de 2022 dejando asentado en el LEV con el archivo de ifnorme. 

