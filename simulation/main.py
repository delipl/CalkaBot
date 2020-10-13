import pygame, sys
from pygame.locals import *
from pygame.math import Vector2
import math

HEIGHT = 1000
WIDTH = 1000

class Background():
    def create_bg(self):
        self.bg_surface = pygame.image.load("assets/board.png").convert_alpha()
        self.bg_rect = self.bg_surface.get_rect()

    def draw_bg(self):
        self.bg_rect.center = (HEIGHT/2, WIDTH/2)
        screen.blit(self.bg_surface, self.bg_rect)

class Robot():
    def __init__(self):
        self.surface = pygame.image.load("assets/robot.png").convert_alpha()
        self.pos = Vector2(WIDTH/2, HEIGHT/2)
        self.rect = self.surface.get_rect(center=(self.pos.x, self.pos.y))
        self.go = 1

    def movement(self, surface, angle, s):
        self.old_center = self.rect.center
        self.angle = angle
        self.surface_rotated = pygame.transform.rotate(self.surface, -self.angle)
        self.rect = self.surface_rotated.get_rect()
        self.rect.center = self.old_center
        #if self.go == 1:
        self.new_x = s * math.sin(math.radians(angle))
        self.new_y = s * math.cos(math.radians(angle))
        self.rect.x += self.new_x
        self.rect.y -= self.new_y
        #self.go = 0
        screen.blit(self.surface_rotated, self.rect)

pygame.init()
screen  = pygame.display.set_mode((HEIGHT, WIDTH))
clock = pygame.time.Clock()

bg = Background()
bg.create_bg()

angle = [45, 60,55, 15, 50]
time = 1
s = 10

robot = Robot()
i = 0
n = 0

while True:
  
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()
    bg.draw_bg()
    x = robot.rect
    
    
    if i == 0:
        elo = angle[n]
        robot.movement(robot.surface, elo, s)
        pygame.display.update()
        print("przesunalem sie")
        i = 10
        if n == 4:
            n = 0
        else:
            n += 1
       
    i = i-1

    dt = round(pygame.time.get_ticks()/1000, 0)
    clock.tick(60)

    
    #pygame.time.wait(100)
    
