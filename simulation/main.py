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
        self.bg_rect.center = (int(HEIGHT / 2), int(WIDTH / 2))
        screen.blit(self.bg_surface, self.bg_rect)


class Robot():
    def __init__(self):
        self.surface = pygame.image.load("assets/robot.png").convert_alpha()
        self.pos = Vector2(WIDTH / 2, HEIGHT / 2)
        self.rect = self.surface.get_rect(center=(int(self.pos.x), int(self.pos.y)))
        self.old_angle = 0

    def movement(self, angle, s):
        self.angle = angle + self.old_angle
        self.old_angle += angle
        self.x = self.rect.x
        self.y = self.rect.y
        self.old_center = self.rect.center
        self.surface_rotated = pygame.transform.rotate(self.surface, -self.angle)
        self.rect = self.surface_rotated.get_rect()
        self.rect.center = self.old_center

        self.new_x = self.x + (s * math.sin(math.radians(self.angle)))
        self.new_y = self.y - (s * math.cos(math.radians(self.angle)))
        self.rect.x = int(self.new_x)
        self.rect.y = int(self.new_y)




pygame.init()
screen = pygame.display.set_mode((HEIGHT, WIDTH))
clock = pygame.time.Clock()

bg = Background()
bg.create_bg()

angle = 45
time = 1
s = 100
x = 1
filename = "data.txt"
robot = Robot()

while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()

    bg.draw_bg()
    if x == 1:
        try:
            filehandle = open(filename, 'r')
            for line in filehandle:
                angle, s = line.split(',')
                robot.movement(int(angle), int(s))
                screen.blit(robot.surface_rotated, robot.rect)
                pygame.display.update()
                pygame.time.wait(1000)
                if not line:
                    break
        finally:
            filehandle.close()
            x = 0





    clock.tick(60)
