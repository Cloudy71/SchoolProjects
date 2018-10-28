import pygame

from GameObject import GameObject
from utils import load_image


class Shield(GameObject):
    def __init__(self, pos):
        super().__init__(load_image("images/phaseshield_icon.gif"), pos)
        self.time_spawned = pygame.time.get_ticks()
        self.time_disappear = 8000  # 8 seconds

    def update(self, engine, delta):
        if pygame.time.get_ticks() >= self.time_spawned + self.time_disappear:
            engine.powerups.remove(self)

        if self.rect.colliderect(engine.player.rect):
            engine.player.shield += 20
            if engine.player.shield > 100:
                engine.player.shield = 100
            engine.powerups.remove(self)
