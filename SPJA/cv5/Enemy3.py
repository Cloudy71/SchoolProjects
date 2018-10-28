import pygame

from Enemy import Enemy
from utils import load_image


class Enemy3(Enemy):
    def __init__(self, pos):
        super().__init__(load_image("images/enemy3.gif"), pos, 300, 500, 100, 20)
        pass

    def update(self, engine, delta):
        super().update(engine, delta)

        self.rect = self.rect.move(0, self.speed * delta)
        pass

    def hit(self, engine, dmg):
        super().hit(engine, dmg)
        if dmg >= 50:
            self.rect.top -= 24
