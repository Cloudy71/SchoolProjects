import pygame

from Enemy import Enemy
from utils import load_image


class Enemy4(Enemy):
    def __init__(self, pos):
        super().__init__(load_image("images/enemy4.gif"), pos, 120, 800, 90, 25)

        self.side = 0
        pass

    def update(self, engine, delta):
        super().update(engine, delta)

        if self.rect.right > engine.width - 16 and self.side == 0:
            self.side = 1
        elif self.rect.left < 16 and self.side == 1:
            self.side = 0

        self.rect = self.rect.move((1.5 if self.side == 0 else -1.5) * self.speed * delta, self.speed * delta)
        print(self.speed * delta * 1.5)
        pass
