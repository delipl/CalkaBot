import pygame, sys
from pygame.locals import *
from pygame.math import Vector2
import math

import randomValues

HEIGHT = 1000
WIDTH = 1000

class Background():
    def create_bg(self):
        self.bg_surface = pygame.image.load("assets/board.png").convert_alpha()
        self.bg_rect = self.bg_surface.get_rect()

    def draw_bg(self):
        self.bg_rect.center = (int(HEIGHT/2), int(WIDTH/2))
        screen.blit(self.bg_surface, self.bg_rect)

class Robot():
    def __init__(self):
        self.surface = pygame.image.load("assets/robot.png").convert_alpha()
        self.pos = Vector2(WIDTH/2, HEIGHT/2)
        self.rect = self.surface.get_rect(center=(int(self.pos.x), int(self.pos.y)))

    def movement(self, surface, angle, speed):
        self.angle = angle
        self.surface_rotated = pygame.transform.rotate(self.surface, -self.angle)
        self.old_center = self.rect.center
        self.rect = self.surface.get_rect()
        self.rect.center = self.old_center
        self.speed_x = int(speed * math.sin(math.radians(angle)))
        self.speed_y = int(speed * math.cos(math.radians(angle)))
        self.rect.x += self.speed_x
        self.rect.y -= self.speed_y
        screen.blit(robot.surface_rotated, robot.rect)

pygame.init()
screen  = pygame.display.set_mode((HEIGHT, WIDTH))
clock = pygame.time.Clock()

bg = Background()
bg.create_bg()

angle = 0
speed = 0
count = 0

robot = Robot()

while True:
    count = count + 1
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()

    bg.draw_bg()
    if(count == 50):
        angle = randomValues.getAngle(angle)
        count = 0
    speed = randomValues.getSpeed(speed)
    f = open("data.txt", "a")
    data = str(angle) + "\t" + str(speed) + "\n"
    f.write(data)
    f.close()

    robot.movement(robot.surface, angle, speed)

    pygame.display.update()
    clock.tick(60)
