#Programa para encontrar el nucleo e imagen de una matriz
#Algebra Lineal
#2BM1
#Perez Lucio Kevyn Alejandro

import numpy as np

#***************************************************************************************
#FUNCIONES

def Imprimir_Matrix(info, matrix):
    print (info)
    for i in range( 0, matrix.shape[0]):
        print('[', end='')
        for j in range( 0, matrix.shape[1]):
            if(j == matrix.shape[1] - 1):# Vector b
                print( '|', end=''),# Separe la matriz de coeficientes y el vector b con "|"
            print("%5.2f" %matrix[i][j], end=' ')
            if j == matrix.shape[1] - 1:# Elemento de matriz de salida m [i] [j]
                print(']', end=' ')
                print('\n')           

def Pivote_Distinto_Cero(matrix1, ecuaciones, arrayde_arrays, elemento):
    ciclos = 0
    while matrix1[arrayde_arrays][elemento] == 0:
        aux = matrix1[arrayde_arrays]
        matrix1.pop(arrayde_arrays)
        matrix1.insert(ecuaciones, aux)
        if ciclos == ecuaciones:
            break
        ciclos = ciclos + 1
    return matrix1

# Funcion que realiza las operaciones elementales en una matriz
def Operaciones_Elementales(array1, array2, constante1, constante2):
    i = 0
    j = 0
    k = 0
    while i < len(array1):
        array1[i] = array1[i] * constante2
        i = i + 1
    while j < len(array2):
        array2[j] = array2[j] * -constante1
        j = j + 1
    while k < len(array1):
        array2[k] = array2[k] + array1[k]
        k = k + 1
    return array2

# Funcion que hace ceros abajo de la diagonal
def DiagonalizaAbajo(matrix, ecuaciones, variables):
    limite_pivote = 0
    fila_cero = []
    for cero in range(0, variables):
        fila_cero.append(0)

    if ecuaciones < variables:
        limite_pivote = ecuaciones
    elif variables < ecuaciones or variables == ecuaciones:
        limite_pivote = variables

    pos_pivote = 0
    while pos_pivote < limite_pivote:
        valor_pivote = matrix[pos_pivote][pos_pivote]
        if pos_pivote + 1 == limite_pivote and valor_pivote == 0:
            break
        elif valor_pivote == 0:
            Pivote_Distinto_Cero(matrix, ecuaciones, pos_pivote, pos_pivote)
            if fila_cero in matrix:
                break
            valor_pivote = matrix[pos_pivote][pos_pivote]
        j = pos_pivote + 1

        while j < ecuaciones:
            cte_sig_fila = matrix[j][pos_pivote]
            if cte_sig_fila != 0:
                matrix[j] = Operaciones_Elementales(matrix[pos_pivote][:], matrix[j][:], valor_pivote, cte_sig_fila)
            j = j + 1
        pos_pivote = pos_pivote + 1
    return matrix

#Funcion que retorna las veces que el cero aparece como resultado
def Filas_Dif_Cero(matrix_aumentada, filas, columnas):
    n = filas
    rn = 0
    v = 0
    for i in range(n):
        ceros = matrix_aumentada[v][-1]
        v = v + 1
        if (ceros == 0):
            rn = rn+1
    return rn

# Funcion que hace ceros arriba de la diagonal
def DiagonalizaArriba(matrix, ecuaciones, variables):
    limite_pivote = 0
    if ecuaciones < variables:
        limite_pivote = ecuaciones
    elif variables < ecuaciones or variables == ecuaciones:
        limite_pivote = variables

    pos_pivote = limite_pivote - 1
    while pos_pivote >= 0:
        valor_pivote = matrix[pos_pivote][pos_pivote]
        if valor_pivote == 0:
            Pivote_Distinto_Cero(matrix, ecuaciones, pos_pivote, pos_pivote)
            valor_pivote = matrix[pos_pivote][pos_pivote]
        j = pos_pivote - 1
        while j >= 0:
            cte_sig_fila = matrix[j][pos_pivote]
            if cte_sig_fila != 0:
                matrix[j] = Operaciones_Elementales(matrix[pos_pivote][:], matrix[j][:], valor_pivote, cte_sig_fila)
            j = j - 1
        pos_pivote = pos_pivote - 1
    return matrix

# Funcion que hace unos la diagonal
def DiagonalUnos(matriz, ecuaciones, variables3):
    r = 0
    t = 0
    while r < ecuaciones:
        constante = matriz[r][r]
        while t <= variables3:
            try:
                matriz[r][t] = round(matriz[r][t]/constante, 10)
                t = t + 1
            except ZeroDivisionError:
                break
        t = 0
        r = r + 1
    return matriz

# Funcion que elimina las filas de "puros ceros" en la matriz aumentada
def EliminaFilasCero(matrix, elementos):
    filas_eliminadas = 0
    fila_cero = []
    for cero in range(0, elementos):
        fila_cero.append(0)
    filas_cero = matrix.count(fila_cero)
    for eliminador in range(0, filas_cero):
        matrix.remove(fila_cero)
        filas_eliminadas = filas_eliminadas + 1
    return filas_eliminadas

def SolucionesInfinitas(matrix, literales, num_param, param):
    comienzo = len(matrix[0]) - num_param
    p_l = 0
    bucles = 0
    for indice, ecuacion in enumerate(matrix):
        print(f"{literales[indice]} = {matrix[indice][-1]:.2f} ", end="")
        for p in range(comienzo, len(matrix[0])):
            if matrix[indice][p - 1] < 0:
                print("+", end="")
            print(f"{-matrix[indice][p - 1]:.2f}{param[p_l]} ", end="")
            p_l = p_l + 1
        print("\n")
        p_l = 0
    p_l = 0
    for g in range(0, bucles):
        literales.pop(0)
        
def NucleoInfinitasSol(matrix, literales, num_param, param):
    comienzo = len(matrix[0]) - num_param
    p_l = 0
    print("Nu(A) = < ", end="")
    for p in range(comienzo, len(matrix[0])):
        print("( ", end="")
        for indice, ecuacion in enumerate(matrix):
            if matrix[indice][p - 1] < 0:
                print("+", end="")
            print(f"{-matrix[indice][p - 1]:.2f} ", end="")
        if p_l == 0:
            if num_param == 1:
                print("1 ", end="")
            elif num_param == 2:
                print("1 0 ", end="")
            elif num_param == 3:
                print("1 0 0 ", end="")
            elif num_param == 4:
                print("1 0 0 0 ", end="")
            elif num_param == 5:
                print("1 0 0 0 0 ", end="")
            elif num_param == 6:
                print("1 0 0 0 0 0 ", end="")
            elif num_param == 7:
                print("1 0 0 0 0 0 0 ", end="")
            elif num_param == 8:
                print("1 0 0 0 0 0 0 0 ", end="")
            elif num_param == 9:
                print("1 0 0 0 0 0 0 0 0 ", end="")
        elif p_l == 1:
            if num_param == 2:
                print("0 1 ", end="")
            elif num_param == 3:
                print("0 1 0 ", end="")
            elif num_param == 4:
                print("0 1 0 0 ", end="")
            elif num_param == 5:
                print("0 1 0 0 0 ", end="")
            elif num_param == 6:
                print("0 1 0 0 0 0 ", end="")
            elif num_param == 7:
                print("0 1 0 0 0 0 0 ", end="")
            elif num_param == 8:
                print("0 1 0 0 0 0 0 0 ", end="")
            elif num_param == 9:
                print("0 1 0 0 0 0 0 0 0 ", end="")
        elif p_l == 2:
            if num_param == 3:
                print("0 0 1 ", end="")
            elif num_param == 4:
                print("0 0 1 0 ", end="")
            elif num_param == 5:
                print("0 0 1 0 0 ", end="")
            elif num_param == 6:
                print("0 0 1 0 0 0 ", end="")
            elif num_param == 7:
                print("0 0 1 0 0 0 0 ", end="")
            elif num_param == 8:
                print("0 0 1 0 0 0 0 0 ", end="")
            elif num_param == 9:
                print("0 0 1 0 0 0 0 0 0 ", end="")
        elif p_l == 3:
            if num_param == 4:
                print("0 0 0 1 ", end="")
            elif num_param == 5:
                print("0 0 0 1 0 ", end="")
            elif num_param == 6:
                print("0 0 0 1 0 0 ", end="")
            elif num_param == 7:
                print("0 0 0 1 0 0 0 ", end="")
            elif num_param == 8:
                print("0 0 0 1 0 0 0 0 ", end="")
            elif num_param == 9:
                print("0 0 0 1 0 0 0 0 0 ", end="")
        elif p_l == 4:
            if num_param == 5:
                print("0 0 0 0 1 ", end="")
            elif num_param == 6:
                print("0 0 0 0 1 0 ", end="")
            elif num_param == 7:
                print("0 0 0 0 1 0 0 ", end="")
            elif num_param == 8:
                print("0 0 0 0 1 0 0 0 ", end="")
            elif num_param == 9:
                print("0 0 0 0 1 0 0 0 0 ", end="")
        elif p_l == 5:
            if num_param == 6:
                print("0 0 0 0 0 1 ", end="")
            elif num_param == 7:
                print("0 0 0 0 0 1 0 ", end="")
            elif num_param == 8:
                print("0 0 0 0 0 1 0 0 ", end="")
            elif num_param == 9:
                print("0 0 0 0 0 1 0 0 0 ", end="")
        elif p_l == 6: 
            if num_param == 7:
                print("0 0 0 0 0 0 1 ", end="")
            elif num_param == 8:
                print("0 0 0 0 0 0 1 0 ", end="")
            elif num_param == 9:
                print("0 0 0 0 0 0 1 0 0 ", end="")
        elif p_l == 7:
            if num_param == 8: 
                print("0 0 0 0 0 0 0 1 ", end="")
            elif num_param == 9:
                print("0 0 0 0 0 0 0 1 0 ", end="")
        elif p_l == 8:
            if num_param == 9:
                print("0 0 0 0 0 0 0 0 1 ", end="")
            else:
                print("0 0 0 0 0 0 0 0 1 0... ", end="")
        print(f"){param[p_l]} ", end="")
        p_l = p_l + 1
    p_l = 0
    print(">")
        
def CasoNoBase(matrixc, filas, columnas):
    matrixc = matrixc.T
    print("El sistema no tiene nucleo, por lo tanto no tiene base")
    print("La imagen de la base es:")
    print("")  
    print("Im(A) = < ", end="")
    for i in range( 0, matrixc.shape[0]):
        print("( ", end="")
        for j in range( 0, matrixc.shape[1]):
            print("%5.2f" %matrixc[i][j], end=' ')
            if j == matrixc.shape[1] - 1:# Elemento de matriz de salida m [i] [j]
                print(') ', end=' ')
    print(">")
    print("")  
    print("Asi por el teorema de Rango Nulidad")
    print("") 
    print("Dim(Nu(A)) = 0")
    print("+")
    print("Dim(Im(A)) = %d" %(columnas))
    print("= %d" %(columnas), "No. columnas")
    print("") 
        
#  --------------------------------------------------------------------------------------------------------------------
# PROGRAMA PRINCIPAL 
        
print("____PROGRAMA PARA ENCONTRAR EL NUCLEO E IMAGEN DE UNA MATRIZ____")
print("")
filas = int(input("Ingrese el numero de filas de la matriz: "))
columnas = int(input("Ingrese el numero de columnas de la matriz: "))

matrix_aumentada = []
matrixa = np.zeros((filas, columnas+1))
matrixc = np.zeros((filas, columnas))
matrixcopia = np.zeros((filas, columnas+1))
variables = []
filas_ceros = []
parametros = ["λ1", "λ2", "λ3", "λ4", "λ5", "λ6", "λ7", "λ8", "λ9"]

for i in range(filas):
    variables.append(f"x{i}")
variables = np.array(variables)

for i in range(filas):
    for j in range(columnas):
        matrixc[i][j] = float(input("Ingrese el componente "+str(j+1)+" de la fila "+str(i+1)+": "))

for i in range(filas):
    for j in range(columnas):
        matrixa[i][j] = matrixc[i][j]

arrayzeros = np.zeros(filas)
for i in range(filas):
    matrixa[i][columnas] = arrayzeros[i]

print("") 
Imprimir_Matrix('La matriz aumentada es:', matrixa)

print("")    
print("INDEPENDENCIA LINEAL\n") 
rango_coeficientes = np.linalg.matrix_rank(matrixc)
print("R(A) = ",rango_coeficientes)
print("")
rango_aumentada = np.linalg.matrix_rank(matrixa)
print("R(A*) = ",rango_aumentada)
print("")

DimNu = 0 #Dimension del nucleo
DimIm = 0 #Dimension de la imagen

matrix_aumentada = matrixa.tolist() #Convierte matriz de numpy a lista
matrix_aumentada = Pivote_Distinto_Cero(matrix_aumentada, filas, 0, 0)
DiagonalizaAbajo(matrix_aumentada, filas, columnas)

#Nucleo de una base
if rango_aumentada == rango_coeficientes and rango_aumentada == columnas:
    print("\nTiene Solución Única\n")
    print("Es un conjunto linealmente independiente\n")
    for cero in range(0, columnas + 1):
        filas_ceros.append(0)
    if filas_ceros in matrix_aumentada:
        numero_fceros = matrix_aumentada.count(filas_ceros)
        for n in range(0, numero_fceros):
            matrix_aumentada.remove(filas_ceros)
        filas = filas - numero_fceros
    DiagonalUnos(matrix_aumentada, filas, columnas)
    DiagonalizaArriba(matrix_aumentada, filas, columnas)
    DiagonalUnos(matrix_aumentada, filas, columnas)
    matrix_resultado = np.array(matrix_aumentada) #Lista a matriz
    row = len(matrix_aumentada)
    for i in range(0, row):
        print("x%d = %4.2f " %(i+1, matrix_aumentada[i][columnas]))
    print("")
    cerosResultado = Filas_Dif_Cero(matrix_aumentada, filas, columnas)
    
    CasoNoBase(matrixc, filas, columnas)
    

elif rango_aumentada == rango_coeficientes and rango_aumentada < columnas:
    print("\nTiene Infinidad de Soluciones\n")
    print("")
    filas_original = filas
    numero_parametros = columnas - rango_aumentada
    f_eliminadas = EliminaFilasCero(matrix_aumentada, columnas + 1)
    filas = filas - f_eliminadas
    DiagonalUnos(matrix_aumentada, filas, columnas)
    DiagonalizaArriba(matrix_aumentada, filas, columnas)
    DiagonalUnos(matrix_aumentada, filas, columnas)
    filas = len(matrix_aumentada)
    matrix_resultado = np.array(matrix_aumentada) #Lista a matriz
    Imprimir_Matrix('La matriz resultante es:', matrix_resultado)
    SolucionesInfinitas(matrix_resultado, variables, numero_parametros, parametros)
    NucleoInfinitasSol(matrix_resultado, variables, numero_parametros, parametros)
    print("")
    #Imagen de una base
    if numero_parametros<columnas:
        nuevaColumna = columnas-numero_parametros
        matrixaCaso1 = np.zeros((filas_original, nuevaColumna+1))
        matrixcCaso1 = np.zeros((filas_original, nuevaColumna))
        for i in range(filas_original):
            for j in range(nuevaColumna):
                matrixaCaso1[i][j] = matrixc[i][j]
                matrixcCaso1[i][j] = matrixc[i][j]
        for i in range(filas_original):
            matrixaCaso1[i][nuevaColumna] = arrayzeros[i]
        rango_coeficientes = np.linalg.matrix_rank(matrixcCaso1)
        rango_aumentada = np.linalg.matrix_rank(matrixaCaso1)
        if rango_coeficientes == rango_aumentada and rango_aumentada == nuevaColumna:
            print("Las primeras columnas son linealmente independientes")
            matrixcCaso1 = matrixcCaso1.T
            print("")  
            print("Im(A) = < ", end="")
            for i in range( 0, matrixcCaso1.shape[0]):
                print("( ", end="")
                for j in range( 0, matrixcCaso1.shape[1]):
                    print("%5.2f" %matrixcCaso1[i][j], end=' ')
                    if j == matrixcCaso1.shape[1] - 1:
                        print(') ', end=' ')
            print(">")
            print("")  
            print("Asi por el teorema de Rango Nulidad")
            print("") 
            print("Dim(Nu(A)) = %d" %(numero_parametros))
            print("+")
            print("Dim(Im(A)) = %d" %(nuevaColumna))
            print("= %d" %(columnas), "No. columnas")
            print("") 
        elif rango_coeficientes == rango_aumentada and rango_aumentada < nuevaColumna:
            print("")
            matrixaCaso2 = np.zeros((filas_original, columnas+1))
            matrixcCaso2 = np.zeros((filas_original, columnas))
            matrixaCaso2 = matrixa
            matrixcCaso2 = matrixc
            for i in range(numero_parametros):
                matrixaCaso2 = np.delete(matrixaCaso2, i, axis=1)
                matrixcCaso2 = np.delete(matrixcCaso2, i, axis=1)
            rango_aumentada = np.linalg.matrix_rank(matrixaCaso2)
            rango_coeficientes = np.linalg.matrix_rank(matrixcCaso2)
            columnaNueva = matrixcCaso2.shape[0]
            if rango_aumentada == rango_coeficientes and rango_aumentada == columnaNueva:
                print("Tomando las ultimas columnas para una independencia lineal")
                matrixcCaso2 = matrixcCaso2.T
                print("")
                print("Im(A) = < ", end="")
                for i in range( 0, matrixcCaso2.shape[0]):
                    print("( ", end="")
                    for j in range( 0, matrixcCaso2.shape[1]):
                        print("%5.2f" %matrixcCaso2[i][j], end=' ')
                        if j == matrixcCaso2.shape[1] - 1:
                            print(') ', end=' ')
                print(">")
                print("")  
                print("Asi por el teorema de Rango Nulidad")
                print("") 
                print("Dim(Nu(A)) = %d" %(numero_parametros))
                print("+")
                print("Dim(Im(A)) = %d" %(nuevaColumna))
                print("= %d" %(columnas), "No. columnas")
                print("")  
            else:
                print("Para que sea linealmente independiente se toman las columnas de en medio")
                matrixc = matrixc.T
                print("")
                print("Im(A) = < ", end="")
                for i in range( 0, matrixc.shape[0]):
                    print("( ", end="")
                    for j in range( 0, matrixc.shape[1]):
                        print("%5.2f" %matrixc[i][j], end=' ')
                        if j == matrixc.shape[1] - 1:
                            print(') ', end=' ')
                print(">")
                print("")  
                print("Asi por el teorema de Rango Nulidad")
                print("") 
                print("Dim(Nu(A)) = %d" %(numero_parametros))
                print("+")
                print("Dim(Im(A)) = %d" %(nuevaColumna))
                print("= %d" %(columnas), "No. columnas")
                print("")  
            
                        
elif rango_aumentada != rango_coeficientes:
    print("\nEl sistema no tiene solución--> No es linealmente independiente") 
    
    