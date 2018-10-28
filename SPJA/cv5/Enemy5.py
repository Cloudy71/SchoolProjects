import math

import pygame

from Enemy import Enemy
from utils import load_image


class Enemy5(Enemy):
    def __init__(self, pos):
        super().__init__(load_image("images/enemy5.gif"), pos, 50, 1100, 120, 30)

        self.angle = 0
        self.save = 1
        self.moving = False
        self.image_shield = load_image("images/shield.png")
        self.image_shield = pygame.transform.scale(self.image_shield, (80, 80))
        self.shield_rect = self.image_shield.get_rect()

        pass

    def update(self, engine, delta):
        super().update(engine, delta)

        self.angle += 200 * delta
        if self.angle > 360:
            self.angle = 0

        if self.moving:
            self.rect = self.rect.move(0, -self.speed * delta * 2)
            if self.rect.top <= 0:
                self.rect.top = 0
                self.moving = False
        else:
            self.rect = self.rect.move(math.sin(self.angle * math.pi / 180) * 4 * self.speed * delta,
                                       math.ceil(self.speed * delta))

        self.shield_rect.left = self.rect.left - 40 + self.rect.width / 2
        self.shield_rect.top = self.rect.top - 40 + self.rect.height / 2
        pass

    def draw(self, surface):
        super().draw(surface)
        if self.moving:
            surface.blit(self.image_shield, self.shield_rect)

    def hit(self, engine, dmg):
        if self.moving:
            return

        if self.save > 0:
            self.save -= 1
            self.moving = True
        else:
            super().hit(engine, dmg)
