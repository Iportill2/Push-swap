# Push Swap

![42 School](https://img.shields.io/badge/42-School-000000?style=flat-square&logo=42&logoColor=white)
![Language](https://img.shields.io/badge/Language-C-blue?style=flat-square)
![Norm](https://img.shields.io/badge/Norm-42-green?style=flat-square)

Un proyecto de algoritmia de **42 School** que implementa un algoritmo de ordenación eficiente utilizando dos stacks y un conjunto limitado de operaciones.

## 📋 Tabla de Contenidos

- [Descripción](#descripción)
- [Algoritmo de Ordenación](#algoritmo-de-ordenación)
- [Operaciones Permitidas](#operaciones-permitidas)
- [Instalación y Uso](#instalación-y-uso)
- [Checker](#checker)
- [Estructura del Proyecto](#estructura-del-proyecto)
- [Ejemplos](#ejemplos)
- [Rendimiento](#rendimiento)
- [Autor](#autor)

## 📖 Descripción

Push Swap es un proyecto que consiste en ordenar una pila de números enteros utilizando el menor número de operaciones posible. El programa debe imprimir la secuencia de operaciones necesarias para ordenar el stack A en orden ascendente.

### Objetivos del Proyecto

- **Algoritmia**: Implementar un algoritmo de ordenación eficiente
- **Optimización**: Minimizar el número de operaciones
- **Gestión de memoria**: Usar listas enlazadas dinámicas
- **Normas de 42**: Cumplir con el coding style de 42 School

## 🧠 Algoritmo de Ordenación

### Descripción Conceptual

El algoritmo implementado es un **algoritmo híbrido inteligente** que se adapta al tamaño del conjunto de datos y utiliza diferentes estrategias según el caso:

#### 1. **Casos Base (≤ 3 elementos)**
Para conjuntos pequeños, utiliza algoritmos específicos optimizados:
- **1-2 elementos**: Ya ordenados o una sola operación
- **3 elementos**: Algoritmo específico con máximo 2 operaciones

#### 2. **Algoritmo Principal (> 3 elementos)**
Utiliza una estrategia de **"Push-Sort-Merge"** que se divide en 4 fases:

### Fases del Algoritmo

#### **Fase 1: Preparación Inicial**
```c
// Mueve elementos estratégicos al stack B
if (len-- > 3 && !ft_stack_sorted(*a))
    pb(a, b, 1);  // Mueve 1 elemento
if (len > 4 && !ft_stack_sorted(*a))
{
    pb(a, b, 1);  // Mueve 1 elemento más
    pb(a, b, 1);  // Mueve otro elemento más
}
```
**Objetivo**: Reducir el stack A y crear un buffer en B para optimizar movimientos.

#### **Fase 2: Ordenación Progresiva del Stack A**
```c
while (len > 3 && !ft_stack_sorted(*a))
{
    ft_init_stack_a(*a, *b);    // Calcula costos y targets
    ft_move_stack_a(a, b);      // Mueve el elemento más eficiente
    len = ft_stack_len(*a);
}
```

**Algoritmo de Costo Mínimo**:
1. **Análisis**: Para cada elemento en A, calcula:
   - Costo de moverlo al top del stack A
   - Posición óptima en el stack B
   - Costo total de la operación

2. **Selección**: Identifica el elemento con menor costo total
3. **Ejecución**: Realiza los movimientos necesarios de forma optimizada

#### **Fase 3: Ordenación de 3 Elementos**
```c
ft_sort_three(a);
```
Utiliza un algoritmo específico para ordenar los últimos 3 elementos del stack A con máximo 2 operaciones.

#### **Fase 4: Merge del Stack B**
```c
while (*b)
{
    ft_init_stack_b(*a, *b);    // Calcula la posición óptima en A
    ft_move_stack_b(a, b);      // Mueve de B a A en posición correcta
}
```

#### **Fase 5: Rotación Final**
```c
ft_check_top(a);
```
Rota el stack A para que el elemento mínimo quede en el top.

### Estrategias de Optimización

#### **1. Cálculo de Costos Inteligente**
El algoritmo calcula múltiples tipos de costos:
- **Costo de posicionamiento**: Movimientos para llevar un elemento al top
- **Costo de inserción**: Movimientos para insertarlo en la posición correcta
- **Optimización de rotaciones**: Detecta oportunidades para rotar ambos stacks simultáneamente

#### **2. Target Selection**
Para cada elemento, encuentra la posición óptima considerando:
- Orden ascendente en el stack de destino
- Minimización de movimientos futuros
- Aprovechamiento de rotaciones simultáneas

#### **3. Movimientos Simultáneos**
Optimiza utilizando operaciones que afectan ambos stacks:
- `rr`: Rota ambos stacks hacia arriba
- `rrr`: Rota ambos stacks hacia abajo

### Ejemplo de Funcionamiento

Para el input `[4, 3, 2, 1]`:

```
Inicial:     A: [4, 3, 2, 1]    B: []

Fase 1:      A: [3, 2, 1]       B: [4]        (pb)
Fase 2:      A: [2, 1, 3]       B: [4]        (ra)
Fase 3:      A: [1, 2, 3]       B: [4]        (sa)
Fase 4:      A: [1, 2, 3, 4]    B: []         (pa)
Fase 5:      A: [1, 2, 3, 4]    B: []         (ra)

Movimientos: pb → ra → sa → pa → ra (5 operaciones)
```

### Complejidad

- **Temporal**: O(n²) en el peor caso, O(n log n) en promedio
- **Espacial**: O(n) para las estructuras de datos
- **Movimientos**: 
  - 3 elementos: ≤ 2 operaciones
  - 5 elementos: ≤ 12 operaciones
  - 100 elementos: ≤ 700 operaciones
  - 500 elementos: ≤ 5500 operaciones

## ⚙️ Operaciones Permitidas

### Stack Operations
| Operación | Descripción |
|-----------|-------------|
| `sa` | Swap los dos primeros elementos del stack A |
| `sb` | Swap los dos primeros elementos del stack B |
| `ss` | `sa` y `sb` simultáneamente |
| `pa` | Push el primer elemento de B al top de A |
| `pb` | Push el primer elemento de A al top de B |
| `ra` | Rotate A hacia arriba (primer elemento va al final) |
| `rb` | Rotate B hacia arriba |
| `rr` | `ra` y `rb` simultáneamente |
| `rra` | Reverse rotate A (último elemento va al inicio) |
| `rrb` | Reverse rotate B |
| `rrr` | `rra` y `rrb` simultáneamente |

## 🚀 Instalación y Uso

### Compilación

```bash
# Clonar el repositorio
git clone [tu-repositorio]
cd Push-swap

# Compilar push_swap
cd push_swap
make

# Compilar checker (opcional)
cd ../checker
make
```

### Uso

```bash
# Ejemplo básico
./push_swap "3 2 1"

# Con argumentos separados
./push_swap 3 2 1

# Con números negativos
./push_swap "5 -2 8 1 -7"

# Verificar con checker
./push_swap "3 2 1" | ./checker "3 2 1"
```

## ✅ Checker

El programa checker valida que una secuencia de operaciones ordene correctamente el stack:

```bash
# Usar con pipe
./push_swap "4 3 2 1" | ./checker "4 3 2 1"

# Usar con archivo
./push_swap "4 3 2 1" > moves.txt
./checker "4 3 2 1" < moves.txt
```

**Salida del Checker**:
- `OK`: La secuencia ordena correctamente el stack
- `KO`: La secuencia no ordena correctamente el stack
- `Error`: Input inválido

## 📁 Estructura del Proyecto

```
Push-swap/
├── push_swap/              # Programa principal
│   ├── srcs/               # Código fuente
│   │   ├── 00_main.c       # Función principal
│   │   ├── 01_init_stack.c # Inicialización de stacks
│   │   ├── 02_utils_stack.c # Utilidades de stack
│   │   ├── 03_error.c      # Manejo de errores
│   │   ├── 04_sort_stack.c # Algoritmo principal
│   │   ├── 05_init_a.c     # Inicialización stack A
│   │   ├── 06_move_stack_a.c # Movimientos stack A
│   │   ├── 07_init_b.c     # Inicialización stack B
│   │   ├── 08_move_stack_b.c # Movimientos stack B
│   │   ├── 09_push.c       # Operaciones push
│   │   ├── 10_reverse_rotate.c # Reverse rotate
│   │   ├── 11_rotate.c     # Operaciones rotate
│   │   ├── 12_sort3.c      # Algoritmo para 3 elementos
│   │   └── 13_swap.c       # Operaciones swap
│   ├── incs/               # Headers
│   │   └── push_swap.h
│   ├── libs/               # Librerías
│   │   ├── Libft/          # Librería estándar 42
│   │   └── ft_printf/      # Printf personalizado
│   └── Makefile
├── checker/                # Programa verificador
│   ├── srcs/
│   │   └── main.c
│   ├── incs/
│   │   └── checker.h
│   ├── libs/
│   │   └── get_next_line/  # Para lectura de operaciones
│   └── Makefile
└── README.md
```

## 📊 Ejemplos

### Caso Simple (3 elementos)
```bash
$ ./push_swap "3 2 1"
ra
sa
```

### Caso Medio (5 elementos)
```bash
$ ./push_swap "5 4 3 2 1"
pb
pb
ra
sa
pa
ra
pa
ra
```

### Verificación
```bash
$ echo -e "ra\nsa" | ./checker "3 2 1"
OK
```

## 🎯 Rendimiento

| Elementos | Operaciones Máximas | Operaciones Típicas |
|-----------|---------------------|---------------------|
| 3         | 2                   | 1-2                 |
| 5         | 12                  | 8-10                |
| 100       | 700                 | 500-600             |
| 500       | 5500                | 4000-4500           |

## 🛠️ Características Técnicas

- **Lenguaje**: C (C99)
- **Compilador**: gcc con flags `-Wall -Wextra -Werror`
- **Normas**: 42 School Norm
- **Gestión de memoria**: Sin memory leaks
- **Librerías permitidas**: Solo funciones básicas de sistema

## 👨‍💻 Autor

Iker Portillo
