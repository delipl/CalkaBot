import pygame, sys
from pygame.locals import *

HEIGHT = 1000
WIDTH = 1000

def draw_bg():
    bg_rect.center = (HEIGHT/2, WIDTH/2)
    screen.blit(bg_surface, bg_rect)

pygame.init()
screen  = pygame.display.set_mode((HEIGHT, WIDTH))
clock = pygame.time.Clock()

bg_surface = pygame.image.load("assets/board.png").convert_alpha()
bg_rect = bg_surface.get_rect()

robot_surface = pygame.image.load("assets/robot.png").convert_alpha()
robot_rect = robot_surface.get_rect()


while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()

    draw_bg()

    robot_rect.center = (HEIGHT/2, WIDTH/2)
    screen.blit(robot_surface, robot_rect)

    pygame.display.update()
    clock.tick(60)
