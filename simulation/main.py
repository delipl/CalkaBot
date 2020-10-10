import pygame, sys
from pygame.locals import *

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
        self.rect = self.surface.get_rect()
        self.posX = WIDTH/2
        self.posY = HEIGHT/2
        self.angle = 0
        self.rect.center = (self.posX, self.posY)

    def rotate(self, surface, angle):
        self.angle = angle
        self.surface_rotated = pygame.transform.rotate(self.surface, self.angle)
        self.old_center = self.rect.center
        self.rect = self.surface_rotated.get_rect()
        self.rect.center = self.old_center
        screen.blit(robot.surface_rotated, robot.rect)

pygame.init()
screen  = pygame.display.set_mode((HEIGHT, WIDTH))
clock = pygame.time.Clock()

bg = Background()
bg.create_bg()


robot = Robot()

while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()

    bg.draw_bg()
    robot.rotate(robot.surface, 45)



    pygame.display.update()
    clock.tick(60)
