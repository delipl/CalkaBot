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

    def movement(self, surface, angle, speed):
        self.angle = angle
        self.surface_rotated = pygame.transform.rotate(self.surface, -self.angle)
        self.old_center = self.rect.center
        self.rect = self.surface_rotated.get_rect()
        self.rect.center = self.old_center
        self.speed_x = speed * math.sin(math.radians(angle))
        self.speed_y = speed * math.cos(math.radians(angle))
        self.rect.x += self.speed_x
        self.rect.y -= self.speed_y
        screen.blit(self.surface_rotated, self.rect)

pygame.init()
screen  = pygame.display.set_mode((HEIGHT, WIDTH))
clock = pygame.time.Clock()

bg = Background()
bg.create_bg()

angle =  45
velocity = 1.5
time = 2
new_angle = 45

robot = Robot()

while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()

    bg.draw_bg()
    robot.movement(robot.surface, angle, velocity)
    dt = round(pygame.time.get_ticks()/1000, 0)
    #print(dt)

    #if dt >= time:
        #if angle != new_angle:
            #angle += 1

    pygame.display.update()
    clock.tick(60)
