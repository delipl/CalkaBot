import math
import pygame
import sys
from pygame.math import Vector2

HEIGHT = 1000
WIDTH = 1000


class Background():
    def __init__(self):
        self.bg_surface = pygame.image.load("assets/board.png").convert_alpha()
        self.bg_rect = self.bg_surface.get_rect()
        self.bg_rect.center = (int(HEIGHT / 2), int(WIDTH / 2))

    def draw_bg(self):
        screen.blit(bg.bg_surface, bg.bg_rect)


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
        self.dx = int((self.new_x - self.x) / 60)
        self.dy = int((self.new_y - self.y) / 60)
        for i in range(60):
            self.rect.x = self.x + self.dx * (i + 1)
            self.rect.y = self.y + self.dy * (i + 1)
            screen.blit(bg.bg_surface, bg.bg_rect)
            screen.blit(self.surface_rotated, self.rect)
            pygame.display.update()

    def draw(self):
        screen.blit(robot.surface_rotated, robot.rect)
        pygame.display.update()
        screen.fill((0, 0, 0))


pygame.init()
screen = pygame.display.set_mode((HEIGHT, WIDTH))
clock = pygame.time.Clock()

bg = Background()
robot = Robot()
angle = 0
s = 0
play = 1
filename = "data.txt"


while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()

    if play == 1:
        try:
            filehandle = open(filename, 'r')
            for line in filehandle:
                angle, s = line.split('     ')
                robot.movement(int(angle), int(s))
                bg.draw_bg()
                robot.draw()
                pygame.time.wait(500)
                if not line:
                    break
        finally:
            filehandle.close()
            play = 0

    clock.tick(60)
