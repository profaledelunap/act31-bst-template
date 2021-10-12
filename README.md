![Tec de Monterrey](images/logotecmty.png)

# Act 3.1 - Operaciones avanzadas en un BST

## <span style="color: rgb(26, 99, 169);">¿Qué tengo que hacer?</span>

En este repositorio ncontrarás el archivo "BST.h" que deberás modificar para el desarrollo de esta actividad. Deberás colocar en la parte superior, en comentarios, tus datos. Por ejemplo:

```
// =========================================================
// File: BST.h
// Author: Edward Elric - A00123456
// Date: 01/01/2021
// =========================================================
```

Diseña e implementa, en forma <span style="text-decoration-line: underline;">forma individual</span>, las funciones que resuelvan los problemas que se describen a continuación.

Las funciones que debes implementar son:

1. ` void BST::print()`
   Desplegará cada uno de los datos almacenados en el BST dependiendo del parámetro en entrada:

- Preorder
- Inorder
- Postorder
- Level by level

2. ` int BST::height()`
   Regresará la altura del BST.
3. ` void BST::ancestors(NodeBST node)`
   Desplegará los ancestros de un dato.
4. ` int BST::getLevel(NodeBST node`
   Regresará un entero que indica el nivel en que se encuentra un dato, o -1 en caso de que no se encuentre en el BST.

<br>Todas las funcionalidades deberán de estar correctamente alineadas y documentadas.&nbsp; Recuerda que todas las funcionalidades deberán pasar exitosamente todas las pruebas. Como parte de la documentación deberá incluirse la complejidad de cada una de ellas.

Para probar tu implementación, ejecuta el comando:

```
make
```

Este comando compilará tu código y generará una serie de archivos de pruebas. Para ejecutar una prueba específica, solo deberás ejecutar el comando correcto. Por ejemplo, si quiere revisar si tu código cumple con la prueba número 3, deberías ejecutar:

```
make test3
```

## <span style="color: rgb(26, 99, 169);">**¿Bajo qué criterios se evalúa mi evidencia?**</span>

- **70%** - Lista de 4 casos de prueba para cada una de las funcionalidades donde para cada una se evaluará:

  - Excelente (70%) - evalúa correctamente los 4 casos de prueba.
  - Muy Bien (55%) - evalúa correctamente 3 casos de prueba.
  - Bien (40%) - evalúa correctamente 2 casos de prueba
  - Insuficientre (25%) - evalúa correctamente 1 o 0 casos de prueba.

-**10%** - Especifican en cada uno de las funcionalidades la complejidad computacional como parte de su documentación.

-**10%** - El código deberá seguir los lineamientos estipulados en el estándar de codificación: liga_estándar_codificación Descargar liga_estándar_codificación .

-**10%** - Se respetenan los nombres de las funciones en la aplicación.

## <span style="color: rgb(26, 99, 169);">**¿Dónde la entrego?**</span>

Cuando hayas pasado todas las pruebas, recuerda publicar el código en tu repositorio (_git push_).
