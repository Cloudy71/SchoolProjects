import pygame
from math import floor

from pygame.rect import Rect

from GameObject import GameObject
from utils import load_image


class Explosion(GameObject):
    def __init__(self, pos):
        super().__init__(load_image("images/explosion_anim.jpg"), pos)
        self.rect = Rect(pos[0], pos[1], 64, 64)
        self.image_index = []
        for i in range(16):
            y = floor(i / 4)
            x = i - y * 4
            self.image_index.append(self.image.subsurface((x * 64 + 1, y * 64 + 1, 63, 63)))
        self.index = 0
        self.sprite_speed = 33

        self.sprite_last = 0
        self.init = False

    def update(self, engine, delta):
        if not self.init:
            self.init = True
            engine.sound_explosion.play()

        if self.index >= 15:
            engine.sprites.remove(self)
        elif pygame.time.get_ticks() >= self.sprite_last + self.sprite_speed:
            self.index += 1
            self.sprite_last = pygame.time.get_ticks()
        pass

    def draw(self, surface):
        surface.blit(self.image_index[self.index], self.rect)
