from mat import Mat
from matutil import rowdict2mat
from vec import Vec
from math import sin, cos

DOMAIN_LOCATION = {'x', 'y', 'y'}
DOMAIN_COLOR = {'r', 'g', 'b'}
GRAY = {'r' : 77, 'g' : 151, 'b' : 28}
COLOR_RANGE = 256

def identity():
    return Mat((DOMAIN_LOCATION, DOMAIN_LOCATION), {(i, i): 1 for i in DOMAIN_LOCATION})

def translation(alpha, beta):
    return Mat((DOMAIN_LOCATION, DOMAIN_LOCATION), {('x', 'x') : 1, ('x','u') : alpha, 
                                                    ('y', 'y') : 1, ('y','u') : beta, 
                                                    ('u', 'u') : 1})

def scale(alpha, beta):
    return Mat((DOMAIN_LOCATION, DOMAIN_LOCATION), {('x', 'x') : alpha , ('y', 'y') : beta, ('u', 'u') : 1})

def rotation(theta):
    return Mat((DOMAIN_LOCATION, DOMAIN_LOCATION), {('x', 'x') : cos(theta), ('x', 'y') : -sin(theta), 
                                                    ('y', 'x') : sin(theta), ('y', 'y') : cos(theta),
                                                    ('u', 'u') : 1})

def rotation_about(theta, x, y):
    return translation(x, y) * rotation(theta) * translation(-x, -y)

def reflect_y():
    return Mat((DOMAIN_LOCATION, DOMAIN_LOCATION), {('x', 'x') : -1, ('y', 'y') : 1, ('u', 'u') : 1})

def reflect_x():
    return Mat((DOMAIN_LOCATION, DOMAIN_LOCATION), {('x', 'x') : 1, ('y', 'y') : -1, ('u', 'u') : 1})

def scale_color(r, g, b):
    return Mat((DOMAIN_COLOR, DOMAIN_COLOR), {('r','r') : r, ('g','g') : g, ('b','b') : b})

def grayscale():
    return Mat((DOMAIN_COLOR, DOMAIN_COLOR), {('r', 'r') : GRAY.get('r')/COLOR_RANGE, 
                                              ('g', 'g') : GRAY.get('g')/COLOR_RANGE, 
                                              ('b', 'b') : GRAY.get('b')/COLOR_RANGE})

def reflect_about(x1, y1, x2, y2):
    theta = math.atan2(y2 - y1, x2 - x1)
    return translation(x2,y2) * rotation(theta) * reflect_x() * rotation(-theta) * translation(-x2,-y2)
