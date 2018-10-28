import pygame

from Enemy import Enemy
from utils import load_image


class Enemy1(Enemy):
    def __init__(self, pos):
        super().__init__(load_image("images/enemy1.gif"), pos, 100, 100, 100)
        pass

    def update(self, engine, delta):
        super().update(engine, delta)

        self.rect = self.rect.move(0, self.speed * delta)
        pass
