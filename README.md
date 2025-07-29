🛒 Trabajo Práctico #1 — Simulación de Compra en Supermercado
Cátedra: Metodología-DP-ECP-Módulos-ED
Lenguaje: C++ (Paradigma Imperativo, Procedural y Modular)
Compilador: Borland C++ 5.5
IDE recomendado: Code::Blocks

📋 Objetivo
Desarrollar un sistema que simule la compra de artículos por parte de un cliente en un supermercado, utilizando registros, arreglos y archivos de texto. El sistema debe:

Leer archivos de entrada (Articulos.txt, IndDescripArt.txt, Rubros.txt, ListaCompras.txt)

Volcar datos a estructuras estáticas (tablas)

Procesar compras, actualizar stock y emitir ticket

Emitir un listado ordenado de artículos por rubro

🗂️ Archivos de Entrada
Articulos.txt (hasta 10.000 artículos, desordenado)
Campo	Tipo	Descripción
Código de Artículo	int (8 dígitos)	Identificador único del artículo
Código de Rubro	short (2 dígitos)	Rubro del artículo
Descripción	char[30]	Descripción del artículo
Stock Actual	unsigned short (4 dígitos)	Stock disponible
Precio Unitario	float (6.2)	Precio por unidad
Unidad de Medida	char[10]	Unidad (ej: litros, gramos, etc.)
Porc. Ofertas	short[14]	Siete pares: tipo de promo y porcentaje (%)

Ejemplo de línea:

yaml
Copiar
Editar
12406297  23 Naranjas de jugo                 54   1526.28 gramos     2 20 3 10 5 10 1 25 7 15 6 25 2 10 
IndDescripArt.txt (ordenado por descripción)
Campo	Tipo
Descripción Art.	char[30]
Posición en archivo Art.	int
Estado	bool (1: activo, 0: baja lógica)

Rubros.txt (ordenado por código de rubro)
Campo	Tipo
Código de Rubro	short
Descripción	char[20]

ListaCompras.txt (hasta 100 ítems, sin orden)
Campo	Tipo
Descripción Art.	char[30]
Cant. Requerida	short

🧱 Estructuras a Crear (en memoria)
Tabla 1: Índice de descripciones (IndDescripArt.txt)

Tabla 2: Lista de compras (ListaCompras.txt)

Tabla 3: Cod.Rubro y posición (Articulos.txt, misma cantidad que Tabla 1)

🔄 Flujo de Ejecución
cpp
Copiar
Editar
main() {
    // Declaración de variables
    
    Abrir(Articulos, IndDescripArt, Rubros, ListaCompras);
    VolcarArchivos(...);
    ProcCompras(...);
    EmitirTicket(...);
    EmitirArt_x_Rubro(...);
    Cerrar(...);
    return 0;
}
🧠 Lógica de Procesamiento
Por cada compra:

Buscar artículo en Tabla 1 (índice de descripciones).

Verificar estado:

Si activo:

Verificar stock:

Si suficiente: descontar y actualizar

Si insuficiente: vender lo disponible

Si baja lógica: cantidad comprada es 0

Emitir ticket con formato tabular

Generar listado final por rubro con todos los descuentos aplicables

🧾 Formato del Ticket
Cabecera con datos de la tienda

Cuerpo por ítem:

Cant. x Precio Unitario

Descripción, Unidad de Medida

Código Artículo, Importe Total

Tipo de descuento, porcentaje y monto

Pie:

Subtotal

Total descuentos

Total final

Pago, vuelto

Mensaje final

📑 Listado por Rubros
Ordenado por código de rubro

Mostrar:

Código Art.

Descripción

Stock actual

Precio unitario

Unidad de medida

7 promociones (tipo y %)

🧰 Funciones Requeridas
Prototipo	Descripción
bool LeerSuf(modo &id, sid &id)	Lectura de línea del archivo
void CabeceraTicket(int &ds)	Imprime cabecera del ticket
void PieTicket(float, float, float)	Imprime pie del ticket
void OrdxBur(...)	Ordena por burbujeo
void IntCmb(...)	Intercambia elementos
void ActLinea(modo &id, sid id)	Actualiza stock actual
int BusBinVec(...)	Búsqueda binaria en índice
string Replicate(char car, unsigned)	Repite carácter
long GetTime(...)	Retorna hora del sistema
long GetDate(...)	Retorna fecha del sistema

📁 Estructura del Proyecto
Copiar
Editar
/TP-Supermercado
├── Articulos.txt
├── IndDescripArt.txt
├── Rubros.txt
├── ListaCompras.txt
├── Ticket.txt (salida)
├── TP1V1_K1XXGX_APELLIDO_NOMBRE.cpp
├── README.md
📦 Requisitos de Entrega
Carpeta A4 con tapa transparente y sujetador.

Carátula con datos de integrantes (máx. 5 por grupo).

Enunciado del TP.

Diagramas de:

Registros de cada archivo

Estructuras auxiliares

Diagrama del main().

Diagrama de cada módulo.

Muestra de datos reales y funcionales (con casos límite y bordes).

Resultados esperados impresos.

Código fuente con comentarios (Code::Blocks).

Entregar versión numerada: TP1V1_..., TP1V2_..., etc.

⚠️ Consideraciones Finales
Usar constantes con nombre para las cantidades.

No usar memoria dinámica.

Solo se permite recorrido secuencial para lectura de archivos.

Se permiten tres accesos aleatorios al archivo Articulos.txt.

Eficiencia en ciclos será tenida en cuenta.

Asignar nombres de identificadores significativos y representativos.

Incluir todos los casos posibles en la muestra de datos:

Stock suficiente / insuficiente / nulo

Artículos activos / dados de baja

Promociones múltiples

📌 Autor / Grupo
A completar con:

Nombre del programa

Fecha de entrega

Curso, turno, grupo e integrantes

Nombre del compilador

Objetivo

Versión actual
