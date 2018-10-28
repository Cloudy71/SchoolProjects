import pygame


class GameObject(pygame.sprite.Sprite):
    def __init__(self, image, pos):
        super().__init__()
        self.image = image
        self.rect = self.image.get_rect()
        self.rect.center = pos

    def update(self, engine, delta):
        pass

    def draw(self, surface):
        surface.blit(self.image, self.rect)

    pass
