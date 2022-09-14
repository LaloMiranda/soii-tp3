Laboratorio III  Sistemas Operativos 2 
### Ingeniería en Computación - FCEFyN - UNC
# Optimizaciones de código

## Introducción
El avance del hardare por sobre el sofware ha generado un gap que continúa en crecimiento. Esto ha generado que los desarrolladores de software en algunas situaciones pierdan de vista el hardware objetivo y generen sofware poco eficiente.

## Objetivo
El objetivo del presente laboratorio es que los Estudiantes aprendan algunas técnicas de optimización de código, con el objetivo de que los trabajos tengan mejor performance y consuman menores recorsos.

## Desarrollo
### Primera ejecución
Al momento de ejecutar por primera vez el programa original encontré que este realizaba un *core dump* ya que los bucles dentro de la función print se exedían de los limites de XDIM e YDIM. Tras solucionar esto obtuve el siguiente tiempo de ejecución:

| Herramienta   | lab original  | lab modificado    |
|---------------|---------------|-------------------|
|time           | 36.872s       | 37.530s           |

### Primera modificacion
Para comenzar con el trabajo era necesario elegir una herramienta de profiling, en mi caso utilicé GPROF. Gprof es una de las herramientas mas utilizadas en el rubro debido a su fácil uso y su sencilla instalación. Con esto ya instalado y funcionando modifique el archivo *lab3_modificado* de la siguiente manera:

```diff
void compute()
...
-double dato, accum;
-int i, j, k, l;
-for (i = 0; i < XDIM - 1; i++)
-    for (j = 0; j < YDIM - 1; j++)
-    {
-        //fprintf(outFile, "array[%d][%d] = %f\n", i, j, arr[i][j]);
-        if (i >= 1 && j >= 1 && i < XDIM - 1 && j < YDIM - 1)
-        {
-            for (k = 0; k < 3; k++)
-                for (l = 0; l < 3; l++)
-                {
-                    int x = i + (l - 1);
-                    int y = j + (k - 1);
-                    dato = arr[x][y];
-                    tmp_sum[l * 3 + k] = 2 * (2 * kern[l][k] * dato) / 1000 + 1;
-                }
-            accum = 0;
-            for (k = 0; k < 3; k++)
-                for (l = 0; l < 3; l++)
-                    accum = accum + tmp_sum[k * 3 + l]; // 0 1 2  3 4 5  6 7 8
-        }
-        arr[i][j] = accum;
-    }

+double accum;
+int i, j, k;
+for (i = 1; i < XDIM - 1; i++){
+    for (j = 1; j < YDIM - 1; j++){
+        accum = 0;
+        for (k = 0; k < 3; k++){
+            int y = j + (k - 1);
+            tmp_sum[k]      = 2 * (2 * kern[0][k] * arr[i - 1][y]) / 1000 + 1;
+            tmp_sum[k + 3]  = 2 * (2 * kern[1][k] * arr[i][y]) / 1000 + 1;
+            tmp_sum[k + 6]  = 2 * (2 * kern[2][k] * arr[i + 1][y]) / 1000 + 1;
+
+            accum += tmp_sum[k * 3] + tmp_sum[k * 3 + 1] + tmp_sum[k * 3 + 2];
+        }
+    arr[i][j] = accum;
+    }
+}
```
Se eliminaron los bucles que utilizaban la variable **L** como iterador y se quito el último bucle de la función (que usaba la vairable **K**) y se lo coloco dentro del bucle principal.

Tiempos de ejecución:
| Herramienta       | lab original  | lab modificado    |
|---------------    |---------------|-------------------|
|gprof - f(compute) | 5.47s         | 3.52s             |

Reducción de tiempo aproximada para esa función: 35,6%

***
## Referencias
- [How to create a diff in Markdown](https://egghead.io/lessons/egghead-create-a-diff-in-markdown-to-show-what-has-changed-in-a-code-snippet)