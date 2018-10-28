import math
import pygame

from Enemy import Enemy
from utils import load_image


class Enemy2(Enemy):
    def __init__(self, pos):
        super().__init__(load_image("images/enemy2.gif"), pos, 51, 300, 50, 15)

        self.angle = 0

        pass

    def hit(self, engine, dmg):
        hp = engine.random.randint(0, 1)
        if hp == 1:
            self.health -= 1
        super().hit(engine, dmg)

    def update(self, engine, delta):
        super().update(engine, delta)

        self.angle += 300 * delta
        if self.angle > 360:
            self.angle = 0

        self.rect = self.rect.move(math.sin(self.angle * math.pi / 180) * 4 * self.speed * delta,
                                   math.ceil(self.speed * delta))
        pass
