#      =======================================================================
#         ===================INSTITUTO POLITECNICO NACIONAL======================
#         =======================================================================
#                             =============================
#                             =ESCUELA SUPERIOR DE COMPUTO=
#                             =============================
# >>Name: Sánchez Martánez Felipe
# >>Gruop: 2BM1
# >>Carrer: Ing en Inteligencia Artificial
# >>date of last modification: 03/01/22
                   
# Lienar Algebra
# This program will play with the vectors and the Vector space

#ADDING LIBRARIES
from turtle import Turtle


# FUNCTIONS
def NewDot(x, y):
    coordinate = Dot()
    coordinate.x = x
    coordinate.y = y
    return coordinate


def Reflection():
    pass


def Expansion():
    pass


def Cut():
    pass


def Rotation():
    pass

def ShowDraw():
    pass

#Main program
def main():
    print("===========================================================================\n")
    print("======== L I N E A R  T R A N S F O R M A T I O N S 'N A D O R ============\n")
    print("===========================================================================\n\n")
    
    # turtle init
    turtle=Turtle()
    turtle.hideturtle()

    #List
    Draw=[]
    #Adding color to the figure
    turtle.color("Black")
    #Color of the screen
    turtle.screen.bgcolor("White")

    dots= int(input("How many points do u need?"))
    cont = int(0)

    for i,k in dots:
        print("For the dot: ")
        x = float(input("Instroduce the coordinate in X"))
        y = float(input("Instroduce the coordinate in y"))

        Draw.append(NewDot(x,y))



    repit = 'y'
    while repit == 'y':
        print("  <<<=== WHICH LINEAR TRANSFORMATION DO U WANT ===>>>")
        print(
            "    1. Reflections\n"
            "    2. Expansion along the axes\n"
            "    3. Cut in the axes\n"
            "    4. Rotations\n")
        option = int(input("?:"))

        if option == 1:
            Reflection()
        elif option == 2:
            Expansion()
        elif option == 3:
            Cut()
        elif option == 4:
            Rotation()
        else:
            print("Pls select a correct one the next time :b")



        repit = input("Do u want to continue? [y/n]")
        print("\n\n")
        repit = repit.lower()


    print("Have a nice day :)")



# Classes
class Dot(object):
    """docstring for Dot"""
    def __init__(self, x, y):
        super(Dot, self).__init__()
        self.x = x
        self.y = y 


# CODE
if __name__ == '__main__':
    main()